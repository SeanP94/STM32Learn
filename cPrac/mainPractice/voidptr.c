#include <stdio.h>
#include <stdlib.h>


void voidPtrPrac(void* var, int kind) {
    if (kind == 1) { // Int
        int* num = (int*) var;
        printf("It worked, %d is an int.\n", *num);
    }
}

int main() {
    int* ptr = malloc(sizeof(int));
    *ptr = 1;

    voidPtrPrac(ptr, 1);
    free(ptr);
    
    return EXIT_SUCCESS;
}