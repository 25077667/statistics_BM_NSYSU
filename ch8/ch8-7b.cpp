#include "statistics.hpp"
using namespace std;
// B073040047 楊志璿

int main() {
    vector<double> dataSet;
    double newData;

    ifstream inFile("Setters.csv", ios::in);
    while (inFile >> newData)
        dataSet.push_back(newData);

    double alpha;
    cout << "what's alpha: ";
    cin >> alpha;
    double mean = genMean(dataSet),
           sampleSize = dataSet.size(),
           ssd = genSampleStandardDeviation(dataSet, mean, sampleSize),
           z = genZValue(alpha);

    cout << "Sample Mean:" << mean << endl;
    cout << "In " << (1 - alpha) * 100 << "% confidence interval mean will in: "
         << "[ " << mean - (ssd * sqrt(sampleSize) / z) << ", " << mean + (ssd * sqrt(sampleSize) / z) << " ]" << endl;

    inFile.close();
    return 0;
}
