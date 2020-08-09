#include "relu.h"

Relu::Relu(){

}

Relu::~Relu(){

}

Relu::Relu(const Relu &l){

}
Vector Relu::activate(Vector v){
    return v.relu();
}

Vector Relu::derivate(Vector v){
    return v.relu_derivated();
}