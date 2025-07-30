
#include <stdbool.h>
#include <stdio.h>

// char pokerHand(int* rank, char* suits){
//     bool isFlush = true;
//     for (int i = 0; i < 5; i++) {
//         // printf("%c\n", suits[i]);
//         if (suits[i] != suits[i + 1]) {
//             isFlush = false;
//         }
//     }
//     if (isFlush == true){
//         printf("Flush\n");
//     } 

//     int highiest = 0;
//         for (int j = 0; j < 5; j++) {
//             if (rank[j] > highiest) {
        
//                 highiest = rank[j];
       
                
//             }
//             // printf("%c\n", suits[i]);
//             // if (rank[j] != rank[j + 1]) {
//                 //     isFlush = false;
//                 // }
//             }
//          printf("%d\n", highiest);
//     return 0;
// }


// int main(){
//     int rank[5] = {1, 9, 3, 4, 2};
//     char suits[5] = {'a', 'a', 'a', 'a', 'b'};
//     pokerHand(rank,suits);
//     // char result = pokerHand(rank, suits); 
//     // printf("%c is result\n", result);
//     return 0;
// }

bool isFlush(char* suits){
    for (int i = 1; i < 5; i++) {
        if (suits[i] != suits[i - 1]) return false;
    }
    return true;
}

int dups(int* rank){
    // int duplicates = 0;
    // bool foundPairs = false;
    // for (int i = 0; i < 5; i++){
    //     if (foundPairs == false){
    //         for (int j = 0; j < 5; j++){
    //             if (i != j && i < j && rank[i] == rank[j]){
    //                 duplicates++;
    //                 printf("duplicates: %d\n", rank[i]);
    //                 foundPairs = true;
    //             }
    //         }
    //     }
    // }
    int max_duplicates = 0;
    int duplicates = 0;

    for (int i = 0; i < 5; i++) {
        duplicates = 0;

        for (int j = 0; j < 5; j++) {
            if (rank[i] == rank[j] && i != j)
                duplicates++;
            // result = condition ? value_if_true : value_if_false;
            // if (condition)
            //    result = value_if_true
            // else
            //    result = value_if_false
            max_duplicates = duplicates > max_duplicates ? duplicates : max_duplicates;
            // equivalent to
            // if (duplicates > max_duplicates)
            //     max_duplicates = duplicates;
        }
    }
    return max_duplicates;
}

int highCard(int* rank){
    int highest = 0;
    for (int i = 0; i < 5; i++){
        if (rank[i] > highest) highest = rank[i];
    }
    return highest;
}

char* pokerHand(int* rank, char* suits){

    if (isFlush(suits)) return "Flush";

    int duplicates = dups(rank);
    printf("result of dups: %d\n", duplicates);
    if (duplicates > 0) {
        if (duplicates > 1) return "Three of a Kind";
        else return "Pair";
    }

    int highest = highCard(rank);

    return "High Card";

    return 0;
}


int main(){
    int rank[5] = {1, 2, 5, 10, 9};
    char suits[5] = {'a', 'a', 'a', 'a', 'a'};
    printf("%s\n", pokerHand(rank,suits));
    // char result = pokerHand(rank, suits); 
    // printf("%c is result\n", result);
    return 0;
}