#include "test/vector_test.h"
#include "test/matrix_test.h"

#include <iostream>

int main(int argc, char** argv){
    // #if defined(HAVE_NEON)
    //     std::cout << "El programa funciona con neon" << std::endl;
    // #endif

    vector_test();

    std::cout << "============================================================\n";

    matrix_test();
    
    return 0;
}