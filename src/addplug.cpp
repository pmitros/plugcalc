#include "common.h"
#include <stdio.h>

void add(int top, popfunc pop, pushfunc push);

void main()
{
  FILE*f=fopen("add", "wb");

  char*c=(char*)add;

  for(int i=0; i<2000; i++)
    putc(c[i], f);

  fclose(f);
}

void add(int top, popfunc pop, pushfunc push)
{
  if(top>1)
    push(pop()+pop());
}
