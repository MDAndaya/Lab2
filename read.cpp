//
// Created by MDand on 2019-09-20.
//

#include <fstream>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

void read() {
    cout << fixed << setprecision(3);

    ifstream fin;
    fin.open("readings.txt");

    double sum = 0;
    double d;
    int readingCount = 0;
    while (fin >> d >> d) {
        readingCount++;
        sum += d;
    }
    double avg = sum / readingCount;
    cout << "There are " << readingCount << " readings in the file" << endl;
    cout << "The average reading is " << avg <<  endl;

    fin.close();

    fin.open("readings.txt");

    double highest = 50;
    while (fin >> d >> d) {
        if (d > highest)
            highest = d;
    }
    cout << "The highest reading is " << highest << endl;

    fin.close();

    fin.open("readings.txt");

    double lowest = 90;
    while (fin >> d >> d) {
        if (d < lowest)
            lowest = d;
    }
    cout << "The lowest reading is " << lowest << endl;

    fin.close();

    fin.open("readings.txt");

    int i = 0;
    double buff;
    double doubleArray[readingCount];
    while (fin >> buff >> doubleArray[i]) {
        i++;
    }

    sort(doubleArray, doubleArray + readingCount);
    double median = 0;

    if (readingCount % 2 != 0)
        median = doubleArray[readingCount/2];
    else
        median = (doubleArray[(readingCount-1)/  2] + doubleArray[readingCount/2])/2.0;
    cout << "The median reading is " << median << endl;

    fin.close();




}
