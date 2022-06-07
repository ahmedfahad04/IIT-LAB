#include <stdio.h>
#include <string.h>


int main()
{
    // Here we declare huge index in order to hold much words.
    char ch[30000][40],w[30000]={},
	v[40][44]={"am", "is", "are", "was", "were", "been", "being", "have", "has", "had", "will", "would", "shall", "should", "may", "might", "must", "need",
	"can", "could", "be","do","does","did","ought", "used"},
	pro[30][30] = {"I", "We", "He", "She", "They", "It", "You", "One", "Who", "How", "When", "Where", "Which", "I", "we", "he", "she", "they", "it"},
	n[100][100]={};
  
   unsigned int i=0,j,k=0,l=0,s=0,p=0,q=0,count=0,x=0,r=0,c=0,z=0;

    
    for(;;)
    {
        scanf("%s", &ch[i]);
        if(getchar() == '\n')
        {
        	break;
		}
		else{
		count++;
        i++;	
		}
        
    }
    
   
   

	
	
	printf("\ni) Noun & Pronoun: \n");	//This part sort out the nouns of sentences which is used before "auxiliary" verbs only. Others complex cases are not appllicable.
	for(i=0;i<count;i++)
    {
    	for(j=0;j<50;j++)
    	{
    		if((strcmp(ch[i],v[j])==0))
    		{
    			
    			strcpy(n[l],ch[i-1]);
    			l++;
    			
    			if((strcmp(ch[i-1],"I")==0) || (strcmp(ch[i-1],"He")==0) || (strcmp(ch[i-1],"She")==0) || (strcmp(ch[i-1],"We")==0) || (strcmp(ch[i-1],"You")==0) ||
    			(strcmp(ch[i-1],"They")==0) || (strcmp(ch[i-1],"It")==0) ) 
				{
    				strcpy(n[l-1],ch[i-1]);
    				l++;
				}
			
			}				
		}
	}
	
	for(i=0;i<=l;i++)		 
	printf("%s\n", n[i]);
	
}
	
