#include <stdio.h>
#include <string.h>


typedef int bool;
#define true 1
#define false 0

int isRotation(char str1[], char str2[]){
    if(strlen(str1) != strlen(str2)) return false;
    
    int len = strlen(str1); int i;
    
    for(i = 0; i < len; i++){
        if(str1[i] == str2[0]){
            int str1Len = len, length = len, j = i, k = 0;
            while(str1Len > 0){
//                if(j < length && str1[j] == str2[k]){ // this statement not necessary just for testing
//                    //printf("str1 = %c  str2 = %c\n",str1[j],str2[k]);
//                }else
                if(j >= length){
                    j = 0;
                    //printf("str1 = %c  str2 = %c\n",str1[j],str2[k]);
                }else if(str1[j] != str2[k]){
                    printf("broke on: str1 = %c  str2 = %c\n",str1[j],str2[k]);
                    break;
                }
                j++; k++;
                str1Len--;
            }
            if(str1Len == 0){ return true; }
        }
    }
    return false;
}

int main(){

    char str1[] = "waterbottle";
    char str2[] = "bottlewater";
    
    if(isRotation(str1,str2)){
        printf("is a rotation\n");
    }else{
        printf("nope\n");
    }

}
