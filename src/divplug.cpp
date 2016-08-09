#include "common.h"
#include <stdio.h>

void add(int top, popfunc pop, pushfunc push);

void main()
{
  FILE*f=fopen("div", "wb");

  char*c=(char*)add;

  for(int i=0; i<2000; i++)
    putc(c[i], f);

  fclose(f);
}

void add(int top, popfunc pop, pushfunc push)
{
  if(top>1)
    {
      double i1=pop();
      if(i1!=0)
	push(pop()/i1);
      else
	push(0);
    }
}
