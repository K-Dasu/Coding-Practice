// Keshav Dasu
//given an array of byte values named B and the length of the array
//B[0] report format
//B[1] reserved
//B[2] delta X [7:0]
//B[3] delta Y [7:0]
//B[4] [7:6]{Timestamp bits 1,0}, [5:4]{delta Y bits 9,8}, [3:2]{delta X bits 9,8 }, [1:0]{left/right button states} 
//B[5] Timestamp [9:2]
//B[6] Timestamp [17:10]

//(Q1.) Extract Data
//(Q2.) Detect a Roll Over
    // if previous ts > current ts
    //      c++;
    // timestamp = 2^18(c) +  current


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef unsigned char UInt8;
typedef unsigned short UInt16;
typedef unsigned int UInt32;

UInt16 ROLLOVER = 0;
UInt32 PREVIOUS = 0;

//method that will take in the BIT and return the request bits back (mask out the remainders to be 0)
UInt8 get_bit_range(UInt8 B4, UInt8 H, UInt8 L)
{
	UInt8 mask = 0;
	char counter = H;
	while (counter >= L)
	{
		//create a mask so if wanting to capture bits 1:0 would create a mask of value 3 = 2^1 + 2^0
		mask += (UInt8)pow(2,counter);
		counter = counter - 1;
	}

	mask = mask & B4;
	return mask;
}


UInt16 extract_deltaX(UInt8 bits70, UInt8 B4)
{
	//Extract bits 9:8 from B[4] which are stored at 3:2
	UInt16 bits98 = get_bit_range(B4, 3, 2);
	//shift 3:2 to position 9:8
	bits98 = bits98 << 6;
	//Concatenate bits 98 with 70
	UInt16 Delta_X = bits98 | bits70;
    printf("\tDelta X: %d\n", Delta_X);
	return Delta_X;
}

UInt16 extract_deltaY(UInt8 bits70, UInt8 B4)
{
	//Extract bits 9:8 from B[4] which are stored at 5:4
	UInt16 bits98 = get_bit_range(B4, 5, 4);
	//shift 5:4 to position 9:8
	bits98 = bits98 << 4;
	//Concatenate bits 98 with 70
	UInt16 Delta_Y = bits98 | bits70;
    printf("\tDelta Y: %d\n", Delta_Y);
	return Delta_Y;
}

UInt8 retrieve_button_state(UInt8 B4)
{
	//return bits 1:0  
	UInt8 button_state = get_bit_range(B4, 1, 0);
	UInt8 left_state = get_bit_range(button_state, 1, 1);
	UInt8 right_state = get_bit_range(button_state, 0, 0);
	if (left_state){
		printf("\tLeft button state: high\n");
	}
	else{
		printf("\tLeft button state: low\n");
	}

	if (right_state){
		printf("\tRight button state: high\n");
	}
	else{
		printf("\tRight button state: low\n");
	}

	return button_state;
}

UInt32 retrieve_timestamp(UInt8 B4, UInt8 B5, UInt8 B6)
{
    UInt8 low_bits = get_bit_range(B4,7,6);
    low_bits = low_bits >> 6;
    UInt32 middle_bits = B5 << 2;
    UInt32 high_bits = B6 << 10;
    high_bits = high_bits | middle_bits | low_bits;
    
    //the time stamp value is equal to #rollovers * 2^18 + timestamp from packet
    high_bits = (pow(2,18) * ROLLOVER) + high_bits;
    
    //if the previous time stamp is greater than the current than a rollover has occurred
    if(PREVIOUS > high_bits){
        ROLLOVER++;
        //adjust for roll over
        high_bits = (pow(2,18) * ROLLOVER) + high_bits;
    }
    
    PREVIOUS = high_bits;
    
    
    printf("\tTimestamp: %dms\n", high_bits);
    return high_bits;
}


void handleReport(UInt8 * B, UInt16 length)
{
	if (length < 7 || sizeof(B) < 7){
		printf("Error missing mouse packet information expected byte array of size 7 recieved size of %d.\n", length);
		exit(1);
	}

	//extract mouse deltaX can be contained in a UInt16 since its size 10bits
		extract_deltaX(B[2], B[4]);
		//use delta x to do something here...

	//extract mouse deltaY can be contained in a UInt16 since its size 10bits
		extract_deltaY(B[3], B[4]);
		//use delta y to do something here...

	//retrieve the button state can be contained in a char (working)
		retrieve_button_state(B[4]);
		//use button state to do something here...

	//retrieve timestamp can be contained in a UInt32 since its size 18 bits
		retrieve_timestamp(B[4],B[5],B[6]);
		//use timestamp here...
    printf("---------------------\n");

}

int main(){
	printf("Program Start\n");

	//Test Case for rollover
	UInt8 A[7] = { 10, 121, 132, 158, 213, 53, 200 };
    UInt8 B[7] = { 10, 121, 132, 158, 213, 53, 2 }; //roll over 1
    UInt8 C[7] = { 10, 121, 132, 158, 213, 53, 12 };
    UInt8 D[7] = { 10, 121, 132, 158, 213, 53, 220 };
    UInt8 E[7] = { 10, 121, 132, 158, 213, 53, 12 }; //roll over 2
    
    handleReport(A,7);
    handleReport(B,7);
    handleReport(C,7);
    handleReport(D,7);
    handleReport(E,7);

	printf("Program End\n");

}