/*
 * Count the repetitions of a string i.e (aabccde) => a2b1c2d1e1  
 * (if the new string is larger than prev ret prev)
 */

#include <stdio.h>
#include <string.h>

void concatenate(int * pos, char buf[], char str[]){
    int len = strlen(str);
    int i = 0;
    for(i = 0; i < len; i++){
        buf[*pos + i] = str[i];
    }
    *pos += i;
}

void count(char str[]){
    int count = 1, i, pos = 0;
    int len = strlen(str);
    char buf[len];
    
    for(i = 0; i + 1 < len; i++){
        if(str[i] == str[i + 1]){
            count++;
        }else{
            char tempbuf[9];
            sprintf(tempbuf,"%c%d",str[i],count);
            concatenate(&pos,buf,tempbuf);
            count = 1;
        }
    }
    buf[pos] = '\0';
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
