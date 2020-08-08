
#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <iostream>
using namespace std;

class Matrix;

class Vector {
        double * _data;
        unsigned int _size;
        Vector add(const Vector& b);
        Vector add(const double& b);
        void  addi(const Vector& b);
        Vector sub(const Vector& b);
        Vector sub(const double& b);
        Vector mul(const Vector& b);
        Vector mul(const double& b);
        Vector div(const Vector& b);
        Vector div(const double& b);
        static ostream& print(ostream& os, Vector const & v);

    public:
        Vector(unsigned int size);
        Vector(const Vector &v);
        Vector();
        
        double& operator[](unsigned int i) {return this->_data[i];};
        Vector subset(unsigned int i, unsigned int f);
        Vector operator+(const Vector& b){return this->add(b);};
        Vector operator+(const double& b){return this->add(b);};
        void   operator+=(const Vector& b){this->addi(b);};
        Vector operator-(const Vector& b){return this->sub(b);};
        Vector operator-(const double& b){return this->sub(b);};
        Vector operator*(const Vector& b){return this->mul(b);};
        Vector operator*(const double& b){return this->mul(b);};
        Vector operator/(const Vector& b){return this->div(b);};
        Vector operator/(const double& b){return this->div(b);};
        friend ostream& operator<<(ostream& os, Vector const & v){return v.print(os,v);};

        double dot(const Vector& b);

        Vector inv();
        Vector exponential();

        Vector absolute();
        
        Matrix extern_product(const Vector& b);

        unsigned int len() const;

        ~Vector();
};

#endif //_VECTOR_H_