# SimpleNN
Simple arbitrary neural network builder and feeder without learning function for arduino.
Implement trained neural network into your project.

# For use you need:
- Predefined biases
- Predefined weights
- Neural network structure
- Activation function

# Features
- User custom activation function

# How to define neural network in SimpleNN library
The given example is in the 'examples' folder.

![Neural network scheme](https://i.imgur.com/d9CD5Mm.jpg)

1. Define weights:
```
float weights[] = {
  W0,   W1,
  W2,   W3,
  W4,   W5,
  
  W6,   W7,   W8,   W9,
  W10,  W11,  W12,  W13
}
```

2. Define biases for each node (except nodes on first layer):
```
float biases[] = {
  B20, B21, B30, B31, B32, B33
}
```

3. Define neural network structure (number of nodes on each layer):
```
unsigned int NNStructure[] = {
  3, 2, 4
}
```
4. Define your activation function (for exapmle we want to use Rely function):
```
float fRely(float x){ 
  return x > 0 ? x : 0;
}
```
5. Define neural network:
```
SimpleNN NeuralNetwork( NNStructure, 3, &fRely, weights, biases);
```
# Feedforward:
```
void loop() {
  /*
   * Reading sensors (for example, but you can use your values as you want), 
   * normalizing values from 0.0f to 1.0f by dividing values from sensors by 1023, because values range between 0 and 1023
   */
  float input[3];
  int state;
  input[0] = analogRead(L_EYE) / 1023.0f;
  input[1] = analogRead(R_EYE) / 1023.0f;
  input[2] = analogRead(LD) / 1023.0f;
  /*
   * Reading output. Output is index of maximum value in output layer
   */
  state = NeuralNetwork.feedForward(input);
  Serial.println(state);
}
```
