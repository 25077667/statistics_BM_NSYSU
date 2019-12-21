#include "../statistics.hpp"

int main() {
    auto alpha = 0.05;
    int n1 = 119, n2 = 162;
    double p1 = 24.0 / 119, p2 = 18.0 / 162;
    double coSigma = sqrt((p1 * (1 - p1) / n1) + (p2 * (1 - p2) / n2));
    double p_vlaue = genPValue((p1 - p2) / coSigma);
    cout << "This is problem 34" << endl;

    cout << "In (a) Please look at the hand-write paper." << endl;
    cout << "In (b) The p1 is " << p1 << endl;
    cout << "In (c) The p2 is " << p2 << endl;
    cout << "In (d) the p_vlaue is " << p_vlaue << endl;

    return 0;
}