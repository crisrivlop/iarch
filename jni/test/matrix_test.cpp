#include "matrix_test.h"
#include "../math/matrix.h"
#include "../math/iavector.h"

#include <iostream>

void matrix_test(){

    Vector v{4};

    Matrix m{4,4};
    for (int i = 0; i < 4;i++){
        m.set(i,0,1.0f);
        m.set(i,1,2.0f);
        m.set(i,2,3.0f);
        m.set(i,3,4.0f);
    }

    Matrix m2{4,4};
    for (int i = 0; i < 4;i++){
        m2.set(i,0,5.0f);
        m2.set(i,1,6.0f);
        m2.set(i,2,7.0f);
        m2.set(i,3,8.0f);
    }

    std::cout << "La matriz 'm'  es \n" << m;
    std::cout << "La matriz 'm2' es \n" << m2;

    v[0] = 1.0f;v[1] = 2.0f;v[2] = 3.0f;v[3] = 4.0f;
    std::cout << "El resultado de la operacion 'v' es " << v << std::endl;

    Vector d = m.dot(v);
    std::cout << "El resultado de la operacion 'd' es " << d << std::endl;
    
    Matrix d2 = m * 2.0f;
    std::cout << "El resultado de la operacion '2*m' es " << d2 << std::endl;

    Matrix m3 = m + m2;
    std::cout << "El resultado de la operacion '+' es " << m3 << std::endl;


    Matrix m4 = m - m2*0.5f;
    std::cout << "Descenso del gradiente: "  << m4 << std::endl;
    

}