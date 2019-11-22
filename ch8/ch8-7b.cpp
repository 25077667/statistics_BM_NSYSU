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
    double ssd = genSampleStandardDeviation(dataSet, mean, dataSet.size());
    auto confididence = genConfidenceInterval(mean, errorRadius(dataSet, alpha / 2));
    //auto confididence = genConfidenceInterval(mean, errorRadius(ssd, alpha, dataSet.size()));

    cout << "In" << title << ": \nSample Mean:" << mean << endl;
    cout << confididence << endl;

    return 0;
}
