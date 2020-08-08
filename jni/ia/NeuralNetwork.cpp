#include "NeuralNetwork.h"


void NeuralNetwork::addLayer(unsigned int outputSize,ACTIVATION_TYPE activationType){
    unsigned lastsize = 0;
    if (layers.size() != 0 ){
        lastsize =layers.back().size();
    }
    Layer layer = Layer(lastsize,outputSize);
    layer.setActivationFunction(activationType);
    layers.push_back(layer);
}
void NeuralNetwork::setEpochs(unsigned int eps){
    epochs = eps;
}
void NeuralNetwork::setThreshold(double th){
    threshold = th;
}
void NeuralNetwork::train(Vector input,Vector output){
    Vector current = input;
    for (int epoch; epoch < epochs;epoch++){
        for (int i = 0; i < layers.size(); i++){
            current = layers.at(i).forward(current);
        }

        //error calculation here
        current = ((output - current)*2.0)/((double)output.len());

        for (int i = layers.size()-1; i >=0 ; i--){
            current = layers.at(i).backward(current);
        }
    }


}
Vector NeuralNetwork::ia(Vector v){

    Vector current = v;
    for (int i = 0; i < layers.size(); i++){
        current = layers.at(i).forward(current);
    }
    return current;
    
}