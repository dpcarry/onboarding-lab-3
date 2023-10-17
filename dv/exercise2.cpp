#include <VExercise2.h>
#include <iostream>
#include <cstdint>
#include <cstdlib>
using namespace std;

int main() {
    VExercise2 model;
    uint16_t initial;
    uint16_t expected;
    uint16_t new_input;
    int num_tests = 200;
    int num_cycles = 10
    for (int i = 0; i < num_tests; i++){
        srand(static_cast<unsigned int>(time(nullptr)));
        initial = rand() % 0xFFFF;
        model.init = initial;
        model.clk = 1;
        model.reset = 1;
        model.eval();
        model.clk = 0;
        model.eval();
        expected = ~ model.init;
        if (model.out != expected)
            return 1;
        new_input = expected;
        for (int j = 0; j < num_cycles; j++){
            model.clk = 1;
            model.reset = 0;
            model.eval();
            model.clk = 0;
            model.eval();
            expected = (new_input<<1)|(((new_input>>10)&1)^((new_input>>8)&1)^((new_input>>3)&1)^((new_input>>1)&1));
            if (model.out != expected)
                return 1;
            temp = model.out;
        }
    }
    return 0;
}