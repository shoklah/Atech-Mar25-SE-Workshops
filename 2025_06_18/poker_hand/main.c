
#include <stdbool.h>
#include <stdio.h>

char pokerHand(int* rank, char* suits){
    bool isFlush = true;
    for (int i = 0; i < 5; i++) {
        // printf("%c\n", suits[i]);
        if (suits[i] != suits[i + 1]) {
            isFlush = false;
        }
    }
    if (isFlush == true){
        printf("Flush\n");
    } 

    int highiest = 0;
        for (int j = 0; j < 5; j++) {
            if (rank[j] > highiest) {
        
                highiest = rank[j];
       
                
            }
            // printf("%c\n", suits[i]);
            // if (rank[j] != rank[j + 1]) {
                //     isFlush = false;
                // }
            }
         printf("%d\n", highiest);
    return 0;
}


int main(){
    int rank[5] = {1, 9, 3, 4, 2};
    char suits[5] = {'a', 'a', 'a', 'a', 'b'};
    pokerHand(rank,suits);
    // char result = pokerHand(rank, suits); 
    // printf("%c is result\n", result);
    return 0;
}