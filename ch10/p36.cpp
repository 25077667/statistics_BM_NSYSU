#include "../statistics.hpp"

int main() {
    auto alpha = 0.01;
    int n1 = 200, n2 = 200;
    double p1 = 104.0 / 200, p2 = 74.0 / 200;  //p1 is man
    double coSigma = sqrt((p1 * (1 - p1) / n1) + (p2 * (1 - p2) / n2));
    double p_value = genPValue((p1 - p2) / coSigma);
    cout << "This is problem 34" << endl;

    cout << "In (a) Please look at the hand-write paper." << endl;
    cout << "In (b) The p1 is " << p1 << " and the p2 is " << p2 << endl;
    cout << "In (c) the p_vlaue is " << p_value << endl
         << "\tHence we do " << ((p_value < alpha) ? "" : "not ") << "reject H0" << endl;

    return 0;
}