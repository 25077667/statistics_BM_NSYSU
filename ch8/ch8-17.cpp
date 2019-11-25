#include <vector>
#include "statistics.hpp"
using namespace std;
// B073040047 楊志璿

int main() {
    vector<double> dataSet;
    string title = readSingleLineCSV(dataSet, "ch8-17.csv");

    double alpha = 0.05;
    double mean = genMean(dataSet);
    auto confidence = genConfidenceInterval(mean, errorRadius(dataSet, alpha / 2));

    cout << "In " << title << endl
         << "Sample Mean:" << mean << endl
         << confidence << endl;
    return 0;
}
