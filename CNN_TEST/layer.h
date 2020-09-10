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
        int bias;
        double study_speed;
        void initialize();
    public:
        Layer_cnn(int,int,double *weight,int,double );
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
        void initialize();
    public:
        Layer_maxpooling(int,int);
        ~Layer_maxpooling();
        void layer_forward(double **);
        void display();
        void layer_backward(double **);
        double ** layer_output();






};
#endif
