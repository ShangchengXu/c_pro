#ifndef _FUNCTION_H_
#define _FUNCTION_H_
#include <iostream>
#include <string>

void function_display(int ,int **,const std::string);
void function_display(int ,double **,const std::string);
void function_extend(int ,int ,int **,int **);
void function_cnn(int ,int ,int **, int **,int **);
void function_cnn(int ,int ,int **, double **,int **);
void function_cnn(int ,int ,int **, double **,double **);
void function_rot180(int , double **,double **);
long long function_loss(int ,int ** ,int ** );

#endif