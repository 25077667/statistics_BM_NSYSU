#include "statistics.hpp"
using namespace std;
// B073040047 楊志璿

int main() {
    vector<double> dataSet;
    string title = readSingleLineCSV(dataSet, "Guardians.csv");

    double alpha;
    cout << "what's alpha: ";
    cin >> alpha;
    double mean = genMean(dataSet);
    auto confidence = genConfidenceInterval(mean, errorRadius(dataSet));  //a
    int sampleSize = dataSet.size();

    cout << "In " << title << "\n" << confidence << endl;

    double meanCustomer = 0;
    for (auto i : dataSet)
        meanCustomer += i / 8.11 / sampleSize;
    cout << "The mean number of customer per theater: " << meanCustomer << endl;

    cout << "The total number of customer who saw the movie in 4048 theaters: " << meanCustomer * 4080 << endl;
    return 0;
}
