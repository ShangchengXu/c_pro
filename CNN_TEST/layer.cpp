#include <iostream>
#include "layer.h"
#include "function.h"
void Layer_cnn::initialize()
{
    frame = new int*[frame_size];
    for (int i = 0;i < frame_size;i++)
    {
        frame[i] = new int [frame_size];
    }
    weight = new int*[weight_size];
    for (int i = 0;i < weight_size;i++)
    {
        weight[i] = new int [weight_size];
    }
    frame_out = new int*[frame_size-weight_size+1];
    for (int i = 0;i < frame_size-weight_size+1;i++)
    {
        frame_out[i] = new int [frame_size-weight_size+1];
    }
    g_frame = new int * [frame_size];
    for (int i = 0;i < frame_size;i++)
    {
        g_frame[i] = new int [frame_size];
    }
}



Layer_cnn::Layer_cnn(int frame_size_,int weight_size_,int * weight_in,int bias_,double study_speed_)
{
    frame_size = frame_size_;
    weight_size = weight_size_;
    int f_s = frame_size;
    int w_s = weight_size;
    bias = bias_;
    study_speed = study_speed_;
    initialize();
    // int f_n = 0;
    int w_n = 0;
    for(int i = 0; i < f_s; i++)
    {
        for(int j = 0; j < f_s; j++)
        {
            frame[i][j] = 0;
            // f_n++;
        }
    }
    for(int i = 0; i < w_s; i++)
    {
        for(int j = 0; j < w_s; j++)
        {
            weight[i][j] = weight_in[w_n];
            w_n++;
        }
    }
    for(int i = 0; i < frame_size-weight_size+1; i++)
    {
        for(int j = 0; j < frame_size-weight_size+1; j++)
        {
            frame_out[i][j] = 0;
        }
    }

};
Layer_cnn::~Layer_cnn()
{
    for(int i = 0;i < frame_size;i++)
        {
            delete[] frame[i];
        }
            delete [] frame;
    for(int i = 0;i < weight_size;i++)
        {
            delete[] weight[i];
        }
            delete [] weight;
    for(int i = 0;i < frame_size-weight_size+1;i++)
        {
            delete[] frame_out[i];
        }
            delete [] frame_out;
    for(int i = 0;i < frame_size;i++)
        {
            delete[] g_frame[i];
        }
            delete [] g_frame;                
};

void Layer_cnn::display()
{
    function_display(frame_size,frame,"frame");
    function_display(weight_size,weight,"weight");
    function_display(frame_size-weight_size+1,frame_out,"frame_out");
};

void Layer_cnn::layer_forward(int frame_in_size,int ** frame_in)
{   
    for(int i = 0; i < frame_in_size; i++)
    {
        for(int j = 0; j < frame_in_size; j++)
        {
            frame[i][j] = frame_in[i][j];
            // f_n++;
        }
    }


    function_cnn(frame_size,weight_size,frame,weight,frame_out);
    for(int i = 0 ; i < frame_size-weight_size+1 ; i++)
    {
        for(int j = 0 ; j < frame_size-weight_size+1 ; j++)
        {
            frame_out[i][j] += bias;
        }
    }
};


void Layer_cnn::layer_backward(int ** g_frame_in)
{
    int ** g_frame_,** weight_rot180;
    int ** g_weight;
    int g_frame_size_ = frame_size+weight_size-1;
    g_frame_ = new int *[g_frame_size_];
    for(int i = 0 ; i < g_frame_size_ ; i++)
    {
        g_frame_[i] = new int [g_frame_size_];
    }
    weight_rot180 = new int * [ weight_size];
    for(int i = 0 ; i < weight_size ; i++)
    {
        weight_rot180[i] = new int [weight_size];
    }
    g_weight = new int * [ weight_size];
    for(int i = 0 ; i < weight_size ; i++)
    {
        g_weight[i] = new int [weight_size];
    }

    function_rot180(weight_size,weight_rot180,weight);
    function_extend(g_frame_size_,weight_size,g_frame_,g_frame_in);
    function_cnn(g_frame_size_,weight_size,g_frame_,weight_rot180,g_frame );
    // function_display(g_frame_size_,g_frame_,"g_frame_");
    // function_display(weight_size,weight_rot180,"weight_rot180");
    // function_display(frame_size,g_frame,"g_frame");
    function_cnn(frame_size,frame_size-weight_size + 1,frame,g_frame_in,g_weight);
    // function_display(weight_size,g_weight,"g_weight");

    for(int i = 0; i < weight_size; i++)
    {
        for (int j = 0; j < weight_size ; j++)
        {
            weight [i][j] -= study_speed*g_weight[i][j];
        }
    }
    // function_display(weight_size,weight,"weight_change");
    





    for(int i = 0; i < frame_size; i++)
    {
        delete [] g_frame_[i];
    }
    delete [] g_frame_;

    for(int i = 0; i < weight_size; i++)
    {
        delete [] weight_rot180[i];
    }
    delete [] weight_rot180;
    for(int i = 0; i < weight_size; i++)
    {
        delete [] g_weight[i];
    }
    delete [] g_weight;
}

int ** Layer_cnn::layer_output()
{
    return frame_out;
}


