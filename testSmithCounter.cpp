//Daniel Joseph Day
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "SmithCounter.h"
#include "Stats.h"
using namespace std;

int main()
{
    SmithCounter  c;
    Stats    stats;
    bool startPrediction;

    for (int i=0; i < 70000; i++)
	{
	cout << setw(5) << i << "  Initally: " << c.get_State() << " predicing: " 
			<< c.get_Prediction() << " then after ";
	if (rand() & 1)
	    {
	    c.record_Branch_Taken();
	    stats.record_Data(true, c.get_Prediction());
	    cout << setw(10) << "TAKEN";
	    }
	 else
	    {
	    c.record_Branch_Not_Taken();
	    stats.record_Data(false, c.get_Prediction());
	    cout << setw(10) << "NOT TAKEN";
	    }

	cout << " State is: " << c.get_State() << endl;
	}
 
    cout << "Number of branches: " << stats.get_total() << endl;
    cout << "Number of branches correctly predicted taken: " << stats.get_taken_correct() << endl;
    cout << "Number of branches correctly predicted not taken: " <<  stats.get_notTaken_correct() << endl;
    cout << "Number of branches incorrectly predicted taken: " << stats.get_taken_incorrect() << endl;
    cout << "Number of branches incorrectly predicted not taken: " << stats.get_notTaken_incorrect() << endl;
    cout << "Percentage correct: " << stats.get_percentage() << "%" << endl;

    return 0;
}
