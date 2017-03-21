//Daniel Joseph Day
#include "SmithCounter.h"
#include <cmath>

SmithCounter::SmithCounter(int bits, int initialValue) {

    state = initialValue;
    number_Of_Bits = bits;
    mask_Value = (pow(2,number_Of_Bits)) - 1;

}
void SmithCounter::record_Branch(bool taken) {

    if(taken) record_Branch_Taken();
    else record_Branch_Not_Taken();

}
void SmithCounter::record_Branch_Taken() {

    state++;
    if(state > 3) state = 3;

}
void SmithCounter::record_Branch_Not_Taken() {

    state--;
    if(state < 0) state = 0;

}
bool SmithCounter::get_Prediction() const {

    if(state > 1) return true;
    else return false;

}
int SmithCounter::get_State() const {

    return state;

}
