#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	int i, n;
   time_t t;
   
   n = 5;
   
   /* Intializes random number generator */
   srand(10);

   /* Print 5 random numbers from 0 to 49 */
   for( i = 0 ; i < n ; i++ ) 
   {
      printf("%d\n", rand() );
   }
	return 0;
}