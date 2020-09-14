#include "cnn_net.h"
#include <iostream>
#include <string>
#include "function.h"
#include "layer.h"
#include <fstream>


void lenet_5_tran()
{

using namespace std;

//*****************************init*************************************//
const int rounds = 300;
int frame_c0_size = 28;
int weight_c0_size = 5;
int weight_c2_size = 5;
int weight_c4_size = 16;
int c0_has_sigmoid = 0;
int c2_has_sigmoid = 1;
int c4_has_sigmoid = 1;
int maxpooling_c1_size = 2;
int maxpooling_c3_size = 4;
int frame_c1_size = frame_c0_size - weight_c0_size + 1;
int frame_c2_size = frame_c1_size / maxpooling_c1_size;
int frame_c3_size = frame_c2_size - weight_c2_size + 1;
int frame_c4_size = (frame_c3_size / maxpooling_c3_size)*(frame_c3_size / maxpooling_c3_size);
double bias_c0 = 0;
double bias_c2 = 0.1;
double bias_c4 = 0.1;
const int layer_c0_num = 4;
const int layer_c1_num = 4;
const int layer_c2_num = 4;
const int layer_c3_num = 4;
const int layer_c4_num = 10;
double study_speed_c0 = 0.1;
double study_speed_c2 = 0.1;
double study_speed_c4 = 0.1;
double ** weight_c0;
double ** weight_c2;
double ** weight_c4;


double *** frame_c4_arr;
double ** frame_c4_out;
double * frame_softmax_in;
double * answer_in;
double *** delt_arr_out;
frame_softmax_in = new double [layer_c4_num];
answer_in = new double [layer_c4_num];
frame_c4_arr = new double **[layer_c3_num];
for(int i = 0 ; i < frame_c3_size/maxpooling_c3_size ; i++)
{
    frame_c4_arr[i] = new double *[frame_c3_size/maxpooling_c3_size];
    for(int j = 0 ; j < frame_c3_size/maxpooling_c3_size; j++)
    {
        frame_c4_arr[i][j] = new double [frame_c3_size/maxpooling_c3_size];
    }
}
frame_c4_out = new double *[layer_c3_num];
for(int j = 0 ; j < layer_c3_num ; j++)
    {
        frame_c4_out[j] = new double [(frame_c3_size/maxpooling_c3_size)*(frame_c3_size/maxpooling_c3_size)];
    }

for(int i = 0 ; i < layer_c4_num ; i++)
{
    frame_c4_arr[i] = new double *[1];
    for(int j = 0 ; j < 1; j++)
    {
        frame_c4_arr[i][j] = new double [1];
    }
}





// weight_c0 = function_new_double(weight_c0_size*weight_c0_size);
weight_c0 = new double*[layer_c0_num];
for(int i = 0 ; i < layer_c0_num; i ++)
{
    weight_c0[i] = new double[weight_c0_size*weight_c0_size];
}
ifstream fweight_c0;
fweight_c0.open("weight_c0.txt");
for(int i = 0 ; i < layer_c0_num ; i++)
{
    for(int j = 0 ; j < weight_c0_size*weight_c0_size;j++)
    {
        fweight_c0 >> weight_c0[i][j];
        // std::cout<<weight_c0[i][j]<<" ";
    }
    // std::cout<<std::endl;
}
fweight_c0.close();
//******************************c0**********************************//
Layer_cnn layer_cnn_c0[layer_c0_num] = {
                            Layer_cnn(frame_c0_size,weight_c0_size,weight_c0[0],bias_c0,study_speed_c0,c0_has_sigmoid),
                            Layer_cnn(frame_c0_size,weight_c0_size,weight_c0[1],bias_c0,study_speed_c0,c0_has_sigmoid),
                            Layer_cnn(frame_c0_size,weight_c0_size,weight_c0[2],bias_c0,study_speed_c0,c0_has_sigmoid),
                            Layer_cnn(frame_c0_size,weight_c0_size,weight_c0[3],bias_c0,study_speed_c0,c0_has_sigmoid)
                            // Layer_cnn(frame_c0_size,weight_c0_size,weight_c0[4],bias_c0,study_speed_c0,c0_has_sigmoid),
                            // Layer_cnn(frame_c0_size,weight_c0_size,weight_c0[5],bias_c0,study_speed_c0,c0_has_sigmoid)
};

for(int i = 0 ; i < layer_c0_num; i ++)
{
    delete [] weight_c0[i];
}
delete [] weight_c0;
//******************************c1**********************************//
Layer_maxpooling layer_maxpooling_c1[layer_c1_num] = {
                            Layer_maxpooling(frame_c1_size,maxpooling_c1_size),
                            Layer_maxpooling(frame_c1_size,maxpooling_c1_size),
                            Layer_maxpooling(frame_c1_size,maxpooling_c1_size),
                            Layer_maxpooling(frame_c1_size,maxpooling_c1_size)
                            // Layer_maxpooling(frame_c1_size,maxpooling_c1_size),
                            // Layer_maxpooling(frame_c1_size,maxpooling_c1_size)
};

// Layer_cnn layer_cnn_c2_g0[layer_c0_num] = {
//                             Layer_cnn(frame_c0_size,weight_c0_size,weight_c0[0],bias_c0,study_speed_c0,c0_has_sigmoid),
//                             Layer_cnn(frame_c0_size,weight_c0_size,weight_c0[1],bias_c0,study_speed_c0,c0_has_sigmoid),
//                             Layer_cnn(frame_c0_size,weight_c0_size,weight_c0[2],bias_c0,study_speed_c0,c0_has_sigmoid),
//                             Layer_cnn(frame_c0_size,weight_c0_size,weight_c0[3],bias_c0,study_speed_c0,c0_has_sigmoid),
//                             Layer_cnn(frame_c0_size,weight_c0_size,weight_c0[4],bias_c0,study_speed_c0,c0_has_sigmoid),
//                             Layer_cnn(frame_c0_size,weight_c0_size,weight_c0[5],bias_c0,study_speed_c0,c0_has_sigmoid)
// };
// Layer_cnn layer_cnn_c2_g1[layer_c0_num] = {
//                             Layer_cnn(frame_c0_size,weight_c0_size,weight_c0[0],bias_c0,study_speed_c0,c0_has_sigmoid),
//                             Layer_cnn(frame_c0_size,weight_c0_size,weight_c0[1],bias_c0,study_speed_c0,c0_has_sigmoid),
//                             Layer_cnn(frame_c0_size,weight_c0_size,weight_c0[2],bias_c0,study_speed_c0,c0_has_sigmoid),
//                             Layer_cnn(frame_c0_size,weight_c0_size,weight_c0[3],bias_c0,study_speed_c0,c0_has_sigmoid),
//                             Layer_cnn(frame_c0_size,weight_c0_size,weight_c0[4],bias_c0,study_speed_c0,c0_has_sigmoid),
//                             Layer_cnn(frame_c0_size,weight_c0_size,weight_c0[5],bias_c0,study_speed_c0,c0_has_sigmoid)
// };
// Layer_cnn layer_cnn_c2_g2[layer_c0_num] = {
//                             Layer_cnn(frame_c0_size,weight_c0_size,weight_c0[0],bias_c0,study_speed_c0,c0_has_sigmoid),
//                             Layer_cnn(frame_c0_size,weight_c0_size,weight_c0[1],bias_c0,study_speed_c0,c0_has_sigmoid),
//                             Layer_cnn(frame_c0_size,weight_c0_size,weight_c0[2],bias_c0,study_speed_c0,c0_has_sigmoid),
//                             Layer_cnn(frame_c0_size,weight_c0_size,weight_c0[3],bias_c0,study_speed_c0,c0_has_sigmoid),
//                             Layer_cnn(frame_c0_size,weight_c0_size,weight_c0[4],bias_c0,study_speed_c0,c0_has_sigmoid),
//                             Layer_cnn(frame_c0_size,weight_c0_size,weight_c0[5],bias_c0,study_speed_c0,c0_has_sigmoid)
// };
// Layer_cnn layer_cnn_c2_g3[layer_c0_num] = {
//                             Layer_cnn(frame_c0_size,weight_c0_size,weight_c0[0],bias_c0,study_speed_c0,c0_has_sigmoid),
//                             Layer_cnn(frame_c0_size,weight_c0_size,weight_c0[1],bias_c0,study_speed_c0,c0_has_sigmoid),
//                             Layer_cnn(frame_c0_size,weight_c0_size,weight_c0[2],bias_c0,study_speed_c0,c0_has_sigmoid),
//                             Layer_cnn(frame_c0_size,weight_c0_size,weight_c0[3],bias_c0,study_speed_c0,c0_has_sigmoid),
//                             Layer_cnn(frame_c0_size,weight_c0_size,weight_c0[4],bias_c0,study_speed_c0,c0_has_sigmoid),
//                             Layer_cnn(frame_c0_size,weight_c0_size,weight_c0[5],bias_c0,study_speed_c0,c0_has_sigmoid)
// };
// Layer_cnn layer_cnn_c2_g4[layer_c0_num] = {
//                             Layer_cnn(frame_c0_size,weight_c0_size,weight_c0[0],bias_c0,study_speed_c0,c0_has_sigmoid),
//                             Layer_cnn(frame_c0_size,weight_c0_size,weight_c0[1],bias_c0,study_speed_c0,c0_has_sigmoid),
//                             Layer_cnn(frame_c0_size,weight_c0_size,weight_c0[2],bias_c0,study_speed_c0,c0_has_sigmoid),
//                             Layer_cnn(frame_c0_size,weight_c0_size,weight_c0[3],bias_c0,study_speed_c0,c0_has_sigmoid),
//                             Layer_cnn(frame_c0_size,weight_c0_size,weight_c0[4],bias_c0,study_speed_c0,c0_has_sigmoid),
//                             Layer_cnn(frame_c0_size,weight_c0_size,weight_c0[5],bias_c0,study_speed_c0,c0_has_sigmoid)
// };

//******************************c2**********************************//
for(int i = 0 ; i < layer_c2_num; i ++)
{
    weight_c2[i] = new double[weight_c2_size*weight_c2_size];
}
ifstream fweight_c2;
fweight_c2.open("weight_c2.txt");
for(int i = 0 ; i < layer_c2_num ; i++)
{
    for(int j = 0 ; j < weight_c2_size*weight_c2_size;j++)
    {
        fweight_c2 >> weight_c2[i][j];
        // std::cout<<weight_c0[i][j]<<" ";
    }
    // std::cout<<std::endl;
}
fweight_c2.close();
Layer_cnn layer_cnn_c2[layer_c2_num] = {
                            Layer_cnn(frame_c2_size,weight_c2_size,weight_c2[0],bias_c2,study_speed_c2,c2_has_sigmoid),
                            Layer_cnn(frame_c2_size,weight_c2_size,weight_c2[1],bias_c2,study_speed_c2,c2_has_sigmoid),
                            Layer_cnn(frame_c2_size,weight_c2_size,weight_c2[2],bias_c2,study_speed_c2,c2_has_sigmoid),
                            Layer_cnn(frame_c2_size,weight_c2_size,weight_c2[3],bias_c2,study_speed_c2,c2_has_sigmoid)
                            // Layer_cnn(frame_c2_size,weight_c2_size,weight_c2[4],bias_c2,study_speed_c2,c2_has_sigmoid),
                            // Layer_cnn(frame_c2_size,weight_c2_size,weight_c2[5],bias_c2,study_speed_c2,c2_has_sigmoid)
};
for(int i = 0 ; i < layer_c2_num; i ++)
{
    delete [] weight_c2[i];
}
delete [] weight_c2;
/***************************************************c3*************************************************/
Layer_maxpooling layer_maxpooling_c3[layer_c3_num] = {
                            Layer_maxpooling(frame_c3_size,maxpooling_c3_size),
                            Layer_maxpooling(frame_c3_size,maxpooling_c3_size),
                            Layer_maxpooling(frame_c3_size,maxpooling_c3_size),
                            Layer_maxpooling(frame_c3_size,maxpooling_c3_size)
                            // Layer_maxpooling(frame_c3_size,maxpooling_c3_size),
                            // Layer_maxpooling(frame_c3_size,maxpooling_c3_size)
};


/***************************************************c4*************************************************/
for(int i = 0 ; i < layer_c4_num; i ++)
{
    weight_c4[i] = new double[weight_c4_size*weight_c4_size];
}
ifstream fweight_c4;
fweight_c4.open("weight_c4.txt");
for(int i = 0 ; i < layer_c4_num ; i++)
{
    for(int j = 0 ; j < weight_c4_size*weight_c4_size;j++)
    {
        fweight_c4 >> weight_c4[i][j];
        // std::cout<<weight_c0[i][j]<<" ";
    }
    // std::cout<<std::endl;
}
fweight_c4.close();
Layer_cnn layer_cnn_c4[layer_c4_num] = {
                            Layer_cnn(frame_c4_size,weight_c4_size,weight_c4[0],bias_c4,study_speed_c4,c4_has_sigmoid),
                            Layer_cnn(frame_c4_size,weight_c4_size,weight_c4[1],bias_c4,study_speed_c4,c4_has_sigmoid),
                            Layer_cnn(frame_c4_size,weight_c4_size,weight_c4[2],bias_c4,study_speed_c4,c4_has_sigmoid),
                            Layer_cnn(frame_c4_size,weight_c4_size,weight_c4[3],bias_c4,study_speed_c4,c4_has_sigmoid),
                            Layer_cnn(frame_c4_size,weight_c4_size,weight_c4[4],bias_c4,study_speed_c4,c4_has_sigmoid),
                            Layer_cnn(frame_c4_size,weight_c4_size,weight_c4[5],bias_c4,study_speed_c4,c4_has_sigmoid),
                            Layer_cnn(frame_c4_size,weight_c4_size,weight_c4[6],bias_c4,study_speed_c4,c4_has_sigmoid),
                            Layer_cnn(frame_c4_size,weight_c4_size,weight_c4[7],bias_c4,study_speed_c4,c4_has_sigmoid),
                            Layer_cnn(frame_c4_size,weight_c4_size,weight_c4[8],bias_c4,study_speed_c4,c4_has_sigmoid),
                            Layer_cnn(frame_c4_size,weight_c4_size,weight_c4[9],bias_c4,study_speed_c4,c4_has_sigmoid)
                            // Layer_cnn(frame_c4_size,weight_c4_size,weight_c4[4],bias_c4,study_speed_c4,c4_has_sigmoid),
                            // Layer_cnn(frame_c2_size,weight_c2_size,weight_c2[5],bias_c2,study_speed_c2,c2_has_sigmoid)
};
for(int i = 0 ; i < layer_c4_num; i ++)
{
    delete [] weight_c4[i];
}
delete [] weight_c4;
/*************************************train********************************************************/
//*************forward*************//
for(int i = 0 ; i < rounds ; i++)
{
    for(int j = 0 ; j < layer_c0_num ; j++)
    {
        layer_cnn_c0[j].layer_forward(frame_c0_size,frame_in);
    }
    for(int j = 0 ; j < layer_c1_num ; j++)
    {
        layer_maxpooling_c1[j].layer_forward(layer_cnn_c0[j].layer_output());
    }
    for(int j = 0 ; j < layer_c2_num ; j++)
    {
        layer_cnn_c2[j].layer_forward(frame_c2_size,layer_maxpooling_c1[j].layer_output());
    }
    for(int j = 0 ; j < layer_c3_num ; j++)
    {
        layer_maxpooling_c3[j].layer_forward(layer_cnn_c2[j].layer_output());
    }
    function_combine((frame_c3_size / maxpooling_c3_size),layer_c3_num,frame_c4_arr,frame_c4_out);



    for(int j = 0 ; j < layer_c4_num ; j++)
    {
        layer_cnn_c4[j].layer_forward(frame_c4_size,frame_c4_out);
    }
    for(int j = 0 ; j < layer_c4_num ; j++)
    {
        frame_softmax_in[j] = layer_cnn_c4[j].layer_output()[0][0];
    }
    std::cout<<function_softmax_out(layer_c4_num,frame_softmax_in,answer_in,delt_arr_out);
//********************backward********************//
    for(int j = 0 ; j < layer_c4_num ; j++)
    {
        layer_cnn_c4[j].layer_backward(delt_arr_out[j]);
    }
    function_spread((frame_c3_size / maxpooling_c3_size),layer_c3_num,frame_c4_arr,frame_c4_out);
    for(int j = 0 ; j < layer_c3_num ; j++)
    {
        layer_maxpooling_c3[j].layer_backward(frame_c4_arr[j]);
    }
    for(int j = 0 ; j < layer_c2_num ; j++)
    {
        layer_cnn_c2[j].layer_backward(layer_maxpooling_c3[j].layer_g_frame_output());
    }

    for(int j = 0 ; j < layer_c1_num ; j++)
    {
        layer_maxpooling_c1[j].layer_backward(layer_cnn_c2[j].layer_output());
    }
    for(int j = 0 ; j < layer_c0_num ; j++)
    {
        layer_cnn_c0[j].layer_backward(layer_maxpooling_c1[j].layer_g_frame_output());
    }












}













for(int i = 0 ; i < layer_c3_num; i++)
{
    delete []frame_c4_out[i];
}
delete []frame_c4_out;
for(int i = 0 ; i < layer_c3_num ; i++)
{
    for (int j = 0 ; j < frame_c3_size/maxpooling_c3_size; j++)
    {
        delete [] frame_c4_arr[i][j];
    }
    delete []frame_c4_arr[i];
}
delete [] frame_c4_arr;

delete []frame_softmax_in;
delete []answer_in;
for(int i = 0 ; i < layer_c4_num ; i++)
{
    for (int j = 0 ; j < 1; j++)
    {
        delete [] delt_arr_out[i][j];
    }
    delete []delt_arr_out[i];
}
delete []delt_arr_out;



}




