/*
  Vector Operations Program
  Author: Kaan
  Purpose: Implement addition, subtraction, and scalar multiplication
  Usage: Run the program, enter the vectors.

*/

// Declare Packages ------------

#include <vector>
#include <iostream>
#include <assert.h>
#include <math.h>

// End of Declare Packages -----

// Functions -------------------


void print_vector(std::vector<double> vector_print){
  int v_size;
  v_size = vector_print.size();
  for(int i=0; i<v_size; i++){
    std::cout << vector_print[i]
              << ", ";
  }
  std::cout << "\n";
}


std::vector<double> vector_scalar_multiplication(std::vector<double> scaled_vector,
                                                 double scalar,
                                                 int vector_size){
  std::vector<double> result_vector;
  for(int i=0; i<vector_size; i++){
    double multiplication_result;
    multiplication_result = scaled_vector[i] * scalar;
    result_vector.push_back(multiplication_result);
  }
  return(result_vector);
}

double vector_magnitude(const std::vector<double> input_vector,
                     int vector_size){
  double magnitude;// stores the magnitude of the vector
  for(int i=0; i < vector_size; i++){
    magnitude += pow(input_vector[i], 2.0);
  }
  magnitude = sqrt(magnitude);
  return(magnitude);
}

std::vector<double> vector_normaliser(std::vector<double> input_vector,
                                      int vector_size){
  double scalar; // stores the magnitude of the vector
  double vec_magnitude;
  vec_magnitude = vector_magnitude(input_vector, vector_size);
  scalar = 1 / vec_magnitude;
  //
  std::vector<double> result_vector;
  result_vector = vector_scalar_multiplication(input_vector,
                                               scalar,
                                               vector_size);
  return(result_vector);
}

int main(){
  // input vector
  double input; // input value which would be taken from the user
  std::cout << "Enter your numbers to be taken to the vector and 2.2 to quit: "
            << std::endl;
  std::vector<double> vector_1; // First vector for operations
  input = 0.2;
  while(input != -4.554){
    std::cin >> input;
    vector_1.push_back(input);
  }
  int vec_size; // store the vector size
  vec_size = vector_1.size();
  int vector_mag; // stores vector magnitude
  std::vector<double> norm_vector; // stores the unit vector
  vector_mag = vector_magnitude(vector_1, vec_size);
  norm_vector = vector_normaliser(vector_1, vec_size);
  std::cout << "Vector Magnitude: "
            << vector_mag << "\n"
            << "Unit Vector: "
            << std::endl;
  print_vector(norm_vector);
  return(0);

}
