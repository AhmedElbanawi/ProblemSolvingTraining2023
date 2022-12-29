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
    uint16 n;
    uint16 h;
    uint16* arr;
}input_t;
void getinput(input_t*input);
void getminwidth(input_t*input,uint16*min);
sint32 main(void)
{
    input_t input;
    getinput(&input);
    uint16 min;
    getminwidth(&input,&min);
    printf("%hu",min);

    
    return 0;
}

void getinput(input_t*input)
{
    scanf("%hu%hu",&input->n,&input->h);
    input->arr=(uint16*)malloc(sizeof(uint16)*input->n);
    uint16 i;
    for(i=0; i<input->n; ++i)
    {
        scanf("%hu", &input->arr[i]);
    }
}
void getminwidth(input_t*input,uint16*min)
{
    uint16 i;
    *min = 0;
    for(i=0; i<input->n; ++i)
    {
        if(input->arr[i]>input->h)
        {
            *min +=2;
        }else
        {
            *min +=1;
        }
    }
}