#include <stdio.h>

void first_case(char c) {
    printf("first case\n");
}

void second_case(char c) {
    printf("second case\n");
}

void third_case(char c) {
    printf("third case\n");
}

void else_case(char c) {
    printf("else case\n");
}

int main(int argc, char **argv) {
    if (argc == 1)
        return -1;

    char indexes[] = {
        'a',
        'b',
        'c',
    };
    void (*func_ptr_arr[])(char) = {
        &first_case,
        &second_case,
        &third_case,
        &else_case
    };
    char input = argv[1][0];
    char index = 3;

    for (int i = 0; i < 3; i++) {
        if (indexes[i] == input) {
            index = i;
            break;
        }
    }
    func_ptr_arr[index](input);

    // func_ptr_arr[0](input);
    // void (*func_ptr)(char) = &first_case;
    // func_ptr(input);

    // switch (input) {
    //     case 'b':
    //         printf("first case\n");
    //         break;
    //     case 'a':
    //         printf("second case\n");
    //         break;
    //     case 'c':
    //         printf("third case\n");
    //         break;
    //     default:
    //         printf("else case\n");
    // }

    // if (input == 'b') {
    //     printf("first case\n");
    // } else if (input == 'a') {
    //     printf("second case\n");
    // } else if (input == 'c') {
    //     printf("third case\n");
    // } else {
    //     printf("else case\n");
    // }

    return 0;
}

// void send_email(char *content, char *recipient, void (*success)(void), void (*failure)(void)) {
//     int sent = try_and_send_email(arguments);

//     if (sent == 1)
//         success();
//     else
//         failure();
// }