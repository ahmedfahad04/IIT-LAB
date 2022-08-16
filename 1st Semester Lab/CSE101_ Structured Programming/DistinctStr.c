/*Thsi programs finds out distict number or Strings using 2D string.*/

#include <stdio.h>

int main()
{
	char ch[10000][20],t[10000][20],a[10000][20];
	int i=0 ,j,count[100000]={0},k=0,b[100],m,n,l=0,x;
	
	printf("Enter paragraph: \n");
	
	//took input until ENTER is pressed
	for(;;)
   {
   	scanf("%s", &ch[i]);
   	if(getchar() == '\n') break;
   	i++;
   	k++;
   }


//Sorting the given strings alphabatically....
	
	for(i=0;i<=k;i++)		
       for(j=0;j<=k-1-i;j++)
           {
        if(strcmp(ch[j],ch[j+1])>0)
        {
            strcpy(t[i],ch[j]);
            strcpy(ch[j],ch[j+1]);
            strcpy(ch[j+1],t[i]);
        }
    }
    
    
    //Finding distinct strings from the paragraph.....
    
    for(i=0;i<k;i=j)
    {
    	for(j=i+1; j<(k+1); j++)
    	{
    		if(strcmp(ch[i],ch[j]) == 0) continue;
    		else
    		{
    			strcpy(a[l],ch[i]);
    			l++;
    			break;
			}
		}
	}
	strcpy(a[l],ch[i]);
	
 /*   DISTINCT members......*/
	
	
	for(i=0;i<=l;i++)
	printf("--%s--\n", a[i]);
	
}
