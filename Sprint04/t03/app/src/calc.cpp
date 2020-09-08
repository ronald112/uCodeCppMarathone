#include "calc.h"

using namespace std;

Calc::Calc() {
    this->pattern = regex("(0-9)+\\s");
    // (\d+)\s*[\+\-\*\/]{1}\s*(\d+)={0,1}(?<==)([a-zA-Z]+)
}