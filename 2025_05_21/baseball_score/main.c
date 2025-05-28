#include <stdio.h>
#include <stdlib.h>

int calPoints(char* ops[], int size){

    // int size = sizeof(ops) / sizeof(ops[0]);
    // printf("%d")
    // printf("%d\n sizE :", size);
 
  for (int i = 0; i < size; i++) {
    int num = atoi(ops[i]);

    printf("String \"%s\" converted to integer: %d\n", ops[i], num);
  // if between 0 and 9 => use the numbers,
  // otherwise check if  we have char C or D and do the math
  // same with + sign 
  // get the final result as int.

//     String "5" converted to integer: 5
// String "2" converted to integer: 2
// String "C" converted to integer: 0
// String "D" converted to integer: 0
// String "+" converted to integer: 0
  
        // printf("%d %c\n", i, ops[i]);
        // printf("%d \n", *opsnumbers);

    // isdigit()

  }
  return 0;
}

int main(){
   char *ops[] = {"5","2","C","D","+"};
   int size = sizeof(ops) / sizeof(ops[0]);
   int result = calPoints(ops, size);
   printf("%d\n", result);
}