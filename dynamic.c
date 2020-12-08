#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main(){
    char* libNames[] = {"./librealization1.so", "./librealization2.so"};
    int lib = 0;
    float (*SinIntegral)(float, float, float) = NULL;
    void (*Sort)(int*, size_t) = NULL;

    void* dlHandle = dlopen(libNames[lib], RTLD_NOW);
    if (dlHandle == NULL){
        perror(dlerror());
    }

    int func;
    while (scanf("%d", &func) > 0) {
        if (func == 1) {
            float a, b, e;
            if (scanf("%f %f %f", &a, &b, &e) != 3) {
                perror("invalid input");
                exit(1);
            }
            SinIntegral = dlsym(dlHandle, "Sort");
            if (SinIntegral == NULL){
                perror(dlerror());
            }
            printf("Sine integral %f\n", SinIntegral(a, b, e));

        } else if (func == 2) {
            size_t size;
            if (scanf("%lu", &size) != 1) {
                perror("invalid input");
                exit(1);
            }
            Sort = dlsym(dlHandle, "Sort");
            if (Sort == NULL){
                perror(dlerror());
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
            printf("%d", arr[size - 1]);
            printf("\n");
            free(arr);
        }
    }

    if (dlclose(dlHandle) != 0){
        perror(dlerror());
        exit(1);
    }

    return 0;
}