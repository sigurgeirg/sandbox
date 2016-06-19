
#ifndef TEST_H
#define TEST_H

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



class Dio {
        private:


        public:
        	Dio();
        	~Dio();

		static unsigned long out[2];
		static unsigned long *pOut;

		static unsigned long in[2];
		static unsigned long *pIn;

		static unsigned long DIn[2];


		static unsigned long Addr_DOut[2];
		static unsigned long Addr_DIn[2];
		static unsigned long Value_DOut[2];
		static unsigned long Value_DIn[2];

};


#endif
