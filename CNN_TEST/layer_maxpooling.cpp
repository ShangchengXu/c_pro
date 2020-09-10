#include <iostream>
#include "layer.h"
#include "function.h"
void Layer_maxpooling::initialize()
{
    frame = new double*[frame_size];
    for (int i = 0;i < frame_size;i++)
    {
        frame[i] = new double [frame_size];
    }
    frame_out = new double*[frame_size/pooling_size];
    for (int i = 0;i < frame_size/pooling_size;i++)
    {
        frame_out[i] = new double [frame_size/pooling_size];
    }
    g_frame = new double * [frame_size];
    for (int i = 0;i < frame_size;i++)
    {
        g_frame[i] = new double [frame_size];
    }
};

Layer_maxpooling::Layer_maxpooling(int frame_size_,int pooling_size_)
{
    frame_size = frame_size_;
    pooling_size = pooling_size_;

    for(int i = 0; i < frame_size; i++)
    {
        for(int j = 0; j < frame_size; j++)
        {
            frame[i][j] = 0;
            // f_n++;
        }
    }

    for(int i = 0; i < frame_size/pooling_size; i++)
    {
        for(int j = 0; j < frame_size/pooling_size; j++)
        {
            frame_out[i][j] = 0;
        }
    }
}


Layer_maxpooling::~Layer_maxpooling()
{
    for(int i = 0 ; i < frame_size ; i++)
    {
        delete [] frame[i];
    }
    delete [] frame;

    for(int i = 0 ; i < frame_size/pooling_size ; i++)
    {
        delete [] frame_out[i];
    }
    delete [] frame_out;

    for(int i = 0 ; i < frame_size; i++)
    {
        delete [] g_frame[i];
    }
    delete [] g_frame;
}