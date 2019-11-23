#include "statistics.hpp"
using namespace std;
// B073040047 楊志璿

int main() {
    vector<double> dataSet;
    string title = readSingleLineCSV(dataSet, "TobaccoFires.csv");

    double alpha;
    cout << "what's alpha: ";
    cin >> alpha;
    double mean = genMean(dataSet);
    auto confidence = genConfidenceInterval(mean, errorRadius(mean, alpha, dataSet.size()));

    cout << "In " << title << endl;
    cout << "Sample Mean:" << mean << endl;
    cout << "In " << (1 - alpha) * 100 << "% confidence interval mean will in: " << confidence << endl;

    return 0;
}
