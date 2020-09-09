#include <iostream>
#include "layer.h"
#include <cstdlib>


int main()
{
    using namespace std;
    srand(10);
    int fra[25],wei[25];



    int ** g_fra;
    g_fra = new int * [4];
    for(int i = 0 ; i < 4 ; i++)
    {
        g_fra[i] = new int [4];
    }
    for(int i = 0 ; i < 4 ; i++)
    {
        for(int j = 0 ; j < 4 ; j++)
        {
            g_fra[i][j] = rand()%256;
        }
    }



    for(int i = 0; i < 25 ; i++)
    {
        fra[i] = rand()%256;
    }
    for(int i = 0; i < 4 ; i++)
    {
        wei[i] = rand()%256;
    }

    Layer_cnn layer = Layer_cnn(5,2,fra,wei);
    layer.layer_forward();
    layer.display();
    layer.layer_backward(g_fra);
    

    for(int i = 0 ; i < 4 ; i++)
    {
        delete [] g_fra[i];
    }
    delete []g_fra;






}