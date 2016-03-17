#include <stdio.h>

void func(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

int main()
{
	int a,b;
	int* apointer = &a;
	int* bpointer = &b;

	printf("enter 2 integers\n");

	scanf("%d",&a);
	scanf("%d",&b);

	printf("you entered\n%d %d \n",a,b);

	func(apointer, bpointer);

	printf("after swapping\n%d %d\n", a, b);
	

	return 0;

}