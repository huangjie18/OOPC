/*  Win32_EX01_01.c  ---- an ANSI-C program  */
#include "stdio.h"
double radius;
double length, width;

void init_circle() 
     { radius = 10.5; }
void pr_area_circle()   
     { printf("AC = %f\n", 3.14 * radius * radius); }
void pr_perimeter_circle() 
     { printf("PC = %f\n", 2 * 3.14 * radius);  }
/* --------------------------------------------------- */ 
void init_rect()  
	{ length = 10.5; width = 5.125; }
void pr_area_rect()
	{ printf("AR = %f\n", length * width); }
void pr_perimeter_rect() 
	{ printf("PR = %f\n", 2 * (length + width)); }
extern void* LightNew();

void main(){
    init_circle(); 
    pr_area_circle();    pr_perimeter_circle();
    init_rect();
    pr_area_rect();      pr_perimeter_rect();
    getchar();    return;
}
