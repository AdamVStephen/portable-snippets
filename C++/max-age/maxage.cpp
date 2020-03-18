// Demonstration of communication packet liveliness tests.

// Caveat : signed and unsigned integers require careful treatment in C, C++
//
// References
//
// https://embeddedgurus.com/stack-overflow/2009/08/a-tutorial-on-signed-and-unsigned-integers/
// https://stackoverflow.com/questions/21392627/abs-vs-stdabs-what-does-the-reference-say


// TODO : adopt a standard test framework

// Be careful : iostream may pull in cstdlib or cmath 
// TO be sure which std::abs or ::abs we get, we need to control this.
#include <iostream>


#include <stdlib.h>

// uint32 typedef according to MARTe1
typedef unsigned long int uint32;

// Pull in the SDN header definition
#include "sdn-header.h"

// Define the maximum data age
uint32 maxDataAgeUsec = 20000;

// GCC 4.8.5 compatible version from SDNDrv using abs
// one version by struct, another by object, to learn the SDN styles.
bool isFreshByStructAbs(uint32 usecTime, sdn::Header_t  * header);

bool isFreshByStructAbs(uint32 usecTime, sdn::Header_t  * header) {

	// aardvark is a marker to help inspect the preprocessor .i output
	// and hence to work out where the abs definition comes from
	// on various toolchains.
	if( abs(int(usecTime - header->send_time / 1000)) > maxDataAgeUsec) {
		return false;
	} else {
		return true;
	}
}

// GCC 7 compatible version from SDNDrv using std::abs
// one version by struct, another by object, to learn the SDN styles.
bool isFreshByStructStdAbs(uint32 usecTime, sdn::Header_t  * header);

bool isFreshByStructStdAbs(uint32 usecTime, sdn::Header_t  * header) {

	// aardvark is a marker to help inspect the preprocessor .i output
	// and hence to work out where the abs definition comes from
	// on various toolchains.
	if( std::abs(int(usecTime - header->send_time / 1000)) > maxDataAgeUsec) {
		return false;
	} else {
		return true;
	}
}




// Test functions

void unitTestAbs(void) {
	uint32 usecTime = 40000000;
	// Just in time
	uint32 validUsecTime = usecTime - (maxDataAgeUsec - 1);
	// Just too late
	uint32 invalidUsecTime = usecTime - (maxDataAgeUsec + 1);

	sdn::Header_t h;

	// SDN times are passed in ns
	h.send_time = validUsecTime*1000;

	if (isFreshByStructAbs(usecTime, &h) ){
		std::cout << "V1 test (known valid age) : passed\n";
	} else {

		std::cout << "V1 test (known valid age) : failed\n";
	}

	// SDN times are passed in ns
	h.send_time = invalidUsecTime*1000;

	if (isFreshByStructAbs(usecTime, &h) ){
		std::cout << "V1 test (known invalid age) : failed\n";
	} else {

		std::cout << "V1 test (known invalid age) : passed\n";
	}
}

void unitTestStdAbs(void) {
	uint32 usecTime = 40000000;
	// Just in time
	uint32 validUsecTime = usecTime - (maxDataAgeUsec - 1);
	// Just too late
	uint32 invalidUsecTime = usecTime - (maxDataAgeUsec + 1);

	sdn::Header_t h;

	// SDN times are passed in ns
	h.send_time = validUsecTime*1000;

	if (isFreshByStructStdAbs(usecTime, &h) ){
		std::cout << "V1 test (known valid age) : passed\n";
	} else {

		std::cout << "V1 test (known valid age) : failed\n";
	}

	// SDN times are passed in ns
	h.send_time = invalidUsecTime*1000;

	if (isFreshByStructStdAbs(usecTime, &h) ){
		std::cout << "V1 test (known invalid age) : failed\n";
	} else {

		std::cout << "V1 test (known invalid age) : passed\n";
	}
}



// Tests have some dependencies on language standards and compiler flags.

void showCompilerInformation() {
	std::cout << "This application compiled with __cplusplus" << __cplusplus << std::endl;
}

int main(int argc, char *argv[]) {
	std::cout << "maxage demo" << std::endl;
	showCompilerInformation();

	unitTestAbs();
	unitTestStdAbs();
	return 0;
}
