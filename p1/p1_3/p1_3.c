#include <stdio.h>
#include <stdlib.h>
 
int main()
{
     int namelen=30,num,i;
     char **name;
     

     scanf("%d",&num);
     name=(char **)malloc(num*sizeof(char *));
     for (i=0;i<num;i++) {
          name[i]=(char *)malloc(namelen*sizeof(char));
     }
 
     printf("enter %d names:\n",num);

     for (i=0;i<num;i++) {
          scanf("%s",name[i]);
     }
     
     printf("the names you entered:\n");

     for (i=0;i<num;i++) {
          printf("%s\n",name[i]);
     }

 
}
