#include "test/vector_test.h"
#include "test/matrix_test.h"

#include "ia/NeuralNetwork.h"

#include <iostream>

int main(int argc, char** argv){
    // #if defined(HAVE_NEON)
    //     std::cout << "El programa funciona con neon" << std::endl;
    // #endif

    vector_test();

    std::cout << "============================================================\n";

    matrix_test();
    
    std::cout << "============================================================\n";

    double weightA[3][2] = {{0.1500, 0.2500},{0.2000, 0.3000},{0.3500, 0.3500}};
    double weightB[3][2] = {{0.4000, 0.5000},{0.4500, 0.5500},{0.6000, 0.6000}};
    double input[2] = {0.05, 0.1};


    Matrix wa{3,2};
    Matrix wb{3,2};

    for(int i = 0; i < 3;i++){
        for(int j = 0; j < 2;j++){
            wa.set(i,j,weightA[i][j]);
            wb.set(i,j,weightB[i][j]);
        }
    }


    NeuralNetwork nn{2,2};
    nn.addLayer(wa,SIGMOID,10.5);
    nn.addLayer(wb,SIGMOID,10.5);

    Vector in{2};

    for(int i = 0; i < 2;i++){
        in[i] = input[i];
    }

    Vector out{2};
    out[0] = 0.01;out[1] = 0.99; 
    nn.setEpochs(100000);
    nn.setThreshold(0.000000000001);
    nn.train(in,out);
    nn.results();

    std::cout << "out defined" << std::endl;
    std::cout << "IA output: " << out <<" total epochs: " << nn.getMaxEpochs() << std::endl;
    std::cout << "After train: " << nn.ia(in) << std::endl;

    return 0;
}