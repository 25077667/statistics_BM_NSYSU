#include "../statistics.hpp"
using namespace std;

int main() {
    double ssd = 4.5, mu_0 = 18, alpha = 0.05, x_bar = 17;
    int sampleSize = 48;
    cout << "this is problem 24" << endl;

    auto test_statistic = testStatistic(x_bar, mu_0, ssd, sampleSize, true);
    auto p_value = genPValue(sampleSize - 1, test_statistic, true, false);
    auto interval = genConfidenceInterval(mu_0, errorRadius(ssd, alpha, sampleSize, false, true));
    auto invInterval = invertInterval(interval);
    cout << "In (a) the test statistic is " << test_statistic << endl;
    cout << "In (b) the p-value is " << p_value << endl;
    cout << "In (c) we do " << ((p_value < alpha) ? "" : "not ") << "reject H0" << endl;
    cout << "In (d) the rejection rule is if x_bar is in ";
    for (auto i : invInterval)
        cout << i << " ";
    cout << endl;

    return 0;
}
