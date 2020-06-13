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
