#include <stdio.h>
#include <string.h>

int main () {
   char str[] = "http://.www.tutorialspoint.com";
   char ch = 'h';
   const char *ret;

   ret = strchr(str, ch);

   printf("String after |%c| is - |%d|\n", ch, ret-str+1);
   
   return(0);
}