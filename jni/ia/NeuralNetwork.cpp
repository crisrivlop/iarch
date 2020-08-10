#include "NeuralNetwork.h"

NeuralNetwork::NeuralNetwork(unsigned int inputSize, unsigned int outputSize)
    :inputSize(inputSize), outputSize(outputSize)
{
    layers = {};
}

void NeuralNetwork::addLayer(unsigned int outputSize,ACTIVATION_TYPE activationType,float learningRate){
    unsigned lastsize = inputSize;
    if (layers.size() != 0 ){
        lastsize =layers.back().size();
    }
    Layer layer = Layer(lastsize,outputSize);
    layer.setActivationFunction(activationType);
    layer.setLearningRate(learningRate);
    layers.push_back(layer);
}

void NeuralNetwork::addLayer(Matrix w,ACTIVATION_TYPE activationType,float learningRate){
    Layer layer{w};
    layer.setActivationFunction(activationType);
    layer.setLearningRate(learningRate);
    layers.push_back(layer);
}



void NeuralNetwork::setEpochs(unsigned int eps){
    epochs = eps;
}
void NeuralNetwork::setThreshold(float th){
    threshold = th;
}
void NeuralNetwork::train(Vector input,Vector output){
    Vector current{input};

    Vector ones{input};

    for (int i=0; i < ones.len();i++) ones[i] = 1.0;
    int epoch=0;
    for (; epoch < epochs;epoch++){
        current = input;
        current = ia(current);

         float total_error = (((current-output)*(current-output))/output.len()).dot(ones);        
        
        if (total_error <= this->threshold && -this->threshold <= total_error){
            break;
        }

        //error calculation here
        Vector error = ((current-output)*2.0)/((float)output.len());

        for (int i = layers.size()-1; i >=0 ; i--){
            error = layers.at(i).backward(error);
        }
    }
    this->max_epochs = epoch;
}

unsigned int NeuralNetwork::getMaxEpochs(){
    return this->max_epochs;
}


Vector NeuralNetwork::ia(Vector v){

    Vector current = v;
    for (int i = 0; i < layers.size(); i++){
            current = layers.at(i).forward(current);
    }
    return current;
    
}


void NeuralNetwork::results(){
    for (int i = 0; i < layers.size(); i++){
        std::cout << "Layer (" << i << ") should have the following weight " << layers.at(i).weight() << endl;
    }
}