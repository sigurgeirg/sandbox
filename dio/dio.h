/*
*********************************************************************************************************
*                                   Embedded Systems Building Blocks
*                                Complete and Ready-to-Use Modules in C
*
*                                         Discrete I/O Module
*
*                            (c) Copyright 1999, Jean J. Labrosse, Weston, FL
*                                          All Rights Reserved
*
* Filename   : DIO.H
* Programmer : Jean J. Labrosse
* Modified for EmbeddedArm module DIO-64, also written in C++ while the original was written in C.
*********************************************************************************************************
*/

#ifndef DIO_H
#define DIO_H


/*
*********************************************************************************************************
*                                           INCLUDE FILES
*********************************************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <bitset>
#include <string>
#include <inttypes.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <assert.h>
#include <fcntl.h>
#include <iostream>
#include <syslog.h>



/*
*********************************************************************************************************
*                                        CONFIGURATION CONSTANTS
*********************************************************************************************************
*/

#define DIO_MAX_DI 32	/* Maximum number of Discreet Input Channels  (1 x DIO-64 module)	*/
#define DIO_MAX_DO 32	/* Maximum number of Discreet Output Channels (1 x DIO-64 module)	*/


#ifdef   DIO_GLOBALS
#define  DIO_EXT
#else
#define  DIO_EXT  extern
#endif


/*
*********************************************************************************************************
*                                       DISCRETE INPUT CONSTANTS
*********************************************************************************************************
*/
                                            /* DI MODE SELECTOR VALUES                                 */
#define  DI_MODE_LOW                0       /* Input is forced low                                     */
#define  DI_MODE_HIGH               1       /* Input is forced high                                    */
#define  DI_MODE_DIRECT             2       /* Input is based on state of physical input               */
#define  DI_MODE_INV                3       /* Input is based on the complement of the physical input  */
#define  DI_MODE_EDGE_LOW_GOING     4       /* Low  going edge detection of input                      */
#define  DI_MODE_EDGE_HIGH_GOING    5       /* High going edge detection of input                      */
#define  DI_MODE_EDGE_BOTH          6       /* Both low and high going edge detection of input         */
#define  DI_MODE_TOGGLE_LOW_GOING   7       /* Low  going edge detection of input                      */
#define  DI_MODE_TOGGLE_HIGH_GOING  8       /* High going edge detection of input                      */

                                            /* DI EDGE TRIGGERING MODE SELECTOR VALUES                 */
#define  DI_EDGE_LOW_GOING          0       /* Negative going edge                                     */
#define  DI_EDGE_HIGH_GOING         1       /* Positive going edge                                     */
#define  DI_EDGE_BOTH               2       /* Both positive and negative going                        */


/*
*********************************************************************************************************
*                                       DISCRETE OUTPUT CONSTANTS
*********************************************************************************************************
*/

                                            /* DO MODE SELECTOR VALUES                                 */
#define  DO_MODE_LOW                0       /* Output will be low                                      */
#define  DO_MODE_HIGH               1       /* Output will be high                                     */
#define  DO_MODE_DIRECT             2       /* Output is based on state of user supplied state         */
#define  DO_MODE_BLINK_SYNC         3       /* Sync.  Blink mode                                       */
#define  DO_MODE_BLINK_ASYNC        4       /* Async. Blink mode                                       */

                                            /* DO BLINK MODE ENABLE SELECTOR VALUES                    */
#define  DO_BLINK_EN                0       /* Blink is always enabled                                 */
#define  DO_BLINK_EN_NORMAL         1       /* Blink depends on user request's state                   */
#define  DO_BLINK_EN_INV            2       /* Blink depends on the complemented user request's state  */



//#define peek8(adr) PEEK8((unsigned long)&Dio::syscon8[(adr)])
//#define poke8(adr, val) POKE8((unsigned long)&Dio::syscon8[(adr)],(val))
#define peek8(adr) 	PEEK8(adr)
#define poke8(adr, val) POKE8(adr,val)


/*
*************************************************************************************************$
*                                           DATA TYPES
*************************************************************************************************$
*/
typedef struct dio_di {			/* DISCRETE INPUT CHANNEL DATA STRUCTURE		*/
	bool            DIIn;		/* Current state of sensor input  			*/
	unsigned long   DIVal;		/* State of discrete input channel (or # of transitions)*/
	bool            DIPrev;		/* Previous state of DIIn for edge detection		*/
	bool            DIBypassEn;	/* Bypass enable switch (Bypass when TRUE)		*/
	unsigned char   DIModeSel;	/* Discrete input channel mode selector			*/
    #if DI_EDGE_EN
        void (*DITrigFnct)(void *); /* Function to execute if edge triggered                        */
        void *DITrigFnctArg;        /* arguments passed to function when edge detected              */
    #endif
} DIO_DI;

