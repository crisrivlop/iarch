#include "math/iavector.h"
#include "math/matrix.h"

#include <iostream>

int main(){
    Vector v{4};

    Vector v2{4};


    Matrix m{4,4};
    for (int i = 0; i < 4;i++){
        m.set(i,0,1.01);
        m.set(i,1,2.01);
        m.set(i,2,3.01);
        m.set(i,3,4.01);
    }

    m.print();


    v[0] = 1.00;v[1] = 2.00;v[2] = 3.00;v[3] = 4.00;
    v2[0] = 1.00;v2[1] = 2.00;v2[2] = 3.00;v2[3] = 4.00;
    std::cout << "El resultado de la operacion 'v' es " << v;

    Vector d = m.dot(v);
    std::cout << "El resultado de la operacion 'd' es " << d;
    std::cout << "El resultado de la operacion 'v' es " << v;
    
    Matrix d2 = m * 2.0;
    d2.print();

    Vector s = v.subset(1,3);
    std::cout << "El resultado de la operacion 'subset' es " << s <<" de largo: " << s.len() << std::endl;
    std::cout << "El resultado de la operacion 'v' es " << v;
    Vector v3 = v2 + v;
    std::cout << "El resultado de la operacion '+' es " << v3 << "=" <<v2<< "+" << v;
    Vector v4 = v2 * v;
    Vector v5 = v2 / v;

    Vector v6 = v2 * 2.0;


    double dot = v2.dot(v);


    Vector v10 = v2;

    Vector ep1{2};
    ep1[0] = 1.0;ep1[1] = 2.0;

    Matrix ep = ep1.extern_product(v);
    
    std::cout << "ep: " << endl;
    ep.print();

    std::cout << "El resultado de la operacion 'v2' es " << v2;
    std::cout << "El resultado de la operacion 'v10' es " << v10;
    std::cout << "El resultado de la operacion '+' es " << v3;
    std::cout << "El resultado de la operacion '*' es " << v4;
    std::cout << "El resultado de la operacion '*2' es " << v6;
    std::cout << "El resultado de la operacion '/' es " << v5;
    std::cout << "El resultado de la operacion 'd=m*v' es " << d;
    std::cout << "El resultado de la operacion '(*)' es " << dot << std::endl;

    Vector delta{5};

    return 0;
}