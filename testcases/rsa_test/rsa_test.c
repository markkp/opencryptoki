// File: driver.c
//
//
// Test driver.  In-depth regression test for PKCS #11
//


#include <windows.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#if (AIX || LINUX)
#include <dlfcn.h>
#include <sys/timeb.h>
#endif

#include "pkcs11types.h"
#include "regress.h"

int skip_token_obj;

CK_FUNCTION_LIST  *funcs;
CK_SLOT_ID  SLOT_ID;

// these values are required when generating a PKCS DSA value.  they were
// obtained by generating a DSA key pair on the 4758 with the default (random)
// values.  these values are in big-endian format
//
CK_BYTE DSA_PUBL_PRIME[128] =
{
   0xba, 0xa2, 0x5b, 0xd9, 0x77, 0xb3, 0xf0, 0x2d, 0xa1, 0x65, 0xf1, 0x83, 0xa7, 0xc9, 0xf0,
   0x8a, 0x51, 0x3f, 0x74, 0xe8, 0xeb, 0x1f, 0xd7, 0x0a, 0xd5, 0x41, 0xfa, 0x52, 0x3c, 0x1f,
   0x79, 0x15, 0x55, 0x18, 0x45, 0x41, 0x29, 0x27, 0x12, 0x4a, 0xb4, 0x32, 0xa6, 0xd2, 0xec,
   0xe2, 0x82, 0x73, 0xf4, 0x30, 0x66, 0x1a, 0x31, 0x06, 0x37, 0xd2, 0xb0, 0xe4, 0x26, 0x39,
   0x2a, 0x0e, 0x48, 0xf6, 0x77, 0x94, 0x47, 0xea, 0x7d, 0x99, 0x22, 0xce, 0x65, 0x61, 0x82,
   0xd5, 0xe3, 0xfc, 0x15, 0x3f, 0xff, 0xff, 0xc8, 0xb9, 0x4f, 0x37, 0xbf, 0x7a, 0xa6, 0x6a,
   0xbe, 0xff, 0xa9, 0xdf, 0xfd, 0xed, 0x4a, 0xb6, 0x83, 0xd6, 0x0f, 0xea, 0xf6, 0x90, 0x4f,
   0x12, 0x8e, 0x09, 0x6e, 0x3c, 0x0a, 0x6d, 0x2e, 0xfb, 0xb3, 0x79, 0x90, 0x8e, 0x39, 0xc0,
   0x86, 0x0e, 0x5d, 0xf0, 0x56, 0xcd, 0x26, 0x45
};

CK_BYTE DSA_PUBL_SUBPRIME[20] =
{
   0x9f, 0x3d, 0x47, 0x13, 0xa3, 0xff, 0x93, 0xbb, 0x4a, 0xa6, 0xb0, 0xf1, 0x7e, 0x54, 0x1e,
   0xba, 0xf0, 0x66, 0x03, 0x61
};


CK_BYTE DSA_PUBL_BASE[128] =
{
   0x1a, 0x5b, 0xfe, 0x12, 0xba, 0x85, 0x8e, 0x9b, 0x08, 0x86, 0xd1, 0x43, 0x9b, 0x4a, 0xaf,
   0x44, 0x31, 0xdf, 0xa1, 0x57, 0xd8, 0xe0, 0xec, 0x34, 0x07, 0x4b, 0x78, 0x8e, 0x3c, 0x62,
   0x47, 0x4c, 0x2f, 0x5d, 0xd3, 0x31, 0x2c, 0xe9, 0xdd, 0x59, 0xc5, 0xe7, 0x2e, 0x06, 0x40,
   0x6c, 0x72, 0x9c, 0x95, 0xc6, 0xa4, 0x2a, 0x1c, 0x1c, 0x45, 0xb9, 0xf3, 0xdc, 0x83, 0xb6,
   0xc6, 0xdd, 0x94, 0x45, 0x4f, 0x74, 0xc6, 0x55, 0x36, 0x54, 0xba, 0x20, 0xad, 0x9a, 0xb6,
   0xe3, 0x20, 0xf2, 0xdd, 0xd3, 0x66, 0x19, 0xeb, 0x53, 0xf5, 0x88, 0x35, 0xe1, 0xea, 0xe8,
   0xd4, 0x57, 0xe1, 0x3d, 0xea, 0xd5, 0x00, 0xc2, 0xa4, 0xf5, 0xff, 0xfb, 0x0b, 0xfb, 0xa2,
   0xb9, 0xf1, 0x49, 0x46, 0x9d, 0x11, 0xa5, 0xb1, 0x94, 0x52, 0x47, 0x6e, 0x2e, 0x79, 0x4b,
   0xc5, 0x18, 0xe9, 0xbc, 0xff, 0xae, 0x34, 0x7f
};


