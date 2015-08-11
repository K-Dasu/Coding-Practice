//Reverse a null terminated string in C
//swap first ele with last ele
// {a,b,c,\0} = {c,b,a,\0}
// i = 0 && j = 2
// i = 1 && j = 1
// Issue with string0[]  = "abcd" VS string0[5] = {"a,b,c,d,\0"};

#include <stdio.h>
#include <string.h>

typedef int bool;
#define true 1
#define false 0


//Expected input are string created like char str[] = "hello world";
void reverseString(char string[]){
    int stringLen = strlen(string);
    if(stringLen <= 1) return;
    
    int j = stringLen - 1; //shift to 0 based
    int i  = 0; int loops = stringLen / 2;
    
    while( loops > 0){
        char temp = string[j];
        string[j] = string[i];
        string[i] = temp;
        i++; j--;
        loops--;
        //printf("during %s\n",string);
    }
}

//Expected input are string created like char str[12] = {'h','e','l','l','o',' ','w','o','r','l','d','\0'};
void reverseNullTerminated(char string[]){
    int stringLen = strlen(string);
    printf("string length %d\n", stringLen);
    if(stringLen <= 1) return;
    
    int j = stringLen - 2; //ignore the null character and shift to 0 based
    int i  = 0; int loops = stringLen / 2;
    
    while( loops >= 0){
        char temp = string[j];
        string[j] = string[i];
        string[i] = temp;
        i++; j--;
        loops--;
        //printf("during %s\n",string);
    }
}

void test(char * string){
    printf("Before %s\n",string);
    reverseString(string);
    printf("After %s\n",string);
}


int main(){
    
    char string0[] = "hello world";
    char nullstr[12] = {'h','e','l','l','o',' ','w','o','r','l','d','\0'};
    char string1[] = "abcd";

    test(string0);
    printf("\n");
    test(nullstr);
}
