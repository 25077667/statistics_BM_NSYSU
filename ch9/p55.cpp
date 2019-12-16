#include "../statistics.hpp"
using namespace std;

int main() {
    double psd = 10, mu_0 = 20, mu_a = 22, alpha = 0.05, beta = 0.05;
    cout << "this is problem 55" << endl;
    cout << "The Z_alpha/2: " << genZValue(alpha, false) << " and the Z_beta/2: " << genZValue(beta, false) << endl;
    cout << "The sampleSize needs "
         << needingSampleSize::hypothesis(mu_0, mu_a, genZValue(alpha, false), genZValue(beta, false), psd) << endl;
    return 0;
}
