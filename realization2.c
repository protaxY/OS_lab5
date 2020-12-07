#include "functions.h"
#include <math.h>

float SinIntegral(float a, float b, float e){
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

void sort(int* nums, int begin, int end)
{
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
        sort(nums, begin, r);
    if(l < end)
        sort(nums, l, end);
}