void hex_dump_to_file(char *str, unsigned char *data, int bytes)
{
   FILE *fp;
   fp = fopen("rsadump.h", "a");
   fprintf(fp, "\nunsigned char %s[] =\n                  {", str);
   while (bytes--)
   {
      fprintf(fp, " 0x%x", *data++);
      if (bytes)
      {
         fprintf(fp, ",");
         if (!(bytes % 8))
            fprintf(fp, "\n                   ");
      }
   }
   fprintf(fp, " };\n");
   fclose(fp);

}


unsigned char cka_modulus[] =
                  { 0xec, 0x51, 0xab, 0xa1, 0xf8, 0x40, 0x2c, 0x8,
                    0x2e, 0x24, 0x52, 0x2e, 0x3c, 0x51, 0x6d, 0x98,
                    0xad, 0xee, 0xc7, 0x7d, 0x0, 0xaf, 0xe1, 0xa8,
                    0x61, 0xda, 0x32, 0x97, 0xb4, 0x32, 0x97, 0xe3,
                    0x52, 0xda, 0x28, 0x45, 0x55, 0xc6, 0xb2, 0x46,
                    0x65, 0x1b, 0x2, 0xcb, 0xbe, 0xf4, 0x2c, 0x6b,
                    0x2a, 0x5f, 0xe1, 0xdf, 0xe9, 0xe3, 0xbc, 0x47,
                    0xb7, 0x38, 0xb5, 0xa2, 0x78, 0x9d, 0x15, 0xe2,
                    0x59, 0x81, 0x77, 0x6b, 0x6b, 0x2e, 0xa9, 0xdb,
                    0x13, 0x26, 0x9c, 0xca, 0x5e, 0xa, 0x1f, 0x3c,
                    0x50, 0x9d, 0xd6, 0x79, 0x59, 0x99, 0x50, 0xe5,
                    0x68, 0x1a, 0x98, 0xca, 0x11, 0xce, 0x37, 0x63,
                    0x58, 0x22, 0x40, 0x19, 0x29, 0x72, 0x4c, 0x41,
                    0x89, 0xb, 0x56, 0x9e, 0x3e, 0xd5, 0x6d, 0x75,
                    0x9e, 0x3f, 0x8a, 0x50, 0xf1, 0xa, 0x59, 0x4a,
                    0xc3, 0x59, 0x4b, 0xf6, 0xbb, 0xc9, 0xa5, 0x93 };

unsigned char cka_public_exponent[] =
                  { 0x3 };

unsigned char cka_prime_1[] =
                  { 0xfb, 0xb7, 0x73, 0x24, 0x42, 0xfe, 0x8f, 0x16,
                    0xf0, 0x6e, 0x2d, 0x86, 0x22, 0x46, 0x79, 0xd1,
                    0x58, 0x6f, 0x26, 0x24, 0x17, 0x12, 0xa3, 0x1a,
                    0xfd, 0xf7, 0x75, 0xd4, 0xcd, 0xf9, 0xde, 0x4b,
                    0x8c, 0xb7, 0x4, 0x5d, 0xd9, 0x18, 0xc8, 0x26,
                    0x61, 0x54, 0xe0, 0x92, 0x2f, 0x47, 0xf7, 0x33,
                    0xc2, 0x17, 0xd8, 0xda, 0xe0, 0x6d, 0xb6, 0x30,
                    0xd6, 0xdc, 0xf9, 0x6a, 0x4c, 0xa1, 0xa2, 0x4b };

