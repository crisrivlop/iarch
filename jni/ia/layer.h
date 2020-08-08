#ifndef _LAYER_H_
#define _LAYER_H_

#include "../math/matrix.h"
#include "../math/iavector.h"
#include "activation.h"



class Layer{
        Activation * activation;
        Matrix w; //weight vector
        Vector o; //output vector
        Vector i; //input vector
        double alpha; //learning rate
        unsigned int _size;
    public:
        Layer(unsigned int inputSize,unsigned int outputSize);
        Layer(const Layer &l);
        void setActivationFunction(ACTIVATION_TYPE activationType);
        void setLearningRate(double lr);
        Matrix weight();
        Vector forward(Vector v);
        Vector backward(Vector v);
        unsigned int size();
        ~Layer();
};


#endif //_LAYER_H_