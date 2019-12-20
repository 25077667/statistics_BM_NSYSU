#include "../statistics.hpp"

int main() {
    double x_bar1 = 86, x_bar2 = 85, sigma = 12, alpha = 0.05;
    int n1 = 86, n2 = 85;
    auto coSigma = sqrt(sigma * sigma / n1 + sigma * sigma / n2);
    auto radius = coSigma * genZValue(alpha, true);
    auto theta = (x_bar1 - x_bar2) / coSigma;
    auto p_value = genPValue(theta, yes);
    cout << "This is problem 7" << endl;

    cout << "In (a) please look at the hand-write paper " << endl;
    cout << "In (b) the test statistics is " << theta << " and p_value is " << p_value << endl
         << "\tHence we do " << ((p_value < alpha) ? "" : "not ") << "reject H0" << endl;
    auto interval = genConfidenceInterval(x_bar1 - x_bar2, radius);
    cout << "In (c) in " << (1 - alpha) * 100 << "% confidence interval is in " << interval << endl;

    return 0;
}