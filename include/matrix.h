#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
using namespace std;
template<typename T>
class Matrix{

public :
    T **p;
    int rows;
    int cols;


    Matrix(){
        this->rows =1;
        this->cols=1;
        this->reserve();
    }
    Matrix(int r ,int c){
    this->rows=r;
    this->cols=c;
    this->reserve();
    }
    ~Matrix(){
    for(int i=0;i<rows ;i++){
            delete []p[i];
    }

    delete[]p;
    }

    void reserve(){
        p = new T*[rows];
        for(int i=0 ; i<rows ;i++){
             p[i] = new T[cols];
        }
    }

friend ostream& operator <<(ostream&op, const Matrix<T>&m){
    for(int i=0;i<m.rows ;i++){
    for(int j=0;j<m.cols;j++){
        op<<m.p[i][j];
        cout<<"  ";
    }
    cout<<endl;
    }
    return op;
}
friend istream& operator >>(istream&in, Matrix<T>&m){

int r=1 , c=0;
for(int i=0;i<m.rows ;i++){
    for(int j=0;j<m.cols;j++){
        cout<<"Enter element (row : "<<r<<" ,col : "<<++c<<" )"<<endl;
        in>>m.p[i][j];
    }

    cout<<"-----------"<<endl;
r++;
c=0;
}


return in;
}

Matrix transpose(){

    Matrix res(cols,rows);

    for(int i=0;i<rows ;i++){
    for(int j=0;j<cols;j++){
        res.p[j][i]=p[i][j];
    }}
    cout<<res;
    return res;
}

Matrix &operator +(Matrix<T>&m){

    for(int i=0;i<m.rows ;i++){
    for(int j=0;j<m.cols;j++){
        m.p[i][j]+=this->p[i][j];
    }}



    return m;
}

Matrix &operator -(Matrix<T>&m){

    for(int i=0;i<rows ;i++){
    for(int j=0;j<cols;j++){
        this->p[i][j]-=m.p[i][j];
    }}



    return *this;
}
Matrix &operator =(Matrix<T>&m){

    for(int i=0;i<m.rows ;i++){
    for(int j=0;j<m.cols;j++){
            p[i][j]=m.p[i][j];
    }
    }


}
Matrix<T> &operator *(const Matrix<T>&m){

    Matrix result(rows,m.cols);
    for(int i = 0; i < rows ; ++i){
        for(int j = 0; j < m.cols; ++j){
                double sum=0;
            for(int k = 0; k < cols; ++k)
            {
                sum += p[i][k] * m.p[k][j];
            }
            result.p[i][j]=sum;
            }
            }

        cout<<result;



}

};
#endif // MATRIX_H
