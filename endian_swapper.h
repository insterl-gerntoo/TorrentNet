#include <stdint.h>

class EndianSwapper
{
	public:
		static inline void swap16(uint16_t &toSwap)
		{
			__asm__("xchgb %%ah, %%al;\n"
					:"=a"(toSwap)
					:"0"(toSwap));
		}
		
		static inline void swap32(uint32_t &toSwap)
		{
			__asm__("bswapl %0;"
					:"=r"(toSwap)
					:"0"(toSwap));
		}
		
		static inline void swap64(uint64_t &toSwap)
		{	
			__asm__("bswapq %0;"
					:"=r"(toSwap)
					:"0"(toSwap));
		}
		
		static inline void swap128(uint8_t *toSwap)
		{
			__asm__("bswapq %0;\n"
					"bswapq %1;\n"
					"xchgq %0, %1;"
					:"=r"(((uint64_t*) toSwap)[0]), "=r"(((uint64_t*) toSwap)[1])
					:"0"(((uint64_t*) toSwap)[0]), "1"(((uint64_t*) toSwap)[1]));
		}
		
		static uint8_t* swap_arbitrary_pw_2(uint8_t *toSwap, uint8_t power)
		{
			__asm__();
		}
};
