#include <stdio.h>
#include <stdlib.h>

struct test_header {
    unsigned cc:4; //4bit 
    unsigned x:1;
    unsigned p:1;
    unsigned v:2;
    unsigned pt:7;
    unsigned m:1;

}__attribute__((packed)); //4+1+1+2+7+1 =16bits = 2byte

struct test_header2 {
    int ball;
    char shape;
    float length;
}__attribute__((packed));// 4+1+4= 9

struct test_header3 {
    char data[10];//10
    int size; // 4
    short start;// 2
    short count;// 2
}__attribute__((packed)); //10+4+2+2=18 

struct test_header4 {
    char data[10];//10 -> 16/12
    int size; // 4
    short start;// 2
    short count;// 2
}__attribute__((aligned(8)));// 24, [20  defaullt aligned(4)]

int main(){

struct test_header *ptr;
struct test_header2 *ptr2;
ptr2 = (struct test_header2*)malloc(sizeof(struct test_header2));

ptr2->ball = 4;
ptr2->shape = 's';
ptr2->length = 12;

printf("struct test_header             %d\n", sizeof(struct test_header));// 2, size of struct  
printf("*ptr                           %d\n", sizeof(*ptr));// 2  
printf("ptr                            %d\n", sizeof(ptr));// 4, size of ptr   

/* packed */
printf("struct test_header3             %d\n", sizeof(struct test_header3));
/* unpacked */
printf("struct test_header4             %d\n", sizeof(struct test_header4));





/* ptr2 */
printf("struct test_header2             %d\n", sizeof(struct test_header2));// 9, size of struct  
printf("*ptr2                           %d\n", sizeof(*ptr2));// 9  
printf("*(ptr2+1)                       %d\n", sizeof(*(ptr2+1)));// 9  
printf("ptr2                            %d\n", sizeof(ptr2));// 4, size of ptr   
/* element */
printf("ball: %d \n",ptr2->ball);
/* base addr, element offset */
printf("%x \n",ptr2);
printf("ball addr: %x \n",&(ptr2->ball));
printf("shape addr: %x \n",&(ptr2->shape));
printf("length addr: %x \n",&(ptr2->length));
printf("ball: %d  \n",*(&(ptr2->ball)));





}
