#include "vector_test.h"
#include "../math/matrix.h"
#include "../math/iavector.h"

#include <iostream>


void vector_test(){
    Vector v{4};

    Vector v2{4};


    v[0] = 1.00;v[1] = 2.00;v[2] = 3.00;v[3] = 4.00;
    v2[0] = 1.00;v2[1] = 2.00;v2[2] = 3.00;v2[3] = 4.00;
    std::cout << "El vector 'v'  es " << v << endl;
    std::cout << "El vector 'v2' es " << v2  << endl;

    Vector s = v.subset(1,3);

    std::cout << "El resultado de la operacion 'subset' es " << s <<" de largo: " << s.len() << std::endl;
    Vector v3 = v2 + v;
    std::cout << "El resultado de la operacion '+' es " << v3 << "=" <<v2<< "+" << v << endl;
    Vector v4 = v2 * v;
    std::cout << "El resultado de la operacion '*' es " << v4 << "=" <<v2<< "+" << v << endl;
    Vector v5 = v2 / v;
    std::cout << "El resultado de la operacion '*' es " << v5 << "=" <<v2<< "/" << v << endl;
    Vector v6 = v2 * 2.0;
    std::cout << "El resultado de la operacion '*2' es " << v6 << "=" <<v2<< " * 2.0" << endl;


    double dot = v2.dot(v);
    std::cout << "El resultado de la operacion '(*)' es " << dot << std::endl;

    Vector v10 = v2;
    std::cout << "El resultado de la operacion 'v10' es " << v10<< std::endl;
    
    Vector ep1{2};
    ep1[0] = 1.0;ep1[1] = 2.0;

    Matrix ep = ep1.extern_product(v);
    
    std::cout << "ep: " << ep<< endl;

    Vector delta{5};
}