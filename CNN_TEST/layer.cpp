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
}



Layer_cnn::Layer_cnn(int frame_size_,int weight_size_,int * frame_in,int * weight_in)
{
    frame_size = frame_size_;
    weight_size = weight_size_;
    int f_s = frame_size;
    int w_s = weight_size;
    initialize();
    int f_n = 0;
    int w_n = 0;
    for(int i = 0; i < f_s; i++)
    {
        for(int j = 0; j < f_s; j++)
        {
            frame[i][j] = frame_in[f_n];
            f_n++;
        }
    }
    for(int i = 0; i < w_s; i++)
    {
        for(int j = 0; j < w_s; j++)
        {
            weight[i][j] = frame_in[w_n];
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
};

void Layer_cnn::display()
{
    function_display(frame_size,frame,"frame");
    function_display(weight_size,weight,"weight");
    function_display(frame_size-weight_size+1,frame_out,"frame_out");
};

void Layer_cnn::function_cnn(int frame_size_,int weight_size_,int ** frame_,int ** weight_,int ** frame_out_)
{
     for(int i = 0; i < frame_size_ - weight_size_ +1 ; i++)
    {
        for(int j = 0; j < frame_size_ - weight_size_ +1 ; j++) 
        {
            int sum = 0;
                for(int k = 0; k < weight_size_; k++)
                {
                    for(int l = 0; l <weight_size_; l++)
                    {
                        sum += frame_[i+k][j+l] * weight_[k][l];
                        // std::cout<<frame[i+k][j+l]<<"*"<<weight[k][l]<<std::endl;
                    }
                }
            frame_out_[i][j] = sum; 
        }
    }
}
void Layer_cnn::layer_forward()
{
    function_cnn(frame_size,weight_size,frame,weight,frame_out);
};


void Layer_cnn::layer_backward(int ** g_frame)
{
    int ** g_frame_;
    g_frame_ = new int *[frame_size];
    for(int i = 0 ; i < frame_size ; i++)
    {
        g_frame_[i] = new int [frame_size];
    }

    for (int i = 0; i < frame_size; i++)
    {
        for(int j = 0; j <frame_size ; j++)
        {
            if((i<weight_size-1)||(i>frame_size-weight_size)||(j<weight_size-1)||(j>frame_size-weight_size))
            {
                g_frame_[i][j] = 0;
            }
            else
            {
                g_frame_[i][j] = g_frame[i-weight_size+1][j-weight_size+1];
            }
            
        }
    }
    function_display(frame_size,g_frame_,"g_frame_");

    for(int i = 0; i < frame_size; i++)
    {
        delete [] g_frame_[i];
    }
    delete [] g_frame_;
    
}


