#include <stdio.h>

int search_insertion(int* nums, int target, int size) {
    int i;
    
     for (i = 0; nums[i] != '\0'; i++) {

         if (nums[i] == target) {
              return i;
         }
          else {
             if (nums[i] > target) {
                return i;
             } else if (nums[size - 1] < target) {
                return size + 1;
             }
         }
     }
 }
 
 
 int main() {
    
     int nums[] = {1,2,4,5};
     size_t totalSize = sizeof(nums);
     size_t elementSize = sizeof(nums[0]);
     size_t size = totalSize / elementSize;

     int target = 10;
     printf("%d\n", search_insertion(nums, target, size));

     return 0;
   }
 
 
