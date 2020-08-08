#include "iavector.h"
#include "matrix.h"

#include <iostream>
#include <exception>
#include <cmath>

using namespace std;

Vector::Vector(unsigned int size){
    this->_size = size;
    this->_data = new double[size];
};

Vector::Vector() : _size(0),_data(0){
};


Vector::~Vector(){
    delete [] this->_data;
};

unsigned int Vector::len() const{
    return this->_size;
};

Vector Vector::subset(unsigned int i, unsigned int f){
    if (f < i || f > this->_size){
        throw new exception();
    }
    Vector v{f-i+1};
    for (int j = 0; j <= f-i; j++){
        v._data[j] = this->_data[i+j];
    }
    return v;
}


Vector Vector::add(const Vector& b){
    Vector v{this->_size};

    for (int i = 0; i < this->_size; i++){
        v._data[i] = this->_data[i] + b._data[i];
    }
    return v;
}

Vector Vector::add(const double& b){
    Vector v{this->_size};

    for (int i = 0; i < this->_size; i++){
        v._data[i] = this->_data[i] + b;
    }
    return v;
}

void Vector::addi(const Vector& b){

    for (int i = 0; i < this->_size; i++){
        this->_data[i] = this->_data[i] + b._data[i];
    }
}


Vector Vector::sub(const Vector& b){
    Vector v{this->_size};

    for (int i = 0; i < this->_size; i++){
        v._data[i] = this->_data[i] - b._data[i];
    }
    return v;
}

Vector Vector::sub(const double& b){
    Vector v{this->_size};

    for (int i = 0; i < this->_size; i++){
        v._data[i] = this->_data[i] - b;
    }
    return v;
}


Vector Vector::mul(const Vector& b){
    Vector v{this->_size};

    for (int i = 0; i < this->_size; i++){
        v._data[i] = this->_data[i] * b._data[i];
    }
    return v;
}


Vector Vector::mul(const double& b){
    Vector v{this->_size};

    for (int i = 0; i < this->_size; i++){
        v._data[i] = this->_data[i] * b;
    }
    return v;
}


Vector Vector::div(const Vector& b){
    Vector v{this->_size};
    for (int i = 0; i < this->_size; i++){
        v._data[i] = this->_data[i] * b._data[i];
    }
    return v;
}


Vector Vector::div(const double& b){
    Vector v{this->_size};
    for (int i = 0; i < this->_size; i++){
        v._data[i] = this->_data[i] / b;
    }
    return v;
}


Vector Vector::inv(){
    Vector v{this->_size};
    for (int i = 0; i < this->_size; i++){
        v._data[i] = 1/this->_data[i];
    }
    return v;
}

ostream& Vector::print(ostream& os, Vector const & v){
    int i;
    os << "[";
    for (i = 0; i < v._size-1; i++){
        os << v._data[i] << ", ";
    } 
    os << v._data[i] << "]\n";
    return os;
}


double Vector::dot(const Vector& b){
    double r = 0;
    for (int i = 0; i < this->_size; i++){
        r += this->_data[i] * b._data[i];
    }
    return r;
}

Vector::Vector(const Vector &v){
    this->_size = v._size;
    this->_data = new double[v._size];
    for (int i = 0; i < this->_size; i++){
        this->_data[i] = v._data[i];
    }
}


Matrix Vector::extern_product(const Vector& b){
    Matrix m{b._size,this->_size};

    for(int i = 0; i < b._size;i++){
        for(int j = 0; j < this->_size;j++){
            m.set(i,j,this->_data[j]*b._data[i]);
        }
    }
    return m;
}


Vector Vector::exponential(){
    Vector v{this->_size};
    for (int i = 0; i < this->_size; i++){
        v._data[i] = exp(this->_data[i]);
    }
    return v;
}



Vector Vector::absolute(){
    Vector v{this->_size};
    for (int i = 0; i < this->_size; i++){
        v._data[i] = abs(this->_data[i]);
    }
    return v;
}