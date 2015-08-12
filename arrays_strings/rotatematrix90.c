//given and N X N matrix rotate 90

#include <stdio.h>
#include <string.h>



// 1 2 3     1 2
// 4 5 6     3 4
// 7 8 9

// 3 6 9     2 4
// 2 5 8     1 3
// 1 4 7



void rotateMatrix(int myArray[][4], int size){
    
    //current level..
    int layer = 0;
    for(layer = 0; layer < size / 2; layer++){
        int startingPosition = layer;
        int endingPosition = size - 1 - layer; // the shift
        int j = 0;
        for(j = startingPosition; j < endingPosition; j++){
            int offset = j - startingPosition;
            //temp
            int TopLeft = myArray[startingPosition][j];
            
            //A -> B
            //printf("A(%d,%d) ->  B(%d,%d)\n",startingPosition,j,j,endingPosition);
            myArray[startingPosition][j] = myArray[j][endingPosition];
            
            //B -> D
            //printf("B(%d,%d) ->  D(%d,%d)\n",j,endingPosition,endingPosition,endingPosition - offset);
            myArray[j][endingPosition]  = myArray[endingPosition][endingPosition - offset];
            
            //D -> C
           // printf("D(%d,%d) ->  C(%d,%d)\n",endingPosition,endingPosition - offset,endingPosition - offset, startingPosition);
            myArray[endingPosition][endingPosition - offset] = myArray[endingPosition - offset][startingPosition];
            
            //C -> A
            //printf("C(%d,%d) ->  A %d\n", endingPosition - offset, startingPosition, TopLeft);
            myArray[endingPosition - offset][startingPosition] = TopLeft;
        }
    }
    
}


void printMatrix(int myArray[][4], int N){
    int i,j;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            printf("%d ", myArray[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


int main(){

    int myArray[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12} ,{13,14,15,16}};
    printMatrix(myArray,4);
    rotateMatrix(myArray,4);
    printMatrix(myArray,4);
    
}
