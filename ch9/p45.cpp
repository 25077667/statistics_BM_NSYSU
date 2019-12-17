#include "../statistics.hpp"
using namespace std;

int main() {
    int sampleSize = 300;
    double p_0 = 0.39, alpha = 0.05, p_bar = 0.35;
    double sd = genPercentageStandardDeviation(p_0, sampleSize);
    cout << "this is problem 45" << endl;

    auto test_statistic = (p_bar - p_0) / sd;
    auto p_value = genPValue(test_statistic, true);
    cout << "In (a) test statistic is " << test_statistic << " and p-value is " << p_value << endl;
    cout << "\t we do " << ((p_value < alpha) ? "" : "not ") << "reject H0" << endl;

    p_0 = 0.3;
    alpha = 0.01;
    p_bar = 0.264;
    sd = genPercentageStandardDeviation(p_0, sampleSize);
    test_statistic = (p_bar - p_0) / sd;
    p_value = genPValue(test_statistic);
    cout << "In (a) test statistic is " << test_statistic << " and p-value is " << p_value << endl;
    cout << "\t we do " << ((p_value < alpha) ? "" : "not ") << "reject H0" << endl;

    return 0;
}
