#include <iostream>
#include "layer.h"
#include "function.h"
#include "test.h"
#include <cstdlib>
#include "source.cpp"


int main()
{
    int frame_size  = 24;
    int pooling_size = 2;
    int frame_out_size = frame_size/pooling_size;
    double ** frame;
    // double ** frame_out;
    // int ** frame_out_pos;
 
    std::cout<<"54545454545";
    frame = function_new_double(frame_size);
    // {
    // frame = new double * [frame_size];
    // for(int i=0;i<frame_size;i++)
    // {
    //     frame[i] = new double [frame_size];
    // }
    // }
    function_init(frame_size,frame);
    // std::cout<<frame[0][0];
    
    // function_new(frame_out_size,frame_out);
    // function_init(frame_out_size,frame_out);

    // function_new(frame_out_size,frame_out_pos);
    // function_init(frame_out_size,frame_out_pos);

    // // function_maxpooling(frame_size,pooling_size,frame,frame_out,frame_out_pos);
    // function_display(frame_size,frame,"frame:");
    // function_display(frame_out_size,frame_out,"frame_out:");
    // function_display(frame_out_size,frame_out,"frame_out_pos:");
    







 











    
    function_delete(frame_size,frame);
//     {
//     for(int i = 0 ; i < frame_size;i++)
//     {
//         delete [] frame[i];
//     }
//     delete []frame;
// }
//     function_delete(frame_out_size,frame_out);
//     function_delete(frame_out_size,frame_out_pos);
 }