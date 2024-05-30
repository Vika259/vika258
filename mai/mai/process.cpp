#include <vector> 
#include "processing.h"
using namespace std;
double process(vector<Precipitation*>& talk, int month) {
    double TotalAmount = 0.0;
    for (Precipitation* t : talk) {
        if (t->month == month) {
            TotalAmount += t->amount;
        }
    }
    return TotalAmount;
}