#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char ch[10050][50],t[10050][50];
	int i=0 ,j,l,m=0,k;
;
	
	printf("Enter strings: ");
	

	 for(;;)
   {
   	scanf("%s", &ch[i]);
   	if(getchar() == '\n') break;
   	i++;
   	k++;
   }
   

   
   
   for(j=k;j>0;j--)
   {
   		for(i=0;i<=(j-1);i++)
   		{
   			if(strcmp(ch[i],ch[i+1])>0)
   			{
   				strcpy(t[0],ch[i]);
   				strcpy(ch[i],ch[i+1]);
   				strcpy(ch[i+1],t[0]);
			}
   			
		}
   }
  
   
   
   
   printf("..........Mission begins........\n");
   
   for(i=0;i<=k;i=j)
   {
   		for(j=i+1; ch[i][j] == ch[j][0]; j++)
   		{
   			if(( (strlen(ch[i]) == strlen(ch[j])) || (strlen(ch[i]) > strlen(ch[j])) )&& (strcmp(ch[i],ch[j]) == 0)) continue;
   			
			else if((strlen(ch[i]) < strlen(ch[j])))
   			{
   				l = strlen(ch[j]);
   				if( ch[j][l-1] == 's' && ch[j][l-2] == 'e') 
   				{
   						ch[j][l-1] == '\0';
   						ch[j][l-2] == '\0';
				}
			}
		}
		if(strcmp(ch[i],ch[j])==0) strcpy(ch[j],ch[i]);
		else continue;
   }
   
   for(i=0;i<=k;i++)
	{
		printf(" %s\n", ch[i]);
	}
   
   
   
   
   
   
   
   
   
/*   
   	for(i=0;i<=k;i++)
	{
		for(j=0; ch[i][j] != '\0'; j++)
		{
			if(ch[i][j] >= 65 && ch[i][j] <= 90) ch[i][j] = ch[i][j] + 32; 			
		}
	}

	
	
	printf("%s", ch[0]);
	for(i=1;i<=k;i++)
	{
		printf(" %s", ch[i]);
	}
	
*/		
	
	
	
	
}
	
