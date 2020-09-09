#ifndef _FUNCTION_H_
#define _FUNCTION_H_
#include <iostream>
#include <string>

void function_display(int ,int **,const std::string);
void function_display(int ,double **,const std::string);
void function_extend(int ,int ,double **,double **);
void function_cnn(int ,int ,double **, double **,double **);
// void function_cnn(int ,int ,int **, double **,int **);
// void function_cnn(int ,int ,int **, double **,double **);
void function_rot180(int , double **,double **);
double function_loss(int ,double ** ,double ** );

#endif