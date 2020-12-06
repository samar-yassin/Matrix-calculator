#include <iostream>
#include "Matrix.h"
#include "MatrixCalculator.h"
using namespace std;

int main()
{
    while(true)
    {
        cout<<"Enter your matrix type:\n1-int\n2-double\n3-float\n\nEnter 'e' if you want to exit the program.\n";
        string type;
        cin>>type;
        if(type=="1")
        {
            MatrixCalculator<int> Calc;
            Calc.showMenu();
        }

        else if(type=="2")
        {
            MatrixCalculator<double> Calc;
            Calc.showMenu();
        }
        else if(type=="3")
        {
            MatrixCalculator<float> Calc;
            Calc.showMenu();
        }

        else if(type=="e"||type=="E")
            return 0;


        else
            cout<<"    -!-Something went wrong."<<endl;

    }

    return 0;
}
