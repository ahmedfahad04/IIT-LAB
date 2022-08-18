#include <stdio.h>
#define STDMAX 33 //customize student number

float gpa(float x);

struct data {
	int num[10];
	float grade[10];
};

int main() {
	FILE *fp,*file;
	struct data std[50];
	int i,j,roll[50];
	float sum=0;

	fp = fopen("raw_data.txt","r");//open file stream

	if(fp == NULL) printf("File failed to open");
	else {

		fscanf(fp, "%*[^\n]"); //skip first line
		for(j=0; j<STDMAX; j++) { // taking input of roll and respective course marks
			for(i=0; i<7; i++) {
				fscanf(fp,"%d",&std[j].num[i]);
			}
		}

		fclose(fp);
	}

	//calculating distinct and cumulative gpa for all courses
	for(j=0; j<STDMAX; j++) {
		for(i=1; i<7; i++) {
			std[j].grade[i] = gpa(std[j].num[i]);// distinct grade
			sum+=std[j].grade[i];
		}
		std[j].grade[7]=sum/6;// cumulative grade
		sum=0;
	}

	//Storing result in new file
	file = fopen("Result.txt", "w");

	//for program output only
	puts("DATA has been stored in following formate\n");
	puts("Roll	  CSE101 CSE102 STAT103 MATH104 GE105  SE106      CGPA");
	puts("----      ------ ------ ------- ------- -----  -----      -----\n");

	for(j=0; j<STDMAX; j++) {
		printf("%d	 ",std[j].num[0]);
		for(i=1; i<7; i++) {
			if(i>=4&&i<=6) printf("  %0.2f  ",std[j].grade[i]);//decoration purpose only
			else printf(" %0.2f  ",std[j].grade[i]);
		}
		printf("\t  %0.2f\n", std[j].grade[7]);

	}

	//store result in "Result.txt" file
	fputs("Roll	  CSE101 CSE102 STAT103 MATH104 GE105  SE106      CGPA\n",file);
	fputs("----      ------ ------ ------- ------- -----  -----      -----\n\n",file);

	for(j=0; j<STDMAX; j++) {
		fprintf(file,"%d	 ",std[j].num[0]);
		for(i=1; i<7; i++) {
			//fprintf(file," %0.2f  ",std[j].grade[i]);
			if(i>=4&&i<=6) fprintf(file,"  %0.2f  ",std[j].grade[i]);//decoration purpose only
			else fprintf(file," %0.2f  ",std[j].grade[i]);
		}
		fprintf(file,"\t  %0.2f\n", std[j].grade[7]);
	}

	fclose(file);

	return 0;

}

float gpa(float x) {
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
