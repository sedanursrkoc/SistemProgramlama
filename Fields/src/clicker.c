#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char s[51];
  int i;

  for (i = 0; i < 50; i++) s[i] = '0' + i % 10;
  s[i] = '\0';

  printf("%s\n", s+45);            /* First line. */

  for (i = 0; i < 50; i += 9) s[i] = '\0';
  for (i = 0; i < 50; i += 11) printf("%d-%s\n", i, s+i);  /* Lines two through six */

  strcat(s+10, s+40);
  printf("%s\n", s+15);      /* Last line */
  
  return 0;
}
