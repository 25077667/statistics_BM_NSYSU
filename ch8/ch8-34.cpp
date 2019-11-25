#include "statistics.hpp"
using namespace std;

int main() {
    int sampleSize;
    sampleSize = needingSampleSize::p(0.05, 0.5, 0.03);  // because for unknown p, using 0.5 to estimate for the conservative n.
    cout << sampleSize << endl;
}
