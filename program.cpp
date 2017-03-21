//Daniel Joseph Day

#include "SmithCounter.h"
#include "Stats.h"
#include <unistd.h>
#include <iostream>

using namespace std;

void read_file();

int main(int argc, char* argv[]) {

    SmithCounter c[128];
    Stats   stats;

    read_file(argv[1], c, stats);

    int totalpredicted = 0;
    double percentage = 0;

    cout << "Number of branches: " <<  << endl;
    cout << "Number of branches correctly predicted taken: " <<  << endl;
    cout << "Number of branches correctly predicted not taken: " <<  << endl;
    cout << "Number of branches incorrectly predicted taken: " << << endl;
    cout << "Number of branches incorrectly predicted not taken: " <<  << endl;

    return 0;

}

void read_file(char *file, SmithCounter &counter[], Stats &stats) {

    string line;
    int number;
    bool taken;


    ifstream infile(file);

    while(getline(infile, line, ' ')) {

        getline(infile, state, '\n');
        number = atoi(line.c_str());

        if(state == "T") taken = true;
        else taken = false;

        if(taken && c[number%128].get_Prediction()) {
            c[number%128].record_Branch(taken);
            stats.record_Data(taken,c[number%128].get_Prediction())
        }
        else if(!taken && c[number%128].get_Prediction())
        else if(taken && !(c[number%128].get_Prediction())
        else

        c[number%128].


    }

    infile.close();

}
