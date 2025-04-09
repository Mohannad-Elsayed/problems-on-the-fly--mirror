#include <stdio.h>
#include <stdint.h>
#include <malloc.h>

union u {
    uint64_t ui;
    double p;
};
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
int main(){
    union u U;
    U.p = -3.14;
    printBits(sizeof U.ui, &U.ui);
    
    return 0;
}