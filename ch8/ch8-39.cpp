#include "statistics.hpp"
using namespace std;

int main() {
    double p = 0.16;
    cout << needingSampleSize::p(0.05, p, 0.03) << endl;
    cout << needingSampleSize::p(0.01, p, 0.03) << endl;
    return 0;
}
