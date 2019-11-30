#include "../statistics.hpp"
using namespace std;

int main() {
    double psd = 3.2, mu_0 = 8, alpha = 0.05, x_bar = 8.4;
    int sampleSize = 120;
    cout << "this is problem 20" << endl;

    auto test_statistic = testStatistic(x_bar, mu_0, psd, sampleSize);
    auto p_value = genPValue(test_statistic, false);
    cout << "In (a) please look hand-write paper." << endl;
    cout << "In (b) test statistic is " << test_statistic << " and p-value is " << p_value << endl;
    cout << "In (c) we do " << ((p_value < alpha / 2) ? "" : "not ") << "reject H0" << endl;
    cout << "In (d) " << (1 - alpha) * 100 << "% confidence interval for the popupation mean is in "
         << genConfidenceInterval(x_bar, errorRadius(psd, alpha, sampleSize))  << " minutes " << endl;
    return 0;
}