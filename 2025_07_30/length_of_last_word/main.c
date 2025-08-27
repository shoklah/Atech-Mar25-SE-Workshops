int main() {
    char str[] = "this is a.   striuuung";
    int length, index = 0;

    while (str[index] != '\0'){
        if (str[index] == ' '){
            length = 0;
        }
        else length++;
        index++;
    }
    printf("%d\n", length);
    return 0;
}