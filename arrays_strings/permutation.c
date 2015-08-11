/*
 * Given two strings determine if one string is a permutation of the other
 */
#include <stdio.h>
#include <string.h>


typedef int bool;
#define true 1;
#define false 0;

typedef char * string;


//Create a unique value for each character
int isPermutation(char * str1, char * str2){
    int str1Len = strlen(str1), str2Len = strlen(str2);
    int str1ascii[127] = {0};
    int str2ascii[127] = {0};
    
    if(str1Len != str2Len){ return false; }
    int i = 0;
    
    for(i = 0; i < str1Len; i++){
        str1ascii[str1[i]] += 1;
        str2ascii[str2[i]] += 1;
    }
    
    for(i = 0; i < str1Len; i++){
        if(str1ascii[str1[i]] != str2ascii[str1[i]]){
            return false;
        }
    }
    
    return true;
    
}


int main(){

    string str1 = "abc";
    string str2 = "aaa";
    
    if(isPermutation(str1,str2)){
        printf("Permutation\n");
    }else{
        printf("Not Permutation\n");
    }
}
