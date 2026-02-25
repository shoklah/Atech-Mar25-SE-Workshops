
#include <stdio.h>
#include <stdlib.h>

int is_triangle(int a, int b, int c)
{
    return a + b > c && a + c > b && c + b > a;
}
//                    s2     m4       e7
//int array[] = {1, 2, 3, 5, 6, 7, 8, 11};                        7
int binary_search_value(int* array, int start, int end, int target_value){
    int middle = (int)(start + (int)((end-start)/2)); // 2+ (2.5 -> 2)
    printf("\nmiddle:%d\n",middle);
    if(middle == start && middle<end)
        middle++;
    if(array[middle] >= target_value && array[middle-1]<target_value)
        // assume that we don't have any duplicates and return previous index from found value
        return middle - 1;
    else if(array[middle] > target_value)
        return binary_search_value(array,start,middle,target_value);
    else
        return binary_search_value(array,middle,end,target_value);
}

int iterative_binary_search_value(int *array, int start, int end, int target_value) {
    int middle = start + (int)((end-start)/2); // 2+ (2.5 -> 2)

    while (array[middle] != target_value) {
        if (array[middle] > target_value) {
            end = middle;
        } else {
            start = middle;
        }
    }

    return middle;
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}


//int arr[] = { 22, 100, 101, 200 200 200 500};
//               0   1    2    3   4   5   6
int binary_iterative_search_v2(int* array,int array_size,int target_edge){
    int start =0;
    int end = array_size-1;
    if(array[end]<target_edge){
        return end;
    }
    while(start!=end){
        int middle =(int)((end + start)/2);
        printf("\nstart: %d\nmiddle: %d\nend:%d",start,middle,end);
        if(target_edge>array[middle]){
            start = middle + 1;
        } else {
            end = middle;
        }
    }
    printf("\n6\n");
    return --start;
}

int main()
{
    int arr[] = {4, 6, 3, 7};
    //int arr[] = {10, 21, 22, 100, 101, 200, 300};
    // int arr[] = {1, 2, 3};
    int arr_size = sizeof(arr) / sizeof(int);
    int triangles_count = 0;
    int first_index = 0;
    int second_index = 1;
    int third_index = 2;

    // while (first_index <= arr_size - 3){
    //     while(second_index <= arr_size - 2){
    //         while(third_index <= arr_size - 1){
    //             triangles_count += is_triangle(arr[first_index],arr[second_index],arr[third_index]);
    //             third_index++;
    //         }
    //         second_index++;
    //         third_index = second_index+1;
    //     }
    //     first_index++;
    //     second_index = first_index+1;
    //     third_index = second_index+1;
    // }

    qsort(arr, arr_size, sizeof(int), compare);
    for(int i =0;i<arr_size;i++)
        printf("%d : %d\n",i,arr[i]);
    for (int k = 0; k < arr_size - 2; k++)
    {
        for (int j = k + 1; j < arr_size - 1; j++)
        {
            triangles_count=binary_iterative_search_v2(arr,arr_size,arr[j]+arr[k]);
            printf("index we are looking for: %d\n", triangles_count);
        }
    }

    return 0;
}


// #include <stdio.h>

// int check_if_triangle(int edge1, int edge2, int edge3)
// {
//     if (edge1 + edge2 > edge3)
//     {
//         if (edge2 + edge3 > edge1)
//         {
//             if (edge3 + edge1 > edge2)
//             {
//                 return 1;
//             }
//         }
//     }
//     return 0;
// }

// int main()
// {
//     int array[] = {1, 5, 3, 6, 2, 7, 11, 4, 8};
//     int count_triangles = 0;

//     printf("%d\n", count_triangles);

//     return 0;
// }