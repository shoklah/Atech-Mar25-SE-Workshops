#include <stdio.h>
#include <stdlib.h>

void printResult(int *result, int size) {
    printf("result: ");
    for (int i = 0; i < size; i++)
        printf("%d ", result[i]);
    printf("\n");
}

int* merge(int* nums1, int m, int* nums2, int n){
    int size = m + n;
    int picked = 0;
    int* result = malloc(sizeof(int) * size + 1);
    int nums1_index = 0;
    int nums2_index = 0;
    int result_index = 0;

    while(result_index < size){

        if (nums1_index < m && nums1[nums1_index] <= nums2[nums2_index]) {
            picked = nums1[nums1_index++];
        } else {
            picked = nums2[nums2_index++];
        }

        result[result_index++] = picked;
    }

    return result;
}

// if (x && y) {
//      do Z;
// }
// <=>
// if (x) {
//      if (y) {
//      do Z;
//     }
// }
int main() {
    int nums1[4] = {1, 2, 3};
    int m = 3;
    int nums2[4] = {2, 5,6};
    int n = 3;

    int* merdedArray = merge(nums1, m, nums2, n);
    printResult(merdedArray, m + n);

    return 0;
}