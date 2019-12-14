#include "../statistics.hpp"
using namespace std;

int main() {
    double ssd = 165, mu_0 = 1503, alpha = 0.05, x_bar = 1440;
    int sampleSize = 25;
    cout << "this is problem 33" << endl;

    auto test_statistic = testStatistic(x_bar, mu_0, ssd, sampleSize, true);
    auto p_value = genPValue(test_statistic);
    cout << "In (a) please look hand-write paper." << endl;
    cout << "In (b) " << x_bar << " - " << mu_0 << " = " << x_bar - mu_0 << endl;
    cout << "In (c) test statistic is " << test_statistic << " and p-value is " << p_value << endl;
    cout << "In (c) we do " << ((p_value < alpha) ? "" : "not ") << "reject H0" << endl;
    return 0;
}