unsigned char cka_prime_2[] =
                  { 0xf0, 0x57, 0x24, 0xf6, 0x2a, 0x5a, 0x6d, 0x8e,
                    0xb8, 0xc6, 0x6f, 0xd2, 0xbb, 0x36, 0x4f, 0x6d,
                    0xd8, 0xbc, 0xa7, 0x2f, 0xbd, 0x43, 0xdc, 0x9a,
                    0xe, 0x2a, 0x36, 0xb9, 0x21, 0x5, 0xfa, 0x22,
                    0x6c, 0xe8, 0x22, 0x68, 0x2f, 0x1c, 0xe8, 0x27,
                    0xc1, 0xed, 0x8, 0x7a, 0x43, 0x70, 0x7b, 0xe3,
                    0x46, 0x74, 0x2, 0x6e, 0xb2, 0xb1, 0xeb, 0x44,
                    0x72, 0x86, 0xd, 0x55, 0x3b, 0xc8, 0xbc, 0xd9 };

unsigned char cka_exponent_1[] =
                  { 0xa7, 0xcf, 0xa2, 0x18, 0x2c, 0xa9, 0xb4, 0xb9,
                    0xf5, 0x9e, 0xc9, 0x4, 0x16, 0xd9, 0xa6, 0x8b,
                    0x90, 0x4a, 0x19, 0x6d, 0x64, 0xb7, 0x17, 0x67,
                    0x53, 0xfa, 0x4e, 0x8d, 0xde, 0xa6, 0x94, 0x32,
                    0x5d, 0xcf, 0x58, 0x3e, 0x90, 0xbb, 0x30, 0x19,
                    0x96, 0x38, 0x95, 0xb6, 0xca, 0x2f, 0xfa, 0x22,
                    0x81, 0x65, 0x3b, 0x3c, 0x95, 0x9e, 0x79, 0x75,
                    0xe4, 0x93, 0x50, 0xf1, 0x88, 0x6b, 0xc1, 0x87 };

unsigned char cka_exponent_2[] =
                  { 0xa0, 0x3a, 0x18, 0xa4, 0x1c, 0x3c, 0x49, 0x9,
                    0xd0, 0x84, 0x4a, 0x8c, 0x7c, 0xce, 0xdf, 0x9e,
                    0x90, 0x7d, 0xc4, 0xca, 0x7e, 0x2d, 0x3d, 0xbc,
                    0x9, 0x71, 0x79, 0xd0, 0xc0, 0xae, 0xa6, 0xc1,
                    0x9d, 0xf0, 0x16, 0xf0, 0x1f, 0x68, 0x9a, 0xc5,
                    0x2b, 0xf3, 0x5a, 0xfc, 0x2c, 0xf5, 0xa7, 0xec,
                    0xd9, 0xa2, 0xac, 0x49, 0xcc, 0x76, 0x9c, 0xd8,
                    0x4c, 0x59, 0x5e, 0x38, 0xd2, 0x85, 0xd3, 0x3b };

unsigned char cka_coefficient[] =
                  { 0x83, 0xf1, 0xca, 0x6, 0x58, 0x4a, 0x4, 0x5e,
                    0x96, 0xb5, 0x30, 0x32, 0x40, 0x36, 0x48, 0xb9,
                    0x2, 0xc, 0xe3, 0x37, 0xb7, 0x51, 0xbc, 0x22,
                    0x26, 0x5d, 0x74, 0x3, 0x47, 0xd3, 0x33, 0x20,
                    0x8e, 0x75, 0x62, 0xf2, 0x9d, 0x4e, 0xc8, 0x7d,
                    0x5d, 0x8e, 0xb6, 0xd9, 0x69, 0x4a, 0x9a, 0xe1,
                    0x36, 0x6e, 0x1c, 0xbe, 0x8a, 0x14, 0xb1, 0x85,
                    0x39, 0x74, 0x7c, 0x25, 0xd8, 0xa4, 0x4f, 0xde };

