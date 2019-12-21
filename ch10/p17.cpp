#include "../statistics.hpp"

int main() {
    double x_bar1 = 6.82, x_bar2 = 6.25, sampleSigma1 = 0.64, sampleSigma2 = 0.75, alpha = 0.05;
    int n1 = 16, n2 = 10;
    auto coSigma = sqrt(sampleSigma1 * sampleSigma1 / n1 + sampleSigma2 * sampleSigma2 / n2);
    auto test_statistic = (x_bar1 - x_bar2) / coSigma;
    auto df = twoPopulationDegreeFreedom(sampleSigma1, sampleSigma2, n1, n2);
    auto p_value = genPValue(df, test_statistic);
    cout << "This is problem 7" << endl;

    cout << "In (a) please look at the hand-write paper " << endl;
    cout << "In (b) the test statistics is " << test_statistic << endl;
    cout << "In (c) p_value is " << p_value << endl;
    cout << "In (d) we do " << ((p_value < alpha) ? "" : "not ") << "reject H0" << endl;

    return 0;
}