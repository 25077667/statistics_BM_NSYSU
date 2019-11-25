#include "statistics.hpp"
using namespace std;
// B073040047 楊志璿

int main() {
    vector<double> dataSet;
    string title = readSingleLineCSV(dataSet, "Setters2.csv");

    double alpha = 0.05;
    double mean = genMean(dataSet);
    auto errorR = errorRadius(255, alpha, dataSet.size());
    auto confididence = genConfidenceInterval(mean, errorR);

    cout << "In" << title << ": \nSample Mean:" << mean << endl;
    cout << "Margin error: " << errorR << endl;
    cout << confididence << endl;

    return 0;
}
