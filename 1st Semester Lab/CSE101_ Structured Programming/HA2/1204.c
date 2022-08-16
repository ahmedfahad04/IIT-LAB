#include <stdio.h>
#include <string.h>

int main()
{
    char a[10000],b[10000];
    int i,j=0,k,m=0,x[10000],y[10000],l;
    
    gets(a);
    gets(b);

   
    for(i=0; i<strlen(a);i++)
    {
    	
    	for(k=i,l=0;l<strlen(b);l++,k++)
    	{
    		
    		if(a[k] == b[l])
    	   {
    	   	
    			if(l == (strlen(b)-1))
				{
    				x[m] = i+1;
    				y[m] = i+l+1;
    				m++;    			
    	    	}
    		
	     	}
	     	
			else
			{
				break;
			}
			
		}
      
    }
    
   
    printf("a. Number of \"%s\" Occurences: %d\n", b,m);
    
    printf("b. Positions: \n");
    
    for(i=0;i<m;i++)
    
    printf("\t %d. Starts: %d Ends: %d\n", i+1,x[i], y[i]);
}
