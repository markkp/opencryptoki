static const char rcsid[] = "$Header: /cvsroot/opencryptoki/opencryptoki/usr/lib/pkcs11/api/apiutil.c,v 1.1 2005/01/18 16:09:00 kyoder Exp $";
//
/*
             Common Public License Version 0.5

             THE ACCOMPANYING PROGRAM IS PROVIDED UNDER THE TERMS OF
             THIS COMMON PUBLIC LICENSE ("AGREEMENT"). ANY USE,
             REPRODUCTION OR DISTRIBUTION OF THE PROGRAM CONSTITUTES
             RECIPIENT'S ACCEPTANCE OF THIS AGREEMENT.

             1. DEFINITIONS

             "Contribution" means: 
                   a) in the case of the initial Contributor, the
                   initial code and documentation distributed under
                   this Agreement, and 

                   b) in the case of each subsequent Contributor:
                   i) changes to the Program, and
                   ii) additions to the Program;

                   where such changes and/or additions to the Program
                   originate from and are distributed by that
                   particular Contributor. A Contribution 'originates'
                   from a Contributor if it was added to the Program
                   by such Contributor itself or anyone acting on such
                   Contributor's behalf. Contributions do not include
                   additions to the Program which: (i) are separate
                   modules of software distributed in conjunction with
                   the Program under their own license agreement, and
                   (ii) are not derivative works of the Program.


             "Contributor" means any person or entity that distributes
             the Program.

             "Licensed Patents " mean patent claims licensable by a
             Contributor which are necessarily infringed by the use or
             sale of its Contribution alone or when combined with the
             Program. 

             "Program" means the Contributions distributed in
             accordance with this Agreement.

             "Recipient" means anyone who receives the Program under
             this Agreement, including all Contributors.

             2. GRANT OF RIGHTS

                   a) Subject to the terms of this Agreement, each
                   Contributor hereby grants Recipient a
                   non-exclusive, worldwide, royalty-free copyright
                   license to reproduce, prepare derivative works of,
                   publicly display, publicly perform, distribute and
                   sublicense the Contribution of such Contributor, if
                   any, and such derivative works, in source code and
                   object code form.

                   b) Subject to the terms of this Agreement, each
                   Contributor hereby grants Recipient a
                   non-exclusive, worldwide, royalty-free patent
                   license under Licensed Patents to make, use, sell,
                   offer to sell, import and otherwise transfer the
                   Contribution of such Contributor, if any, in source
                   code and object code form. This patent license
                   shall apply to the combination of the Contribution
                   and the Program if, at the time the Contribution is
                   added by the Contributor, such addition of the
                   Contribution causes such combination to be covered
                   by the Licensed Patents. The patent license shall
                   not apply to any other combinations which include
                   the Contribution. No hardware per se is licensed
                   hereunder.

                   c) Recipient understands that although each
                   Contributor grants the licenses to its
                   Contributions set forth herein, no assurances are
                   provided by any Contributor that the Program does
                   not infringe the patent or other intellectual
                   property rights of any other entity. Each
                   Contributor disclaims any liability to Recipient
                   for claims brought by any other entity based on
                   infringement of intellectual property rights or
                   otherwise. As a condition to exercising the rights
                   and licenses granted hereunder, each Recipient
                   hereby assumes sole responsibility to secure any
                   other intellectual property rights needed, if any.

                   For example, if a third party patent license is
                   required to allow Recipient to distribute the
                   Program, it is Recipient's responsibility to
                   acquire that license before distributing the
                   Program.

                   d) Each Contributor represents that to its
                   knowledge it has sufficient copyright rights in its
                   Contribution, if any, to grant the copyright
                   license set forth in this Agreement.

             3. REQUIREMENTS

             A Contributor may choose to distribute the Program in
             object code form under its own license agreement, provided
             that:
                   a) it complies with the terms and conditions of
                   this Agreement; and

                   b) its license agreement:
                   i) effectively disclaims on behalf of all
                   Contributors all warranties and conditions, express
                   and implied, including warranties or conditions of
                   title and non-infringement, and implied warranties
                   or conditions of merchantability and fitness for a
                   particular purpose;

                   ii) effectively excludes on behalf of all
                   Contributors all liability for damages, including
                   direct, indirect, special, incidental and
                   consequential damages, such as lost profits;

                   iii) states that any provisions which differ from
                   this Agreement are offered by that Contributor
                   alone and not by any other party; and

                   iv) states that source code for the Program is
                   available from such Contributor, and informs
                   licensees how to obtain it in a reasonable manner
                   on or through a medium customarily used for
                   software exchange.

             When the Program is made available in source code form:
                   a) it must be made available under this Agreement;
                   and
                   b) a copy of this Agreement must be included with
                   each copy of the Program. 

             Contributors may not remove or alter any copyright notices
             contained within the Program.

             Each Contributor must identify itself as the originator of
             its Contribution, if any, in a manner that reasonably
             allows subsequent Recipients to identify the originator of
             the Contribution. 


             4. COMMERCIAL DISTRIBUTION

             Commercial distributors of software may accept certain
             responsibilities with respect to end users, business
             partners and the like. While this license is intended to
             facilitate the commercial use of the Program, the
             Contributor who includes the Program in a commercial
             product offering should do so in a manner which does not
             create potential liability for other Contributors.
             Therefore, if a Contributor includes the Program in a
             commercial product offering, such Contributor ("Commercial
             Contributor") hereby agrees to defend and indemnify every
             other Contributor ("Indemnified Contributor") against any
             losses, damages and costs (collectively "Losses") arising
             from claims, lawsuits and other legal actions brought by a
             third party against the Indemnified Contributor to the
             extent caused by the acts or omissions of such Commercial
             Contributor in connection with its distribution of the
             Program in a commercial product offering. The obligations
             in this section do not apply to any claims or Losses
             relating to any actual or alleged intellectual property
             infringement. In order to qualify, an Indemnified
             Contributor must: a) promptly notify the Commercial
             Contributor in writing of such claim, and b) allow the
             Commercial Contributor to control, and cooperate with the
             Commercial Contributor in, the defense and any related
             settlement negotiations. The Indemnified Contributor may
             participate in any such claim at its own expense.


             For example, a Contributor might include the Program in a
             commercial product offering, Product X. That Contributor
             is then a Commercial Contributor. If that Commercial
             Contributor then makes performance claims, or offers
             warranties related to Product X, those performance claims
             and warranties are such Commercial Contributor's
             responsibility alone. Under this section, the Commercial
             Contributor would have to defend claims against the other
             Contributors related to those performance claims and
             warranties, and if a court requires any other Contributor
             to pay any damages as a result, the Commercial Contributor
             must pay those damages.


             5. NO WARRANTY

             EXCEPT AS EXPRESSLY SET FORTH IN THIS AGREEMENT, THE
             PROGRAM IS PROVIDED ON AN "AS IS" BASIS, WITHOUT
             WARRANTIES OR CONDITIONS OF ANY KIND, EITHER EXPRESS OR
             IMPLIED INCLUDING, WITHOUT LIMITATION, ANY WARRANTIES OR
             CONDITIONS OF TITLE, NON-INFRINGEMENT, MERCHANTABILITY OR
             FITNESS FOR A PARTICULAR PURPOSE. Each Recipient is solely
             responsible for determining the appropriateness of using
             and distributing the Program and assumes all risks
             associated with its exercise of rights under this
             Agreement, including but not limited to the risks and
             costs of program errors, compliance with applicable laws,
             damage to or loss of data, programs or equipment, and
             unavailability or interruption of operations. 

             6. DISCLAIMER OF LIABILITY
             EXCEPT AS EXPRESSLY SET FORTH IN THIS AGREEMENT, NEITHER
             RECIPIENT NOR ANY CONTRIBUTORS SHALL HAVE ANY LIABILITY
             FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
             OR CONSEQUENTIAL DAMAGES (INCLUDING WITHOUT LIMITATION
             LOST PROFITS), HOWEVER CAUSED AND ON ANY THEORY OF
             LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
             (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
             OF THE USE OR DISTRIBUTION OF THE PROGRAM OR THE EXERCISE
             OF ANY RIGHTS GRANTED HEREUNDER, EVEN IF ADVISED OF THE
             POSSIBILITY OF SUCH DAMAGES.

             7. GENERAL

             If any provision of this Agreement is invalid or
             unenforceable under applicable law, it shall not affect
             the validity or enforceability of the remainder of the
             terms of this Agreement, and without further action by the
             parties hereto, such provision shall be reformed to the
             minimum extent necessary to make such provision valid and
             enforceable.


             If Recipient institutes patent litigation against a
             Contributor with respect to a patent applicable to
             software (including a cross-claim or counterclaim in a
             lawsuit), then any patent licenses granted by that
             Contributor to such Recipient under this Agreement shall
             terminate as of the date such litigation is filed. In
             addition, If Recipient institutes patent litigation
             against any entity (including a cross-claim or
             counterclaim in a lawsuit) alleging that the Program
             itself (excluding combinations of the Program with other
             software or hardware) infringes such Recipient's
             patent(s), then such Recipient's rights granted under
             Section 2(b) shall terminate as of the date such
             litigation is filed.

             All Recipient's rights under this Agreement shall
             terminate if it fails to comply with any of the material
             terms or conditions of this Agreement and does not cure
             such failure in a reasonable period of time after becoming
             aware of such noncompliance. If all Recipient's rights
             under this Agreement terminate, Recipient agrees to cease
             use and distribution of the Program as soon as reasonably
             practicable. However, Recipient's obligations under this
             Agreement and any licenses granted by Recipient relating
             to the Program shall continue and survive. 

             Everyone is permitted to copy and distribute copies of
             this Agreement, but in order to avoid inconsistency the
             Agreement is copyrighted and may only be modified in the
             following manner. The Agreement Steward reserves the right
             to publish new versions (including revisions) of this
             Agreement from time to time. No one other than the
             Agreement Steward has the right to modify this Agreement.

             IBM is the initial Agreement Steward. IBM may assign the
             responsibility to serve as the Agreement Steward to a
             suitable separate entity. Each new version of the
             Agreement will be given a distinguishing version number.
             The Program (including Contributions) may always be
             distributed subject to the version of the Agreement under
             which it was received. In addition, after a new version of
             the Agreement is published, Contributor may elect to
             distribute the Program (including its Contributions) under
             the new version. Except as expressly stated in Sections
             2(a) and 2(b) above, Recipient receives no rights or
             licenses to the intellectual property of any Contributor
             under this Agreement, whether expressly, by implication,
             estoppel or otherwise. All rights in the Program not
             expressly granted under this Agreement are reserved.


             This Agreement is governed by the laws of the State of New
             York and the intellectual property laws of the United
             States of America. No party to this Agreement will bring a
             legal action under this Agreement more than one year after
             the cause of action arose. Each party waives its rights to
             a jury trial in any resulting litigation. 



*/

