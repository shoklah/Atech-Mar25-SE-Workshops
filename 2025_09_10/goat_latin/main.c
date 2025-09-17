#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* toGoatLatin(char* sentence){

    char* newString = (char*)malloc(sizeof(char)*1000);
    char* letters = {"aeiou"};

    int newStringIndex = 0;
    int wordCount = 0;

    for(int i = 0; i<strlen(sentence); i++){

        char character = *(sentence+i);

        newString[newStringIndex++]= character;

        if(character == ' '){
            wordCount++;
            character=*(sentence+(++i));

            printf("%c\n", character);
            for(int j = 0; i<strlen(letters);j++){
                if(character==letters[j]){
                    do {
                        character=*(sentence+(i++));
                        newString[newStringIndex++]= character;
                    }while (character != ' ');

                    newString[newStringIndex++] = 'm';
                    newString[newStringIndex++] = 'a';

                    for(int k = 0; k<wordCount;k++)
                        newString[newStringIndex++] = 'a';

                    i--;
                }
            }
        }
    }

    return newString;
}

// owl ma

int main(){
    //char* sentence = {"I speak Goat Latin"}; // "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
    char* sentence = {"I speak owl Latin"}; // "I peaksmaaa owlmaaa atinLmaaaaa"

    printf("To Goat Latin: %s\n", toGoatLatin(sentence));
    return 0;
}