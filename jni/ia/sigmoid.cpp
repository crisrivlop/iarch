#include "sigmoid.h"


Sigmoid::Sigmoid(){

}
Sigmoid::Sigmoid(const Sigmoid &l){

}
Vector Sigmoid::activate(Vector v){
    return ((v*-1.0f).exponential() + 1.0f).inv();
}

Vector Sigmoid::derivate(Vector v){
    return v*(v*-1.0f + 1.0f);
}
Sigmoid::~Sigmoid(){

}