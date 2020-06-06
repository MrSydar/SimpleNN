/*
  SimpleNN.h - Simple neural network builder and feeder without learning function.

  Created by Denys Hromniuk, June 6, 2020.
  Released into the public domain.
*/

#include "Arduino.h"
#include "SimpleNN.h"

SimpleNN::SimpleNN(unsigned int* networkStructure, unsigned int layersCount, float (*activation)(float), float* weights, float* biases) {
    this->networkStructure = networkStructure;
    this->layersCount = layersCount;
    this->activation = activation;
    this->weights = weights;
    this->biases = biases;

    nodes = new float* [layersCount];
    for (unsigned int i = 0; i < layersCount; i++) nodes[i] = new float[networkStructure[i]];
};

int SimpleNN::floatMaxIdx(float* arr, int size) {
    int maxIndex = 0;
    for (int i = 1; i < size; i++)
        if (arr[maxIndex] < arr[i]) maxIndex = i;
    return maxIndex;
}

int SimpleNN::feedForward(float* input) {
    unsigned int weightsCounter = 0, biasesCounter = 0;
    for (unsigned int i = 0; i < networkStructure[0]; i++) nodes[0][i] = input[i];

    for (unsigned int Layer = 1; Layer < layersCount; Layer++) {
        for (unsigned int Node = 0; Node < networkStructure[Layer]; Node++) {
            nodes[Layer][Node] = 0;

            for (unsigned int prevNode = 0; prevNode < networkStructure[Layer - 1]; prevNode++)
                nodes[Layer][Node] += nodes[Layer - 1][prevNode] * weights[weightsCounter++];

            nodes[Layer][Node] = activation(nodes[Layer][Node] + biases[biasesCounter++]);
        }
    }

    return floatMaxIdx(nodes[layersCount - 1], networkStructure[layersCount - 1]);
}
