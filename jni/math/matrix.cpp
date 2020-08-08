#include "matrix.h"
#include "iavector.h"
#include <iostream>

Matrix::Matrix(unsigned int rows, unsigned int cols){

    this->_rows = rows;
    this->_cols = cols;
    this->_data = new double*[rows]();
    for (int i = 0; i < rows; ++i)
        this->_data[i] = new double[cols];
}

Matrix::Matrix() : _rows(0),_cols(0),_data(0){
}

Matrix::Matrix(const Matrix& m){

    this->_rows = m._rows;
    this->_cols = m._cols;
    this->_data = new double*[m._rows]();
    for (int i = 0; i < m._rows; ++i){
        this->_data[i] = new double[m._cols];
        for(int j = 0; j < m._rows; ++j)
            this->_data[i][j] = m._data[i][j];
    }
        
            

}



Matrix::~Matrix(){
    for (int i = 0; i < this->_rows; ++i)
        delete [] this->_data[i];
    delete [] this->_data;
};



Matrix Matrix::add(const Matrix& b){
    Matrix m{this->_rows,this->_cols};

    for (int i = 0; i < this->_rows; i++)
        for (int j = 0; j < this->_cols; j++)
            m._data[i][j] = this->_data[i][j] + b._data[i][j];
    return m;
}


Matrix Matrix::sub(const Matrix& b){
    Matrix m{this->_rows,this->_cols};

    for (int i = 0; i < this->_rows; i++)
        for (int j = 0; j < this->_cols; j++)
            m._data[i][j] = this->_data[i][j] - b._data[i][j];
    return m;
}

Matrix Matrix::mul(const Matrix& b){
    Matrix m{this->_rows,this->_cols};

    for (int i = 0; i < this->_rows; i++)
        for (int j = 0; j < this->_cols; j++)
            m._data[i][j] = this->_data[i][j] * b._data[i][j];
    return m;
}


Matrix Matrix::mul(const double& b){
    Matrix m{this->_rows,this->_cols};

    for (int i = 0; i < this->_rows; i++)
        for (int j = 0; j < this->_cols; j++)
            m._data[i][j] = this->_data[i][j] * b;
    return m;
}

Vector Matrix::dot(const Vector& b){
    unsigned int len = b.len();
    Vector v{len};
    Vector tmp{len};

    for (int i = 0; i < this->_cols; i++){
        for (int j = 0; j < this->_rows; j++)
            tmp[j] = this->_data[j][i];
        v += (tmp * b);
    }
    return v;
}

void Matrix::print(){
    for (int i = 0; i < this->_rows; i++){
        for (int j = 0; j < this->_cols; j++){
            std::cout << this->_data[i][j] << "\t";
        }
        std::cout << std::endl;
    }

}


ostream& Matrix::print(ostream& os, Matrix const & v){

    os << std::endl << "[";
    for (int i = 0; i < v._rows; i++){
        if(i != 0)os << " ";
        for (int j = 0; j < v._cols; j++){
            os << v._data[i][j];
            if(j+1 != v._cols)os << ",\t";
        }

        if(i+1 == v._rows)os << "]";
        
        os << std::endl;
    }
    return os;
}

