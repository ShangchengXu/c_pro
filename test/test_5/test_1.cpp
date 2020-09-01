#include <iostream>
#include <fstream>



int main()
{
    using namespace std;
    ofstream f;
    int n;
    f.open("./test.txt");
    cout << "Enter number in the range 0-10" << endl;
    // do
    // {
    //     cin >> n;
    // } while (n != 7 );
    // cout << "7 is f number";
    do
    {
        cin >> n;
        switch(n)
        {
            case 1: cout << "z" <<endl;
                    f << 9 <<endl;
                    break;
            case 2: cout << "a" <<endl;
                    f << 8 <<endl;
                    break;                
            case 3: cout << "k" <<endl;
                    f << 7 <<endl;
                    break;
            default: cout << "end" <<endl;
                    f << 0 <<endl;
                    break;
        }

  

    }while(n!=7);



f.close()   ; 
ifstream k;
k.open("./test.txt");
k >> n;
cout << n;


return 0;



    
}