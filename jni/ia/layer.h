#ifndef _LAYER_H_
#define _LAYER_H_

#include "../math/matrix.h"
#include "../math/iavector.h"
#include "activation.h"



class Layer{
        Activation * activation = 0;
        Matrix w; //weight vector
        Vector o; //output vector
        Vector i; //input vector
        float alpha; //learning rate
        unsigned int _size;
        ACTIVATION_TYPE activation_type;
        void clone(const Layer& b);
    public:
        Layer(unsigned int inputSize,unsigned int outputSize);
        Layer(Matrix w);
        Layer(const Layer &l);
        void setActivationFunction(ACTIVATION_TYPE activationType);
        void setLearningRate(float lr);
        Matrix weight();
        Vector forward(Vector v);
        Vector backward(Vector v);
        unsigned int size();
        void operator=(const Layer& b){this->clone(b);};
        ~Layer();
};


#endif //_LAYER_H_