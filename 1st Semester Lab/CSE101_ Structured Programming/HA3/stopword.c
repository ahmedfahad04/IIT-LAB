#include <stdio.h>
#include <string.h>

int main()
{
	char ch[10050][50];
	int i=0 ,j,l=0,m=0,k;
;
	
	printf("Enter strings: ");
	

	 for(;;)
   {
   	scanf("%s", &ch[i]);
   	if(getchar() == '\n') break;
   	i++;
   	k++;
   }
   
   
   /*For instance: Corona and Corona. are both same word but full stop(.) or other punctuations clings to such words make it different form other. To
   avoid this mistake we turn those pucntuations into null character so that compiler understand the end of the word and it will help to indentifying 
   similar words*/
   
   for(i=0;i<=k;i++)
	{
		for(j=0; ch[i][j] != '\0'; j++)
		{
			if((ch[i][j] == '.') || (ch[i][j] == '!') || (ch[i][j] == '?') || (ch[i][j] == ',') || (ch[i][j] == ':')|| (ch[i][j] == ';')|| (ch[i][j] == '-')
			|| (ch[i][j] == '_') || (ch[i][j] == '\'')|| (ch[i][j] == '(')|| (ch[i][j] == ')')|| (ch[i][j] == '{')|| (ch[i][j] == '}')
			|| (ch[i][j] == '[]')|| (ch[i][j] == ']')) 
			
			ch[i][j] = '\0';
		}
	}
  
	for(i=0;i<=k;i++)
	{
		if((strcmp(ch[i],"the") == 0) || (strcmp(ch[i],"a") == 0) ||(strcmp(ch[i],"an") == 0) ||(strcmp(ch[i],"to") == 0)||(strcmp(ch[i],"at") == 0)
		||(strcmp(ch[i],"on") == 0)||(strcmp(ch[i],"in") == 0)||(strcmp(ch[i],"of") == 0)||(strcmp(ch[i],"for") == 0)||(strcmp(ch[i],"over") == 0)
		||(strcmp(ch[i],"by") == 0)||(strcmp(ch[i],"but") == 0)||(strcmp(ch[i],"and") == 0)||(strcmp(ch[i],"or") == 0)||(strcmp(ch[i],"so") == 0)
		||(strcmp(ch[i],"as") == 0)||(strcmp(ch[i],"with") == 0)||(strcmp(ch[i],"up") == 0)||(strcmp(ch[i],"into") == 0)||(strcmp(ch[i],"without") == 0)
		||(strcmp(ch[i],"am") == 0)||(strcmp(ch[i],"is") == 0)||(strcmp(ch[i],"are") == 0)||(strcmp(ch[i],"were") == 0)||(strcmp(ch[i],"be") == 0)
		||(strcmp(ch[i],"been") == 0)||(strcmp(ch[i],"being") == 0)||(strcmp(ch[i],"has") == 0)||(strcmp(ch[i],"have") == 0)||(strcmp(ch[i],"had") == 0)
		||(strcmp(ch[i],"both") == 0)||(strcmp(ch[i],"however") == 0) ||(strcmp(ch[i],"from") == 0))
		{
			strcpy(ch[i],"");
			m=i;
			for(j=m;j<=k;j++)
			{
				strcpy(ch[j],ch[j+1]);
			}
		}
	}

	
	printf("%s", ch[0]);
	for(i=1;i<=k;i++)
	{
		printf(" %s", ch[i]);
	}
	
}
	
