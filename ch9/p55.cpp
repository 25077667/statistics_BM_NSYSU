#include "../statistics.hpp"
using namespace std;

int main() {
    double psd = 10, mu_0 = 20, mu_a = 22, alpha = 0.05, beta = 0.05;
    cout << "this is problem 55" << endl;
    cout << "In (a) the sampleSize needs "
         << needingSampleSize::hypothesis(mu_0, mu_a, genZValue(alpha, false), genZValue(beta, false), psd) << endl;
    return 0;
}
