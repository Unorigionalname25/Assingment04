#include "asgn4.h"

int main() {
    int arry0[16] ={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int arry1[16] = {0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1};
    int arry2[16] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    int arry6[16] = {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0};

    int Num1 =0;
    int Num2=255;
    int Num = 65535;
    int Num3 = 4256;
    int Num4 = 23197;
    int arry3[4] = {0x0,0x0,0x0,0x0};
    int arry4[4] = {0x0,0x0,0xF,0xF};
    int arry5[4] = {0xF,0xF,0xF,0xF};
    int arry7[4] = {12,10,9,8};
    
    convertDecToBin(Num1);
    convertDecToBin(Num2);
    convertDecToBin(Num);
    convertDecToBin(Num3);
    convertDecToBin(Num4);


    convertBinToDec(arry0);    
    convertBinToDec(arry1);
    convertBinToDec(arry2);
    convertBinToDec(arry6);


    convertDecToHex(Num1);
    convertDecToHex(Num2);
    convertDecToHex(Num);
    convertDecToHex(Num3);
    convertDecToHex(Num4);


    convertHexToDec(arry3);
    convertHexToDec(arry4);
    convertHexToDec(arry5);
    convertHexToDec(arry7);




    

    return 0;
}





