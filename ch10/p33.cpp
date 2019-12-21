#include "../statistics.hpp"

int main() {
    auto alpha = 0.05;
    int n1 = 884, n2 = 575;
    double p1 = 663.0 / 884, p2 = 414.0 / 575;
    double coSigma = sqrt((p1 * (1 - p1) / n1) + (p2 * (1 - p2) / n2));
    auto radius = coSigma * genZValue(alpha, no);
    auto interval = genConfidenceInterval(p1 - p2, radius);
    cout << "This is problem 33" << endl;

    cout << "In (a) Please look at the hand-write paper." << endl;
    cout << "In (b) The p1 is " << p1 << endl;
    cout << "In (c) The p2 is " << p2 << endl;
    cout << "In (d) the interval is " << interval << endl;

    return 0;
}