/* (C) COPYRIGHT International Business Machines Corp. 2001          */


//
//
//AIX Pkcs11 Api Utility functions
//

#if NGPTH
#include <pth.h>
#else
#include <pthread.h>
#endif

#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>
#include <errno.h>
#include <sys/syslog.h>

#if defined(AIX)
#include <sys/mode.h>
#endif
#include <sys/ipc.h>

#include "msg.h" //HACK


#include <pkcs11types.h>
#include <apiclient.h>  // Function prototypes for PKCS11
#include <slotmgr.h>
#include <apictl.h>


#include <apiproto.h>

#if SPINXPL
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/file.h>
static int xplfd=-1;
#endif

#include <libgen.h>

#define LIBLOCATION  "/usr/lib/pkcs11"      // this should be set via config


extern  API_Proc_Struct_t  *Anchor;
/* KEY XXX extern  pthread_mutex_t    logmutex; */
extern  int                 logging;

#include <stdarg.h>


void
set_perm(int file)
{
   struct group *grp;

   // Set absolute permissions or rw-rw-r--
   fchmod(file,S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);

}





#ifdef DEBUG
#define LOGIT  logit
#else
#define LOGIT  
#endif

#define SYSLOG

#if defined(AIX)
struct syslog_data log_data = SYSLOG_DATA_INIT;
#endif


