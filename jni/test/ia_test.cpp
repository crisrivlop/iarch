#include <omp.h>

#include "ia_test.h"
#include "../ia/NeuralNetwork.h"


void train_test(unsigned int size,int epochs, float th, int testingIterations){
    NeuralNetwork nn{size,size};

    
    nn.addLayer(size,SIGMOID,0.5);
    nn.addLayer(size,SIGMOID,0.5);
    nn.addLayer(size,SIGMOID,0.5);
    nn.setEpochs(epochs);
    nn.setThreshold(th);

    Vector  trainIn{size};
    Vector trainOut{size};
    Matrix w{trainIn.extern_product(trainOut)};


    double start_time, run_time;
    for (int j = 0 ; j < testingIterations; j++){
        run_time = 0;
        start_time = omp_get_wtime();
        nn.train(trainIn,trainOut);
        run_time += omp_get_wtime() - start_time;
        std::cout << "(" << j << ")" << " Vector size is: " << size<< " - Training time: " << run_time  << endl;
    }

}

void forward_test(unsigned int  size,int epochs, float th, int layerNumber){
    NeuralNetwork nn{size,size};
    
    for (int i = 0 ; i < layerNumber; i++)
        nn.addLayer(size,SIGMOID,0.5);
    nn.setEpochs(epochs);
    nn.setThreshold(th);

    Vector  trainIn{size};
    Vector trainOut{size};
    Matrix w{trainIn.extern_product(trainOut)};


    double start_time, run_time;
    run_time = 0;
    start_time = omp_get_wtime();
    nn.ia(trainIn);
    run_time += omp_get_wtime() - start_time;
    std::cout << " Vector size is: " << size << ", Calculation time: " << run_time << " #layer" << layerNumber << endl;

}

void stress_layer_count_test(){
    forward_test(1000, 100, 0.0001f, 5+4);
    forward_test(1000, 100, 0.0001f, 5+5);
    forward_test(1000, 100, 0.0001f, 5+6);
    forward_test(1000, 100, 0.0001f, 5+7);
    forward_test(1000, 100, 0.0001f, 5+8);
}

//stressing forward by layer len
void stress_layer_len_test(){
    forward_test(   10, 100, 0.0001f, 10);
    forward_test(  100, 100, 0.0001f, 10);
    forward_test( 1000, 100, 0.0001f, 10);
    forward_test( 2000, 100, 0.0001f, 10);
    forward_test( 5000, 100, 0.0001f, 10);
}



void stress_layer_len_and_layer_count_test(){
    forward_test(   10, 100, 0.0001f, 6+4);
    forward_test(  100, 100, 0.0001f, 6+5);
    forward_test( 1000, 100, 0.0001f, 6+6);
    forward_test( 2000, 100, 0.0001f, 6+7);
    forward_test( 5000, 100, 0.0001f, 6+8);
}



void ia_example(){
    float weightA[3][2] = {{0.1500f, 0.2500f},{0.2000f, 0.3000f},{0.3500f, 0.3500f}};
    float weightB[3][2] = {{0.4000f, 0.5000f},{0.4500f, 0.5500f},{0.6000f, 0.6000f}};
    float input[2] = {0.05f, 0.1f};


    Matrix wa{3,2};
    Matrix wb{3,2};

    for(int i = 0; i < 3;i++){
        for(int j = 0; j < 2;j++){
            wa.set(i,j,weightA[i][j]);
            wb.set(i,j,weightB[i][j]);
        }
    }
    // nn.addLayer(wa,SIGMOID,10.5f);
    // nn.addLayer(wb,SIGMOID,10.5f);
}