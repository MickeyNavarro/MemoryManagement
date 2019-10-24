#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

//Almicke Navarro
//CST-221
//October 20, 2019
//This is my own work.

/*References: https://www.geeksforgeeks.org/g-fact-41-setting-decimal-precision-in-c/
https://stackoverflow.com/questions/499939/extract-decimal-part-from-a-floating-point-number-in-c
https://math.stackexchange.com/questions/144659/an-algorithm-to-convert-float-number-to-binary-representation
https://github.com/tjames222/CST-221/blob/master/Memory%20Management/decimalConversions.txt
https://www.viva64.com/en/k/0019/
https://www.dyclassroom.com/conversion/decimal-to-hexadecimal-conversion-of-a-number-with-fractional-part
https://processing.org/reference/leftshift.html
*/

//Originally, I thought that by decimal, they meant a number like "50.75", however after more research, they didn't mean that. They meant like int values. 

void convertToBinary(int decimal) { 
    //CONVERT TO BINARY
	    //get the decimal number
        unsigned int bi = decimal; 

    	//holds the 32 bit binary number 
    	int binary[32]; 
    	int i = 32; 
    
    	//set the binary number to 0
    	for (int j = 0; j<=32; j++) {
    		binary[j]=0; 
    	}
    	/*
    	//prints binary number as 0 
    	for (int j = 0; j<=32; j++) { // loop used to check output
    		printf("%d", binary[j]); 
    	}
    	*/
    	
    	//converts the intpart into a binary number
    	while (bi != 0) {
    		int r = bi % 2;
    		binary[i] = r;
    		bi = bi / 2;
    		i--;
    	}
    
    	printf("BINARY CONVERSION: ");
    	//prints binary number
    	for (int j = 0; j<=32; j++) {
    		printf("%d", binary[j]);
    	}
    	printf("\n");
    	
    return;
}

void convertToHexadecimal(int decimal){ 
    //CONVERT TO HEXADECIMAL
        //converts the intpart into hexadecimal
        printf("HEXADECIMAL CONVERSION: ");
	    unsigned int hi = decimal; 
        printf("%X",hi);
        printf("\n");
    return; 
}

int main() {
    
    //create variable to hold user input 
    unsigned int decimal; 
    
	START: //define the start of the program
	//output what is needed & get the user input
	printf("Enter an int number 0 to 4095: "); 
	scanf("%d", &decimal); 
	
	//check if the decimal is in the given range
	if (decimal > 0 && decimal < 4095) { 
    	printf("DECIMAL: %d\n", decimal); //check in the input
	}
	else { 
	    printf("You have to enter an int number 0 to 4095.\n");
	    goto START; //sends program to start position to reprompt the user 
	}
	
	convertToBinary(decimal); 
    convertToHexadecimal(decimal); 

    //TRANSFORM INPUT 
        //shift the number 16 bits to the left
        unsigned int shift = decimal << 16; 
        //printf("\nLEFT SHIFT: %d", shift);  //used to check
        
        //mask out (AND) the bottom 16 bits 
        shift &= ~0xFFFF;
        //printf("\nMASK OUT BOTTOM: %d", shift);  //used to check

        //hex number 0x07FF to produce the final resultant number
        shift |= 0x07FF; 
        //printf("\nHEX OUTPUT: %d", shift);  //used to check

        
        //output final resultant
        printf("\nFINAL OUTPUTS: ");
        printf("\nDECIMAL CONVERSION: %d\n", shift); 
        	convertToBinary(shift); 
            convertToHexadecimal(shift); 
            
	return 0;
}


