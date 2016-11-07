#include <stdio.h>

int main(){

int Array[8] = {-1,0,1,2,3,4,5,6};
unsigned short *data2 = (unsigned short*)Array; // CAST 4 -> 2

char String[8] = {-1,0,1,2,3,4,5,6};
short *data = (short*)String; // CAST 1 -> 2


    printf("«¬ºA        ¤j¤p¡]bytes¡^\n");
    printf("char             %d\n", sizeof(char));// 1    
    printf("short            %d\n", sizeof(short));// 2
    printf("int              %d\n", sizeof(int));// 4
    printf("long             %d\n", sizeof(long));// 4 or 8
    printf("float            %d\n", sizeof(float));// 4
    printf("double           %d\n", sizeof(double));//8
    printf("long double      %d\n", sizeof(long double));//12 or 16
    printf("unsigned short   %d\n", sizeof(unsigned short));// 2
    printf("unsigned int     %d\n", sizeof(unsigned int));// 4
    printf("=====================================\n");
    printf("String           %d\n", sizeof(String));// 8 size of array
    printf("String[12]       %d\n", sizeof(String[12]));// 1, size of element (char)
    printf("&String[0]       %d\n", sizeof(&String[0]));// 4, size of ptr
    printf("String[0]        %d\n", String[0]);// -1
    printf("String[8]        %d\n", String[8]);// 0 //unknown addr   
    printf("=======================\n");    
    printf("data             %d\n", sizeof(data));// 4, size of ptr
    printf("*data            %d\n", sizeof(*data));// 2, size of element1  (short)  
    printf("data[0]          %d\n", data[0]);// 255   0000 0000 1111 1111 (00FF) 
    printf("data[1]          %d\n", data[1]);// 513   0000 0010 0000 0001 (0201)
    printf("data[2]          %d\n", data[2]);// 1027 0000 0100 0000 0011 (0403)
    printf("data[4]          %d\n", data[4]);// unknown addr  
    printf("data[7]          %d\n", data[7]);// unknown addr     
    printf("*(data+1)          %d\n", *(data+1));// 513         
    printf("=====================================\n");    
    printf("Array            %d\n", sizeof(Array));// 32=4*8, size of array
    printf("*Array           %d\n", sizeof(*Array));// 4, size of element1 (int)
    printf("Array[7]         %d\n", Array[7]);// 6    
    printf("=======================\n");    
    printf("data2[0]          %d\n", data2[0]);// 65535
    printf("data2[1]          %d\n", data2[1]);// 65535  
    printf("data2[2]          %d\n", data2[2]);// 0
    printf("data2[3]          %d\n", data2[3]);// 0     
    printf("data2[4]          %d\n", data2[4]);// 1
    printf("data2[5]          %d\n", data2[5]);// 0
    printf("data2[5]          %d\n", data2[6]);// 2     
    printf("*(data2+9)          %d\n", *(data2+9));// 0   

    *data = 0x1234;
    printf("String[0]        %d\n", String[0]);// 0X34 = 52 
    printf("String[1]        %d\n", String[1]);// 0X12 = 18



}
