#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUM_HW 6
#define NUM_EXAM 2
#define NUM_ENROLL 5


double hwAvgT ;
double examAvgT;

typedef struct {
	char name[30];
	int hw [NUM_HW];
	int exam [NUM_EXAM];
	double hwAvg;
	double examAvg;
} STUDENT;

int main(int argc, char *argv[])
{
	int stuNum;

	FILE *fp = fopen(argv[1], "r");
	FILE *fo = fopen(argv[2], "w");

	fscanf(fp, "%d", &stuNum);

	STUDENT *s = (STUDENT*)malloc(sizeof(STUDENT) *stuNum);

	for(int k=0; k<stuNum; k++)
		{
			fscanf(fp,"%s", s[k].name);

			s[k].hwAvg = 0;
			s[k].examAvg = 0;

			for(int i=0; i<NUM_HW; i++) {
				fscanf(fp,"%d", &s[k].hw[i]);
				s[k].hwAvg += s[k].hw[i];
			}
			s[k].hwAvg /= NUM_HW;
			hwAvgT += s[k].hwAvg;


			for(int i=0; i<NUM_EXAM; i++) {
				fscanf(fp,"%d", &s[k].exam[i]);
				s[k].examAvg += s[k].exam[i];
			}
			s[k].examAvg /= NUM_EXAM;
			examAvgT += s[k].examAvg;

		}

	
	for(int i=0; i<stuNum; i++) {
		fprintf(fo,"%s\n", s[i].name);
		fprintf(fo,"HwAvg %.2f\n", s[i].hwAvg + 0.005 );
		fprintf(fo,"ExamAvg %.2f\n", s[i].examAvg + 0.005);
	}

	fprintf(fo,"Course\n");
	fprintf(fo,"HwAvg %.2f\n", hwAvgT / stuNum + 0.005);
	fprintf(fo,"ExamAvg %.2f\n", examAvgT / stuNum + 0.005);

	free(s);

}