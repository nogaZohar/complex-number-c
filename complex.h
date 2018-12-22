#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED

typedef struct Complex
{
  double a;
  double b;
} complex;


void print_complex (complex * complex);

void sub_complex(complex* a, complex* b);

void add_complex(complex* a, complex* b);

void mult_complex_complex(complex* a, complex* b);

void mult_complex_real(double real, complex* comp);

void mult_complex_img(double img, complex* comp);

void abs_complex(complex* c);


#endif // COMPLEX_H_INCLUDED