void logit( int, char *, ...);


static int enabled=0;
// Logging types.  Ultimately this will allow
// us to log to different log files.  The logger will also
// handle keeping the files to a decent size.
// Much work needs to be done on this capability... 
// Other logging types need to be implemented

void 
loginit(){

//   if (!logging) return;  // WE will always log...

   if (!enabled){
      enabled=1;
#if defined(AIX) || defined(PTHREAD_SYSLOG)
      openlog_r("AIXPKCSModule",LOG_PID|LOG_NDELAY,LOG_DAEMON,&log_data);
      setlogmask_r(LOG_UPTO(LOG_DEBUG),&log_data);
#elif defined(LINUX)
      openlog("openCryptokiModule",LOG_PID|LOG_NDELAY,LOG_DAEMON);
      setlogmask(LOG_UPTO(LOG_DEBUG));
	logit(LOG_DEBUG,"Logging enabled %d enabled",enabled);
#else
#error  "logging not defined for this os"
#endif
   }

}

void
logterm()
{ 
enabled = 0;
}

void
logit(int type,char *fmt, ...)
{
      int n;
      va_list pvar;
      char *env;
      char buffer[2048];
      

   if ( enabled){
      // Verify that the requested logging level is less than or 
      // equal to that which is set at compile time.
      if ( type <= logging ){
         va_start(pvar, fmt);
         vsprintf(buffer,fmt,pvar);
         va_end(pvar);
#if defined(AIX) || defined(PTHREAD_SYSLOG)
         syslog_r(type,&log_data,buffer);
#elif defined(LINUX)
          syslog(type,buffer);
#endif
      }
   }

}


