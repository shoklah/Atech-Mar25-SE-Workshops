#include <stdio.h>
int main(){

    int digits [] = {1,2,3};
    int length = sizeof(digits) / sizeof(int);

    if (length == 0 && digits[length-1] == 9){

        int digits [] = {1,0};
    }

    if (digits[length-1] == 9){

        digits[length-2] +=1;
        digits[length-1] = 0;


    }


    digits[length-1] += 1;

    

return 0;

}