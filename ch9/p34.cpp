#include "../statistics.hpp"
using namespace std;

int main() {
    auto data = {1.7, 1.5, 2.6, 2.2, 2.4, 2.3, 2.6, 3.0, 1.4, 2.3};
    double ssd = genSampleStandardDeviation(data, genMean(data), data.size()),
           mu_0 = 2, alpha = 0.05, x_bar = genMean(data);
    int sampleSize = data.size();
    cout << "this is problem 34" << endl;

    auto test_statistic = testStatistic(x_bar, mu_0, ssd, sampleSize, true);
    auto p_value = genPValue(test_statistic);
    cout << "In (a) please look hand-write paper." << endl;
    cout << "In (b) the smaple mean is " << x_bar << endl;
    cout << "In (c) the smaple standatrd deviation: " << ssd << endl;
    cout << "In (d) test statistic is " << test_statistic << " and p-value is " << p_value << endl;
    cout << "In (e) we do " << ((p_value < alpha) ? "" : "not ") << "reject H0" << endl;
    return 0;
}
