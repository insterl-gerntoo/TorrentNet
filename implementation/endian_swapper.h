#include <stdint.h>

//Mainly because I don't know of a hton() that handles 128-bit and beyond
//Also because I'm not sure glibc's hton functions are inlined, which would
// be a shame if true considering it's only a single instruction for most of them.
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
					:"=r"(((uint64_t*) toSwap)[0]), "=r"(((uint64_t*) toSwap)[1])
					:"0"(((uint64_t*) toSwap)[1]), "1"(((uint64_t*) toSwap)[0]));
		}
		
		static void swap_arbitrary(uint8_t *toSwap, uint32_t size)
		{
			uint32_t high, low, i;
			uint8_t remainder, oddity, temp;
			
			//in case we have exactly 8 bytes, since our 64-bit swapping
			//code only does pairs of 8 bytes, and the remainder of size % 8
			//(in our case, size << 29) cannot be exactly 8
			if(size == 8)
			{
				swap64(*((uint64_t*) toSwap));
				return;
			}
			
			//See if the length is odd
			oddity = (uint8_t)(size & 0x00000001);
			
			//Set low and high values to start at
			low = (size >> 1) - 1;
			high = low + 1;
			
			//See if the length is a multiple of 8, if not, the extra
			//	in the middle will have to be swapped byte-by-byte
			if((size << 29) != 0)
			{
				remainder = size & 0x00000007;
				remainder >>= 1;

				//If we have an odd number for size, we will have a value in the middle, so skip it
				high += oddity;
				
				for(i = 0; i < (uint32_t)remainder; ++i)
				{
					temp = toSwap[low];
					toSwap[low] = toSwap[high];
					toSwap[high] = temp;
					--low;
					++high;
				}
			}
			
			//(size / 2) / 8 gives us the number of 64-bit swaps we must do
			size >>= 4;
			
			//Make sure we don't read 8 bytes ahead of our low value
			//Would be 8, but indices start at zero, so 7, otherwise segfault
			low -= 7;
			
			//remaining length is a multiple of 8, so swap 8 bytes at a time
			for(i = 0; i < size; ++i)
			{
				__asm__("bswapq %0;\n"
						"bswapq %1;\n"
						:"=r"(*((uint64_t*) (&toSwap[low]))), "=r"(*((uint64_t*) (&toSwap[high])))
						:"0"(*((uint64_t*) (&toSwap[high]))), "1"(*((uint64_t*) (&toSwap[low]))));	
				low -= 8;
				high += 8;
			}
		}
};
