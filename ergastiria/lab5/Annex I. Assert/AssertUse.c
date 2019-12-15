#include <assert.h>
#include <stdio.h>

/* demonstrate functionality of assert */

int main()
{
   int a;
	 
   printf("Enter an integer value:");
   scanf("%d", &a);

   assert(a >= 10);
   printf("Integer entered is %d\n", a);
	
   return(0);
}
