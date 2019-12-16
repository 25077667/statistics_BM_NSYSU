#include "../statistics.hpp"
using namespace std;

int main() {
    double psd = 1.3, mu_0 = 10.6, mu_a = 10.2, alpha = 0.02, beta = 0.2;
    cout << "this is problem 59" << endl;
    cout << "The Z_alpha: " << genZValue(alpha, true) << " and the Z_beta: " << genZValue(beta, true) << endl;
    cout << "In (a) the sampleSize needs "
         << needingSampleSize::hypothesis(mu_0, mu_a, genZValue(alpha, true), genZValue(beta, true), psd) << endl;
    return 0;
}
