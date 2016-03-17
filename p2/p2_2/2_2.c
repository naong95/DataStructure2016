#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student{
	char name[30];
	int literature;
	int math;
	int science;
} student;

int main(int argc, char* argv[])
{
	int i=0;
	int stuNum;
	char stuName[30];
	FILE *fp = fopen(argv[1], "r");
	FILE *f = fopen(argv[2], "w");

	fscanf(fp, "%d", &stuNum);
	student * s = (student*)malloc(sizeof(student) * stuNum);

    for(int k=0; k<stuNum; k++)
    	fscanf(fp,"%s %d %d %d\n",s[k].name,&s[k].literature,&s[k].math,&s[k].science);

    for(int k=0; k<stuNum; k++)
    	printf("%s %d %d %d\n",s[k].name,s[k].literature,s[k].math,s[k].science);


    fprintf(f,"Name\t");
    for(int i=0; i<stuNum; i++)
    	fprintf(f,"\t%s\t",s[i].name);

    fprintf(f,"\n");
    fprintf(f,"Literature\t");
    for(int i=0; i<stuNum; i++)
    	fprintf(f,"%d\t",s[i].literature);
    fprintf(f,"\n");
    fprintf(f,"Math\t");
    for(int i=0; i<stuNum; i++)
    	fprintf(f,"\t%d\t",s[i].math);
    fprintf(f,"\n");
    fprintf(f,"Science\t");
    for(int i=0; i<stuNum; i++)
    	fprintf(f,"\t%d\t",s[i].science);



	fclose(fp);    
    fclose(f);
    free(s);
	
	

	
}