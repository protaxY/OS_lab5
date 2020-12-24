//вариант 8 (1,9)

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(){
    int func;
    while (scanf("%d", &func) > 0){
        if (func == 1) {
            float a, b, e;
            if (scanf("%f %f %f", &a, &b, &e) != 3) {
                perror("invalid input");
                exit(1);
            }
            printf("Sin integral %f\n", SinIntegral(a, b, e));

        } else if (func == 2) {
            size_t size;
            if (scanf("%lu", &size) != 1) {
                perror("invalid input");
                exit(1);
            }
            int* arr = (int*) malloc(sizeof (int) * size);
            for (size_t i = 0; i < size; ++i){
                if (scanf("%d", &arr[i]) != 1){
                    perror("invalid input");
                    exit(1);
                }
            }
            Sort(arr, size);
            printf("Sorted array;");
            for (size_t i = 0; i < size - 1; ++i){
                printf("%d, ", arr[i]);
            }
            printf("%dю", arr[size - 1]);
            printf("\n");
            free(arr);
        }
    }
    return 0;
}