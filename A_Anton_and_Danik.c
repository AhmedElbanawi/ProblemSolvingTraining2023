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
    uint32 n;
    char* arr;
}input_t;

typedef enum{
    ANTON=0,
    DANIK,
    FRIENDSHIP
}winner_t;
void getinput(input_t*input);
void getwinner(input_t*input, winner_t*winner);
sint32 main(void)
{
    input_t input;
    getinput(&input);
    winner_t winner;
    getwinner(&input,&winner);
    switch (winner)
    {
    case ANTON:
        printf("Anton");
        break;
    case DANIK:
        printf("Danik");
        break;
    default:
        printf("Friendship");
        break;
    }

    
    return 0;
}

void getinput(input_t*input)
{
    scanf("%u",&input->n);
    input->arr=(char*)malloc((1+input->n)*sizeof(char));
    scanf("%s",input->arr);
}
void getwinner(input_t*input, winner_t*winner)
{
    uint32 i=0;
    uint32 Acnt=0;
    uint32 Dcnt=0;
    while (input->arr[i]!='\0')
    {
        if('A'==input->arr[i])
        {
            ++Acnt;
        }else
        {
           ++Dcnt;
        }
        ++i;
    }
    if(Acnt>Dcnt)
    {
        *winner = ANTON;
    }
    else if (Dcnt>Acnt)
    {
        *winner = DANIK;
    }
    else
    {
        *winner = FRIENDSHIP;
    }
    
}