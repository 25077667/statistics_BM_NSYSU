#include "../statistics.hpp"
using namespace std;

int main() {
    int sampleSize = 100;
    double p_0 = 0.64, alpha = 0.05, p_bar = 0.52;
    double sd = genPercentageStandardDeviation(p_0, sampleSize);
    cout << "this is problem 38" << endl;

    auto test_statistic = (p_bar - p_0) / sd;
    auto p_value = genPValue(test_statistic, true);
    cout << "In (a) please look hand-write paper." << endl;
    cout << "In (b) test statistic is " << test_statistic << " and p-value is " << p_value << endl;
    cout << "In (c) we do " << ((p_value < alpha) ? "" : "not ") << "reject H0" << endl;
    return 0;
}
