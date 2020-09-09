#include <iostream>
#include "layer.h"
#include "function.h"
#include <cstdlib>


int main()
{
    using namespace std;
    srand(10);
    double wei[25];
    int bias_ = 0;

//****************************init*********************************//

    double **answer;
    answer = new double * [1];
    for(int i = 0 ; i < 1 ; i++)
    {
        answer[i] = new double [1];
    }
    for(int i = 0 ; i < 1 ; i++)
    {
        for(int j = 0 ; j < 1 ; j++)
        {
            answer[i][j] = rand()%1024;
        }
    }


    double ** g_fra;
    g_fra = new double * [1];
    for(int i = 0 ; i < 21 ; i++)
    {
        g_fra[i] = new double [1];
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
    for(int i = 0; i <25 ; i++)
    {
        wei[i] = rand()%256;
        wei[i] = wei[i]/512;
    }

    //********************************************************//
    double ** fra_in;
    fra_in  = new double *[25];
    for(int i = 0 ; i < 25 ; i++)
    {
        fra_in[i] = new double [25];
    }
    for(int i = 0 ; i < 25 ; i++)
    {
        for(int j = 0 ; j < 25 ; j++)
        {
            fra_in[i][j] = (rand()%256)/1024;
        }
    }



//************************************************************//

    Layer_cnn layer = Layer_cnn(5,5,wei,bias_,0.0003);
    for(int i = 0 ; i < 2 ; i ++)
    {
    layer.layer_forward(5,fra_in);
    layer.display();
    std::cout<<std::endl<<"loss: "<<function_loss(1,answer,layer.layer_output())<<std::endl;
    for(int i = 0 ; i < 1 ; i++)
    {
        for(int j = 0 ; j < 1 ; j++)
        {
            g_fra[i][j] = 2*(layer.layer_output()[i][j]-answer[i][j]);
            std:cout<<std::endl<<"g_fra:"<<g_fra[i][j]<<std::endl;;
        }
    }

    layer.layer_backward(g_fra);
    }
    

    for(int i = 0 ; i < 1 ; i++)
    {
        delete [] g_fra[i];
    }
    delete []g_fra;

    for(int i = 0 ; i < 1 ; i++)
    {
        delete [] answer[i];
    }
    delete []answer;

    for(int i = 0 ; i < 25 ; i++)
    {
        delete [] fra_in[i];
    }
    delete []fra_in;




}