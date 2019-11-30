#include "../statistics.hpp"
using namespace std;

int main() {
    double psd = 300, mu_0 = 838, alpha = 0.01, x_bar = 745;
    int sampleSize = 60;
    cout << "this is problem 20" << endl;

    auto test_statistic = testStatistic(x_bar, mu_0, psd, sampleSize);
    auto p_value = genPValue(test_statistic, true);
    cout << "In (a) please look hand-write paper." << endl;
    cout << "In (b) test statistic is " << test_statistic << endl;
    cout << "In (c) p - value is " << p_value << endl;
    cout << "In (d) we do " << ((p_value < alpha) ? "" : "not ") << "reject H0" << endl;
    return 0;
}