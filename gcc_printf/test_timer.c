#include <stdio.h>
const int MIN_PER_HOUR = 60;  // minutes per hour

int main(void)
{
 int hour, min, left;

 printf("Convert minutes to hours and minutes!\n");
 printf("Enter the number of minutes (<=0 to Quit):\n");

 scanf("%d", &min);    // read number of minutes

 while(min > 0){
  hour = min / MIN_PER_HOUR; // truncated number of hours
  left = min % MIN_PER_HOUR; // number of minutes left over

  printf("%d minutes is %d hours, %d minutes.\n", min, hour, left);

  printf("Enter next value (<=0 to quit)");
  scanf("%d", &min);
 }
 printf("Done!\n");

 return 0;
}