int do_EncryptRSA_PKCS( void )
{
   CK_BYTE             data1[100];
   CK_BYTE             data2[256];
   CK_BYTE             cipher[256];
   CK_SLOT_ID          slot_id;
   CK_SESSION_HANDLE   session;
   CK_MECHANISM        mech;
   CK_OBJECT_HANDLE    publ_key, priv_key;
   CK_FLAGS            flags;
   CK_BYTE             user_pin[8];
   CK_ULONG            user_pin_len;
   CK_ULONG            i;
   CK_ULONG            len1, len2, cipherlen;
   CK_RV               rc;
   CK_OBJECT_CLASS  class = CKO_PUBLIC_KEY; 
   CK_KEY_TYPE      type= CKK_RSA;
   CK_OBJECT_CLASS  privclass = CKO_PRIVATE_KEY; 
   CK_BBOOL		true = TRUE;
   CK_BBOOL		false = FALSE;


   CK_ULONG  bits = 1024;
   CK_BYTE   pub_exp[] = { 0x3 };

#if GENKEY
   CK_ATTRIBUTE pub_tmpl[] = {
      {CKA_MODULUS_BITS,    &bits,    sizeof(bits)    },
      {CKA_PUBLIC_EXPONENT, &pub_exp, sizeof(pub_exp) },
   };
#else
   CK_ATTRIBUTE pub_tmpl[] =
   {
      {CKA_CLASS,    &class,    sizeof(class)    },
      {CKA_KEY_TYPE,    &type,    sizeof(type)    },
      {CKA_TOKEN,    &false,    sizeof(false)    },
      {CKA_ENCRYPT,  &true, sizeof(true) },
      {CKA_PUBLIC_EXPONENT, &pub_exp, sizeof(pub_exp) },
      {CKA_MODULUS, cka_modulus, sizeof(cka_modulus)}
   };
#define NUMPUBL 6

   CK_ATTRIBUTE priv_tmpl[] =
   {
      {CKA_CLASS,    &privclass,    sizeof(privclass)    },
      {CKA_KEY_TYPE,    &type,    sizeof(type)    },
      {CKA_TOKEN,    &false,    sizeof(false)    },
      {CKA_DECRYPT,  &true, sizeof(true) },
      {CKA_PUBLIC_EXPONENT, &pub_exp, sizeof(pub_exp) },
      {CKA_PRIVATE_EXPONENT, NULL, 0 },
      {CKA_MODULUS, cka_modulus, sizeof(cka_modulus)},
      {CKA_PRIME_1, cka_prime_1, sizeof(cka_prime_1)},
      {CKA_PRIME_2, cka_prime_2, sizeof(cka_prime_2)},
      {CKA_EXPONENT_1, cka_exponent_1, sizeof(cka_exponent_1)},
      {CKA_EXPONENT_2, cka_exponent_2, sizeof(cka_exponent_2)},
      {CKA_COEFFICIENT, cka_coefficient, sizeof(cka_coefficient)},
      {CKA_SENSITIVE, &true, sizeof(true)}
   };
#define NUMPRIV 13
#endif

   printf("do_EncryptRSA_PKCS...\n");

   slot_id = SLOT_ID;
   flags = CKF_SERIAL_SESSION | CKF_RW_SESSION;
   rc = funcs->C_OpenSession( slot_id, flags, NULL, NULL, &session );
   if (rc != CKR_OK) {
      show_error("   C_OpenSession #1", rc );
      return FALSE;
   }


   memcpy( user_pin, "12345678", 8 );
   user_pin_len = 8;

   rc = funcs->C_Login( session, CKU_USER, user_pin, user_pin_len );
   if (rc != CKR_OK) {
      show_error("   C_Login #1", rc );
      return FALSE;
   }



#if GENKEY
printf("GENERATING KEY \n");
   mech.mechanism      = CKM_RSA_PKCS_KEY_PAIR_GEN;
   mech.ulParameterLen = 0;
   mech.pParameter     = NULL;

   rc = funcs->C_GenerateKeyPair( session,   &mech,
                                  pub_tmpl,   2,
                                  NULL,       0,
                                  &publ_key, &priv_key );
   if (rc != CKR_OK) {
      show_error("   C_GenerateKeyPair #1", rc );
      return FALSE;
   }

#else
// We will create the objects here...
   rc = funcs->C_CreateObject( session, pub_tmpl, NUMPUBL, &publ_key );
   if (rc != CKR_OK) {
      show_error("   C_CreateObject #1", rc );
      rc = FALSE;
      return FALSE;
   }

   rc = funcs->C_CreateObject( session, priv_tmpl, NUMPRIV, &priv_key );
   if (rc != CKR_OK) {
      show_error("   C_CreateObject #2", rc );
      rc = FALSE;
      return FALSE;
   }


#endif
   // now, encrypt some data
   //
   len1      = sizeof(data1);
   len2      = sizeof(data2);
   cipherlen = sizeof(cipher);

   for (i=0; i < len1; i++)
      data1[i] = i % 255;

   mech.mechanism      = CKM_RSA_PKCS;
   mech.ulParameterLen = 0;
   mech.pParameter     = NULL;

   rc = funcs->C_EncryptInit( session, &mech, publ_key );
   if (rc != CKR_OK) {
      show_error("   C_EncryptInit #1", rc );
      return FALSE;
   }

   rc = funcs->C_Encrypt( session, data1, len1, cipher, &cipherlen );
   if (rc != CKR_OK) {
      show_error("   C_Encrypt #1", rc );
      return FALSE;
   }

   printf("Cipyer len %d \n",cipherlen);
   hex_dump_to_file("Ciphertext",cipher,cipherlen);

   // now, decrypt the data
   //
   rc = funcs->C_DecryptInit( session, &mech, priv_key );
   if (rc != CKR_OK) {
      show_error("   C_DecryptInit #1", rc );
      return FALSE;
   }

   rc = funcs->C_Decrypt( session, cipher, cipherlen, data2, &len2 );
   if (rc != CKR_OK) {
      show_error("   C_Decrypt #1", rc );
      return FALSE;
   }

   printf("Len from encrypt %d  from decrypt %d \n",len1, len2);
   //if (len1 != len2) {
   //   printf("   ERROR:  lengths don't match\n");
   //   return FALSE;
  // }

   hex_dump_to_file("decrypted",data2,len2);
   for (i=0; i <len1; i++) {
      if (data1[i] != data2[i]) {
         printf("   ERROR:  mismatch at byte %d\n", i );
         return FALSE;
      }
   }

   rc = funcs->C_CloseAllSessions( slot_id );
   if (rc != CKR_OK) {
      show_error("   C_CloseAllSessions #1", rc );
      return FALSE;
   }


   printf("Looks okay...\n");
   return TRUE;
}



