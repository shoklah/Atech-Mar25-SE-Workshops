#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int isDigit(char c) {
  if (c >= '0' && c <= '9')
    return 1;
  return 0;
}

int myAtoi(char *array) {
  int value = 0;
  int is_negative = 0;

  for (int i = 0; array[i] != '\0'; i++) {
    if (array[i] == '-' && i == 0) {
      is_negative = 1;
    } else if (isDigit(array[i])) {
      value *= 10; // value = value * 10
      value += (array[i] - '0'); // value = value + array[i] - '0'
    }
  }

  if (is_negative) {
    value *= -1;
  }

  return value;
}

int getMaxRecordsCount(char *ops[], int size) {
  int max_records = 0;
  int records = 0;

  for (int i = 0; i < size; i++) {
    if (strcmp(ops[i], "C") == 0) {
      records--;
    } else {
      records++;
    }

    if (max_records < records) {
      max_records = records;
    }
  }

  return max_records;
}

int calPoints(char* ops[], int size){
  int max_records = getMaxRecordsCount(ops, size);
  int result = 0;
  int *scores = malloc(max_records * sizeof(int));
  int index = 0;

  for (int i = 0; i < size; i++) {
    int num = myAtoi(ops[i]);

    if((strcmp(ops[i], "C") == 0)) {
      index--;
    } else if((strcmp(ops[i], "D") == 0)) {
      scores[index] = 2 * scores[index - 1];
      index++;
    } else if((strcmp(ops[i], "+") == 0)) {
      scores[index] = scores[index - 1] + scores[index - 2];
      index++;
    } else {
      scores[index] = num;
      index++;
    }
  }

  for (int i = 0; i < index; i++) {
    result += scores[i];
  }

  printf("%d is result\n", result);
  return result;
}

int main(){
   char *ops[] = {"5","-2","4","C","D","9","+","+"};
   int size = sizeof(ops) / sizeof(ops[0]);
   int result = calPoints(ops, size);
   printf("%d\n", result);

  printf("1 = %d\n", myAtoi("1"));
  printf("15 = %d\n", myAtoi("15"));
  printf("156 = %d\n", myAtoi("156"));
  printf("-14564 = %d\n", myAtoi("-14564"));
}