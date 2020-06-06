/*
  SimpleNN.h - Simple neural network builder and feeder without learning function.

  Created by Denys Hromniuk, June 6, 2020.
  Released into the public domain.
*/

#ifndef SimpleNN_h
#define SimpleNN_h

#include "Arduino.h"

class SimpleNN {
private:
    float (*activation)(float);
    unsigned int* networkStructure, layersCount;
    float** nodes, * weights, * biases;

    /*
        @param arr - float array
        @param size - size of arr

        @return index of maximum value in arr
    */
    int floatMaxIdx(float* arr, int size);

public:
    /*
        @param input - input layer size of first layer

        @return index of node with maximum value in output layer
    */
    int feedForward(float* input);

    /*
        @param networkStructure - number of neurons on each layer

        @param layersCount - number of layers or networkStructure array size

        @param activation - activation function pointer

        @param weights:
        Sequence: weights entering each node (starting from second layer, first node)
        weights = {
            N11 - N21, N12 - N21, ..., N1n - N21, 
            N11 - N22, N12 - N22, ..., N1n - N22,
            ...,
            N(l-1)n - N(l)m
        }
        where Nab - node on layer a and index b

        @param biases:
        Sequence: biases for each node (starting from second layer, first node)
        biases = {
            Node21, Node22, ..., Node2N, Node31, ..., NodeLM
        }
        where Nab - node on layer a and index b
    */
    SimpleNN(unsigned int* networkStructure, unsigned int layersCount, float (*activation)(float), float* weights, float* biases);
};

#endif