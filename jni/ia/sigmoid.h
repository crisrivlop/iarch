#ifndef _SIGMOID_H_
#define _SIGMOID_H_

#include "../math/iavector.h"
#include "activation.h"

class Sigmoid : public Activation{
    public:
        Sigmoid();
        Sigmoid(const Sigmoid &l);
        virtual Vector activate(Vector v);
        virtual Vector derivate(Vector v);
        virtual ~Sigmoid();
};


#endif //_SIGMOID_H_