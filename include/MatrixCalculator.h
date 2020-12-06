#ifndef MATRIXCALCULATOR_H
#define MATRIXCALCULATOR_H
#include "matrix.h"
#include <cstdlib>

template<typename T>
class MatrixCalculator
{
    public:
        MatrixCalculator(){}
        int showMenu(){
            while(true){
                cout<<"\nWelcome to FCAI Matrix Calculator\n\n----------------------------------------"<<endl;
                cout<<"\n1- Perform Matrix Addition\n\n2- Perform Matrix Subtraction"<<endl;
                cout<<"\n3- Perform Matrix Multiplication\n\n4- Matrix Transpose\n\nEnter 'b' if you want to change matrix type\nEnter 'e' if you want to exit the program"<<endl;
                cout<<"\nYour choice : ";
                string op;
                cin>>op;
                if(op=="e"||op=="E") exit(0);
                else if(op=="b"||op=="B") break;
                else chooseOption(op);

        }

        }
        void chooseOption(string op){

            if(op=="1"||op=="2"||op=="3"||op=="4"){
            int row,col;

            cout<<"Enter your matrix attributes:"<<endl<<"No. of rows : ";
            cin>>row;
            cout<<"No. of columns : ";
            cin>>col;
            Matrix<T> m(row,col);
            cin>>m;



            if(op=="1"){
                cout<<"Enter your second matrix values:"<<endl;
                Matrix <T>n(row,col);
                cin>>n;
                cout <<endl<<"Equal :"<<endl;
                cout<<m+n<<endl;
            }
            else if (op=="2"){

                cout<<"Enter your second matrix values:"<<endl;
                Matrix <T>n(row,col);
                cin>>n;
                cout <<endl<<"Equal :"<<endl;
                cout<<m-n<<endl;
            }
            else if (op=="3"){
                cout<<"Enter your second matrix attributes (Make sure the columns of the first matrix = rows of second one to complete the multiplication):"<<endl<<"No. of rows : ";
                cin>>row;
                cout<<"No. of columns : ";
                cin>>col;
                if(m.cols==row){
                Matrix <T>n(row,col);
                cin>>n;
                cout <<endl<<"Equal :"<<endl;
                m*n;
                }
                else cout<<"Sorry can't preform multiplication no. of cols of first one doesn't equal no. of row of second one."<<endl;
            }
            else if (op=="4"){
            cout <<endl <<"Transpose :"<<endl;
                m.transpose();
            }

            else cout<<"    -Something went wrong."<<endl;

        }

            else cout<<"    -Something went wrong."<<endl;

        }


};

#endif // MATRIXCALCULATOR_H
