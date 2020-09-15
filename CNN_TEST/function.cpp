#include <iostream>
#include "function.h"
#include <cmath>
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

void function_maxpooling(int frame_in_size,int pooling_size,double ** frame_in, double ** frame_out,int ** frame_out_pos)
{
    for(int i = 0 ; i < frame_in_size;i = i + pooling_size)
    {
        for(int j=0;j<frame_in_size;j = j + pooling_size)
        {   
            double max_temp = frame_in[i][j];
            frame_out_pos[i/pooling_size][j/pooling_size] = i*frame_in_size+j;
            for(int k = 0 ; k < pooling_size;k++)
            {
                for(int l = 0 ; l < pooling_size;l++)
                {
                    if(frame_in[i+k][j+l]>max_temp)
                    {
                        max_temp = frame_in[i+k][j+l];
                        frame_out_pos[i/pooling_size][j/pooling_size] = (i+k)*frame_in_size+j+l;
                    }
                }
            }
            frame_out[i/pooling_size][j/pooling_size] = max_temp;
        }
    }
};


double ** function_new_double(int frame_size)
{
    // std::cout<<"ok_1"<<std::endl;
    double ** frame;
    frame = new double * [frame_size];
    for(int i=0;i<frame_size;i++)
    {
        frame[i] = new double [frame_size];
    }
    return frame;
};
int** function_new_int(int frame_size)
{   
    int ** frame;
    // std::cout<<"ok_1"<<std::endl;
    frame = new int * [frame_size];
    for(int i=0;i<frame_size;i++)
    {
        frame[i] = new int [frame_size];
    }
    return frame;
};
void function_init(int frame_size,double **frame)
{   
    srand(20);
    for(int i = 0 ; i < frame_size ; i++)
    {
        for(int j = 0 ; j < frame_size ; j++)
        {
            frame[i][j] = rand()%256;
            frame[i][j] = frame[i][j]/256;
            // answer[i][j] = 0.222;
        }
    }
};
void function_init(int frame_size,int **frame)
{
    srand(20);
    for(int i = 0 ; i < frame_size ; i++)
    {
        for(int j = 0 ; j < frame_size ; j++)
        {
            frame[i][j] = rand()%256;
            frame[i][j] = frame[i][j]/256;
            // answer[i][j] = 0.222;
        }
    }
};
void function_delete(int frame_size,double **frame)
{   
    // std::cout<<"ok_1"<<std::endl;
    for(int i = 0 ; i < frame_size;i++)
    {
        delete [] frame[i];
    }
    delete []frame;
};
void function_delete(int frame_size,int **frame)
{
    for(int i = 0 ; i < frame_size;i++)
    {
        delete [] frame[i];
    }
    delete []frame;
};



void function_combine(int frame_size,int frame_num,int *** frame_arr_in, int **frame_out)
{
    for(int i = 0; i < frame_num ; i++)
    {
        for (int j = 0 ; j < frame_size ; j++)
        {
            for(int k = 0 ; k <frame_size ; k++)
            {
                frame_out[i][j*frame_size+k] = frame_arr_in[i][j][k];
            }
        }
    }
}

void function_combine(int frame_size,int frame_num,double *** frame_arr_in, double **frame_out)
{
    for(int i = 0; i < frame_num ; i++)
    {
        for (int j = 0 ; j < frame_size ; j++)
        {
            for(int k = 0 ; k <frame_size ; k++)
            {
                frame_out[i][j*frame_size+k] = frame_arr_in[i][j][k];
            }
        }
    }
}

void function_spread(int frame_size,int frame_num,double *** frame_arr_out, double **frame_out_in)
{
    for(int i = 0; i < frame_num ; i++)
    {
        for (int j = 0 ; j < frame_size ; j++)
        {
            for(int k = 0 ; k <frame_size ; k++)
            {
                frame_arr_out[i][j][k] = frame_out_in[i][j*frame_size+k];
            }
        }
    }
}

double function_softmax_out(int num,double * arr_in,double * answer_in,double ***delt_arr_out)
{
    double sum = 0;
    double * arr_out;
    double loss = 0;
    arr_out = new double [num];
    for (int i = 0; i < num ; i++)
    {
        sum += std::exp(arr_in[i]);
    }
    for (int i = 0; i < num ; i++)
    {
        arr_out[i] = std::exp(arr_in[i])/sum;
    }
    for(int i = 0 ; i < num ; i++)
    {
        loss += (arr_out[i]-answer_in[i])*(arr_out[i]-answer_in[i]);
    }
    loss = loss / (num * num);

    for (int i = 0; i < num ; i++)
    {
        delt_arr_out[i][0][0] = 2*(arr_out[i]-answer_in[i])*arr_out[i]*(1-arr_out[i])/(num*num);
    }
//用三维数组表示一个一维数组只是为了模块匹配
    delete [] arr_out;
    return loss;
}

void function_input(int frame_size,ifstream & fid_image, ifstream & fid_lable,double ** frame_out,double *answer_out)
{
    for(int i = 0 ; i < frame_size ; i++)
    {
        for(int j = 0; j < frame_size ; j++)
        {
            fid_image >> frame_out[i][j];
        }
    }
    for(int i = 0 ; i < 10 ; i++)
    {
        fid_lable >> answer_out[i];
    }
}