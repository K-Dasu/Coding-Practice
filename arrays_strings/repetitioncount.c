/*
 * Count the repetitions of a string i.e (aabccde) => a2b1c2d1e1  
 * (if the new string is larger than prev ret prev)
 */

#include <stdio.h>
#include <string.h>

void count(char str[]){
    int count = 1, i;
    int len = strlen(str);
    char buf[len];
    strcpy(buf,"");
    
    for(i = 0; i + 1 < len; i++){
        if(str[i] == str[i + 1]){
            count++;
        }else{
            char tempbuf[9];
            sprintf(tempbuf,"%c%d",str[i],count);
            strcat(buf,tempbuf);
            count = 1;
        }
    }
    
    if(strlen(buf) > strlen(str)) return;
    
    for(i = 0; i < len; i++){
        str[i] = buf[i];
    }
    
}

int main(){

    char str[] = "aaabbbcdef";
    count(str);
    
    printf("%s\n",str);
}
