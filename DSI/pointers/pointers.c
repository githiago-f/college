#include <stdio.h>
int main()
{
  int x, *px;
  x = 1;
  px = &x;
  printf("01. x= %d\n", x);
  printf("02. px= %u\n", px);
  printf("03. *px+1= %d\n", *px + 1);
  printf("04. px= %u\n", px);
  printf("05. *px= %d\n", *px);
  printf("06. *px+=1= %d\n", *px += 1);
  printf("07. px= %u\n", px);
  printf("08. (*px)++= %d\n", (*px)++);
  printf("09. px= %u\n", px);
  printf("10. *(px++)= %d\n", *(px++));
  printf("11. px= %u\n", px);
  printf("12. *px++= %d\n", *px++);
  printf("13. px= %u\n", px);
}