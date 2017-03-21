//Daniel Joseph Day

#include "SmithCounter.h"
#include "Stats.h"
#include <unistd.h>
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

void read_file(char *file, SmithCounter counter[], Stats &stats);

int main(int argc, char* argv[]) {

    SmithCounter c[128];
    Stats   stats;

    read_file("branch.dat", c, stats);

    stats.get_percentage();

    cout << "Number of branches: " << stats.get_total() << endl;
    cout << "Number of branches correctly predicted taken: " << stats.get_taken_correct() << endl;
    cout << "Number of branches correctly predicted not taken: " <<  stats.get_notTaken_correct() << endl;
    cout << "Number of branches incorrectly predicted taken: " << stats.get_taken_incorrect() << endl;
    cout << "Number of branches incorrectly predicted not taken: " << stats.get_notTaken_incorrect() << endl;
    cout << "Percentage correct: " << stats.get_percentage() << "%" << endl;

    return 0;

}

void read_file(char *file, SmithCounter counter[], Stats &stats) {

    string line;
    string state;
    int address;
    bool taken;


    ifstream infile(file);

    while(getline(infile, line, ' ')) {

        getline(infile, state, '\n');
        address = atoi(line.c_str());

        if(state == "T") taken = true;
        else taken = false;

        stats.record_Data(taken,counter[address%128].get_Prediction());
        counter[address%128].record_Branch(taken);

    }

    infile.close();

}
