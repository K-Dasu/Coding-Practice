/*
 * Without using any other datastructures determine if a string contains all unique characters
 * (if using data structures can use a hash table (structure vs me creating my own) and if there is a collision string is not unique)
 * C - Language take aways
 *    can type def bool (bool doesn't exist in c )
 *    string functions (strlen, strcat, strstr (first occurence of str2 in str1), strcpy, strcmp)
 */


#include <stdio.h>
#include <string.h>

typedef int bool;
#define true 1
#define false 0

int allUnique(char string[]){
    int array[127] = {0};
    int stringSize = strlen(string);
    int i = 0;
    
    for(i = 0;i < stringSize; i++){
        if(array[string[i]] < 1){
            array[string[i]] += 1;
        }else{
            return false;
        }
    }
    
    return true;
}


int main(){
    char string[5] = {'a','d','b','c','\0'};
    if(allUnique(string)){
        printf("String is unique %s\n",string);
    }else{
        printf("String is NOT unique %s\n",string);
    }
    
}
