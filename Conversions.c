#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

//Originally, I thought that by decimal, they meant a number like "50.75", however after more research, they didn't mean that. 

int main() {
    
    //create variable to hold user input 
    float decimal; 
    
	START: //define the start of the program
	//output what is needed & get the user input
	printf("Enter a decimal number 0 to 4095: "); 
	scanf("%f", &decimal); 
	
	//check if the decimal is in the given range
	if (decimal > 0 && decimal < 4095) { 
    	printf("You have entered: %f\n", decimal); //check in the input
	}
	else { 
	    printf("You have to enter a decimal number 0 to 4095.\n");
	    goto START; //sends program to start position to reprompt the user 
	}
	
	//separate the decimal into its whole number & its decimal value
	int intpart = (int)decimal;
    double decpart = decimal - intpart;
    printf("decimal = %f, intpart = %d, decpart = %f\n", decimal, intpart, decpart);
	
	//CONVERT TO BINARY
	    //get the whole number & decimal part of the user input
        int bi = intpart; 
        double bp = decpart; 
        
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
    	
    	//converts the decpart into its binary number & prints it 
    	if (decpart !=0 ){ 
    	    printf("."); 
        	while(bp != 0) { 
        	    int t = bp*2; 
        	    printf("%d", t); 
        	    bp = (bp*2) - 1; 
        	}
    	}
    	printf("\n");
	
	//CONVERT TO HEXADECIMAL
    	/*
    	***** This code is no longer in use due to finding a simpler solution******
    	//get the whole number & decimal part of the user input
        int hi = intpart; 
        double hp = decpart; 
    	
    	//holds the hexadecimal
    	char hexa[8]; 
    	char h[17] = "0123456789ABCDEF";
    	int k = 8; 
    
    	//set the hexadecimal number to 0
        for (int j = 0; j<=8; j++) {
    		hexa[j]=0; 
        }
    
        //converts the intpart into hexadecimal
    	while (hi != 0) {
    		int a = hi % 16;
    		if (a == 10) { 
    		    hexa[k] = "A";
    		} 
    		else if (a == 11) { 
    		    hexa[k] = "B";
    		}
    		else if (a == 12) { 
    		    hexa[k] = "C";
    		}
    		else if (a == 13) { 
    		    hexa[k] = "D";
    		}
    		else if (a == 14) { 
    		    hexa[k] = "E";
    		}
    		else if (a == 15) { 
    		    hexa[k] = "F";
    		}
    		else { 
    		    hexa[k] = a;
    		}
    		hi = hi /16; 
    		k--; 
    	}
    	printf("HEXADECIMAL CONVERSION: ");
        //prints hexadecimal number
        for (int j = 0; j<=8; j++) {
    		printf("%d", hexa[j]);
        }
        */
        
        //converts the intpart into hexadecimal
        printf("HEXADECIMAL CONVERSION: ");
	    unsigned int hi = intpart; 
        printf("%X.",hi);
        
        //converts the decpart into its binary number & prints it 
        double hp = decpart; 
        while (hp !=0) { 
            hp = hp * 16; 
            
            //separate into its whole number & its decimal
            int ip = (int)hp;
            double dp = hp - ip;
            
            //print the whole number in its hexadecimal format
            printf("%X", ip);

            //set the hp to its new decimal format
            hp = dp; 
            
        }

    //TRANSFORM INPUT 
        //shift the number 16 bits to the left
        //float shift = decimal << 16;   //does not work with float values
        float shift = decimal * (10^16); 
        printf("\nLEFT SHIFT: %f", shift); 
        //mask out (AND) the bottom 16 bits 
        //add (OR) the hex number 0x07FF to produce the final resultant number




	return 0;
}