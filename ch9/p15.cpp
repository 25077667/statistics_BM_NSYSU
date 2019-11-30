#include "../statistics.hpp"
using namespace std;

int main() {
    double psd = 1600, mu_0 = 1056, alpha = 0.05, x_bar = 910;
    int sampleSize = 400;
    cout << "this is problem 15" << endl;

    auto test_statistic = testStatistic(x_bar, mu_0, psd, sampleSize);
    auto p_value = genPValue(test_statistic, false);
    cout << "In (a) please look hand-write paper." << endl;
    cout << "In (b) test statistic is " << test_statistic  << " and p-value is " << p_value << endl;
    
    cout << "In (c) we do " << ((p_value < alpha) ? "" : "not ") << "reject H0" << endl;
    cout << "In (d) please look hand-write paper." << endl;
    return 0;
}