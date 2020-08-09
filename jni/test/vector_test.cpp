#include "vector_test.h"
#include "../math/matrix.h"
#include "../math/iavector.h"

#include <iostream>


void vector_test(){
    Vector v{4};

    Vector v2{4};


    v[0] = 1.0f;v[1] = 2.0f;v[2] = 3.0f;v[3] = 4.0f;
    v2[0] = -1.0f;v2[1] = 2.0f;v2[2] = 3.0f;v2[3] = 4.0f;
    
    std::cout << "El vector 'v'  es " << v << endl;
    std::cout << "El vector 'v2' es " << v2  << endl;

    std::cout << "El vector '|v2|' es " << v2.absolute()  << endl;

    v2 = v2.absolute() ;

    Vector s = v.subset(1,3);

    std::cout << "El resultado de la operacion 'subset' es " << s <<" de largo: " << s.len() << std::endl;
    Vector v3 = v2 + v;
    std::cout << "El resultado de la operacion '+' es " << v3 << "=" <<v2<< "+" << v << endl;
    std::cout << "El resultado de la operacion '-' es " << v3 << "-" <<v2<< "=" << v3-v2 << endl;
    Vector v4 = v2 * v;
    std::cout << "El resultado de la operacion '*' es " << v4 << "=" <<v2<< "*" << v << endl;
    Vector v5 = v2 / v;
    std::cout << "El resultado de la operacion '/' es " << v5 << "=" <<v2<< "/" << v << endl;
    Vector v6 = v2 * 2.0f;
    std::cout << "El resultado de la operacion '*2' es " << v6 << "=" <<v2<< " * 2.0" << endl;
    std::cout << "El resultado de la operacion 'v6/2' es " << v6 << "/2=" <<v6/2.0 << endl;
    std::cout << "El resultado de la operacion maximum es " << v6.maximum() << endl;


    float dot = v2.dot(v);
    std::cout << "El resultado de la operacion "<< v2 <<"'(*)' "<< v <<" es " << dot << std::endl;

    Vector v10 = v2;
    std::cout << "El resultado de la operacion " << v2 << " '=' es " << v10<< std::endl;
    
    Vector ep1{4};
    ep1[0] = 1.0;ep1[1] = 1.0f;ep1[2] = 1.0f;ep1[3] = 1.0f;//ep1[4] = 1.0f;
    Vector ep2{4};
    ep2[0] = 1.0;ep2[1] = 2.0f;ep2[2] = 3.0f;ep2[3] = 4.0f;//ep2[4] = 5.0f;

    Matrix ep = ep2.extern_product(ep1);
    
    std::cout << "ep: " << ep<< endl;


    Matrix ept = ep1.extern_product(ep2);
    
    std::cout << "ept: " << ept<< endl;

    
    std::cout << "ep1 + ep1: " << ep1 + ep1<< endl;


}