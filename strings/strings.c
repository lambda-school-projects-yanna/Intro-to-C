#include <stdio.h>
#include <stdlib.h>


// To compile and run: 

// make
// ./name-of-file

/*
    Given a character array s (as a pointer), return the number of 
    characters in the string.
    
    Do not just use the `strlen` function from the standard libary.
*/
int string_length(char *s)
{
  int count = 0;
  /*  *s is s[0], *(s+1) = s[1], and etc. Pointers refer to some value in memory. Arrays always end in \0. */
  while (*(s + count) != '\0') 
  {
    count ++;
  }
  return count;
}


char *reverse_string(char *rv, char *s)
{
  int count = string_length(s);
  int i = 0;
  while (count >= 0) 
  {
    count--;
    *(rv + i) = *(s + count);
    i++;
  }

  *(rv + i) = '\0';
  return rv;
}


#ifndef TESTING
int main(void)
{
    char quote1[] = "Don't forget to be awesome";
    char quote2[] = "a man a plan a canal panama";

    char rv[512];

    printf("The string 'Don't forget to be awesome' has %d characters.\n", string_length(quote1));
    printf("The string 'a man a plan a canal panama' reversed is: '%s'\n", reverse_string(rv, quote2));

    return 0;
}
#endif
    
