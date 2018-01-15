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

std::vector<double> vector_addition(std::vector<double> first_vector,
                                 std::vector<double> second_vector,
                                 int vector_size){
  std::vector<double> result_vector;
  for(int i=0; i<vector_size; i++){
    double addition_result;
    addition_result = first_vector[i] + second_vector[i];
    result_vector.push_back(addition_result);
  }
  return(result_vector);
}

std::vector<double> vector_subtraction(std::vector<double> first_vector,
                                 std::vector<double> second_vector,
                                 int vector_size){
  std::vector<double> result_vector;
  for(int i=0; i < vector_size; i++){
    double subtraction_result;
    subtraction_result = first_vector[i] - second_vector[i];
    result_vector.push_back(subtraction_result);
  }
  return(result_vector);
}

std::vector<double> vector_scalar_multiplication(
                                              std::vector<double> scaled_vector,
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


int main(){
  // implement addition, subtraction, and scalar multiplication
  // input vector
  double input; // input value which would be taken from the user
  std::cout << "Enter your numbers to be taken to the first vector and 2.2 to quit: "
            << std::endl;
  std::vector<double> int_vector_1; // First vector for operations
  input = 0.2;
  while(input != 2.2){
    std::cin >> input;
    int_vector_1.push_back(input);
  }
  std::cout << "Enter your numbers to be taken to the second vector and 2.2 to quit: "
            << std::endl;
  std::vector<double> int_vector_2; // Second vector for operations
  input = 0.2; // reassigning the input variable
  while(input != 2.2){
    std::cin >> input;
    int_vector_2.push_back(input);
  }
  // Check validity of vectors
  assert(int_vector_1.size() == int_vector_2.size());
  std::cout << "Vectors with same number of elements, operations are possible"
            << std::endl;
  std::vector<double> resulting_vector; // vector for acquiring results
  int total; // counter for looping
  total = int_vector_1.size();
  // Addition
  //
  resulting_vector = vector_addition(
                                     int_vector_1,
                                     int_vector_2,
                                     total);
  // Print resulting vector
  print_vector(resulting_vector);
  resulting_vector.clear();
  // Substraction
  //
  resulting_vector = vector_subtraction(
                                        int_vector_1,
                                        int_vector_2,
                                        total);
  // Print resulting vector
  print_vector(resulting_vector);
  resulting_vector.clear();
  // Vector Multiplication
  resulting_vector = vector_scalar_multiplication(
                                                  int_vector_1,
                                                  7.41,
                                                  total);
  // Print resulting vector
  print_vector(resulting_vector);
  resulting_vector.clear();
  int_vector_2.clear();
  int_vector_1.clear();
  //
  return(0);
}
