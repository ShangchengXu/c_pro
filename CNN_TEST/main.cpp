#include <iostream>
#include "layer.h"
#include "function.h"
#include <cstdlib>


int main()
{
    using namespace std;
    srand(10);
    int wei[25];
    int bias_ = 10;



    int **answer;
    answer = new int * [21];
    for(int i = 0 ; i < 21 ; i++)
    {
        answer[i] = new int [21];
    }
    for(int i = 0 ; i < 21 ; i++)
    {
        for(int j = 0 ; j < 21 ; j++)
        {
            answer[i][j] = rand()%256;
        }
    }


    int ** g_fra;
    g_fra = new int * [25];
    for(int i = 0 ; i < 25 ; i++)
    {
        g_fra[i] = new int [25];
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
    for(int i = 0; i < 4 ; i++)
    {
        wei[i] = rand()%256;
    }

    //********************************************************//
    int ** fra_in;
    fra_in  = new int *[25];
    for(int i = 0 ; i < 25 ; i++)
    {
        fra_in[i] = new int [25];
    }
    for(int i = 0 ; i < 4 ; i++)
    {
        for(int j = 0 ; j < 4 ; j++)
        {
            fra_in[i][j] = rand()%256;
        }
    }





    Layer_cnn layer = Layer_cnn(5,2,wei,bias_,0.01);
    for(int i = 0 ; i < 20 ; i ++)
    {
    layer.layer_forward(25,fra_in);
    //layer.display();
    std::cout<<std::endl<<"loss: "<<function_loss(4,answer,layer.layer_output())<<std::endl;
    for(int i = 0 ; i < 4 ; i++)
    {
        for(int j = 0 ; j < 4 ; j++)
        {
            g_fra[i][j] = function_loss(4,answer,layer.layer_output());
        }
    }

    layer.layer_backward(g_fra);
    }
    

    for(int i = 0 ; i < 4 ; i++)
    {
        delete [] g_fra[i];
    }
    delete []g_fra;

    for(int i = 0 ; i < 4 ; i++)
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