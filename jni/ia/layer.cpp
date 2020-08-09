#include "layer.h"
#include "sigmoid.h"
#include "relu.h"


Layer::Layer(Matrix w): i(w.cols()),o(w.rows()), w(w)
{
    _size = w.rows();
    this->activation = new Sigmoid();
    activation_type = SIGMOID;   
}

Layer::Layer(unsigned int inputSize,unsigned int outputSize) 
    : w{outputSize, inputSize},i{inputSize},o{outputSize}, alpha{0.5},_size(outputSize){
    this->activation = new Sigmoid();
    activation_type = SIGMOID;
}
Layer::Layer(const Layer &l) : w(l.w), i(l.i), o(l.o), alpha(l.alpha)
 {
    _size = l.w.rows();
    this->activation = new Sigmoid();
    this->setActivationFunction(l.activation_type);
}
void   Layer::setActivationFunction(ACTIVATION_TYPE activationType){
    activation_type = activationType;
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
    o = activation->activate(w.transpose().dot(v.append(1.0)));
    return o;
}

Vector Layer::backward(Vector e){
    Vector dedn{e*activation->derivate(o)};
    Matrix extern_prod{dedn.extern_product(i.append(1.0))};
    w = (w - extern_prod*alpha);
    Vector h{w.dot(dedn)}; 
    return h.subset(0,h.len()-2);
}

void Layer::setLearningRate(float lr){
    this->alpha = lr;
}

Matrix Layer::weight(){
    return w;
}

unsigned int Layer::size(){
    return _size;
}


Layer::~Layer(){

    delete activation;

}


void  Layer::clone(const Layer& l)
{
    w = l.w;
    i = l.i;
    o = l.o;
    alpha = l.alpha;
    _size = l.w.rows();
    delete activation;
    this->activation = new Sigmoid();
    this->setActivationFunction(l.activation_type);
}