#include "statistics.hpp"
using namespace std;

int main() {
    map<string, int> dataSet;
    string title = readSingleLineCSV(dataSet, "RightDirection.csv");
    int dataSize = 0;
    cout << "In " << title << ": " << endl;
    for (const auto& i : dataSet) {
        cout << i.first << ":\t" << i.second << endl;
        dataSize += i.second;
    }

    auto p_bar = (dataSet.at("Yes") * 1.0 / dataSize);
    cout << "In (a): " << p_bar << endl;

    auto sigma_p = sqrt(p_bar * (1 - p_bar));
    auto marginError = errorRadius(sigma_p, 0.05, dataSize);
    cout << "In (b) margin Error: " << marginError << endl;

    auto confidential = genConfidenceInterval(p_bar, marginError);
    cout << "In (c) Confidence Interval: " << confidential << endl;

    p_bar = 1 - p_bar;
    sigma_p = sqrt(p_bar * (1 - p_bar));
    marginError = errorRadius(sigma_p, 0.05, dataSize);
    confidential = genConfidenceInterval(p_bar, marginError);
    cout << "In (d) Confidence Interval: " << confidential << endl;
    return 0;
}
