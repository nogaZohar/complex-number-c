#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "complex.h"
#include <ctype.h>

#define LINE_SIZE 100

complex A={0,0}, B={0,0}, C={0,0}, D={0,0}, E={0,0}, F={0,0};


complex * get_complex (char complex)
{
  if (complex == 'A')
    return &A;
  if (complex == 'B')
    return &B;
  if (complex == 'C')
    return &C;
  if (complex == 'D')
    return &D;
  if (complex == 'E')
    return &E;
  if (complex == 'F')
    return &F;
  output_error("Undefined complex variable\n");
  return NULL;
}


void output_error (char *error)
{
  printf ("%s", error);
  //exit(1); ---> FOR DEBUG
}


int get_line(char* s, int size){
    int c, i;
    for (i = 0; i<size-1 && (c=getchar())!=EOF && c != '\n'; ++i)
    {
        s[i] = c;
        if(c == '\n')
        {
            s[i] = c;
            ++i;
        }
    }
    s[i] = '\0';
    return i;
}

void remove_spaces(char* source)
{
  char* i = source;
  char* j = source;
  while(*j != '\0')
  {
    *i = *j++;
    if(*i != ' ' && *i != '\t'){
        i++;
    }
  }
  *i = '\0';
}

void read_comp()
{
  char input[LINE_SIZE];
  char cmplx;
  double a, b;
  char* err;
  int line_length = get_line(input, LINE_SIZE);
  if (line_length < 4)
  {
    output_error("Missing parameters\n");
    return;
  }
  cmplx = *(strtok(input, ","));
  complex *c = get_complex(cmplx);
  if(c == NULL)
    return;
  char *parameter = strtok(NULL, ","); // number a
  remove_spaces(parameter);
  a = strtod(parameter, &err);
  if(a == 0 && strcmp(parameter, "0") || *err!=0)
  {
    output_error("Error parsing parameter a: Not a valid number\n");
    return;
  }
  parameter = strtok(NULL, " "); // number b
  if(parameter == NULL)
  {
      output_error("Missing parameter or comma!\n");
      return;
  }
  remove_spaces(parameter);
  b = strtod (parameter, NULL);
  if((b == 0 && strcmp(parameter, "0")) || *err != 0){
    output_error("Error parsing parameter b: Not a valid number\n");
    return;
  }
  parameter = strtok(NULL, " ");
  if(parameter != NULL){
    output_error("Too many arguments!\n");
    return;
  }
  c->a = a;
  c->b = b;
}

void sub_comp()
{
  char input[LINE_SIZE];
  char comp1name, comp2name;
  int line_length = get_line(input, LINE_SIZE);
  remove_spaces(input);
  if(strlen(input) != 3)
  {
    output_error("Given unsupported argument list: try to use name1, name2 \n");
    return;
  }
  comp1name = strtok(input, ",")[0];
  comp2name = strtok(NULL, "\n")[0];
  complex* c1 = get_complex(comp1name);
  complex* c2 = get_complex(comp2name);
  if(c1 != NULL && c2 != NULL)
    sub_complex(c1, c2);
}

void add_comp()
{
  char input[LINE_SIZE];
  char comp1name, comp2name;
  int line_length = get_line(input, LINE_SIZE);
  remove_spaces(input);
  if(strlen(input) != 3)
  {
    output_error("Given unsupported argument list: try to use name1, name2 \n");
    return;
  }
  comp1name = strtok(input, ",")[0];
  comp2name = strtok(NULL, "\n")[0];
  complex* c1 = get_complex(comp1name);
  complex* c2 = get_complex(comp2name);
  if(c1 != NULL && c2 != NULL)
    add_complex(c1, c2);
}

