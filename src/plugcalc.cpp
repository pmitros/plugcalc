// Plug-in calculator
// This is a demo of the Piotr Plug-in Module format

#include <stdio.h>
#include <stdlib.h>
#include "common.h"

#define MAXPLUG 100

void push(double f);
double pop();
void handleNum(char*c);
void handleOp(char*c);
void showStack();
void init();
void addplug(char*cn, char*cf, int size);

double stack[STACKSIZE];
int top;

plugin ps[MAXPLUG];
int plugcnt;

void main()
{
  char c[80];

  init();
  while(1)
    {
      scanf("%s", c);
      if((c[0]<='9')&&(c[0]>='0'))
	handleNum(c);
      else
	handleOp(c);
      showStack();
    }
}

void init()
{
  FILE*f=fopen("plugcalc.cfg", "r");
  char cn[80], cf[80];
  int size;

  while(!feof(f))
    {
      if(fscanf(f, "%s %s %i", cn, cf, &size)<3)
	continue;
      addplug(cn, cf, size);
    }

  fclose(f);
}

void addplug(char*cn, char*cf, int size)
{
  printf("Loading plugin %s (size %i) mapped to %s\n", cf, size, cn);

  ps[plugcnt].name=(char*)malloc(sizeof(char)*(strlen(cn)+1));

  strcpy(ps[plugcnt].name, cn);
  ps[plugcnt].plug=(plugfunc)malloc(sizeof(char)*(size+1));

  char *c=(char*)ps[plugcnt].plug;

  FILE*f=fopen(cf, "rb");

  while(!feof(f))
    {
      *c=getc(f);
      c++;
    }

  fclose(f);

  plugcnt++;
}

void handleNum(char*c)
{
  double f=atof(c);
  push(f);
}

void handleOp(char*c)
{
  int i;
  for(i=0; i<plugcnt; i++)
    if(!strcmp(c, ps[i].name))
       {
	 ps[i].plug(top, pop, push);
	 return;
       }
  printf("Undefined operator: %s\n", c);
}

void showStack()
{
  printf("======Stack=====\n");
  for(int i=0; i<top; i++)
    printf("%i: %.4f\n", i, stack[i]);
  printf(">");
}

double pop()
{
  top--;
  return stack[top];
}

void push(double f)
{
  stack[top]=f;
  top++;
}
