#include "statistics.hpp"
using namespace std;
// B073040047 楊志璿

int main() {
    vector<double> dataSet;
    string title = readSingleLineCSV(dataSet, "TobaccoFires.csv");

    double alpha = 0.05;
    double mean = genMean(dataSet);
    double ssd = genSampleStandardDeviation(dataSet, mean, dataSet.size());
    auto confidence = genConfidenceInterval(mean, errorRadius(ssd, alpha, dataSet.size()));

    cout << "In " << title << endl;
    cout << "In " << (1 - alpha) * 100 << "% confidence interval mean will in: " << confidence << endl;

    return 0;
}
