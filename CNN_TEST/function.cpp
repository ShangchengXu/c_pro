#include <iostream>
#include "function.h"
void function_display(int frame_size_in,int ** frame_in_,const std::string str)
{
    std::cout<<str;
    for(int i = 0 ; i < frame_size_in ; i++)
    {   
        std::cout<<std::endl;
        for(int j = 0 ; j < frame_size_in ; j++)
        {
            std::cout<<frame_in_[i][j]<<" ";
        }
    }
    std::cout<<std::endl;
};


void function_extend(int g_frame_size_ , int weight_size_ , int ** g_frame_out,int ** g_frame_in)
{
    // int g_frame_size_ = frame_size_+weight_size_-1;
    for (int i = 0; i < g_frame_size_; i++)
    {
        for(int j = 0; j <g_frame_size_; j++)
        {
            if((i<weight_size_-1)||(i>g_frame_size_-weight_size_)||(j<weight_size_-1)||(j>g_frame_size_-weight_size_))
            {
                g_frame_out[i][j] = 0;
            }
            else
            {
                g_frame_out[i][j] = g_frame_in[i-weight_size_+1][j-weight_size_+1];
            }
            
        }
    }
};


void function_cnn(int frame_size_,int weight_size_,int ** frame_,int ** weight_,int ** frame_out_)
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