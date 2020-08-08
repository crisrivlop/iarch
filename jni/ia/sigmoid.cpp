#include "sigmoid.h"


Sigmoid::Sigmoid(){

}
Sigmoid::Sigmoid(const Sigmoid &l){

}
Vector Sigmoid::activate(Vector v){
    return ((v*-1.0).exponential() + 1.0).inv();
}

Vector Sigmoid::derivate(Vector v){
    return v*(v*-1.0 + 1.0);
}
Sigmoid::~Sigmoid(){

}