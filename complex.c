#include "complex.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void print_complex (complex * complex)
{
  if(complex->b >= 0){
    printf ("%.2f + (%.2f)i\n", complex->a, complex->b);
  }
  else printf("%.2f - (%.2f)i\n", complex->a, -1*complex->b);
}

void sub_complex(complex* a, complex* b)
{
    complex c = {a->a - b->a, a->b - b->b};
    print_complex(&c);
}

void add_complex(complex* a, complex* b)
{
    complex c = {a->a + b->a, a->b + b->b};
    print_complex(&c);
}

void mult_complex_complex(complex* a, complex* b)
{
    complex c = {a->a*b->a - a->b*b->b , a->a*b->b + a->b*b->a};
    print_complex(&c);
}

void mult_complex_real(double real, complex* comp)
{
    complex c = {real*comp->a, real* comp->b};
    print_complex(&c);
}

void mult_complex_img(double img, complex* comp)
{
    complex c = {img*comp->b*-1, img* comp->a};
    print_complex(&c);
}

void abs_complex(complex* c)
{
    double square_a = c->a * c->a;
    double square_b = c->b * c->b;
    double complex_abs = sqrt(square_a + square_b);
    complex abs = {complex_abs, 0};
    print_complex(&abs);
}

