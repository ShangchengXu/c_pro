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
}