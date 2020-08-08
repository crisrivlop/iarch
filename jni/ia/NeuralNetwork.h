
#ifndef _NEURAL_NETWORK_H
#define _NEURAL_NETWORK_H

#include <vector>
#include "layer.h"

class NeuralNetwork {
    std::vector<Layer> layers;
    unsigned int epochs;
    double threshold;

    public:

    void addLayer(unsigned int outputSize,ACTIVATION_TYPE activationType);
    void setEpochs(unsigned int);
    void setThreshold(double th);
    void train(Vector input,Vector output);
    Vector ia(Vector v);

};

#endif //_NEURAL_NETWORK_H
