#include "../statistics.hpp"

int main() {
    double x_bar1 = 85.36, x_bar2 = 81.4, sigma1 = 4.55, sigma2 = 3.97, alpha = 0.05;
    int n1 = 37, n2 = 44;
    auto coSigma = sqrt(sigma1 * sigma1 / n1 + sigma2 * sigma2 / n2);
    auto radius = coSigma * genZValue(alpha / 2, true);
    cout << "This is problem 4" << endl;

    cout << "In (a) \\bar x_1 - \\bar x_2 is " << x_bar1 - x_bar2 << endl;
    cout << "In (b) error radius is " << radius << endl;
    auto interval = genConfidenceInterval(x_bar1 - x_bar2, radius);
    cout << "In (c) in " << (1 - alpha) * 100 << "% confidence interval is in " << interval << endl;

    return 0;
}