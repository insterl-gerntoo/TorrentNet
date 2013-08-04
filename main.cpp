#include <iostream>
#include <iomanip>
#include "endian_swapper.h"


int main(void)
{
	/*NodeList nl();
	NodeListManager nlm(nl);
	
	nlm.start();
	
	nlm.stop();*/
	
	uint16_t ss16 = 0x0001;
	uint32_t ss32 = 0x00010203;
	uint64_t ss64 = 0x0001020304050607;
	uint8_t ss128[16] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f};
	
	std::cout << std::setfill('0') << std::setw(4) << std::hex << ss16 << std::endl;
	std::cout << std::setw(8) << ss32 << std::endl;
	std::cout << std::setw(16) << ss64 << std::endl;
	for(uint8_t i = 0; i < 16; ++i){std::cout << std::setw(2) << (uint16_t) ss128[i];}
	std::cout << std::endl << std::endl;
	
	EndianSwapper::swap16(ss16);
	EndianSwapper::swap32(ss32);
	EndianSwapper::swap64(ss64);
	EndianSwapper::swap128(ss128);
	
	std::cout << std::setw(4) << std::hex << ss16 << std::endl;
	std::cout << std::setw(8) << ss32 << std::endl;
	std::cout << std::setw(16) << ss64 << std::endl;
	for(uint8_t i = 0; i < 16; ++i){std::cout << std::setw(2) << (uint16_t) ss128[i];}
	std::cout << std::endl << std::endl;
	
	return 0;
}
