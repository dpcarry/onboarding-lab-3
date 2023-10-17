#include <cstdlib>
#include <cstdint>
#include <iostream>
#include "VExercise1.h"

using namespace std


int main() {
  VExercise1 model;

  for(int op = 0; op < 4; op++) {
    for(int a = 0; a < 256; a++) {
      for(int b = 0; b < 256; b++) {
        model.op = op;
        model.a = a;
        model.b = b;
        model.eval();

        switch(op) {
          case 0:
            if(model.out != (a ^ b)) {
              cerr << "incorrect output" << endl;
              exit(EXIT_FAILURE);
            }
            break;

          case 1:
            if(b >= 8) {
              uint8_t expected = a << b;
                cerr << "shift is out of range" << endl;
                exit(EXIT_FAILURE);
            }
            else {
              if(model.out != expected) {
                cerr << "incorrect output" << endl;
                exit(EXIT_FAILURE);
              }
            }
            break;
//
          case 2:
            if(b != 0 && model.out != (a % b)) {
              cerr << "incorrect output" << endl;
              exit(EXIT_FAILURE);
            }
            break;

          case 3:
            uint8_t expected = ~(a & b);
            if(model.out != expected) {
              std::cerr << "incorrect output" << endl;
              exit(EXIT_FAILURE);
            }
            break;
        }
      }
    } 
  }

  return 0;
}