#include "layer.h"
#include "sigmoid.h"
#include "relu.h"

Layer::Layer(unsigned int inputSize,unsigned int outputSize) 
    : w{outputSize, inputSize},i{inputSize},o{outputSize}, alpha{0.5},_size(outputSize){
}
Layer::Layer(const Layer &l){

}
void   Layer::setActivationFunction(ACTIVATION_TYPE activationType){
    delete this->activation;
    switch (activationType)
    {
    case SIGMOID:
        this->activation = new Sigmoid();
        break;
    case RELU:
        this->activation = new Relu();
        break;
    default:
        this->activation = new Sigmoid();
        break;
    }

}

Vector Layer::forward(Vector v){
    i = v;
    o = activation->activate(w.dot(v));
    return o;
}

Vector Layer::backward(Vector v){
    return o;
}

Matrix Layer::weight(){
    return w;
}

unsigned int Layer::size(){
    return _size;
}


Layer::~Layer(){

}