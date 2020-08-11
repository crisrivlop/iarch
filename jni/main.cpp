#include "test/vector_test.h"
#include "test/matrix_test.h"
#include "test/ia_test.h"
#include "ia/NeuralNetwork.h"

#include <iostream>

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>


#ifdef __ARM_NEON

#include <arm_neon.h>

#endif

int main(int argc, char** argv){


    std::cout << "TESTING IA APLICATION PARALLELIZED USING NEON INTRINSICS" << std::endl;
    std::cout << "============================================================\n";

    std::cout << "starting 'train_test' test ..." << std::endl;
    train_test(500,100, 0.0001f, 10);
    std::cout << "============================================================\n";

    std::cout << "starting 'forward_test' test ..." << std::endl;
    forward_test(500,100, 0.0001f, 100);
    std::cout << "============================================================\n";
    
    std::cout << "starting 'stress_layer_count_test' test ..." << std::endl;
    stress_layer_count_test();
    std::cout << "============================================================\n";
    
    std::cout << "starting 'stress_layer_len_test' test ..." << std::endl;
    stress_layer_len_test();
    std::cout << "============================================================\n";
    
    std::cout << "starting 'stress_layer_len_and_layer_count_test' test ..." << std::endl;
    stress_layer_len_and_layer_count_test();
    std::cout << "============================================================\n";



    return 0;
}