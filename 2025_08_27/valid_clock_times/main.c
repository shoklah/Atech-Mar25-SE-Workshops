
#include <stdio.h>
#include <stdlib.h>

int parse_to_number(char* number_string){
    
    int result= (number_string[0]-'0')*10 + (number_string[1]-'0');
    return result;
}

int change_question_mark(char* copy, int position, int timer){
    int count =0;

    if(copy[position]=='?'){
        for(char i='0';i<='9';i++){
            copy[position]=i;

            if(parse_to_number(copy) <= timer)
                count++;
        }
    }

    return count;
}

int posibilities_time(char* number_minutes_string, int timer){
    int count = 0;

    char* copy = (char*)malloc(sizeof(char)*2);
    copy[0]= number_minutes_string[0];
    copy[1]= number_minutes_string[1];

    if(copy[0] == '?' && copy[1] == '?')
        return timer+1;
    
    count = change_question_mark(copy,0,timer) + change_question_mark(copy,1,timer);
    if(count == 0)
        return 1;
    return count;
}

int valid_clock_times(char* time){ 
    int possibilites =0;
    char* hours = (char*)malloc(sizeof(char)*2);
    hours[0]= time[0];
    hours[1]= time[1];

    char* minutes = (char*)malloc(sizeof(char)*2);
    minutes[0]= time[3];
    minutes[1]= time[4];

    // char* seconds = (char*)malloc(sizeof(char)*2);
    // seconds[0]= time[6];
    // seconds[1]= time[7];

    int p_hour = posibilities_time(hours,23);
    int p_minutes = posibilities_time(minutes,59);
    //int p_seconds = posibilities_time(seconds,59);
    //printf("\n%d %d\n",p_hour,p_minutes);
    possibilites = p_hour * p_minutes; //* p_seconds;
    return possibilites;
}
// int valid_clock_times(char* time){ 
//     int index = 0;
//     int possibilites = 1;
//     for (int i = 0; i < 5; i++){
//         if (time[i] == '?'){
//            index = i;
//            if (i == 0 && time[1] != '?'){
//                 if (time[1] < '5') {
//                     possibilites *= 3;
//                 } else {
//                     possibilites *= 2;
//                 }
//            } else if(i == 1 && time[1] == '?'){
//                    if (time[0] == '2') {
//                     possibilites *= 4;
//                 } else {
//                     possibilites *= 10;
//                 }
//            }
//         }
//     }
//     return possibilites;
// }

int main(){
    // char* time = {"??:11"};
    // printf("possible times: %d\n", valid_clock_times(time));
    // return 0;
    
}