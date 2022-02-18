#include<stdio.h>
#include<stdlib.h>

int main(void){
  int c;
  /* use system call to make terminal send all keystrokes directly to stdin */
  system ("/bin/stty raw");
  while((c=getchar())!= '.') {
    /* type a period to break out of the loop, since CTRL-D won't work raw */
    putchar(c);
  }
  /* use system call to set terminal behaviour to more normal behaviour */
  system ("/bin/stty cooked");
  return 0;
}
