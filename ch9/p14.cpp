#include "../statistics.hpp"
using namespace std;

int main() {
    double psd = 10, mu_0 = 22, alpha = 0.05;
    ;
    int sampleSize = 75;
    cout << "this is problem 14" << endl;

    auto test_statistic = testStatistic(23, mu_0, psd, sampleSize);
    auto p_value = genPValue(test_statistic, true);
    cout << "In (a) " << p_value << ".\n we do " << ((p_value < alpha) ? "" : "not ") << "reject H0" << endl;

    test_statistic = testStatistic(25.1, mu_0, psd, sampleSize);
    p_value = genPValue(test_statistic, true);
    cout << "In (b) " << p_value << ".\n we do " << ((p_value < alpha) ? "" : "not ") << "reject H0" << endl;
    
    test_statistic = testStatistic(20, mu_0, psd, sampleSize);
    p_value = genPValue(test_statistic, true);
    cout << "In (c) " << p_value << ".\n we do " << ((p_value < alpha) ? "" : "not ") << "reject H0" << endl;
    return 0;
}