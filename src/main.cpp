#include <Arduino.h> 

// Function declaration
int calculateSum(int, int);
int calculateProduct(int, int);

void setup() {
  // Initialize Serial communication
  Serial.begin(9600);
  while (!Serial); // Wait for Serial to be ready

  int option = 0;
  int one = 0, two = 0;

  // Print menu options
  Serial.println("Please select an option:");
  Serial.println("1 - Calculate sum of two numbers");
  Serial.println("2 - Calculate multiplication of two numbers");

  // Wait for user input
  while (Serial.available() == 0); // Wait for input
  option = Serial.parseInt();

  // Ask for two numbers
  Serial.println("Enter the first number:");
  while (Serial.available() == 0); // Wait for input
  one = Serial.parseInt();

  Serial.println("Enter the second number:");
  while (Serial.available() == 0); // Wait for input
  two = Serial.parseInt();

  // Perform calculation based on option
  int result = 0;
  switch (option) {
    case 1:
      result = calculateSum(one, two);
      Serial.print("The sum is: ");
      break;
    case 2:
      result = calculateProduct(one, two);
      Serial.print("The product is: ");
      break;
    default:
      Serial.println("Invalid option selected.");
      return; // Exit the function
  }
  Serial.println(result);
}

void loop() {
  // Empty loop since calculations are done in setup
}

// Function definitions
int calculateSum(int x, int y) {
  return x + y;
}

int calculateProduct(int x, int y) {
  return x * y;
}
