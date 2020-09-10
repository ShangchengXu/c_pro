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
int frame_c0_size = 28;
int weight_c0_size = 5;
int weight_c2_size = 5;
int c0_has_sigmoid = 0;
int c2_has_sigmoid = 1;
int maxpooling_c1_size = 2;
int frame_c1_size = frame_c0_size - weight_c0_size + 1;
int frame_c2_size = frame_c1_size / maxpooling_c1_size;
double bias_c0 = 0;
const int layer_c0_num = 6;
const int layer_c1_num = 6;
const int layer_c2_num = 6;
double study_speed_c0 = 0.1;
double study_speed_c2 = 0.1;
double ** weight_c0;
double ** weight_c2;
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
Layer_cnn layer_cnn_c1[layer_c0_num] = {
                            Layer_cnn(frame_c0_size,weight_c0_size,weight_c0[0],bias_c0,study_speed_c0,c0_has_sigmoid),
                            Layer_cnn(frame_c0_size,weight_c0_size,weight_c0[1],bias_c0,study_speed_c0,c0_has_sigmoid),
                            Layer_cnn(frame_c0_size,weight_c0_size,weight_c0[2],bias_c0,study_speed_c0,c0_has_sigmoid),
                            Layer_cnn(frame_c0_size,weight_c0_size,weight_c0[3],bias_c0,study_speed_c0,c0_has_sigmoid),
                            Layer_cnn(frame_c0_size,weight_c0_size,weight_c0[4],bias_c0,study_speed_c0,c0_has_sigmoid),
                            Layer_cnn(frame_c0_size,weight_c0_size,weight_c0[5],bias_c0,study_speed_c0,c0_has_sigmoid)
};

for(int i = 0 ; i < layer_c0_num; i ++)
{
    delete [] weight_c0[i];
}
delete [] weight_c0;
//******************************c1**********************************//
Layer_maxpooling layer_maxpooling[layer_c1_num] = {
                            Layer_maxpooling(frame_c1_size,maxpooling_c1_size),
                            Layer_maxpooling(frame_c1_size,maxpooling_c1_size),
                            Layer_maxpooling(frame_c1_size,maxpooling_c1_size),
                            Layer_maxpooling(frame_c1_size,maxpooling_c1_size),
                            Layer_maxpooling(frame_c1_size,maxpooling_c1_size),
                            Layer_maxpooling(frame_c1_size,maxpooling_c1_size)
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
fweight_c0.close();
Layer_cnn layer_cnn_c2[layer_c2_num] = {
                            Layer_cnn(frame_c2_size,weight_c2_size,weight_c2[0],bias_c0,study_speed_c2,c2_has_sigmoid),
                            Layer_cnn(frame_c2_size,weight_c2_size,weight_c2[1],bias_c0,study_speed_c2,c2_has_sigmoid),
                            Layer_cnn(frame_c2_size,weight_c2_size,weight_c2[2],bias_c0,study_speed_c2,c2_has_sigmoid),
                            Layer_cnn(frame_c2_size,weight_c2_size,weight_c2[3],bias_c0,study_speed_c2,c2_has_sigmoid),
                            Layer_cnn(frame_c2_size,weight_c2_size,weight_c2[4],bias_c0,study_speed_c2,c2_has_sigmoid),
                            Layer_cnn(frame_c2_size,weight_c2_size,weight_c2[5],bias_c0,study_speed_c2,c2_has_sigmoid)
};
for(int i = 0 ; i < layer_c2_num; i ++)
{
    delete [] weight_c2[i];
}
delete [] weight_c2;












}