#if !(AIX || LINUX)
//
//
void process_time(SYSTEMTIME t1, SYSTEMTIME t2)
{
   long ms   = t2.wMilliseconds - t1.wMilliseconds;
   long s    = t2.wSecond - t1.wSecond;
   long min  = t2.wMinute - t1.wMinute;
   long hour = t2.wHour   - t1.wHour;

   // this doesn't handle hour wrap around but that's not a problem here
   //

   while (ms < 0) {
      ms += 1000;
      s--;
   }

   while (s < 0) {
      s += 60;
      min--;
   }

   while (min < 0) {
      min += 60;
      hour--;
   }

   ms += (s * 1000) + (min * 60 * 1000);

   printf("Time:  %d ms\n", ms );
}
#else
void process_time(SYSTEMTIME t1, SYSTEMTIME t2)
{
   long ms   = t2.millitm - t1.millitm;
   long s    = t2.time - t1.time;

   while (ms < 0) {
      ms += 1000;
      s--;
   }

   ms += (s*1000);



   printf("Time:  %u msec\n", ms );

}
#endif


//
//
void process_ret_code( CK_RV rc )
{
   switch (rc) {
      case CKR_OK:                               printf(" CKR_OK");                               break;
      case CKR_CANCEL:                           printf(" CKR_CANCEL");                           break;
      case CKR_HOST_MEMORY:                      printf(" CKR_HOST_MEMORY");                      break;
      case CKR_SLOT_ID_INVALID:                  printf(" CKR_SLOT_ID_INVALID");                  break;
      case CKR_GENERAL_ERROR:                    printf(" CKR_GENERAL_ERROR");                    break;
      case CKR_FUNCTION_FAILED:                  printf(" CKR_FUNCTION_FAILED");                  break;
      case CKR_ARGUMENTS_BAD:                    printf(" CKR_ARGUMENTS_BAD");                    break;
      case CKR_NO_EVENT:                         printf(" CKR_NO_EVENT");                         break;
      case CKR_NEED_TO_CREATE_THREADS:           printf(" CKR_NEED_TO_CREATE_THREADS");           break;
      case CKR_CANT_LOCK:                        printf(" CKR_CANT_LOCK");                        break;
      case CKR_ATTRIBUTE_READ_ONLY:              printf(" CKR_ATTRIBUTE_READ_ONLY");              break;
      case CKR_ATTRIBUTE_SENSITIVE:              printf(" CKR_ATTRIBUTE_SENSITIVE");              break;
      case CKR_ATTRIBUTE_TYPE_INVALID:           printf(" CKR_ATTRIBUTE_TYPE_INVALID");           break;
      case CKR_ATTRIBUTE_VALUE_INVALID:          printf(" CKR_ATTRIBUTE_VALUE_INVALID");          break;
      case CKR_DATA_INVALID:                     printf(" CKR_DATA_INVALID");                     break;
      case CKR_DATA_LEN_RANGE:                   printf(" CKR_DATA_LEN_RANGE");                   break;
      case CKR_DEVICE_ERROR:                     printf(" CKR_DEVICE_ERROR");                     break;
      case CKR_DEVICE_MEMORY:                    printf(" CKR_DEVICE_MEMORY");                    break;
      case CKR_DEVICE_REMOVED:                   printf(" CKR_DEVICE_REMOVED");                   break;
      case CKR_ENCRYPTED_DATA_INVALID:           printf(" CKR_ENCRYPTED_DATA_INVALID");           break;
      case CKR_ENCRYPTED_DATA_LEN_RANGE:         printf(" CKR_ENCRYPTED_DATA_LEN_RANGE");         break;
      case CKR_FUNCTION_CANCELED:                printf(" CKR_FUNCTION_CANCELED");                break;
      case CKR_FUNCTION_NOT_PARALLEL:            printf(" CKR_FUNCTION_NOT_PARALLEL");            break;
      case CKR_FUNCTION_NOT_SUPPORTED:           printf(" CKR_FUNCTION_NOT_SUPPORTED");           break;
      case CKR_KEY_HANDLE_INVALID:               printf(" CKR_KEY_HANDLE_INVALID");               break;
      case CKR_KEY_SIZE_RANGE:                   printf(" CKR_KEY_SIZE_RANGE");                   break;
      case CKR_KEY_TYPE_INCONSISTENT:            printf(" CKR_KEY_TYPE_INCONSISTENT");            break;
      case CKR_KEY_NOT_NEEDED:                   printf(" CKR_KEY_NOT_NEEDED");                   break;
      case CKR_KEY_CHANGED:                      printf(" CKR_KEY_CHANGED");                      break;
      case CKR_KEY_NEEDED:                       printf(" CKR_KEY_NEEDED");                       break;
      case CKR_KEY_INDIGESTIBLE:                 printf(" CKR_KEY_INDIGESTIBLE");                 break;
      case CKR_KEY_FUNCTION_NOT_PERMITTED:       printf(" CKR_KEY_FUNCTION_NOT_PERMITTED");       break;
      case CKR_KEY_NOT_WRAPPABLE:                printf(" CKR_KEY_NOT_WRAPPABLE");                break;
      case CKR_KEY_UNEXTRACTABLE:                printf(" CKR_KEY_UNEXTRACTABLE");                break;
      case CKR_MECHANISM_INVALID:                printf(" CKR_MECHANISM_INVALID");                break;
      case CKR_MECHANISM_PARAM_INVALID:          printf(" CKR_MECHANISM_PARAM_INVALID");          break;
      case CKR_OBJECT_HANDLE_INVALID:            printf(" CKR_OBJECT_HANDLE_INVALID");            break;
      case CKR_OPERATION_ACTIVE:                 printf(" CKR_OPERATION_ACTIVE");                 break;
      case CKR_OPERATION_NOT_INITIALIZED:        printf(" CKR_OPERATION_NOT_INITIALIZED");        break;
      case CKR_PIN_INCORRECT:                    printf(" CKR_PIN_INCORRECT");                    break;
      case CKR_PIN_INVALID:                      printf(" CKR_PIN_INVALID");                      break;
      case CKR_PIN_LEN_RANGE:                    printf(" CKR_PIN_LEN_RANGE");                    break;
      case CKR_PIN_EXPIRED:                      printf(" CKR_PIN_EXPIRED");                      break;
      case CKR_PIN_LOCKED:                       printf(" CKR_PIN_LOCKED");                       break;
      case CKR_SESSION_CLOSED:                   printf(" CKR_SESSION_CLOSED");                   break;
      case CKR_SESSION_COUNT:                    printf(" CKR_SESSION_COUNT");                    break;
      case CKR_SESSION_HANDLE_INVALID:           printf(" CKR_SESSION_HANDLE_INVALID");           break;
      case CKR_SESSION_PARALLEL_NOT_SUPPORTED:   printf(" CKR_SESSION_PARALLEL_NOT_SUPPORTED");   break;
      case CKR_SESSION_READ_ONLY:                printf(" CKR_SESSION_READ_ONLY");                break;
      case CKR_SESSION_EXISTS:                   printf(" CKR_SESSION_EXISTS");                   break;
      case CKR_SESSION_READ_ONLY_EXISTS:         printf(" CKR_SESSION_READ_ONLY_EXISTS");         break;
      case CKR_SESSION_READ_WRITE_SO_EXISTS:     printf(" CKR_SESSION_READ_WRITE_SO_EXISTS");     break;
      case CKR_SIGNATURE_INVALID:                printf(" CKR_SIGNATURE_INVALID");                break;
      case CKR_SIGNATURE_LEN_RANGE:              printf(" CKR_SIGNATURE_LEN_RANGE");              break;
      case CKR_TEMPLATE_INCOMPLETE:              printf(" CKR_TEMPLATE_INCOMPLETE");              break;
      case CKR_TEMPLATE_INCONSISTENT:            printf(" CKR_TEMPLATE_INCONSISTENT");            break;
      case CKR_TOKEN_NOT_PRESENT:                printf(" CKR_TOKEN_NOT_PRESENT");                break;
      case CKR_TOKEN_NOT_RECOGNIZED:             printf(" CKR_TOKEN_NOT_RECOGNIZED");             break;
      case CKR_TOKEN_WRITE_PROTECTED:            printf(" CKR_TOKEN_WRITE_PROTECTED");            break;
      case CKR_UNWRAPPING_KEY_HANDLE_INVALID:    printf(" CKR_UNWRAPPING_KEY_HANDLE_INVALID");    break;
      case CKR_UNWRAPPING_KEY_SIZE_RANGE:        printf(" CKR_UNWRAPPING_KEY_SIZE_RANGE");        break;
      case CKR_UNWRAPPING_KEY_TYPE_INCONSISTENT: printf(" CKR_UNWRAPPING_KEY_TYPE_INCONSISTENT"); break;
      case CKR_USER_ALREADY_LOGGED_IN:           printf(" CKR_USER_ALREADY_LOGGED_IN");           break;
      case CKR_USER_NOT_LOGGED_IN:               printf(" CKR_USER_NOT_LOGGED_IN");               break;
      case CKR_USER_PIN_NOT_INITIALIZED:         printf(" CKR_USER_PIN_NOT_INITIALIZED");         break;
      case CKR_USER_TYPE_INVALID:                printf(" CKR_USER_TYPE_INVALID");                break;
      case CKR_USER_ANOTHER_ALREADY_LOGGED_IN:   printf(" CKR_USER_ANOTHER_ALREADY_LOGGED_IN");   break;
      case CKR_USER_TOO_MANY_TYPES:              printf(" CKR_USER_TOO_MANY_TYPES");              break;
      case CKR_WRAPPED_KEY_INVALID:              printf(" CKR_WRAPPED_KEY_INVALID");              break;
      case CKR_WRAPPED_KEY_LEN_RANGE:            printf(" CKR_WRAPPED_KEY_LEN_RANGE");            break;
      case CKR_WRAPPING_KEY_HANDLE_INVALID:      printf(" CKR_WRAPPING_KEY_HANDLE_INVALID");      break;
      case CKR_WRAPPING_KEY_SIZE_RANGE:          printf(" CKR_WRAPPING_KEY_SIZE_RANGE");          break;
      case CKR_WRAPPING_KEY_TYPE_INCONSISTENT:   printf(" CKR_WRAPPING_KEY_TYPE_INCONSISTENT");   break;
      case CKR_RANDOM_SEED_NOT_SUPPORTED:        printf(" CKR_RANDOM_SEED_NOT_SUPPORTED");        break;
      case CKR_RANDOM_NO_RNG:                    printf(" CKR_RANDOM_NO_RNG");                    break;
      case CKR_BUFFER_TOO_SMALL:                 printf(" CKR_BUFFER_TOO_SMALL");                 break;
      case CKR_SAVED_STATE_INVALID:              printf(" CKR_SAVED_STATE_INVALID");              break;
      case CKR_INFORMATION_SENSITIVE:            printf(" CKR_INFORMATION_SENSITIVE");            break;
      case CKR_STATE_UNSAVEABLE:                 printf(" CKR_STATE_UNSAVEABLE");                 break;
      case CKR_CRYPTOKI_NOT_INITIALIZED:         printf(" CKR_CRYPTOKI_NOT_INITIALIZED");         break;
      case CKR_CRYPTOKI_ALREADY_INITIALIZED:     printf(" CKR_CRYPTOKI_ALREADY_INITIALIZED");     break;
      case CKR_MUTEX_BAD:                        printf(" CKR_MUTEX_BAD");                        break;
      case CKR_MUTEX_NOT_LOCKED:                 printf(" CKR_MUTEX_NOT_LOCKED");                 break;
   }
}


