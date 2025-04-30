#include <stdio.h>

int threeIntegers(int num1,int num2,int num3){
    if ((num1 > num2 && num1 < num3) || (num1 < num2 && num1 > num3)){
        return num1;
    }
    if ((num2 > num1 && num2 < num3) || (num2 < num1 && num2 > num3)){
        return num2;
    }
    else{
        return num3;
    }
}

int main() {
    int a;
    printf("Type a number: \n");
    scanf("%d", &a);
    int b;
    printf("Type a number: \n");
    scanf("%d", &b);
    int c;
    printf("Type a number: \n");
    scanf("%d", &c);

    printf("%d\n",threeIntegers(a, b, c));
    getchar();
    return 0;
}
