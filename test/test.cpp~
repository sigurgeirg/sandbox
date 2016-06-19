
#include "test.h"


unsigned long Dio::out[] = {0x00, 0x00};
unsigned long Dio::in[] = {0xFF, 0xFF};

unsigned long *Dio::pOut = &Dio::out[0];
unsigned long *Dio::pIn = &Dio::in[0];


unsigned long Dio::Addr_DOut[] 	= {*(Dio::pOut+0), *(Dio::pOut+1)};
unsigned long Dio::Addr_DIn[] 	= {*(Dio::pIn+0), *(Dio::pIn+1)};

unsigned long Dio::Value_DOut[] = {*(Dio::pOut+0), *(Dio::pOut+1)};
unsigned long Dio::Value_DIn[] 	= {*(Dio::pIn+0), *(Dio::pIn+1)};



Dio::Dio() {

}

Dio::~Dio() {

}

int main()
{
	//std::cout << "This is a value: " << (int)Dio::in[0] << std::endl;

	std::cout << "This is an address: " << &Dio::pIn[0] << std::endl;
	std::cout << "This is a value: " << Dio::pIn[0] << std::endl;

	(Dio::pIn[0]) = 42;

	std::cout << "This is a value: " << Dio::pIn[0] << std::endl;




	//std::cout << "This is an address: " << &Dio::pIn[1] << std::endl;
	//std::cout << "This is a value: " << Dio::pIn[1] << std::endl;

	return 0;
}
