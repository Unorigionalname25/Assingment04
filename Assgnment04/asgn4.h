#ifndef __asgn4__
#define __asgn4__
/* the two lines above check to ensure
we haven't already included this header*/

/* any needed include statements can go here */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>         /* for malloc() */
#include <stdio.h> 


/* some helper define statements */
#define NUMBER_OF_BITS 16          /* since we're using 16 bit binary numbers */
#define NUMBER_OF_HEX_DIGITS 4     /* 16 bit numbers are 2 bytes, or 4 hex digits */


/* helper function, prints a 16 bit binary number in a reasonably nice format
Takes an integer array, where each element represents one binary bit
Returns nothing, but as a side-effect it prints the number
*/
void printMyBinaryNum(int *myNumArray){
    /* loop through the number, one element (bit) at a time */
    for(int i = 0; i < NUMBER_OF_BITS; i++){
        /* lets print a space before every 4th digit (except the first, i==0), for readability */
        if(i % 4 == 0 && i != 0) {
            /* retrieve this element and print it */            
            printf(" %d", *(myNumArray + i));
        } else {          
            /* else, this is not a 4th digit, just print it with no space */ 
            printf("%d", *(myNumArray + i));
        }
    }  // end for-i loop
    printf("\n");      /* and a newline when we're done, because it's kind to the reader */
}  // end printMyBinaryNum()



/* helper function, prints a 4 bit hex number 
Takes an integer array, where each element represents one hex digit
Returns nothing, but as a side-effect it prints the number
*/
void printMyHexNum(int *myNumArray){
    /* start by printing a sign to inform the reader that what follows is a hex number */
    printf("0x");
    /* loop through the number, one element (digit) at a time */
    for(int i = 0; i < NUMBER_OF_HEX_DIGITS; i++){
        /* print it out, %X is the conversion specifier for hex, in captital letters */
        printf("%X", *(myNumArray + i));
    }
    printf("\n");       /* and a newline when we're done, again because it's kind
    to poor TAs who have to look at thousands of lines of code, and too many
    output lines to count
    // end soap-box
    */
}  // end printMyHexNum()



/* Helper function to reverse an array 
Takes two arguments:
    an int size:  the size of the array, or number of elements
    an int pointer: the array
Returns a int pointer to the reverse array
Note: the return array is malloc'd and it is expected the user will free() the memory
    when no longer required
*/
int* reverseMyArrayPlease(int size, int *myArray){
    /* allocate memory, one int for each element, size*4 bytes */
    int *reversedArray = (int *)malloc( size * sizeof(int));
    /* loop through the array, extract one element, place it in the new array */  
    for(int i = 0; i < size; i++){
        /* -1 since the end of the array is at (size-1),
         -i since we want to reverse the array */
        *(reversedArray + (size - 1) - i) = *(myArray + i);
    }
    return reversedArray;
}  // end reverseMyArrayPlease()




/* ========================================================================= */
/* ~~~~~~~~~~~~~~~~~~~~~ your functions go here ~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/* Note: main() goes in the asgn4.c file                                     */


/*Function convertDecToBin:
Description: converts a decimal number into a Array containing the representation of that number
in binary
Parameters: takes a single argument called Num 
returns: Array containing the binary representation of a number*/
int* convertDecToBin(int Num) {
    /*allocate memory for the array such that each memory location is the size of int*/
    int* arr = (int*)malloc(NUMBER_OF_BITS * sizeof(int)); 
    /*placeholder variable that holds the value of the number after modular division*/
    int n = Num;
    /*if statment checks to see if the bit is 0 or 1, if its non-zero then the for loop runs*/
    if (n != 0) {
        /*for loop uses modular divion to get the remainder of the divion and adds the remainder value
        to the arry then changes n to the new value. The loop runs until n==0 or every array location is
        filled*/
        for (int i = 0; i < NUMBER_OF_BITS; i++) {
            int bit = n % 2;
            /*accessing the array location and storing the bit value (1 or 0) inside it*/
            *(arr + i) = bit;
            n = n / 2;
        }
    }
    /*reverses the array so it is represented in big endian format*/
    int* reversedArray = reverseMyArrayPlease(NUMBER_OF_BITS,arr);
    /*prints the array*/
    printMyBinaryNum(reversedArray);
    free(reversedArray);
    free(arr);   
    return arr;

}
/*Function: convertBinToDec 
Description: Converts a binary representation of a number into decimal format
parameters: Takes a single argument which is a derefrenced array
returns: the decimal value of the binary value that was inputed*/
int convertBinToDec(int *Array){
    /*reverses the array so we can access the elements in order*/
    int* reversedArray = reverseMyArrayPlease(NUMBER_OF_BITS,Array);
    /*represents the final number*/
    int number = 0;  
    /*loops through the array that was inputed and adds the value of each bit (2^i) to number*/
    for(int i = 0; i < NUMBER_OF_BITS;i++){
        /*stores the values used with pow() as doubles */
        double  x = 2, y = i;

        if (*(reversedArray+i)==1){
            /*pow returns the value of x raised to the power of y
            Cite: https://www.geeksforgeeks.org/power-function-c-cpp/  */
            int total = pow(x,y);
            number = number + total;

        }
    }
    printf("%d\n", number);
    return number;
}

/*Function: convertDecToHex
Description: Converts a binary number into an array of values that is the hex representation of
that number
Parameters: a number that is to be converted into a hex value
returns: an int pointer to the arr*/
int* convertDecToHex(int Num) {
    /*allocate memory to the heap*/
    int* arr = (int*)malloc(NUMBER_OF_HEX_DIGITS * sizeof(int));
    /*Stores the value of num after being divided by 16 to move down to the next "bit level"*/
    int n = Num;
    /*Gate to run the for loop if n is not zero*/
    if (n != 0) {
        /*uses modular divion to get the remainder of each value and adds it to the arry*/
        for (int i = 0; i < NUMBER_OF_HEX_DIGITS; i++) {
            int bit = n % 16;
            *(arr + i) = bit;
            n = n / 16;
        }
    }
    /*reverses the array so the format is big endian. with the most signifigant digit first*/
    int* reversedArray = reverseMyArrayPlease(NUMBER_OF_HEX_DIGITS,arr);

    printMyHexNum(reversedArray);
    /*free the space on the heap*/
    free(reversedArray);
    free(arr);
    return arr;

}
/*Function: convertHexToDec 
Description: Converts a hex representation of a number into decimal format
parameters: Takes a single argument which is a derefrenced array
returns: the decimal value of the Hex value that was inputed*/
int convertHexToDec(int *Array){
    /*reverses the array so the elements can be accessed in the proper order*/
    int* reversedArray = reverseMyArrayPlease(NUMBER_OF_HEX_DIGITS,Array);
    /*is used to store the number as more values are added to it*/
    int number = 0;  
    /*iterates through the array and multiplies the value of 16^i where "i" is the 
    level of signifigance to the value in the array. It then adds that value to number until it has
    iterated through the entire list. */
    for(int i = 0; i < NUMBER_OF_HEX_DIGITS;i++){
         /*stores the values used with pow() as doubles */
        double  x = 16, y = i;
        if (*(reversedArray+i)!=0){
            /*pow returns the value of x raised to the power of y
            Cite: https://www.geeksforgeeks.org/power-function-c-cpp/  
            I used this function to multiply 16^i to the value that in that array location*/
            int total = (pow(x,y))*(*(reversedArray+i));
            number = number + total;

        }
    }
    printf("%d\n", number);
    free(reversedArray);
    return number;
}



#endif