void mult_comp_comp()
{
  char input[LINE_SIZE];
  char comp1name, comp2name;
  int line_length = get_line(input, LINE_SIZE);
  remove_spaces(input);
  if(strlen(input) != 3)
  {
    output_error("Given unsupported argument list: try to use name1, name2 \n");
    return;
  }
  comp1name = strtok(input, ",")[0];
  comp2name = strtok(NULL, "\n")[0];
  complex* c1 = get_complex(comp1name);
  complex* c2 = get_complex(comp2name);
  if(c1 != NULL && c2 != NULL)
    mult_complex_complex(c1, c2);
}

void mult_comp_real()
{
  char input[LINE_SIZE];
  char comp1name;
  double real;
  int line_length = get_line(input, LINE_SIZE);
  remove_spaces(input);
  if(strlen(input) < 3)
  {
    output_error("Too few arguments \n");
    return;
  }
  comp1name = strtok(input, ",")[0];
  char *parameter = strtok(NULL, ",");
  real = strtod(parameter, NULL);
  remove_spaces(parameter);
  if(real == 0 && strcmp(parameter, "0")){
    output_error("Error parsing real number: Not a valid number\n");
    return;
  }
  complex* c1 = get_complex(comp1name);
  if(c1 != NULL)
    mult_complex_real(real, c1);
}

void mult_comp_img()
{
  char input[LINE_SIZE];
  char comp1name;
  double img;
  int line_length = get_line(input, LINE_SIZE);
  remove_spaces(input);
  if(strlen(input) < 3)
  {
    output_error("Too few arguments \n");
    return;
  }
  comp1name = strtok(input, ",")[0];
  char *parameter = strtok(NULL, ",");
  img = strtod(parameter, NULL);
  remove_spaces(parameter);
  if(img == 0 && strcmp(parameter, "0")){
    output_error("Error parsing real number: Not a valid number\n");
    return;
  }
  complex* c1 = get_complex(comp1name);
  if(c1 != NULL)
    mult_complex_img(img, c1);
}

void print_comp()
{
  char input[LINE_SIZE];
  char comp;
  int line_length = get_line(input, LINE_SIZE);
  remove_spaces(input);
  if(strlen(input) > 1)
  {
    output_error("Too many arguments! \n");
    return;
  }
  complex* c = get_complex(input[0]);
  if(c != NULL)
    print_complex(c);
}

void abs_comp()
{
  char input[LINE_SIZE];
  char comp;
  int line_length = get_line(input, LINE_SIZE);
  remove_spaces(input);
  if(strlen(input) > 1)
  {
    output_error("Too many arguments! \n");
    return;
  }
  complex* c = get_complex(input[0]);
  if(c != NULL)
    abs_complex(c);
}

int exe_cmd(char *cmd)
{
  if (strcmp(cmd, "read_comp") == 0)
    read_comp();
  else if(strcmp(cmd, "print_comp") == 0)
    print_comp();
  else if(strcmp(cmd, "stop") == 0)
    return 0;
  else if(strcmp(cmd, "add_comp") == 0)
    add_comp();
  else if(strcmp(cmd, "sub_comp") == 0)
    sub_comp();
  else if(strcmp(cmd, "mult_comp_real") == 0)
    mult_comp_real();
  else if(strcmp(cmd, "mult_comp_img") == 0)
    mult_comp_img();
  else if(strcmp(cmd, "mult_comp_comp") == 0)
    mult_comp_comp();
  else if(strcmp(cmd, "abs_comp") == 0)
    abs_comp();
  else
  {
      output_error("Command not found!\n");
      char input[LINE_SIZE];
      int line_length = get_line(input, LINE_SIZE);
  }
  return 1;
}


int handle_input()
{
  char cmd[LINE_SIZE];
  int i = 0;
  cmd[i] = getchar ();
  while (cmd[i] != ' ' && cmd[i] != '\n')
    cmd[++i] = getchar();
  cmd[i] = '\0';
  return exe_cmd(cmd);
}


int main()
{
  int status = 1;
  while (status)
    status = handle_input();
  return 0;
}
