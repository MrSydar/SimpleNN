#include <SimpleNN.h>
#define L_EYE A0
#define R_EYE A1
#define LD A2

/*
 * 3 input neurons  - 1st layer
 * 2 hidden neurons - 2nd layer
 * 4 output neurons - 3rd layer
 */
unsigned int networkStructure[] = {3, 2, 4};

// We defined three layers above
unsigned int layersCount = 3;

/* 
 * Pre-trained weights: 
 * Sequense explained in SimpleNN.h file
 */
float weights[] = {
    -3.7610714f, 2.995033f, -0.00982121f,
    0.93687856f, -4.1849513f, -0.21093537f,

    -0.03498226f, 1.94131f,
    2.2092955f, -4.3791156f,
    -3.3368099f, 3.01515f,
    -0.26486933f, -2.2291489f
};

/* 
 * Pre-trained biases:
 * Sequense explained in SimpleNN.h file
 */
float biases[] = {
    0.80323184f, 0.9375553f, -0.4283787f, -0.37323758f, -0.45093277f, 1.0982088f
};

/*
 *  Function that we will use as activation for neural network
 */
float fRely(float x){ 
  return x > 0 ? x : 0;
}

/*
 * Define deural network
 */
SimpleNN NeuralNetwork( networkStructure, layersCount, &fRely, weights, biases);

void setup(){
  Serial.begin(9600);
}

void loop() {
  /*
   * Reading sensors, normalizing values from 0.0f to 1.0f
   */
  float input[3];
  int state;
  input[0] = analogRead(L_EYE) / 1023.0f;
  input[1] = analogRead(R_EYE) / 1023.0f;
  input[2] = analogRead(LD) / 1023.0f
  /*
   * Writing output to variable state. Output is index of maximum value in output layer
   */
  state = NeuralNetwork.feedForward(input);
  Serial.println(state);
}
