#include <stdio.h>
int main(){

    int digits [] = {1,2,3};
    int length = sizeof(digits) / sizeof(int);

    


    for(int i = length -1; i >=0; i--){
        if (digits[i] == 9){

        digits[i] = 0;

        }  else {   
        digits[i] += 1;
        break;
        }
        
    }
    
      if (digits[0] == 0) {

        printf("1 ");

        for (int i = 0; i < length; i++) {
            
            printf("0 ");
        }
        printf("\n");

        } else {
        for (int i = 0; i < length; i++) {

            printf("%d ", digits[i]);
        }
        printf("\n");
        }
        
    

    return 0;

}