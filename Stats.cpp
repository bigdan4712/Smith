#include "Stats.h"
#include <iostream>

Stats::Stats()
{
    total = 0;
    total_taken = 0;
    total_taken_predicted_correctly = 0;
    total_notTaken = 0;
    total_notTaken_predicted_correctly = 0;
}
void Stats::record_Data(bool actual, bool predicted) {

    if(predicted && actual) {
        total_taken++;
        total++;
        total_taken_predicted_correctly++;
    }
    else if(predicted && !actual) {
        total_notTaken++;
        total++;
    }
    else if(!predicted && actual) {
        total_taken++;
        total++;
    }
    else {
        total_notTaken++;
        total_notTaken_predicted_correctly++;
        total++;
    }

}

void Stats::reset() {

    total = 0;
    total_taken = 0;
    total_taken_predicted_correctly = 0;
    total_notTaken = 0;
    total_notTaken_predicted_correctly = 0;

}

int Stats::get_total() const {

    return total;

}

int Stats::get_total_taken() const {

    return total_taken;

}

int Stats::get_taken_correct() const {

    return total_taken_predicted_correctly;

}

int Stats::get_taken_incorrect() const {

    return total_notTaken - total_notTaken_predicted_correctly;

}

int Stats::get_total_notTaken() const {

    return total_notTaken;

}

int Stats::get_notTaken_correct() const {

    return total_notTaken_predicted_correctly;

}

int Stats::get_notTaken_incorrect() const {

    return total_taken - total_taken_predicted_correctly;

}
double Stats::get_percentage() {

    double denominator = ((double)get_total());
    double numerator = ((double)get_notTaken_correct()) + ((double)get_taken_correct());

    return (numerator/denominator)*100;

}
