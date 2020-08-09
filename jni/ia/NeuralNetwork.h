
#ifndef _NEURAL_NETWORK_H
#define _NEURAL_NETWORK_H

#include <vector>
#include "layer.h"

class NeuralNetwork {
    std::vector<Layer> layers;
    unsigned int epochs,max_epochs;
    float threshold;

    unsigned int inputSize, outputSize;

    public:
    NeuralNetwork(unsigned int inputSize, unsigned int outputSize);
    void addLayer(unsigned int outputSize,ACTIVATION_TYPE activationType,float learningRate);
    void addLayer(Matrix w,ACTIVATION_TYPE activationType,float learningRate);
    void setEpochs(unsigned int);
    unsigned int getMaxEpochs();
    void setThreshold(float th);
    void train(Vector input,Vector output);
    void results();
    Vector ia(Vector v);

};

#endif //_NEURAL_NETWORK_H
