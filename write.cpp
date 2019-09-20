//
// Created by MDand on 2019-09-20.
//

#include <fstream>
#include <random>
#include <ctime>
#include <iomanip>

using namespace std;

void write() {
    ofstream fout;
    fout.open("readings.txt");

    random_device rd; // a random number generator
    mt19937 generator(rd()); // calls operator()
    uniform_int_distribution<> distribution(512, 1024);
    int randomLastInt = distribution(generator);


    default_random_engine generatorDouble(time(0));
    uniform_real_distribution<double> distributionDouble(50.00, 90.00);

    for (int i = 0; i < randomLastInt; i++) {

        double randomDouble = distributionDouble(generatorDouble);
        fout << fixed << setprecision(3);
        fout << i << " " << randomDouble << endl;
    }




    fout.close();
}