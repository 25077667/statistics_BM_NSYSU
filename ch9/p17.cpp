#include "../statistics.hpp"
using namespace std;

int main() {
    double psd = 33.17, mu_0 = 128, alpha = 0.05, x_bar = 118.6;
    int sampleSize = 30;
    cout << "this is problem 17" << endl;

    auto test_statistic = testStatistic(x_bar, mu_0, psd, sampleSize);
    auto p_value = genPValue(test_statistic, true);
    cout << "In (a) please look hand-write paper." << endl;
    cout << "In (b) test statistic is " << test_statistic << " and p-value is " << p_value << endl;

    cout << "In (c) we do " << (!(p_value < alpha) ? "" : "not ") << "reject H0" << endl;
    cout << "In (d) " << genConfidenceInterval(x_bar, errorRadius(psd, alpha, sampleSize)) << endl;
    return 0;
}