#if SYSVSEM
#include <sys/sem.h>
int   Shm_Sem=-1; // system 5 shared memory semaphore...
pthread_mutex_t  semmtx = PTHREAD_MUTEX_INITIALIZER;  // local mutex for semaphore functions...
static struct sembuf xlock_lock[2]={
               0,0,0,
                                    0,1,SEM_UNDO
};

static struct sembuf xlock_unlock[1] = {
               0,-1,(IPC_NOWAIT | SEM_UNDO)
};


#endif


int
XProcLock(void *x)
{
#if (AIX)
#if PKCS64
   return msem_lock(x,0);
#else
   return pthread_mutex_lock(x);
#endif
#elif PTHREADXPL
   return pthread_mutex_lock(x);
#elif POSIXSEM
#error "posix semaphores need to be defined"
#elif SYSVSEM
#error  "LINUX Code for sysvsem xproc lock needs to be done" 
#elif NOXPROCLOCK
   return CKR_OK;
#elif SPINXPL
   if (xplfd == -1 ) {
        xplfd = open(XPL_FILE,O_CREAT|O_RDWR,S_IRWXU|S_IRWXG|S_IRWXO);
   }
   flock(xplfd,LOCK_EX);
   return CKR_OK;
#else
#error  "XProcess locking needs to be defined"
#endif

}

int 
XProcUnLock(void *x)
{
#if (AIX)
#if PKCS64
   return msem_unlock(x,0);
#else
   return pthread_mutex_unlock(x);
#endif
#elif PTHREADXPL
   return pthread_mutex_unlock(x);
#elif POSIXSEM
#error "posix semaphores need to be defined"
#elif SYSVSEM
#error  "LINUX Code for sysvsem xproc lock needs to be done" 
#elif NOXPROCLOCK
   return CKR_OK;
#elif SPINXPL
   flock(xplfd,LOCK_UN);
   return CKR_OK;
#else
#error  "XProcess locking needs to be definec"
#endif
}


void
AddToSessionList(pSess)
   Session_Struct_t *pSess;
{
   Session_Struct_t *pCur;


   pthread_mutex_lock(&(Anchor->SessListMutex));

   //LOGIT(LOG_DEBUG,"AddToSessionList %x",pSess);
   pCur = Anchor->SessListBeg;

   if (!pCur ) { // first time to add
      //LOGIT(LOG_DEBUG,"\t\tFirst Addition");
      pthread_mutex_lock(&(Anchor->ProcMutex));
      Anchor->SessListBeg = pSess;
      pthread_mutex_unlock(&(Anchor->ProcMutex));
      pSess->Previous = pSess->Next = NULL;
   } else {
      // Go to the end of the list..
      while (pCur->Next != NULL ){
         //LOGIT(LOG_DEBUG,"\t\tPcur = %x  Next = %x",pCur,pCur->Next);
         pCur = pCur->Next;
      }
      // Append this one
      pCur->Next = pSess;
      pSess->Previous = pCur;
      pSess->Next = NULL;
   }

   pthread_mutex_unlock(&(Anchor->SessListMutex));
}

void
RemoveFromSessionList(pSess)
   Session_Struct_t *pSess;
{
   Session_Struct_t *pCur,*pTmp;

   pthread_mutex_lock(&(Anchor->SessListMutex));

   pCur = Anchor->SessListBeg;
   // Just in case check that there really is a list although
   // the call to ValidSession should have caught this already.
   // But someone may have removed the session already 
   // while we were validating the call.
   if ( pCur)  {
      // Are we the beginning of the list
      if (pCur == pSess){
           pthread_mutex_lock(&(Anchor->ProcMutex));
           pTmp = pSess->Next;
           Anchor->SessListBeg = pSess->Next;
           if (pTmp){
              pTmp->Previous = NULL;
           }
           free(pSess);
           pthread_mutex_unlock(&(Anchor->ProcMutex));
           pCur = NULL; // Force out of the loop
      } else {
         // First check for a Null element then check next against 
         // the desired element.  This will allow the loop to terminate
         // at the end of the list even if the desired element is not in
         // the list (should not happen, but be defensive).
         while (pCur && pCur->Next != pSess) {
               pCur = pCur->Next;
         }
         // We did not hit the end of the list without finding
         // our element so we can continue to remove it
         if (pCur != NULL ){
            pTmp = pSess->Next;
            pCur->Next = pTmp;
            if (pTmp) {
               pTmp->Previous = pCur;
            }
            free(pSess);
         }
      }
   }

   pthread_mutex_unlock(&(Anchor->SessListMutex));
}

