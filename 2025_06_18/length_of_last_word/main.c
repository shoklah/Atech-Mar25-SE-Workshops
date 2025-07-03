#include <stdio.h>

int lengthOfLastWord(char *str) {
    int length = 0;
    int index = 0;

    for (; str[index] != '\0';) {
        if (str[index] != ' ') {
            length++;
        } else {
            length = 0;
        }

        index++;
    }
    
    return length;
}

int main() {
    char str[] = "Hello World foo";

    printf("result: %d\n", lengthOfLastWord(str));
    return 0;
}