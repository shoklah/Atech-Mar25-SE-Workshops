
#include <stdio.h>

int valid_clock_times(char* time){ 
    int index = 0;
    int possibilites = 1;
    for (int i = 0; i < 5; i++){
        if (time[i] == '?'){
           index = i;
           if (i == 0 && time[1] != '?'){
                if (time[1] < '5') {
                    possibilites *= 3;
                } else {
                    possibilites *= 2;
                }
           } else if(i == 1 && time[1] == '?'){
                   if (time[0] == '2') {
                    possibilites *= 4;
                } else {
                    possibilites *= 10;
                }
           }
        }
    }
    return possibilites;
}

int main(){
    char* time = {"1?:00"};
    printf("possible times: %d\n", valid_clock_times(time));
    return 0;
}