#ifndef __IA_TEST_H_
#define __IA_TEST_H_



void train_test(unsigned int  size,int epochs, float th, int testingIterations);

void forward_test(unsigned int  size,int epochs, float th, int layerNumber);

void stress_layer_count_test();

void stress_layer_len_test();

void stress_layer_len_and_layer_count_test();


void ia_example();

#endif //__IA_TEST_H_