int
Valid_Session(pSession,rSession)
   Session_Struct_t *pSession;
   ST_SESSION_T   *rSession;
{

   int rv=FALSE;  // Assume that it is not on the list
   Session_Struct_t  *cSessionp;


   if ( !pSession )
      return FALSE;   
      
   // Walk the Anchor block session linked list
   // return TRUE if the pointer is on the list
   // False if it is not
   pthread_mutex_lock(&(Anchor->SessListMutex));

   cSessionp = Anchor->SessListBeg;
   while (cSessionp) {
      if (cSessionp == pSession){
         rv = TRUE;
         rSession->sessionh = pSession->RealHandle;
         rSession->slotID = pSession->SltId;
         break;
      }
      cSessionp = (Session_Struct_t *)cSessionp->Next;
   }

   pthread_mutex_unlock(&(Anchor->SessListMutex));
   return rv;
}


int 
API_Initialized()
{

   if ( Anchor == NULL )
      return FALSE;

#if !(LINUX)
   if ( Anchor->Pid == getpid() ){
      return TRUE;
   } else {
      return FALSE;
   }
#endif

   return TRUE;
}

int
slot_present(id)
   CK_SLOT_ID  id;
{
   Slot_Mgr_Shr_t  *shm;

#ifdef PKCS64
   Slot_Info_t_64  *sinfp;
#else
   Slot_Info_t     *sinfp;
#endif

   // Get pointer to shared memory from the anchor block
   //

   shm = Anchor->SharedMemP;
   sinfp = &(shm->slot_info[id]);

   if ( sinfp->present == FALSE ){
      return FALSE;
   }

   return TRUE;

}

int
incr_sess_counts(slotID)
   CK_SLOT_ID   slotID;
{
   Slot_Mgr_Shr_t  *shm;

#ifdef PKCS64
   Slot_Info_t_64      *sinfp;
   Slot_Mgr_Proc_t_64  *procp;
#else
   Slot_Info_t     *sinfp;
   Slot_Mgr_Proc_t  *procp;
#endif

   // Get the slot mutex
   shm = Anchor->SharedMemP;

      XProcLock(&(shm->slt_mutex));

   sinfp = &(shm->slot_info[slotID]);
   sinfp->global_sessions++;

   procp = &shm->proc_table[Anchor->MgrProcIndex];
   procp->slot_session_count[slotID]++;
   
   XProcUnLock(&(shm->slt_mutex)); 

}

int
decr_sess_counts(slotID)
   CK_SLOT_ID   slotID;
{
   Slot_Mgr_Shr_t  *shm;

#ifdef PKCS64
   Slot_Info_t_64      *sinfp;
   Slot_Mgr_Proc_t_64  *procp;
#else
   Slot_Info_t     *sinfp;
   Slot_Mgr_Proc_t  *procp;
#endif

   // Get the slot mutex
   shm = Anchor->SharedMemP;

   XProcLock(&(shm->slt_mutex));

   sinfp = &(shm->slot_info[slotID]);
   if (sinfp->global_sessions > 0){
      sinfp->global_sessions--;
   }

   procp = &shm->proc_table[Anchor->MgrProcIndex];
   if (procp->slot_session_count[slotID] > 0){
      procp->slot_session_count[slotID]++;
   }
   
   XProcUnLock(&(shm->slt_mutex));


}

// Check if any sessions from other applicaitons exist on this particular
// token.... This will also validate our own sessions as well.
// There might be an issue with the fact that a session is created but the
// number is not incremented until the session allocation is completed by
// the token.  The API may need to lock the shared memory prior to creating
// the session and then unlock when the stdll has completed its work.
// Closing sessions should probably behave the same way.
int
sessions_exist(slotID)
   CK_SLOT_ID   slotID;
{
   Slot_Mgr_Shr_t  *shm;

#ifdef PKCS64
   Slot_Info_t_64      *sinfp;
   Slot_Mgr_Proc_t_64  *procp;
#else
   Slot_Info_t     *sinfp;
   Slot_Mgr_Proc_t  *procp;
#endif

   // Get the slot mutex
   shm = Anchor->SharedMemP;

#ifdef PKCS64
   XProcLock(&(shm->slt_mutex));
   sinfp = &(shm->slot_info[slotID]);
   if (sinfp->global_sessions == 0) {
      XProcUnLock(&(shm->slt_mutex));
      return FALSE;
   }
      XProcUnLock(&(shm->slt_mutex));

#else
   XProcLock(&(shm->slt_mutex));
   sinfp = &(shm->slot_info[slotID]);
   if (sinfp->global_sessions == 0) {
      XProcUnLock(&(shm->slt_mutex));
      return FALSE;
   }
      XProcUnLock(&(shm->slt_mutex));
#endif

   return TRUE;
}

