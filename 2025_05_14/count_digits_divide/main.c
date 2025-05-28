#include <stdio.h>

int countDigits(int num){
    int digits[10]; // array of digits
    int count = 0; // number of digits
    int dividable = 0; // number of dividables
    int original = num; // storing the original number

    while (num > 0){
        digits[count] = num % 10; 
        num = num / 10;
        count++;
    }

    for (int i = 0; i < count; i++){
        if ((original % digits[i]) == 0){
            dividable++;
        }
    }
    return dividable;
}

int main(){
    
    printf("%d\n", countDigits(7)); // should return 1
    printf("%d\n", countDigits(121)); // should return 2
    printf("%d\n", countDigits(1248)); // should return 4
}