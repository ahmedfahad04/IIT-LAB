/*This calculator claculates the GPA, number of students using Array*/

#include <stdio.h>

float gpa(float x);
int mark(void);

int main()
{

    int s,t,u,v,w,x,p,a[50],b[50],c[50],d[50],e[50],f[50],marks,st,tk,y;
    float cgpa;
        printf("Enter total number of students: ");
        scanf("%d", &st);

            for(y = 0; y < st; y++)
{

printf("\tCSE-101: \n");
   s = mark();
   a[y] = s;

printf("\tCSE-102: \n");
   t = mark();
   b[y] = t;

printf("\tMath-101: \n");
   u = mark();
   c[y] = u;

printf("\tMath-102: \n");
   v = mark();
   d[y] = v;

printf("\tSociology: \n");
   w = mark();
   e[y] = w;	

printf("\tSE-101: \n");
   x = mark();
   f[y] = x;

printf("If you wanna input value then press 1\n If you wanna see the results press 0\n");
scanf("%d", &p);
if(p == 1) continue;
else break;
       
}        
        
        
 for(y = 0; y < st; y++){        
        

printf("total Marks in CSE-101:  %d and GPA: %.2f\n", a[y], gpa(a[y]));
printf("total Marks in CSE-102:  %d and GPA: %.2f\n", b[y], gpa(b[y]));
printf("total Marks in Math-101: %d and GPA: %.2f\n", c[y], gpa(c[y]));
printf("total Marks in Math-102: %d and GPA: %.2f\n", d[y], gpa(d[y]));
printf("total Marks in Socilogy: %d and GPA: %.2f\n", e[y], gpa(e[y]));
printf("total Marks in SE-101:   %d and GPA: %.2f\n", f[y], gpa(f[y]));

        marks=(a[y]+b[y]+c[y]+d[y]+e[y]+f[y])/6;
        cgpa =(( gpa(a[y])+gpa(b[y])+gpa(c[y])+gpa(d[y])+gpa(e[y])+gpa(f[y]))/6);

        printf("Average marks is: %d\n", marks);
        
        

  

        if(s >= 33 && t >= 33 && u >= 33 && v >= 33 && w >= 33 && x >= 33 )
           {

           
            if( marks >= 80) {
                printf("Total GPA is: %f\n", cgpa);
                printf("Grade: A+\n");}
            else if( marks >= 75 && marks <80){
                printf("Total GPA is: %f\n", cgpa);
             printf("Grade: A\n\n");}
            else if( marks < 75 && marks >= 70){
                printf("Total GPA is: %f\n", cgpa);
             printf("Grade: A-\n\n");}
            else if( marks >= 65 && marks < 70){
                printf("Total GPA is: %f\n", cgpa);
             printf("Grade: B+\n\n");}
	    else if( marks >= 60 && marks < 65){
                printf("Total GPA is: %f\n", cgpa);
             printf("Grade: B\n\n");}
            else if( marks >= 55 && marks < 60){
                printf("Total GPA is: %f\n", cgpa);
             printf("Grade: B+\n\n");}
            else if( marks >= 50 && marks < 55){
		printf("Total GPA is: %f\n", cgpa);
              printf("Grade: C+\n\n");}
            else if( marks >= 45 && marks < 50){
		printf("Total GPA is: %f\n", cgpa);
              printf("Grade: C\n\n");}
            else if( marks >= 40 && marks < 45){
                printf("Total GPA is: %f\n", cgpa);
             printf("Grade: D\n\n");}


}

        else {
            printf("You have failed\nGPA=0\n");
}


  
}

}



float gpa(float x)
{
   if( x >= 80) return 4.00;
else if( x >= 75 && x < 80) return 3.75;
else if( x >= 70 && x < 75) return 3.50;
else if( x >= 65 && x < 70) return 3.25;
else if( x >= 60 && x < 65) return 3.00;
else if( x >= 55 && x < 60) return 2.75;
else if( x >= 50 && x < 55) return 2.50;
else if( x >= 45 && x < 50) return 2.25;
else if( x >= 40 && x < 45) return 2.00;

else printf("0.00");
}


int mark(void)
{

int x,y,z,k;

	
    printf("Continues Evaluation: ");
    scanf("%d", &x);

	while(x>34)
{
	printf("Enter wrong, So enter again: ");
		scanf("%d", &x);
		if(x>34) continue;
else break;
}
	
    printf("Lab: "); scanf("%d", &y);
while(y>34)
{
	printf("Enter wrong, So enter again: ");
		scanf("%d", &y);
		if(y>34) continue;
else break;
}
    printf("Final: ");
scanf("%d", &z);
while(z>34)
{
	printf("Enter wrong, So enter again: ");
		scanf("%d", &z);
		if(z>34) continue;
else break;
}

k = x+y+z;
return k;

}



