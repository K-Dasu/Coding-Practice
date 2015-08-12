/*
 *  Replace all spaces with %20
 *  you are provided with extra padding and the true len of the string
 */

#include <stdio.h>
#include <string.h>


// using the same character array to do the swap
void replaceSpaces(char * str, int len){
    int numSpaces = 0, i = 0;
    
    //count # spaces
    for(i = 0; i < len; i++){
        if(str[i] == ' ') numSpaces += 2;
    }
    
    //create room for %20 insert
    for(i = len - 1; i >= 0; i--){
        if(str[i] == ' ') numSpaces -= 2;
        str[i + numSpaces] = str[i];
        if(numSpaces > 0) str[i] = ' ';
    }
    
    //insert %20
    for(i = 0; i < strlen(str); i++){
        if(str[i] == ' '){
            str[i] = '%';
            str[i + 1] = '2';
            str[i + 2] = '0';
            i += 2;
        }
    }
    
}




int main(){
    char string[] = "ab bc de fg hi        ";
    replaceSpaces(string,14);
    printf("new string %s\n", string);
}
