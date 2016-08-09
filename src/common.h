#define STACKSIZE 1000

typedef double (*popfunc)();
typedef void (*pushfunc)(double);

typedef void (*plugfunc)(int, popfunc, pushfunc);

struct plugin
{
  plugfunc plug;
  char* name;
};
