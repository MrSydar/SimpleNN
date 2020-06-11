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

    /**
    *   floatMaxIdx - get index of maximum element in float array
    *   
    *   @param arr - float array
    *   @param size - size of arr
    *   @return integer index of maximum value in arr
    */
    int floatMaxIdx(float* arr, int size);

public:
    /**
    *   int feedForward - feeds neural network with given values
    *   
    *   @param input - input layer size of first layer
    *   @return index of node with maximum value in output layer
    */
    int feedForward(float* input);

    /**
    *   @param networkStructure - number of neurons on each layer
    *   @param layersCount - number of layers or networkStructure array size
    *   @param activation - activation function pointer
    *
    *   @param weights:
    *   Sequence: weights entering each node (starting from second layer, first node)
    *   weights = {
    *       w(N11 -> N21), w(N12 -> N21), ..., w(N1n -> N2m), ..., w(N(penult layer)(last node on penult layer) -> N(last layer)(last node on last layer))
    *   }
    *   where Nab - node on layer a and local index b
    *
    *   @param biases:
    *   Sequence: biases for each node (starting from second layer, first node)
    *   biases = {
    *       N21, N22, ..., N2n, N31, N32, ..., N3n, ..., N(last layer)(last node)
    *   }
    *   where Nab - node on layer a and local index b
    */
    SimpleNN(unsigned int* networkStructure, unsigned int layersCount, float (*activation)(float), float* weights, float* biases);
};

#endif