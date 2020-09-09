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
void function_display(int frame_size_in,double ** frame_in_,const std::string str)
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


void function_extend(int g_frame_size_ , int weight_size_ , double ** g_frame_out,double ** g_frame_in)
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


void function_cnn(int frame_size_,int weight_size_,double ** frame_,double ** weight_,double ** frame_out_)
{
     for(int i = 0; i < frame_size_ - weight_size_ +1 ; i++)
    {
        for(int j = 0; j < frame_size_ - weight_size_ +1 ; j++) 
        {
            double sum = 0;
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




void function_rot180(const int size,double ** arr_out,double ** arr_in)
{
    double **arr_temp = new double *[size];
    for(int i = 0; i < size ; i++)
    {
        arr_temp[i] = new double [size];
    }
    for (int i = 0 ; i < size ; i++)
    {
        for (int j = 0; j < size ; j++)
        {
            arr_temp[i][j] = arr_in[i][j];
        }
    }
    for (int i = 0 ; i < size ; i++)
    {
        for (int j = 0; j < size ; j++)
        {
            arr_out[i][j] = arr_temp[size - i - 1][size-j - 1];
        }
    }
    for (int i = 0; i < size; i++)
    {
        delete [] arr_temp[i];
    }
    delete [] arr_temp;


}

double function_loss(int m_size,double ** y,double ** x)
{
    double sum = 0 ;
    for(int i = 0; i < m_size ; i ++)
    {
      for(int j = 0; j < m_size ; j ++)  
      {
          sum += (y[i][j]-x[i][j])*(y[i][j]-x[i][j]);
      }
    }
    sum = sum /(m_size*m_size);
    return sum;
}