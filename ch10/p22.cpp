#include "../statistics.hpp"

int main() {
    auto alpha = 0.05;
    vector<double> Beginning = {53.82, 77.02, 109, 83.58, 139.23, 135.78, 41.07, 53.04, 36.44, 17.98, 38.54, 38.86, 188.03, 107.95, 90.65, 53.53, 42.23, 84.68, 85.95, 45.59, 65.2, 85.03, 44.49, 46.63, 127.58};
    vector<double> Ending = {54.19, 55.70, 102.57, 79.95, 126.01, 132.73, 32.06, 50.91, 35.40, 14.05, 32.54, 44.83, 184.63, 108.78, 71.96, 48.82, 36.20, 79.07, 95.00, 42.59, 50.82, 76.95, 46.27, 45.95, 129.86};
    vector<double> di;
    for (size_t i = 0; i < Beginning.size(); i++) {
        di.push_back((Ending.at(i) - Beginning.at(i)) / Beginning.at(i));
    }
    auto mean = genMean(di);
    auto ssd = genSampleStandardDeviation(di, mean, di.size());
    auto radius = errorRadius(di);
    auto interval = genConfidenceInterval(mean, radius);
    cout << "This is problem 22" << endl;

    cout << "In (a) The sample mean is " << mean << endl;
    cout << "In (b) in " << (1 - alpha) * 100 << "% confidence interval is in " << interval << endl;

    return 0;
}