void
unlock_shm()
{
   Slot_Mgr_Shr_t  *shm;
   shm = Anchor->SharedMemP;

   XProcUnLock(&(shm->slt_mutex));
}

void
lock_shm()
{
   Slot_Mgr_Shr_t  *shm;
   shm = Anchor->SharedMemP;
   XProcLock(&(shm->slt_mutex));
}



// Terminates all sessions associated with a given process
// this cleans up any lingering sessions with the process
// and does not 
//
// It is only called from the C_Finalize routine
void
Terminate_All_Process_Sessions()
{
   CK_SLOT_ID   id;
   CK_RV        rv;


   LOGIT(LOG_DEBUG,"Terminate_All_Process_Sessions");
   for (id=0;id<NUMBER_SLOTS_MANAGED;id++){
      // Check if the slot is present in the slot manager
      // if not just skip it...
      if (slot_present(id) == TRUE) {
         rv = C_CloseAllSessions(id);
      } else {
         continue;
      }
      // If the return code is not OK, we are really hosed
      // since we are terminating the session.  
      // For now we will just log it
      if (rv != CKR_OK){
         LOGIT(LOG_DEBUG,"Terminate_All_Process_Sessions RV %x",rv);
      }
   }
   
}

// Register the process with PKCSSLOTD in the
// shared memory.
// This call must be made with the API Global Mutex Locked
// and the Anchor control block initialized with the 
// shared memory.  No checking for shared memory validity is done
int 
API_Register()
{

   long int       reuse=-1,free=-1;
   Slot_Mgr_Shr_t *shm;

#ifdef PKCS64
   Slot_Mgr_Proc_t_64  *procp;
#else
   Slot_Mgr_Proc_t  *procp;
#endif

   uint16         indx;

   // Grab the Shared Memory MUTEX to prevent other updates to the
   // SHM Process 
   // The registration is done to allow for future handling of
   // the Slot Event List.  Which is maintained by the Slotd.
   
   shm = Anchor->SharedMemP;

   XProcLock(&(shm->slt_mutex));

   procp = shm->proc_table;
   for (indx=0;indx< NUMBER_PROCESSES_ALLOWED; indx++,procp++){
      // Is the entry in use

      if (procp->inuse == TRUE) {
         // Handle the weird case of the process terminating without
         // un-registering, and restarting with exactly the same PID 
         // before the slot manager garbage collection can performed.
         // To eliminate the race condition between garbage collection
         // the shm-slt_mutex will protect us.
         // This should be a VERY rare (if ever) occurance, given the
         // way AIX deals with re-allocation of PID;s, however if this
         // ever gets ported over to another platform we want to deal
         // with this accordingly since it may re-use pids differently 
         // (Linux appears to re-use pids more rapidly).
         if ( procp->proc_id == getpid()) {
            if ( reuse == -1 ) {
               reuse = indx;
            }
         }
      }else {
         //Already found the first free
         if (free == -1 ) {
            free = indx;
         }
      }
   }

   // If we did not find a free entry then we fail the routine
   if ( (reuse == -1) && (free == -1 ) ){
      XProcUnLock(&(shm->slt_mutex));
      return FALSE;
   }

   // check if we are reusing a control block or taking the first free.
   // Since th mutex is helt, we don;t have to worry about some other
   // process grabbing the slot...  Garbage collection from
   // the slotd should not affect this since it will grab the mutex
   // before doing its thing.
   if (reuse != -1 ){
      procp = &(shm->proc_table[reuse]);
      indx = reuse;
   } else {
      procp = &(shm->proc_table[free]);
      indx = free;
   }

#ifdef PKCS64
   bzero((char *)procp,sizeof(Slot_Mgr_Proc_t_64));
#else
   bzero((char *)procp,sizeof(Slot_Mgr_Proc_t));
#endif
   procp->inuse = TRUE;
   procp->proc_id = getpid();
   procp->reg_time = time(NULL);

   Anchor->MgrProcIndex=indx;


   LOGIT(LOG_DEBUG,"API_Register MgrProcIndc %d  pid %d \n",procp->proc_id,Anchor->MgrProcIndex);

   //??? What to do about the Mutex and cond variable
   //Does initializing them in the slotd allow for them to not be 
   //initialized in the application.

      XProcUnLock(&(shm->slt_mutex));

   return TRUE;
}