typedef struct dio_do {                /* DISCRETE OUTPUT CHANNEL DATA STRUCTURE                       */
    bool                DOOut;         /* Current state of discrete output channel                     */
    bool                DOCtrl;        /* Discrete output control request                              */
    bool                DOBypass;      /* Discrete output control bypass state                         */
    bool                DOBypassEn;    /* Bypass enable switch (Bypass when TRUE)                      */
    unsigned char       DOModeSel;     /* Discrete output channel mode selector                        */
    unsigned char       DOBlinkEnSel;  /* Blink enable mode selector                                   */
    bool                DOInv;         /* Discrete output inverter selector (Invert when TRUE)         */
    #if DO_BLINK_MODE_EN
        unsigned char     DOA;         /* Blink mode ON time                                           */
        unsigned char     DOB;         /* Asynchronous blink mode period                               */
        unsigned char     DOBCtr;      /* Asynchronous blink mode period counter                       */
    #endif
} DIO_DO;


/*
*********************************************************************************************************
*                                          GLOBAL VARIABLES
*********************************************************************************************************
*/
extern DIO_DI DITbl[DIO_MAX_DI];
//DIO_EXT DIO_DI DITbl[DIO_MAX_DI];
//DIO_DI DITbl[DIO_MAX_DI];
extern  DIO_DO DOTbl[DIO_MAX_DO];
//DIO_EXT DIO_DO DOTbl[DIO_MAX_DO];
//DIO_DO DOTbl[DIO_MAX_DO];


#if DO_BLINK_MODE_EN
    extern unsigned char DOSyncCtr;
    //DIO_EXT unsigned char DOSyncCtr;
    //unsigned char DOSyncCtr;
    extern unsigned char DOSyncCtrMax;
    //DIO_EXT unsigned char DOSyncCtrMax;
    //unsigned char DOSyncCtrMax;
#endif



/*
*********************************************************************************************************
*                                  CLASS AND MEMBER FUNCIONS DEFENITION
*********************************************************************************************************
*/
class Dio {
        private:
        	int devmem;
		//static volatile unsigned char *syscon8;

        public:
        	Dio();
        	~Dio();

		static unsigned long Addr_DOut[4];
		static unsigned long Addr_DIn[4];
		static unsigned char Value_DOut[4];
		static unsigned char Value_DIn[4];


    /*
    *********************************************************************************************************
    *                                          FUNCTION PROTOTYPES
    *********************************************************************************************************
    */

	inline unsigned char PEEK8(unsigned long addr);
	inline void POKE8(unsigned long addr, unsigned char dat);

        void DIOInit(void);

        void DICfgMode(unsigned char n, unsigned char mode);
        unsigned short DIGet(unsigned char n);
        void DISetBypass(unsigned char n, unsigned short val);
        void DISetBypassEn(unsigned char n, bool state);

        #if DI_EDGE_EN
            void DIClr(unsigned char n);
            void DICfgEdgeDetectFnct(unsigned char n, void (*fnct)(void *), void *arg);
        #endif

        void DOCfgMode(unsigned char n, unsigned char mode, bool inv);
        bool DOGet (unsigned char n);
        void DOSet(unsigned char n, bool state);
        void DOSetBypass(unsigned char n, bool state);
        void DOSetBypassEn(unsigned char n, bool state);

        #if DO_BLINK_MODE_EN
            void DOCfgBlink (unsigned char n, unsigned char mode, unsigned char a, unsigned char b);
            void DOSetSyncCtrMax(unsigned char val);
        #endif



	/*
	*********************************************************************************************************
	*                                      LOCAL FUNCTION PROTOTYPES
	*********************************************************************************************************
	*/
	static void DIIsTrig(DIO_DI *pdi);

      	static void DIOTask(void *data);

	static void DIUpdate(void);

      	static bool DOIsBlinkEn(DIO_DO *pdo);
      	static void DOUpdate(void);

	/*
	*********************************************************************************************************
	*                                          FUNCTION PROTOTYPES
	*                                           HARDWARE SPECIFIC
	*********************************************************************************************************
	*/
      	void DIOInitIO(void);
	void DIRd(void);
      	void DOWr(void);
};
#endif
