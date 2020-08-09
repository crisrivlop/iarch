#include "test/vector_test.h"
#include "test/matrix_test.h"

#include "ia/NeuralNetwork.h"

#include <iostream>

#include <omp.h>
#include <stdio.h>

int main(int argc, char** argv){
    #if defined(HAVE_NEON)
        std::cout << "La inteligencia artificial funciona con paralelismo a nivel de datos" << std::endl;
    #endif

    // Vector a{100000000};
    // Vector b{100000000};

    // double start_time, run_time;
    // start_time = omp_get_wtime();
    // Vector c{a-b};
    // run_time = omp_get_wtime() - start_time;

    // std::cout << "Tiempo de ejecion total: "<< run_time << std::endl;

    vector_test();

    // std::cout << "============================================================\n";

    // matrix_test();
    
    // std::cout << "============================================================\n";

    // float weightA[3][2] = {{0.1500f, 0.2500f},{0.2000f, 0.3000f},{0.3500f, 0.3500f}};
    // float weightB[3][2] = {{0.4000f, 0.5000f},{0.4500f, 0.5500f},{0.6000f, 0.6000f}};
    // float input[2] = {0.05f, 0.1f};


    // Matrix wa{3,2};
    // Matrix wb{3,2};

    // for(int i = 0; i < 3;i++){
    //     for(int j = 0; j < 2;j++){
    //         wa.set(i,j,weightA[i][j]);
    //         wb.set(i,j,weightB[i][j]);
    //     }
    // }


    // NeuralNetwork nn{2,2};
    // nn.addLayer(wa,SIGMOID,10.5f);
    // nn.addLayer(wb,SIGMOID,10.5f);

    // Vector in{2};

    // for(int i = 0; i < 2;i++){
    //     in[i] = input[i];
    // }

    // Vector out{2};
    // out[0] = 0.01f;out[1] = 0.99f; 
    // nn.setEpochs(100000);
    // nn.setThreshold(0.000000000001f);
    // nn.train(in,out);
    // nn.results();

    // // std::cout << "out defined" << std::endl;
    // std::cout << "IA output: " << out <<" total epochs: " << nn.getMaxEpochs() << std::endl;
    // std::cout << "After train: " << nn.ia(in) << std::endl;


    return 0;
}