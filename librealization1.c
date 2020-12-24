#include "functions.h"
#include <math.h>

float SinIntegral(float a, float b, float e){
    printf("realization 1\n");
    float res = 0;
    float pos = a;
    while (pos <= b){
        res += sin(pos) * e;
        pos += e;
    }
    return res;
}

void Sort(int *a, size_t size) {
    printf("realization 1\n");
    size_t i, j;
    int tmp;
    for (i = 1; i < size; i++) {
        for (j = 1; j < size; j++) {
            if (a[j] < a[j-1]) {
                tmp = a[j];
                a[j] = a[j-1];
                a[j-1] = tmp;
            }
        }
    }
}