// DeRegister the process with PKCSSLOTD in the
// shared memory.
// This call must be made with the API Global Mutex Locked
// and the Anchor control block initialized with the 
// shared memory.  No checking for shared memory validity is done
void 
API_UnRegister()
{
   
   Slot_Mgr_Shr_t *shm;

#ifdef PKCS64
   Slot_Mgr_Proc_t_64  *procp;
#else
   Slot_Mgr_Proc_t  *procp;
#endif

   uint16         indx;

   // Grab the Shared Memory MUTEX to prevent other updates to the
   // SHM Process 
   // The registration is done to allow for future handling of
   // the Slot Event List.  Which is maintained by the Slotd.
   
   shm = Anchor->SharedMemP;

   XProcLock(&(shm->slt_mutex));

   procp = &(shm->proc_table[Anchor->MgrProcIndex]);

#ifdef PKCS64
   bzero((char *)procp,sizeof(Slot_Mgr_Proc_t_64));
#else
   bzero((char *)procp,sizeof(Slot_Mgr_Proc_t));
#endif

   Anchor->MgrProcIndex=0;

   //??? What to do about the Mutex and cond variable
   //Does initializing them in the slotd allow for them to not be 
   //initialized in the application.

   XProcUnLock(&(shm->slt_mutex));

}

void
DL_UnLoad( sltp,slotID )
   API_Slot_t  *sltp;
   CK_SLOT_ID  slotID;
{
   Slot_Mgr_Shr_t  *shm;

#ifdef PKCS64
   Slot_Info_t_64  *sinfp;
#else
   Slot_Info_t     *sinfp;
#endif

   shm = Anchor->SharedMemP;
   sinfp = &(shm->slot_info[slotID]);

   if ( sinfp->present == FALSE ){
      return;
   }
   if (! sltp->dlop_p ){
      return ;
   }

   // Call the routine to properly unload the DLL
   DL_Unload(sltp);

   return ;

}

int
DL_Loaded( location, dllload)
   char *location;
   DLL_Load_t  *dllload;
{
   int i;

   for (i=0;i< NUMBER_SLOTS_MANAGED;i++){
      if ( dllload[i].dll_name != NULL){
	 LOGIT(LOG_DEBUG,"DL_LOADED Looking for index %d name %s",i,dllload[i].dll_name);
         if (strcmp(location,dllload[i].dll_name)== 0) {
            return i; // Return the index of the dll
         }
      }
   }
   return -1; // Indicate failure to find the dll
}

int
DL_Load( sinfp,sltp,dllload)

#ifdef PKCS64
   Slot_Info_t_64 *sinfp;
#else
   Slot_Info_t *sinfp;
#endif

   API_Slot_t  *sltp;
   DLL_Load_t  *dllload;
{
   int i;
   char  buffer[2048];
   char  *path,*path2;
   char *dname;
   int plen;

 LOGIT(LOG_DEBUG,"DL_LOAD");

   for (i=0;i<NUMBER_SLOTS_MANAGED;i++){
      if (dllload[i].dll_name == NULL){
         LOGIT(LOG_DEBUG,"Empty slot at %d ", i);
         break;
      }
   }
   if (i == NUMBER_SLOTS_MANAGED){  
	LOGIT(LOG_DEBUG,"No empty slots ");
	return 0; // Failed to find it..
   }

   dllload[i].dll_name = sinfp->dll_location;  // Point to the location

   // allocate off the stack
   path = alloca(strlen(sinfp->dll_location)+20);
   path2 = alloca(strlen(sinfp->dll_location)+20);
   if ( !path ) {
        sltp->dlop_p = NULL;
        return 0; // allocation failed
   }

   // Check for the name specified to be corre
   sprintf(path,"%s",sinfp->dll_location);  // make a copy since dir name can change the memory
   sprintf(path2,"%s/stdll",LIBLOCATION);  // make a copy since dir name can change the memory
   dname = dirname(path);
   if (strcmp(dname,path2) != 0 ) {
        // Not in the location we expect
        sltp->dlop_p = NULL;
        return 0;

   }



   if ( sizeof(long) == 4 ) {
      dllload[i].dlop_p = dlopen(sinfp->dll_location,RTLD_NOW);
   } else {
     // 64 bit env 
      sprintf(buffer,"%s64",sinfp->dll_location);
      dllload[i].dlop_p = dlopen(buffer,RTLD_NOW);

   }
   if (dllload[i].dlop_p != NULL ){
      sltp->dlop_p = dllload[i].dlop_p;
      sltp->dll_information = &dllload[i];
      dllload[i].dll_load_count=1;;

   } else {
      LOGIT(LOG_DEBUG,"\tDL_Load of %s failed, dlerror: %s",sinfp->dll_location,dlerror());
      sltp->dlop_p = NULL;
      return 0;
   }
   return 1;

}

