#include <iostream>
#include <string>

using namespace std;

int find_digit(float n, int d) {
  // your-code-here
  return 0;
}

int main(int argc, char** argv) {

  float number;
  int digit;
  
  if (argc < 3) {
    cout << "You must pass a a float number and the digit to find" << endl;
    cout << "Example: " << argv[0] << " 1.134 3" << endl;
      return -1;
  }

  number = stof(argv[1]);
  digit = stoi(argv[2]);
  
  cout << "Looking for [" << digit << "] digit in: [" << number << "]" << endl;

  if ( find_digit(number, digit) == 1 )
    cout << "Found" << endl;
  else
    cout << "Not Found" << endl;
  return 0;
}
