#include "../statistics.hpp"

int main() {
    auto alpha = 0.05;
    vector<double> deluxe = {39, 39, 45, 38, 40, 39, 35};
    vector<double> standard = {27, 28, 35, 30, 30, 34, 29};
    vector<double> di;
    for (size_t i = 0; i < deluxe.size(); i++) {
        di.push_back(deluxe.at(i) - standard.at(i));
    }
    auto mean = genMean(di);
    auto ssd = genSampleStandardDeviation(di, mean, di.size());
    auto df = twoPopulationDegreeFreedom(deluxe, standard);
    auto p_value = genPValue(df, (mean - 10) / (ssd / sqrt(di.size())), yes);
    auto radius = errorRadius(di);
    auto interval = genConfidenceInterval(mean, radius);
    cout << "This is problem 27" << endl;

    cout << "In (a) The p_value is " << p_value << endl;
    cout << "In (b) the interval is " << interval << endl;

    return 0;
}