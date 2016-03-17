#include <stdio.h>
#include <string.h>

FILE * fo;

void swap(char *a, char *b)
{
	
	char c = *a;
	*a = *b;
	*b = c;
}

void perm(char *list, int i, int n)
{
	int j, temp;
	if (i==n)
	{
		fprintf(fo,"{");
		for (j=0; j<n; j++)
			fprintf(fo,"%c,", list[j]);
		fprintf(fo,"%c", list[n]);
		fprintf(fo,"}");
		fprintf(fo,"\n");
	}

	else {
		for (j=i; j<=n; j++){
			swap(&list[i], &list[j]);
			perm(list, i+1, n);
			swap(&list[i], &list[j]);
		}
	}
}

int main(int argc, char* argv[])
{
	int i, j;
	int index;
	int len;
	char odd[100] = {0,};
	char *input = argv[1];
	char *output = argv[2];

	FILE *fp = fopen(input, "r");

	char tmp[100];
	fgets(tmp, 100, fp);

	printf("%s\n",tmp);

	len = strlen(tmp);

	for(i=0; i<(len/2); i++)
	{
		odd[i] = tmp[i*2+1];
	}

	len = strlen(odd);
	fo = fopen(output, "w");
	perm(odd,0,len - 1);



}