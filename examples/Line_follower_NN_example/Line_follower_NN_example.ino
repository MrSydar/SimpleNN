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
    -0.21988334f, 4.035063f,
    -4.418429f, -0.03453574f,
    -0.29352435f, 0.10613765f,
     3.3308315f, -2.4351354f, 1.7342336f, -3.1583638f,
     -4.1817966f, -3.4644322f, 2.7307634f, 3.0570772f
};

/* 
 * Pre-trained biases:
 * Sequense explained in SimpleNN.h file
 */
float biases[] = {
    1.0584476f, -0.10252313f, -0.2423227f, 1.9445289f, -1.8162689f, -0.3903467f
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
  input[2] = analogRead(LD) / 1023.0f;
  /*
   * Writing output to variable state. Output is index of maximum value in output layer
   */
  state = NeuralNetwork.feedForward(input);
  Serial.println(state);
}
