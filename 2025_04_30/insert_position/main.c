#include <stdio.h>

int position(int[] arr, int target) {
    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0, i < size; i++){
        if (arr[i] >= target) {
            return i;
        }
    }

    return size;
}
    


int main(){
    int arr[] = {1, 2, 3, 5}
    int target = 4;

    printf("%d\n",position(arr, target));
}