/* ex16-idisp.h */

INTERFACE(IDisplay)
{
  void (*init)(void*);
  void (*display)(void*);
  int value;
};

