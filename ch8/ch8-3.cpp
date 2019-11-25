#include "statistics.hpp"
using namespace std;
// B073040047 楊志璿

int main() {
    int sampleSize = 60, mean = 80, sd = 15;
    cout << "In (a): " << genConfidenceInterval(mean, errorRadius(15, 0.05, sampleSize)) << endl;
    sampleSize = 120;
    cout << "In (b): " << genConfidenceInterval(mean, errorRadius(15, 0.05, sampleSize)) << endl;
    return 0;
}
