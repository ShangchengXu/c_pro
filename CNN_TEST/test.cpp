#include <iostream>
#include "layer.h"
#include "function.h"
#include <cstdlib>
#include "test.h"
#include <fstream>

void layer_cnn_test()
{

using namespace std;
    srand(10);
    ifstream fid_weight;
    fid_weight.open("weight_c0.txt");
    
    double bias_ = 0;

//****************************init*********************************//
    int fra_in_size = 16;
    int wei_size = 4;
    int g_fra_size = fra_in_size - wei_size + 1;
    int fra_out_size = fra_in_size - wei_size + 1;
    int answer_size = fra_in_size - wei_size + 1;
    
//****************************init*********************************//
    double * wei = new double[wei_size*wei_size];
    double **answer;
    answer = new double * [answer_size];
    for(int i = 0 ; i < answer_size ; i++)
    {
        answer[i] = new double [answer_size];
    }
    for(int i = 0 ; i < answer_size ; i++)
    {
        for(int j = 0 ; j < answer_size ; j++)
        {
            answer[i][j] = rand()%256;
            answer[i][j] = answer[i][j]/256;
            // answer[i][j] = 0.222;
        }
    }


    double ** g_fra;
    g_fra = new double * [g_fra_size];
    for(int i = 0 ; i < g_fra_size ; i++)
    {
        g_fra[i] = new double [g_fra_size];
    }
    // for(int i = 0 ; i < 4 ; i++)
    // {
    //     for(int j = 0 ; j < 4 ; j++)
    //     {
    //         g_fra[i][j] = rand()%256;
    //     }
    // }



    // for(int i = 0; i < 25 ; i++)
    // {
    //     fra[i] = rand()%256;
    // }
    for(int i = 0; i <wei_size*wei_size ; i++)
    {
        // wei[i] = rand()%256;
        fid_weight >> wei[i];
        // std::cout << wei[i]<<"  "<< std::endl;
        // wei[i] = wei[i]/512;
    }

    //********************************************************//
    double ** fra_in;
    fra_in  = new double *[fra_in_size];
    for(int i = 0 ; i < fra_in_size ; i++)
    {
        fra_in[i] = new double [fra_in_size];
    }
    for(int i = 0 ; i < fra_in_size ; i++)
    {
        for(int j = 0 ; j < fra_in_size ; j++)
        {
            fra_in[i][j] = (rand()%256);
            fra_in[i][j] = fra_in[i][j]/256;
        }
    }



//************************************************************//

    Layer_cnn layer = Layer_cnn(fra_in_size,wei_size,wei,bias_,0.1,1);
    // layer.display();
    for(int i = 0 ; i < 1; i ++)
    {
    layer.layer_forward(fra_in_size,fra_in);
    layer.display();
    std::cout<<std::endl<<"loss: "<<function_loss(fra_out_size,answer,layer.layer_output())<<std::endl;
    for(int i = 0 ; i < g_fra_size ; i++)
    {
        for(int j = 0 ; j < g_fra_size ; j++)
        {
            g_fra[i][j] = (2*(layer.layer_output()[i][j]-answer[i][j]))/(g_fra_size*g_fra_size);
            //  std:cout<<std::endl<<"g_fra:"<<g_fra[i][j]<<std::endl;
        }
    }
    function_display(g_fra_size,g_fra,"g_fra:");
    layer.layer_backward(g_fra);
    }
    std::cout<<std::endl<<"loss: "<<function_loss(fra_out_size,answer,layer.layer_output())<<std::endl;
    layer.display();
    function_display(answer_size,answer,"answer:");
    

    for(int i = 0 ; i < fra_in_size ; i++)
    {
        delete [] g_fra[i];
    }
    delete []g_fra;

    for(int i = 0 ; i < answer_size ; i++)
    {
        delete [] answer[i];
    }
    delete []answer;

    for(int i = 0 ; i < fra_in_size ; i++)
    {
        delete [] fra_in[i];
    }
    delete []fra_in;

    delete [] wei;


};

void max_pooling_test()
{   
    int frame_size  = 6;
    int pooling_size = 2;
    int frame_out_size = frame_size/pooling_size;
    double ** frame;
    double ** frame_out;
    int ** frame_out_pos;

    // std::cout<<"54545454545";
    frame = function_new_double(frame_size);
    function_init(frame_size,frame);
    
    frame_out = function_new_double(frame_out_size);
    function_init(frame_out_size,frame_out);

    frame_out_pos = function_new_int(frame_out_size);
    // function_init(frame_out_size,frame_out_pos);
    function_display(frame_size,frame,"frame:");
    function_display(frame_out_size,frame_out,"frame_out:");
    function_display(frame_out_size,frame_out_pos,"frame_out_pos:");

    function_maxpooling(frame_size,pooling_size,frame,frame_out,frame_out_pos);
    function_display(frame_size,frame,"frame:");
    function_display(frame_out_size,frame_out,"frame_out:");
    function_display(frame_out_size,frame_out_pos,"frame_out_pos:");
    



















    
    function_delete(frame_size,frame);
    function_delete(frame_out_size,frame_out);
    function_delete(frame_out_size,frame_out_pos);



};



void layer_maxpooling_test()
{
    int frame_size  = 6;
    int pooling_size = 2;
    int frame_out_size = frame_size/pooling_size;
    double ** frame;
    // double ** frame_out;
    // int ** frame_out_pos;

    // std::cout<<"54545454545";
    frame = function_new_double(frame_size);
    function_init(frame_size,frame);
    
    // frame_out = function_new_double(frame_out_size);
    // function_init(frame_out_size,frame_out);

    // frame_out_pos = function_new_int(frame_out_size);


    Layer_maxpooling layer_maxpooling = Layer_maxpooling(frame_size,pooling_size);
    layer_maxpooling.layer_forward(frame);
    layer_maxpooling.layer_backward(layer_maxpooling.layer_output());
    layer_maxpooling.display();

    function_delete(frame_size,frame);


}