int DL_Unload(sltp)
   API_Slot_t  *sltp;
{
   DLL_Load_t  *dllload;

   // Decrement the count of loads.  When 0 then unloadthis thing;
   //
   dllload = sltp->dll_information;
   dllload->dll_load_count --;
   if (dllload->dll_load_count == 0 ){
// bug in 64bit causes crash of system...
// check here for 64bit app
	if (sizeof(long) == 4){
	      dlclose(dllload->dlop_p);
        }
      dllload->dll_name = NULL;
   }
   // Clear out the slot information
   sltp->DLLoaded = FALSE;
   sltp->dlop_p = NULL;
   sltp->pSTfini = NULL;
   sltp->pSTcloseall = NULL;

}

int
DL_Load_and_Init(sltp,slotID )
   API_Slot_t  *sltp;
   CK_SLOT_ID  slotID;
{

   Slot_Mgr_Shr_t  *shm;

#ifdef PKCS64
   Slot_Info_t_64  *sinfp;
#else
   Slot_Info_t     *sinfp;
#endif

   int            (*pSTinit)();
   void            (*pSTfini)();
   void            (*pSTcloseall)();
   void             *dlp;
   CK_RV            rv;
   int            dll_len,dl_index;
   DLL_Load_t  *dllload;


   // Get pointer to shared memory from the anchor block
   //

   shm = Anchor->SharedMemP;
   sinfp = &(shm->slot_info[slotID]);
   dllload = Anchor->DLLs;   // list of dll's in the system

   if ( sinfp->present == FALSE ){
      return FALSE;
   }

   if ( (dll_len = strlen(sinfp->dll_location))){
      // Check if this DLL has been loaded already.. If so, just increment
      // the counter in the dllload structure and copy the data to
      // the slot pointer.
      if ( (dl_index = DL_Loaded(sinfp->dll_location,dllload)) != -1 ){
         dllload[dl_index].dll_load_count++;
         sltp->dll_information = &dllload[dl_index];
         sltp->dlop_p = dllload[dl_index].dlop_p;
      } else {
         LOGIT(LOG_DEBUG,"DL_Load_and_Init dll_location %s",sinfp->dll_location);
         DL_Load(sinfp,sltp,dllload);
      }
   } else {
      return FALSE;
   }


   if (! sltp->dlop_p ){
      LOGIT(LOG_DEBUG,"DL_Load_and_Init pointer %x",sltp->dlop_p);
   
      return FALSE;
   }

   if (strlen(sinfp->slot_init_fcn)){
      pSTinit = (int (*)())dlsym( sltp->dlop_p, sinfp->slot_init_fcn);
   } else {
      DL_Unload(sltp);
      // dlclose(sltp->dlop_p);
      return FALSE;
   }
   if (!pSTinit ){
      // Unload the DLL
      DL_Unload(sltp);
      //dlclose(sltp->dlop_p);
      return FALSE;
   }

   // Returns true or false
   rv = pSTinit(&(sltp->FcnList),slotID,sinfp->correlator);
   LOGIT(LOG_DEBUG,"return from STDDLL Init = %x",rv);
   
   if (rv != CKR_OK ){
      // clean up and unload
      DL_Unload(sltp);
      //dlclose(sltp->dlop_p);
       sltp->DLLoaded=FALSE;
      return FALSE;
   } else {
      sltp->DLLoaded=TRUE;
      // Check if a SC_Finalize function has been exported
      pSTfini = (void (*)())dlsym(sltp->dlop_p,"SC_Finalize");
      sltp->pSTfini = pSTfini;

      sltp->pSTcloseall = (void (*)())dlsym(sltp->dlop_p,"SC_CloseAllSessions");
      return TRUE;
   }

   return TRUE;

}
void
st_err_log(int num, ...)
{
      int n;
      va_list pvar;
      char *env;
      char buffer[4096*4];
   if (!enabled)  loginit();

   if ( enabled ){
         va_start(pvar, num);
         vsprintf(buffer,err_msg[num].msg,pvar);
         va_end(pvar);
#if defined(AIX)
         syslog_r(LOG_ERR,&log_data,buffer);
#else
         syslog(LOG_ERR,buffer);
#endif
   }

}
