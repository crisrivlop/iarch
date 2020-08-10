#include "test/vector_test.h"
#include "test/matrix_test.h"

#include "ia/NeuralNetwork.h"

#include <iostream>

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#if defined(HAVE_NEON)

#include <arm_neon.h>

#endif

int main(int argc, char** argv){

    // int i;
    // unsigned int len=1000;
    // Vector a{len}, b{len};
    // float sum;
    // /* Initialize dot product vectors */
    // for (i=0; i<len; i++) {
    //   a[i]= (float)i/((float)len);
    //   b[i]= (float)i/((float)len);
    //   }

    // double start_time, run_time;

    // for (int m = 0;m < 10;m++){
    //     sum = 0.0;
    //     start_time = omp_get_wtime();

    //     double c =  a.dot(b);

    //     run_time = omp_get_wtime() - start_time;
    //     std::cout << "total time: " << run_time  << " value: " << c << std::endl;
    // }


    
    // Vector *a = new Vector{10000000};
    // Vector *b = new Vector{10000000};

    // 
    // 
    // Vector *c = new Vector{10000000};
    // *c = {*a-*b};
    // 

    // std::cout <<  run_time << std::endl;


    // start_time = omp_get_wtime();
    // *c = {*a+*b};
    // run_time = omp_get_wtime() - start_time;

    // std::cout <<  run_time << std::endl;



    // start_time = omp_get_wtime();
    // *c = {*a * (*b)};
    // run_time = omp_get_wtime() - start_time;

    // std::cout <<   run_time << std::endl;



    // start_time = omp_get_wtime();
    // *c = a->dot(*b);
    // run_time = omp_get_wtime() - start_time;

    // std::cout << run_time << std::endl;

    // Matrix * w = new Matrix{12,10000000};
    // start_time = omp_get_wtime();
    // *c = w->dot(*b);
    // run_time = omp_get_wtime() - start_time;

    // std::cout  << run_time << std::endl;



    // vector_test();

    // std::cout << "============================================================\n";

    // matrix_test();
    
    // std::cout << "============================================================\n";

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


    NeuralNetwork nn{500,500};
    // nn.addLayer(wa,SIGMOID,10.5f);
    // nn.addLayer(wb,SIGMOID,10.5f);

    // std::cout << "loading layers" << std::endl;
    nn.addLayer(500,SIGMOID,0.5);
    nn.addLayer(500,SIGMOID,0.5);
    nn.addLayer(500,SIGMOID,0.5);
    // std::cout << "layers loaded" << std::endl;

    Vector in{2};


    // for(int i = 0; i < 2;i++){
    //     in[i] = input[i];
    // }

    Vector out{2};
    out[0] = 0.01f;out[1] = 0.99f; 
    nn.setEpochs(100);
    nn.setThreshold(0.000000000001f);
    Vector  trainIn{500};
    Vector trainOut{500};

    Matrix w{trainIn.extern_product(trainOut)};

    double start_time, run_time;
    std::cout << "training..." << std::endl;
    for (int j = 0 ; j < 30; j++){
        run_time = 0;
        // for (int i = 0; i < 100; i++){
            start_time = omp_get_wtime();
            // nn.ia(trainIn);
            nn.train(trainIn,trainOut);
            // Matrix w2{w - trainIn.extern_product(trainOut)*0.5};
            run_time += omp_get_wtime() - start_time;
        // }

        std::cout << "total time: " << run_time << " average time is: " << run_time/1000 << endl;

    }

    // nn.train(trainIn,trainOut);


    //std::cout << "Tiempo de ejecion total: "<< run_time << std::endl;
    // nn.results();

    // std::cout << "out defined" << std::endl;
    // std::cout << "IA output: " << out.len() <<" total epochs: " << nn.getMaxEpochs() << std::endl;
    // std::cout << "After train: " << nn.ia(in) << std::endl;


    return 0;
}