//
//
void show_error( CK_BYTE *str, CK_RV rc )
{
   printf("%s returned:  %d (0x%0x)", str, rc, rc );
   process_ret_code( rc );
   printf("\n");
}


//
//
void print_hex( CK_BYTE *buf, CK_ULONG len )
{
   CK_ULONG i, j;

   i = 0;

   while (i < len) {
      for (j=0; (j < 15) && (i < len); j++, i++)
         printf("%03x ", buf[i] );
      printf("\n");
   }
   printf("\n");
}


//
//
int do_GetFunctionList( void )
{
   CK_RV            rc;
#if (AIX || LINUX)
   CK_RV  (*pfoo)();
   void    *d;
   char    *e;
   char	   f[]="/usr/lib/pkcs11/PKCS11_API.so";

#endif


   printf("do_GetFunctionList...\n");

#if (AIX || LINUX)
   e = getenv("PKCSLIB");
   if ( e == NULL) {
	e = f;
      //return FALSE;
   }
   d = dlopen(e,RTLD_NOW);
   if ( d == NULL ) {
      return FALSE;
   }

   pfoo = (CK_RV (*)())dlsym(d,"C_GetFunctionList");
   if (pfoo == NULL ) {
      return FALSE;
   }
   rc = pfoo(&funcs);
#else
   rc = C_GetFunctionList( &funcs ) ;
#endif

   if (rc != CKR_OK) {
      show_error("   C_GetFunctionList", rc );
      return FALSE;
   }

   printf("Looks okay...\n");
   return TRUE;

}



