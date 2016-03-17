#include<stdio.h>

int selectcal();
int add(int, int);
int sub(int, int);
int mul(int, int);
int div(int, int);

int selectcal()
{
       int choice;
       while(1)
       {
           printf("=======================\n");
           printf("0. add\n");
           printf("1. sub\n");
           printf("2. mul\n");
           printf("3. div\n");
           printf("4. exit\n");
           printf("=======================\n");
           printf("Select Operation : ");
           scanf("%d", &choice);
           if((choice >= 0) && (choice <=4))
           {
                   return (choice);
           }
           else
           {
                   printf("intput only 0~4 integer\n");
           }
     }
     return 0;
}

int main()
{
       int c;
       int a, b;
       int result;
       int (*pf[4]) (int, int) = {add, sub, mul, div};
       while(1)
       {
                 c = selectcal();
                 if(c == 4)
                 {
                    return 0;
                 }
                 printf("Input 2 operand : ");
                 scanf("%d %d", &a, &b);
                 
                 result = pf[c] (a, b);
                 printf("Result = %d\n", result);
      }
      return 0;
}

int add(int a, int b)
{
	int res;
	res = a + b;
	return res;
}

int sub(int a, int b)
{
	int res;
	res = a - b;
	return res;
}

int mul(int a, int b)
{
	int res;
	res = a * b;
	return res;
}

int div(int a, int b)
{
	int res;
	res = a / b;
	return res;
}