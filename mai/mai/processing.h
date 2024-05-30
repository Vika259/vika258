#include <vector> 
using namespace std;
struct Precipitation {
    int day;
    int month;
    double amount;
    char characteristic[50];
};
double process(vector<Precipitation*>& talk, int month);
