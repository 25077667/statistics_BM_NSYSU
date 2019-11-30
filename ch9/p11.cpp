#include "../statistics.hpp"
using namespace std;

int main() {
    double x_bar = 14.15, psd = 3, mu_0 = 15;
    int sampleSize = 50;
    auto test_statistic = testStatistic(x_bar, mu_0, psd, sampleSize);
    auto p_value = genPValue(test_statistic);
    cout << "this is problem 11" << endl;
    cout << "In (a) " << test_statistic << endl;
    cout << "In (b) " << p_value << endl;

    double alpha = 0.05;
    cout << "In (c) we do " << ((p_value < alpha) ? "" : "not ") << "reject H0" << endl;
    cout << "In (d) please look hand-write paper." << endl;
    return 0;
}