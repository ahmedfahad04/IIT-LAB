/*This program is used to indetify some characteristic of sentences. But all of them are not fully accurate. Here we focused on the general rules only. 
Necessary instruction and restrictions are included as comment with each new sections.*/

#include <stdio.h>
#include <string.h>


int main()
{
    // Here we declare huge index in order to hold much words.
    char ch[30000][40],s2[10][10] ={"A","An","The","the", "a", "an"},w[30000]={},
	v[40][44]={"am", "is", "are", "was", "were", "been", "being", "have", "has", "had", "will", "would", "shall", "should", "may", "might", "must", "need",
	"can", "could", "be","do","does","did","ought", "used"},
	pro[30][30] = {"I", "We", "He", "She", "They", "It", "You", "One", "Who", "How", "When", "Where", "Which", "I", "we", "he", "she", "they", "it"},
	pre[30][30]={"in", "at", "to", "of", "from", "by", "over", "up", "above", "out", "on", "through", "below", "for", "about", "after", "before", "with",
	"behind", "with", "but", "But", "into", "within", "between", "among"},n[100][100]={};
  
   unsigned int i=0,j,k=0,l=0,s=0,p=0,q=0,count=0,x=0,r=0,c=0,z=0;

    
    for(;;)
    {
        scanf("%s", &ch[i]);
        strcat(w,ch[i]);		//In this section we use strcat so that our 2D string can be treated as 1D string in order to count punctuations.
        if(getchar() == '\n')
        {
        	break;
		}
		else{
		count++;
        i++;	
		}
        
    }
    
    for(i=0;w[i] != '\0';i++)		//This loop counts the no of senctences.
    {
    	if(w[i] == '.' || w[i] == '?' || w[i] == '!') k++;
	}
	
	for(i=0;w[i] != '\0';i++)		//This loop counts no. of punctuations.
    {
    	if(w[i] == '.' || w[i] == '!' || w[i] == '?' || w[i] == ',' || w[i] == ';' || w[i] == ':' || w[i] == '_' ||
         w[i] == '-' || w[i] == '[' || w[i] == '\''|| w[i] == '\''  || w[i] == '{'  ||w[i] == '('  ) 
		 x++;
	}
	
	
    printf("\na. No of sentences: %d", k);
    printf("\nb. No of characters: \n");
    printf("\ti) %d with white spaces\n\tii) %d without white spaces", strlen(w)+count,strlen(w));
    printf("\nc. No of words: %d", count+1);
    printf("\nd. No of spaces: %d", count);
    printf("\ne. No of Punctuation: %d", x);
    printf("\n");
   
   
    for(i=0;i<count;i++)		//Here it counts no of articles.
    {
    	for(j=0;j<10;j++)
    	{
    		if(strcmp(ch[i],s2[j])==0)
    		{
    			printf("-->%s\n", ch[i]);
    			p++;
    			break;
			}
		}
	}
    
    printf("f. No of article: %d\n", p);
    
    for(i=0;i<count;i++)		//Here it counts no of "be" verbs.
    {
    	for(j=0;j<15;j++)
    	{
    		if(strcmp(ch[i],v[j])==0)
    		{
    			printf("-->%s\n", ch[i]);
    			q++;
    			break;
			}
		}
	}
	
	printf("g. No of Verbs: %d", q);
	

	printf("\nh. Parts of speech: \n");
	
//Parsts of speech identification begins.....

	
	
	printf("\ni) Noun: ");	//This part sort out the nouns of sentences which is used before "auxiliary" verbs only. Others complex cases are not appllicable.
	for(i=0;i<count;i++)
    {
    	for(j=0;j<50;j++)
    	{
    		if((strcmp(ch[i],v[j])==0))
    		{
    			if((strcmp(ch[i-1],"I")!=0) && (strcmp(ch[i-1],"He")!=0) && (strcmp(ch[i-1],"She")!=0) && (strcmp(ch[i-1],"We")!=0) && (strcmp(ch[i-1],"You")!=0) && 
    			(strcmp(ch[i-1],"They")!=0) && (strcmp(ch[i-1],"It")!=0) && (strcmp(ch[i-1],"My")!=0) ) 
				{
    				strcpy(n[l],ch[i-1]);
    				l++;
				}
			}				
		}
	}
	
	for(i=0;i<=l;i++)		 
	printf(" %s", n[i]);
	

	for(i=0;i<=count;i++)   //Here we sort out those noun which is used before the full stop and also ensure that it is not an adverb. Others complex cases are not appllicable.
    {
    	for(j=0;ch[i][j] != '\0';j++)
    	{
    		if((ch[i][j] == '.' ) && (ch[i][j-2] != 'l' && ch[i][j-1] !='y')) printf(" %s", ch[i]);
    		
		}
	}
	
	
/*	Here we try to sort those noun which is preceded by "Principal" verb only. But it is not included with main
source code as it create repeated same output at the same time. You can check it out to find noun using Principal verb.


for(i=0;i<=count;i++)		
    {
    	for(j=0;ch[i][j] != '\0';j++)
    	{
    		
    		if(ch[i+1][j] == 'e' && ch[i+1][j+1] =='s' && (ch[i+2][0] >= 'a' && ch[i+2][0] <= 'z' ) )
			{
    			printf(" %s", ch[i]);
    			break;
			}
			else if(ch[i+1][j] =='e' && ch[i+1][j+1] =='d' && (ch[i+2][0] >= 'a' && ch[i+2][0] <= 'z' ) ) 
			{
    			printf(" %s", ch[i]);
    			break;
			}
			else if(ch[i+1][j] =='s' && (ch[i+2][0] >= 'a' && ch[i+2][0] <= 'z' ) ) 
			{
    			printf(" %s", ch[i]);
    			break;
			}
			else if(ch[i+1][j] =='e' && ch[i+1][j+1] =='n' && (ch[i+2][0] >= 'a' && ch[i+2][0] <= 'z' ) ) 
			{
    			printf(" %s", ch[i]);
    			break;
			}
			else if(ch[i+1][j] =='i' && ch[i+1][j+1] =='s' && ch[i+1][j+2] == 'e' && (ch[i+2][0] >= 'a' && ch[i+2][0] <= 'z' ) )
			 
			{
    			printf(" %s", ch[i]);
    			break;
			}
			else if(ch[i+1][j] =='i' && ch[i+1][j+1] =='z' && ch[i+1][j+2] =='e' && (ch[i+2][0] >= 'a' && ch[i+2][0] <= 'z' ) )
			 
			{
    			printf(" %s", ch[i]);
    			break;
			}
			else if(ch[i+1][j] =='i' && ch[i+1][j+1] =='f' && ch[i+1][j+2] =='y' && (ch[i+2][0] >= 'a' && ch[i+2][0] <= 'z' ) ) 
			{
    			printf(" %s", ch[i]);
    			break;
			}
			
		}
	}
	
*/		
	printf("\nii) Pronoun:");	//only subjective form of pronoun is used here. Objective and others forms are not applicable.
	for(i=0;i<count;i++)
    {
    	for(j=0;j<20;j++)
		{
			if(strcmp(ch[i],pro[j])==0)
    		{
    			printf(" %s",ch[i]);
    			break;
			}
		}
	}


	printf("\niii) Verb: "); 		//Here we count those Pricipal verbs which is preceded by the "be" and auxiliary verbs only. Others complex cases are not appllicable.
	for(i=0;i<count;i++)
    {
    	for(j=0;j<50;j++)
    	{
    		if((strcmp(ch[i],v[j])==0))
    		{
    			if(strcmp(ch[i+1],"a") == 0) break;
    			else if(strcmp(ch[i+1],"an") == 0) break;
    			else if(strcmp(ch[i+1],"the") == 0) break;
    			else
    			printf(" %s", ch[i+1]);
			}
						
		}
	}	
	
	
/*
	/lthis part also count verb bases on some fixed suffix like 'ed', 'es' etc. Others complex cases are not appllicable.
	Sometimes it creates same output twice or more. So it has been hide out using comment. But you can try to check it out for
	finding the principal verbs.

	for(i=0;i<=count;i++)	
    {
    	for(j=0;ch[i][j] != '\0';j++)
    	{
    		
    		if(ch[i][j] == 'e' && ch[i][j+1] =='s' && (ch[i+1][0] >= 'a' && ch[i+1][0] <= 'z' ) )
			{
    			printf(" %s", ch[i]);
    			break;
			}
			else if(ch[i][j] == 's' && (ch[i+1][0] >= 'a' && ch[i+1][0] <= 'z' ) && strcmp(ch[i-1],"has") != 0  && strcmp(ch[i-1],"had") != 0
			&& strcmp(ch[i-1],"have") != 0)
			{
    			printf(" %s", ch[i]);
    			break;
			}
			else if(ch[i][j] =='e' && ch[i][j+1] =='d' && (ch[i+1][0] >= 'a' && ch[i+1][0] <= 'z' ) && strcmp(ch[i-1],"has") != 0 && strcmp(ch[i-1],"had") != 0 
			&& strcmp(ch[i-1],"have") != 0) 
			{
    			printf(" %s", ch[i]);
    			break;
			}
			else if(ch[i][j] =='e' && ch[i][j+1] =='n' && (ch[i+1][0] >= 'a' && ch[i+1][0] <= 'z' ) && strcmp(ch[i-1],"has") != 0 && strcmp(ch[i-1],"had") != 0
			&& strcmp(ch[i-1],"have") != 0) 
			{
    			printf(" %s", ch[i]);
    			break;
			}
			else if(ch[i][j] =='i' && ch[i][j+1] =='s' && ch[i][j+2] == 'e' && (ch[i+1][0] >= 'a' && ch[i+1][0] <= 'z' ) && strcmp(ch[i-1],"has") != 0 && strcmp(ch[i-1],"had") != 0
			&& strcmp(ch[i-1],"have") != 0)
			 
			{
    			printf(" %s", ch[i]);
    			break;
			}
			else if(ch[i][j] =='i' && ch[i][j+1] =='z' && ch[i][j+2] =='e' && (ch[i+1][0] >= 'a' && ch[i+1][0] <= 'z' ) && strcmp(ch[i-1],"has") != 0 && strcmp(ch[i-1],"had") != 0
			&& strcmp(ch[i-1],"have") != 0)
			 
			{
    			printf(" %s", ch[i]);
    			break;
			}
			else if(ch[i][j] =='i' && ch[i][j+1] =='f' && ch[i][j+2] =='y' && (ch[i+1][0] >= 'a' && ch[i+1][0] <= 'z' ) && strcmp(ch[i-1],"has") != 0 && strcmp(ch[i-1],"had") != 0
			&& strcmp(ch[i-1],"have") != 0) 
			{
    			printf(" %s", ch[i]);
    			break;
			}
			
		}
	}
	
*/	
	printf("\niv) Preposition: "); 		//Here we used some most familier prepostions. 
	for(i=0;i<count;i++)
    {
    	for(j=0;j<15;j++)
    	{
    		if(strcmp(ch[i],pre[j])==0)
    		{
    			printf(" %s", ch[i]);
    			break;
			}
		}
	}
	
	
	
	printf("\nv) Adverb: ");		//Here we count such word which use 'ly' suffix. Other complex cases won't be appllicable.
	for(i=0;i<=count;i++)
    {
    	for(j=0;ch[i][j] != '\0';j++)
    	{
    		if(ch[i][j] == 'l' && ch[i][j+1] =='y') printf(" %s", ch[i]);
    		
		}
	}
	
	
	printf("\nvi) Adjective: ");     	//Here we count the adjective which are only after the articles. Others complex cases won't be appllicable.
	 for(i=0;i<count;i++)
    {
    	for(j=0;j<10;j++)
    	{
    		if((strcmp(ch[i],s2[j])==0)  && (ch[i+2][0] >= 'a' && ch[i+2][0] <= 'z' ))
    		{
    			printf(" %s", ch[i+1]);
    			break;
			}
		}
	}
	
	
	
	
}
