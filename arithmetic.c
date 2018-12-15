/*----------------------------------------------------------
 *				HTBLA-Leonding / Class: <2AHIF>
 * ---------------------------------------------------------
 * Exercise Number: 4
 * Title:			<Conditional Arithmetic>
 * Author:			<Daniel Andricic>
 * ----------------------------------------------------------
 * Description:
 * < You choose between Add or Multiply and then you choose
 *  a number. You go through every number between 1-chosen number
 * If the number is a multiple of 3 or 5 you add/multiply it
 * with each other.>
 * ----------------------------------------------------------
 */

#include "arithmetic.h"
#include <stdio.h>
#include <float.h>
#include <limits.h>
#include <stdbool.h>

int main(int argc, char const *argv[]) {

  int choice;
  long number,result = 1;
  bool isValid = false;
  do
  {
    printf("Select Add (1) or Multiply (2): ");
    scanf("%d",&choice);

    switch (choice)
    {
      //Add
      case 1:
        isValid = true;
        getnumber(&number);
        for(long i = 1; i <= number; i++)
        {
          if(((i%5) == 0)||((i%3) == 0))
          {
            result = result + i;
          }
        }
        printf("The result is: %ld\n",result - 1);
      break;

      //Multiply
      case 2:
        isValid = true;
        getnumber(&number);
        for(long i = 1; i <= number; i++)
        {
          if(((i%5) == 0)||((i%3) == 0))
          {
            result = result * i;
          }
        }
        if(result == 1)
        {
          result = 0;
        }
        if(checkoverflow(number)==-1)
        {
          printf("The result is: %ld\n", result);
        }
        else
        {
          printf("Overflow!\n");
        }
      break;

      default:
        isValid = false;
      break;
    }
  }while(isValid == false);

  return 0;
}

//Gets the input and checks if it is valid.
void getnumber(long* n)
{
  bool isValid = false;

  while(isValid == false)
  {
    printf("Select a number in the range (1-100): ");
    scanf("%ld", n);
    if(*n > 100 || * n<1)
    {
        isValid = false;
    }
    else
    {
      isValid = true;
    }
  }

}

//Checks if the number is too big.
int checkoverflow(long x)
{
  long y = LONG_MAX;

  for(long i = x; i > 3; i--)
  {
    if(((i%5) == 0)||((i%3) == 0))
    {
        y /= i;
    }
  }

  if(y > 3)
  {
    return -1;
  }

  return 1;
}
