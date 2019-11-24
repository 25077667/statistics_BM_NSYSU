#include "statistics.hpp"
using namespace std;

int main() {
    int sampleSize;
    sampleSize = needingSampleSize::x_bar(0.05, 3200, 160);
    cout << sampleSize << endl;
}
