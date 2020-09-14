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
    g_frame_pos = new int * [frame_size/pooling_size];
    for (int i = 0;i < frame_size/pooling_size;i++)
    {
        g_frame_pos[i] = new int [frame_size/pooling_size];
    }

};

Layer_maxpooling::Layer_maxpooling(int frame_size_,int pooling_size_)
{
    
    frame_size = frame_size_;
    pooling_size = pooling_size_;

    initialize();

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

    for(int i = 0 ; i < frame_size/pooling_size ; i++)
    {
        delete [] g_frame_pos[i];
    }
    delete [] g_frame_pos;
}

void Layer_maxpooling::layer_forward(double ** frame_in)
{
    for(int i = 0; i < frame_size; i++)
    {
        for(int j = 0; j < frame_size; j++)
        {
            frame[i][j] = frame_in[i][j];
        }
    }

    function_maxpooling(frame_size,pooling_size,frame,frame_out,g_frame_pos);
};


void Layer_maxpooling::layer_backward(double ** g_fra)
{
    for(int i = 0; i < frame_size; i++)
    {
       for(int j = 0; j < frame_size; j++) 
       {
           g_frame[i][j] = 0;
       }
    }
    for(int i = 0; i < frame_size/pooling_size; i++)
    {
        for(int j = 0; j < frame_size/pooling_size; j++)
        {
            int y = g_frame_pos[i][j]%frame_size;
            int x = g_frame_pos[i][j]/frame_size;
            g_frame[x][y] = g_fra[i][j];
        }
    }
}
void Layer_maxpooling::display()
{
    function_display(frame_size,frame,"frame:");
    function_display(frame_size/pooling_size,frame_out,"frame:");
    function_display(frame_size,g_frame,"g_frame:");
    function_display(frame_size/pooling_size,g_frame_pos,"g_frame_pos:");
}

double ** Layer_maxpooling::layer_output()
{
    return frame_out;
}

double ** Layer_maxpooling::layer_g_frame_output()
{
    return g_frame;
}
