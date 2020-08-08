#ifndef _RELU_H_
#define _RELU_H_

#include "../math/iavector.h"
#include "activation.h"

class Relu : public Activation{
    public:
        Relu();
        Relu(const Relu &l);
        virtual Vector activate(Vector v);
        virtual Vector derivate(Vector v);
        virtual ~Relu();
};


#endif //_RELU_H_