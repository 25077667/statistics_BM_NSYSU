#include "statistics.hpp"
using namespace std;
// B073040047 楊志璿

int main() {
    vector<double> dataSet;
    string title = readSingleLineCSV(dataSet, "Setters2.csv");

    double alpha;
    cout << "what's alpha: ";
    cin >> alpha;
    double mean = genMean(dataSet);
    auto confididence = genConfidenceInterval(mean, errorRadius(255, alpha, dataSet.size()));

    cout << "In" << title << ": \nSample Mean:" << mean << endl;
    cout << confididence << endl;

    return 0;
}
