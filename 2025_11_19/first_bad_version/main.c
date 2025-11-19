#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int apiCalls = 0;
int lastVersion = 0;
int firstBadVersion = 0;

// returns 0 if good
// returns 1 if bad
int isBadVersion(int version) {
    apiCalls++;
    return (version >= firstBadVersion);
}
// [ 1,2,3,4,5,6,7,8,9,10 ]
int main() {
    srand(time(NULL));
    // lastVersion = rand() % 1002 + 1;
    // firstBadVersion = rand() % (lastVersion + 1);
    lastVersion = 1000000000000;
    firstBadVersion = rand() % (lastVersion + 1);
    //first version can't be 0 so we choose 1
    int left = 1;
    int right = lastVersion;
    int result = 0;
    if(!isBadVersion(lastVersion)){
        result = 0;
        apiCalls--;
    }else{
        while(left < right){
            int mid  = (int)(left+right)/2;
            printf("left: %d right: %d mid: %d\n", left, right, mid);
            if(!isBadVersion(mid)){
                left = mid;
            } else {
                right = mid;
            }
            if(right - left == 1){
                printf("right - left = %d\n", right-left);
                if(isBadVersion(left))
                    result = left;
                else
                    result = right;
                break;
            }
        }
        if(result == 0)
            result = left;
    }
    

    printf("last version: %d first bad version: %d result: %d number of calls: %d\n", lastVersion, firstBadVersion, result, apiCalls);
}

// O(n) -> worst case scenario we have to go over every element (n)
// O(log(n)) -> worst case scenario we to go over log(n) elements