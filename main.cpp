#include <iostream>
#include <data_structures/data_structures.h>
#include <fstream>

using namespace std;
int main(){
    ostreamTest();
    ofstream file{ "lunchtime.txt", ios::out|ios::app};

    file << "Time is an illusion." << endl;
    file << "Lunch time, " << 2 << "x so." << endl;

    return 0;
}