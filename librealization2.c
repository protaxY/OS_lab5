#include "functions.h"
#include <math.h>

float SinIntegral(float a, float b, float e){
    printf("realization 2\n");
    float res = 0;
    float pos1 = a;
    float pos2 = a + e;
    while (pos2 < b){
        res += 0.5 * e * (sin(pos1) + sin(pos2));
        pos1 = pos2;
        pos2 += e;
    }
    return res;
}

void QuickSort(int* nums, int begin, int end)
{
    printf("realization 2\n");
    int l = begin, r = end;
    int v = nums[l+(r-l)/2];
    while(l <= r)
    {
        while(nums[l] < v) l++;
        while(nums[r] > v) r--;
        if(l <= r)
        {
            int tmp = nums[l];
            nums[l] = nums[r];
            nums[r] = tmp;
            l++, r--;
        }
    }
    if(begin < r)
        QuickSort(nums, begin, r);
    if(l < end)
        QuickSort(nums, l, end);
}

void Sort(int* arr, const size_t n) {
    QuickSort(arr, 0, n);
}
