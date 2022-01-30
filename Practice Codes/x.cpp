#include<stdio.h>
int main()
{
    int n,row=0,col=0,i=0,cnt=0,prev;
    const char dfa[3][2] = {{'A','B'},{'A','C'},{'A','C'}};
    char str[100];
    scanf("%s",str);

    while(str[i]!='\0')
    {
        if(str[i]=='0')
        {
            prev = 0;
            stateA:
            printf("A->");
            i++;
        }

        else if(str[i]=='1' && cnt<1)
        {
            cnt++;
            stateB:
            printf("B->");
            i++;
        }
        if(str[i]=='0') goto stateA;
        if(str[i]=='1' && cnt>=1)
        {
stateC:
            printf("C->");
            i++;
        }
    }

}

// B->C->C->A->A->C->C->C->
// B *C *C A A B *C *C
