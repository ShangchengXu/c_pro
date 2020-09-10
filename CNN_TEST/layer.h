#ifndef LAYER_CNN_H_
#define LAYER_CNN_H_
#include <iostream>
class Layer_cnn
{
    private:
        int frame_size;
        int weight_size;
        double ** frame;
        double ** frame_out;
        double ** weight;
        double ** g_frame;
        int has_sigmoid;
        double bias;
        double study_speed;
        void initialize();
    public:
        Layer_cnn(int,int,double *weight,double,double,int );
        void layer_forward(int ,double **);
        ~Layer_cnn();
        void display();
        void layer_backward(double **);
        double ** layer_output();
        // void function_cnn(int ,int ,int **, int **,int **);
};

class Layer_maxpooling
{
    private:
        int frame_size;
        int pooling_size;
        double ** frame;
        double ** frame_out;
        double ** g_frame;
        int ** g_frame_pos;
        void initialize();
    public:
        Layer_maxpooling(int,int);
        ~Layer_maxpooling();
        void layer_forward(double **);
        void display();
        void layer_backward(double **);
        double ** layer_output();

};

class Layer_combine
{
    private:
        int index;
        double *** frame_arr;
        int frame_num;
        int frame_size;
        int weight_size;
        double ** frame_out;
        // double ** g_frame_in;
        double *** g_frame_arr;
        double *** weight_arr;
        Layer_cnn ** layer_cnn_point;
        void initialize();
    public:
        Layer_combine(int index,int frame_num, int frame_size,int weight_size);
        ~Layer_combine();







};




#endif
