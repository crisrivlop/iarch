
#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <iostream>
#include "iavector.h"
using namespace std;


class Matrix {
        double ** _data;
        unsigned int _rows;
        unsigned int _cols;
        Matrix add(const Matrix& b);
        Matrix sub(const Matrix& b);
        Matrix mul(const Matrix& b);
        Matrix mul(double b);
        Matrix div(const Matrix& b);
        static ostream& print(ostream& os, Matrix const & v);
        void clone(const Matrix& b);

    public:
        Matrix(unsigned int rows, unsigned int cols);
        Matrix(const Matrix& m);
        Matrix();
        
        double& get(unsigned int i,unsigned int j) {return this->_data[i][j];};
        void set(unsigned int i,unsigned int j,double data) {this->_data[i][j] = data;};
        Matrix subset(unsigned int i, unsigned int f);
        Matrix operator+(const Matrix& b){return this->add(b);};
        Matrix operator-(const Matrix& b){return this->sub(b);};
        Matrix operator*(const Matrix& b){return this->mul(b);};
        Matrix operator*(double b){return this->mul(b);};
        Matrix operator/(const Matrix& b){return this->div(b);};
        Matrix operator<<(const Matrix& b){return this->div(b);};
        void   operator=(const Matrix& b){this->clone(b);};
        friend ostream& operator<<(ostream& os, Matrix const & m){return m.print(os,m);};

        
        Matrix dotm(const Matrix& b);
        Vector dot(const Vector& b);

        unsigned int cols() const;
        unsigned int rows() const;

        Matrix transpose();

        void print();

        ~Matrix();
};

#endif //_MATRIX_H_