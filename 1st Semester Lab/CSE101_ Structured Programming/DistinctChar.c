/* Distinct Character identification using 1D string. It can be used for both Strings and digits*/

#include <stdio.h>
#include <string.h>
int length();

int main()
{

  printf("Distinct Characters: %d", length());

}

int length()
{
    char a[100],ch[100],temp;
    int i,j,k=0,l,p;

    gets(ch);
    l = strlen(ch);

    for(j=l;j>0;j--)
        for(i = 0;i <(j-1);i++)
    {
        if(ch[i]>ch[i+1])
        {
            temp = ch[i];
            ch[i] = ch[i+1];
            ch[i+1] = temp;
        }

    }


    for(i=0;i<l;i=j)
        for(j=(i+1); j<(l+1); j++)
    {
        if(ch[i] == ch[j])
            continue;
        else{
            a[k] = ch[i];
            k++;
            break;
        }
    }
    a[k] = ch[i];

    p =strlen(a);
   return p;

}
