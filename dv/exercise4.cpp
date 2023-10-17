#include <VExercise4.h>
#include <iostream>

using namespace std;


int main() {
  VExercise4 model;
  for (model.sel = 0; model.sel<=7; model.sel++){
    model.cs = 0;
    model.alpha = 0x0A;
    model.beta = 0x3B;
    model.gamma = 0x5C;
    model.eval();
    if (model.out != 0){
      cout << "incorrect output when c is 0" << endl;
      return 1;
    }
  }
  model.cs = 1;
  for (int counter = 0; counter <= 3; counter++) {
        model.sel = counter;
        model.eval();
        uint8_t expected;
        switch (counter) {
        case 0: 
          expected = model.alpha; 
          break;
        case 1: 
          expected = model.beta; 
          break;
        case 2: 
          expected = model.gamma; 
          break;
        case 3: 
          expected = model.alpha & (model.beta | model.gamma); 
          break;
        }
        if (model.out != expected) {
            cout << "incorrect " << endl;
            return 1;
        }
    }
    
    return 0;


}
