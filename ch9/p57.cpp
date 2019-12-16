#include "../statistics.hpp"
using namespace std;

int main() {
    double psd = 30, mu_0 = 400, mu_a = 385, alpha = 0.02, beta = 0.10;
    cout << "this is problem 57" << endl;
    cout << "The Z_alpha/2: " << genZValue(alpha, false) << " and the Z_beta/2: " << genZValue(beta, false) << endl;
    cout << "In (a) the sampleSize needs "
         << needingSampleSize::hypothesis(mu_0, mu_a, genZValue(alpha, false), genZValue(beta, false), psd) << endl;
    return 0;
}
