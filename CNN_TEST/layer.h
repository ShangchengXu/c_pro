#ifndef LAYER_CNN_H_
#define LAYER_CNN_H_
#include <iostream>
class Layer_cnn
{
    private:
        int frame_size;
        int weight_size;
        int ** frame;
        int ** frame_out;
        int ** weight;
        void initialize();
    public:
        Layer_cnn(int,int,int *frame,int *weight);
        void layer_forward();
        ~Layer_cnn();
        void display();
        int ** layer_backword(int **);
};


#endif
