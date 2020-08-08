#ifndef _ACTIVATION_H_
#define _ACTIVATION_H_

#include "../math/matrix.h"
#include "../math/iavector.h"

enum ACTIVATION_TYPE{
    SIGMOID,
    RELU
};

class Activation{

    public:
        virtual Vector activate(Vector v) = 0;
        virtual Vector derivate(Vector v) = 0;
        virtual ~Activation();
};


#endif //_ACTIVATION_H_