//
//
void main( int argc, char **argv )
{
   CK_C_INITIALIZE_ARGS  cinit_args;
   int        rc, i;

   CK_BBOOL      no_init;

   SLOT_ID = 0;
   skip_token_obj = TRUE;
   no_init = FALSE;


   for (i=1; i < argc; i++) {
      if (strcmp(argv[i], "-noskip") == 0)
         skip_token_obj = FALSE;

      if (strcmp(argv[i], "-slot") == 0) {
         SLOT_ID = atoi(argv[i+1]);
         i++;
      }
      if (strcmp(argv[i], "-noinit") == 0)
         no_init = TRUE;

      if (strcmp(argv[i], "-h") == 0) {
         printf("usage:  %s [-noskip] [-slot <num>] [-h]\n\n", argv[0] );
         printf("By default, Slot #1 is used\n\n");
         printf("By default we skip anything that creates or modifies\n");
         printf("token objects to preserve flash lifetime.\n");
         return;
      }
   }

   printf("Using slot #%d...\n\n", SLOT_ID );

   rc = do_GetFunctionList();
   if (!rc)
      return;

   memset( &cinit_args, 0x0, sizeof(cinit_args) );
   cinit_args.flags = CKF_OS_LOCKING_OK;

   // SAB Add calls to ALL functions before the C_Initialize gets hit

 funcs->C_Initialize( &cinit_args );


   rc = do_EncryptRSA_PKCS();
   if (!rc)
      return;

   funcs->C_Finalize( NULL );
}