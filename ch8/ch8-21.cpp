#include "statistics.hpp"
using namespace std;

int main() {
    vector<double> dataSet;
    string title = readSingleLineCSV(dataSet, "TeleHealth.csv");

    double mean = genMean(dataSet);
    double ssd = genSampleStandardDeviation(dataSet, mean, dataSet.size());
    auto confidence = genConfidenceInterval(mean, errorRadius(dataSet, 0.05));
    cout << "In " << title << " with 95% confidence interval: "<< confidence << endl;
}
