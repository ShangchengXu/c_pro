#ifndef _FUNCTION_H_
#define _FUNCTION_H_
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
void function_display(int ,int **,const std::string);
void function_display(int ,double **,const std::string);
void function_extend(int ,int ,double **,double **);
void function_cnn(int ,int ,double **, double **,double **);
// void function_cnn(int ,int ,int **, double **,int **);
// void function_cnn(int ,int ,int **, double **,double **);
void function_rot180(int , double **,double **);
double function_loss(int ,double ** ,double ** );
void function_maxpooling(int frame_in_size,int pooling_size,double ** frame_in, double ** frame_out,int ** frame_out_pos);
double ** function_new_double(int frame_size);
int ** function_new_int(int frame_size);
void function_init(int frame_size,double **);
void function_init(int frame_size,int **);
void function_delete(int frame_size,double **);
void function_delete(int frame_size,int **);
void function_combine(int frame_size,int frame_num,double ***, double **);
void function_spread(int frame_size,int frame_num,double ***, double **);
double function_softmax_out(int num,double * arr_in,double * answer_in,double ***delt_arr_out);
int function_input(int frame_size,ifstream & fid_image, ifstream & fid_lable,double ** frame_out,double *answer_out);
#endif