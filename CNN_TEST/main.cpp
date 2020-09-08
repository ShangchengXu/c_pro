#include <iostream>
#include "layer.h"
#include <cstdlib>


int main()
{
    using namespace std;
    srand(10);
    int fra[25],wei[25];
    for(int i = 0; i < 25 ; i++)
    {
        fra[i] = rand()%256;
        //wei[i] = rand()%256;
        // cout << fra[i] << " " << wei[i] << " ";
    }
    for(int i = 0; i < 4 ; i++)
    {
        wei[i] = rand()%256;
        //wei[i] = rand()%256;
        // cout << fra[i] << " " << wei[i] << " ";
    }

    Layer_cnn layer = Layer_cnn(5,2,fra,wei);
    layer.layer_forward();
    layer.display();
    






}