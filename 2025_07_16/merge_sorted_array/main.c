#include <stdio.h>
#include <stdlib.h>


void merge(int *nums1, int m, int *nums2, int n, int* arr){
    int i = 0,j = 0;

    while (i < m && j < n) {
        if(i = m){
            i = 9999;
        }
        if(j = n){
            i = 9999;
        }
        if (nums1[i]<nums2[j]){
            arr[i+j] = nums1[i];
            i++;
        }else{
            arr[i+j] = nums2[j];
            j++;
        }
    }

    for (int i = 0; i < m + n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

}

int main () {

    int nums1[] = {1,2,3};
    int nums2[] = {2,5,6};
    int n = 3;
    int m = 3;
    // allocate memory we need
    int *arr = (int *)malloc((m + n) *sizeof(int));

    // make sure that memory has been allocated properly
    if (arr == NULL){
        printf("ERROR\n");
        return 1; 
    }

    // set everything to 0 to make sure that we don't pick up any artifacts
    for (int i = 0; i < n + m; i++) {
        arr[i] = 0;
    }

    // do stuff
    merge(nums1, m, nums2, n, arr);

    // release allocated memory once we don't need it anymore
    free(arr);

    return 0;

}