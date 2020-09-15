#include "cnn_net.h"
#include <iostream>
#include <string>
#include "function.h"
#include "layer.h"
#include <fstream>
 

void net_tran()
{

using namespace std;
//*****************************init*************************************//
double ** frame_in;
double * answer_in;
 int frame_in_size = 28;
 int answer_in_size = 10;
answer_in = new double [answer_in_size];
frame_in = new double *[frame_in_size];
for(int i = 0;i < frame_in_size ; i++)
{
    frame_in[i] = new double [frame_in_size];
}
 
ifstream fid_frame_in,fid_answer_in;
fid_frame_in.open("train_image.txt");
fid_answer_in.open("train_lable.txt");
// std::cout<<function_input(frame_in_size,fid_frame_in, fid_answer_in,frame_in,answer_in);
function_input(frame_in_size,fid_frame_in, fid_answer_in,frame_in,answer_in);
//*****************************config*************************************//
const int train_rounds = 2;
const int test_rounds = 00;
const int rounds = 100;
const int frame_c0_size = frame_in_size;
const int weight_c0_size = 5;
const int weight_c2_size = 5;
const int weight_c4_size = 4;
const int c0_has_sigmoid = 0;
const int c2_has_sigmoid = 0;
const int c4_has_sigmoid = 0;
const int maxpooling_c1_size = 2;
const int maxpooling_c3_size = 4;
const int frame_c1_size = frame_c0_size - weight_c0_size + 1;
const int frame_c2_size = frame_c1_size / maxpooling_c1_size;
const int frame_c3_size = frame_c2_size - weight_c2_size + 1;
const int frame_c4_size = (frame_c3_size / maxpooling_c3_size)*(frame_c3_size / maxpooling_c3_size);
const double bias_c0 = 0;
const double bias_c2 = 0.1;
const double bias_c4 = 0.1;
const int layer_c0_num = 4;
const int layer_c1_num = 4;
const int layer_c2_num = 4;
const int layer_c3_num = 4;
const int layer_c4_num = 10;
const double study_speed_c0 = 0.01;
const double study_speed_c2 = 0.01;
const double study_speed_c4 = 0.01;
double ** weight_c0;
double ** weight_c2;
double ** weight_c4;
double *** frame_c4_arr;
double ** frame_c4_out;
double * frame_softmax_in;
// double * answer_in;
double *** delt_arr_out;
frame_softmax_in = new double [layer_c4_num];
// answer_in = new double [layer_c4_num];
frame_c4_arr = new double **[layer_c3_num];
for(int i = 0 ; i < layer_c3_num ; i++)
{
    frame_c4_arr[i] = new double *[frame_c3_size/maxpooling_c3_size];
    for(int j = 0 ; j < frame_c3_size/maxpooling_c3_size; j++)
    {
        frame_c4_arr[i][j] = new double [frame_c3_size/maxpooling_c3_size];
    }
}
delt_arr_out = new double **[layer_c4_num];
for(int i = 0 ; i < layer_c4_num; i++)
{
    delt_arr_out[i] = new double *[1];
    for(int j = 0 ; j < 1; j++)
    {
       delt_arr_out[i][j] = new double [1]; 
    }
}


frame_c4_out = new double *[layer_c3_num];
for(int j = 0 ; j < layer_c3_num ; j++)
    {
        frame_c4_out[j] = new double [(frame_c3_size/maxpooling_c3_size)*(frame_c3_size/maxpooling_c3_size)];
    }

// for(int i = 0 ; i < layer_c4_num ; i++)
// {
//     frame_c4_arr[i] = new double *[1];
//     for(int j = 0 ; j < 1; j++)
//     {
//         frame_c4_arr[i][j] = new double [1];
//     }
// }



// std::cout<<"111";
// weight_c0 = function_new_double(weight_c0_size*weight_c0_size);
weight_c0 = new double*[layer_c0_num];
for(int i = 0 ; i < layer_c0_num; i++)
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
// //******************************c0**********************************//
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



//******************************c2**********************************//
weight_c2 = new double *[layer_c2_num];
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
weight_c4 = new double * [layer_c4_num];
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
for(int m = 0 ; m < train_rounds ; m++)
{
function_input(frame_in_size,fid_frame_in, fid_answer_in,frame_in,answer_in);
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
    for(int j = 0 ; j < layer_c3_num ; j++)
    {
        for(int k = 0 ; k < (frame_c3_size / maxpooling_c3_size) ; k++)
        {
            for(int l = 0 ; l < (frame_c3_size / maxpooling_c3_size) ; l++)
            {
                frame_c4_arr[j][k][l] = layer_maxpooling_c3[j].layer_output()[k][l];
            }
        }
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

    std::cout<<function_softmax_out(layer_c4_num,frame_softmax_in,answer_in,delt_arr_out,1)<<std::endl;
    // function_softmax_out(layer_c4_num,frame_softmax_in,answer_in,delt_arr_out,0);
// ********************backward********************//
    for(int j = 0 ; j < layer_c4_num ; j++)
    {
        layer_cnn_c4[j].layer_backward(delt_arr_out[j]);
        // layer_cnn_c4[j].display();
    }
    for(int j = 0 ; j < (frame_c3_size / maxpooling_c3_size)*(frame_c3_size / maxpooling_c3_size);j++)
    {
       for(int k = 0 ; k < (frame_c3_size / maxpooling_c3_size)*(frame_c3_size / maxpooling_c3_size);k++) 
       {    
           frame_c4_out[j][k] = 0;

           for(int g = 0 ; g < layer_c4_num; g++)
           {
               frame_c4_out[j][k] +=  layer_cnn_c4[g].layer_g_frame_output()[j][k];
           }
       }
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
        // function_display()
        layer_maxpooling_c1[j].layer_backward(layer_cnn_c2[j].layer_g_frame_output());
    }
    for(int j = 0 ; j < layer_c0_num ; j++)
    {
        layer_cnn_c0[j].layer_backward(layer_maxpooling_c1[j].layer_g_frame_output());
    }


}


}


//******************************************test***************************//
ifstream fid_frame_test_in,fid_answer_test_in;
fid_frame_test_in.open("test_image.txt");
fid_answer_test_in.open("test_lable.txt");
double sum = 0;
for(int i = 0 ; i < test_rounds ; i++)
{
   function_input(frame_in_size,fid_frame_test_in, fid_answer_test_in,frame_in,answer_in);
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
    for(int j = 0 ; j < layer_c3_num ; j++)
    {
        for(int k = 0 ; k < (frame_c3_size / maxpooling_c3_size) ; k++)
        {
            for(int l = 0 ; l < (frame_c3_size / maxpooling_c3_size) ; l++)
            {
                frame_c4_arr[j][k][l] = layer_maxpooling_c3[j].layer_output()[k][l];
            }
        }
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

    // std::cout<<function_softmax_out(layer_c4_num,frame_softmax_in,answer_in,delt_arr_out)<<std::endl;
    sum += function_softmax_out(layer_c4_num,frame_softmax_in,answer_in,delt_arr_out,1);

}
// std::cout<<sum/test_rounds;

 


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
// delete []answer_in;
for(int i = 0 ; i < layer_c4_num ; i++)
{
    for (int j = 0 ; j < 1; j++)
    {
        delete [] delt_arr_out[i][j];
    }
    delete []delt_arr_out[i];
}
delete []delt_arr_out;

for(int i = 0 ; i < frame_in_size; i++)
{
    delete []frame_in[i];
}
delete [] frame_in;
delete [] answer_in;

fid_frame_in.close();
fid_answer_in.close();
fid_frame_test_in.close();
fid_answer_test_in.close();


}




