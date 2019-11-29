#include "../statistics.hpp"
using namespace std;

int main() {
    double x_bar = 26.4, psd = 6, mu_0 = 25;
    int sampleSize = 40;
    auto test_statistic = testStatistic(x_bar, mu_0, psd, sampleSize);
    auto p_value = genPValue(test_statistic, true);
    cout << "this is problem 10" << endl;
    cout << "In (a) " << test_statistic << endl;
    cout << "In (b) " << p_value << endl;

    double alpha = 0.01;
    cout << "In (c) we do " << ((p_value < alpha) ? "" : "not ") << "reject H0" << endl;
    cout << "In (d) please look hand-write paper." << endl;
    return 0;
}