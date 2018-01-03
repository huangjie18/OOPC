/* ex16-int.h */ 

CLASS(Integer)
{
  void (*init)(Integer*);
  void (*display)(Integer*);
  int value;
};

