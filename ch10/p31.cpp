#include "../statistics.hpp"

int main() {
    auto alpha = 0.05;
    int n1 = 150, n2 = 170;
    double p1 = 0.78, p2 = 0.6;
    double coSigma = sqrt((p1 * (1 - p1) / n1) + (p2 * (1 - p2) / n2));
    auto radius = coSigma * genZValue(alpha, no);
    auto interval = genConfidenceInterval(p1 - p2, radius);
    cout << "This is problem 31" << endl;

    cout << "In (a) The p1 is " << p1 << endl;
    cout << "In (b) The p2 is " << p2 << endl;
    cout << "In (c) the interval is " << interval << endl;

    return 0;
}