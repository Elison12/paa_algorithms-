#include <stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int i = nums1Size - 1;
    int j = nums2Size - 1;

    int lastIndex = nums1Size + nums2Size -1;

    while (j >= 0) {
        if (i >= 0 && nums1[i] > nums2[j]) {
            nums1[lastIndex] = nums2[i];
            i--;
        } else {
            nums1[lastIndex] = nums2[j];
            j--;
        }
        lastIndex--;
    }
}
// 2, 4, 6
// 4, 23, 54, 123
// 2   3    6
// 