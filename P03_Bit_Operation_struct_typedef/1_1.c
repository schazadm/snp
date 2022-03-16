#include <stdlib.h>
#include <stdio.h>

void printBits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;
    
    for (i = size-1; i >= 0; i--) {
        for (j = 7; j >= 0; j--) {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
    }
    puts("");
}

int main() {
  unsigned int number = 0x75; // dec 117
  unsigned int bit = 3; // bit at position 3

  // Setting a bit
  number |= 1 << bit; //0x7D
  number |= 1 << 1; // 0x7F -> 0111 1111
  
  // Clearing a bit
  bit = 1;
  // unsigned int test = ~(1 << bit);
  number &= ~(1 << bit); // 0x7D
  // printf("~(1 << 1) = 0x%02X\n", test);
  // printBits(sizeof(test), &test);
  
  // Toggling a bit
  bit = 0;
  number ^= 1 << bit;

  printf("number = 0x%02X\n", number);
  
  return EXIT_SUCCESS;
}

