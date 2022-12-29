#include <stdio.h>
#include <malloc.h>
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef unsigned long long int uint64;

typedef char sint8;
typedef  short sint16;
typedef  int sint32;
typedef  long long int sint64;

typedef float float32;
typedef double float64;

typedef struct{
    char* arr;
}input_t;
void getinput(input_t*input);
void Cnt(input_t*input,uint16*small,uint16*capital);
void tocapital(input_t*input);
void tosmall(input_t*input);
sint32 main(void)
{
    input_t input;
    getinput(&input);
    uint16 small;
    uint16 capital;
    Cnt(&input,&small,&capital);
    if(capital > small)
    {
        tocapital(&input);
    }
    else
    {
        tosmall(&input);
    }
    printf("%s",input.arr);

    
    return 0;
}

void getinput(input_t*input)
{
    input->arr=(char*)malloc(sizeof(char)*101);
    scanf("%s",input->arr);
}
void Cnt(input_t*input,uint16*small,uint16*capital)
{
    uint16 i=0;
    *small=0;
    *capital=0;
    while (input->arr[i]!='\0')
    {
        if(input->arr[i]>='a'&&input->arr[i]<='z')
        {
            ++*small;
        }
        else
        {
            ++*capital;
        }
        ++i;
    }
    
}
void tocapital(input_t*input)
{
    uint16 i=0;
    while (input->arr[i]!='\0')
    {
        if(input->arr[i]>='a'&&input->arr[i]<='z')
        {
            input->arr[i]-=0x20;
        }
        ++i;
    }
    
}
void tosmall(input_t*input)
{
    uint16 i=0;
    while (input->arr[i]!='\0')
    {
        if(input->arr[i]>='A'&&input->arr[i]<='Z')
        {
            input->arr[i]+=0x20;
        }
        ++i;
    }
    
}