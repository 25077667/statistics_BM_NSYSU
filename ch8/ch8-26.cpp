#include "statistics.hpp"
using namespace std;

int main() {
    int sampleSize[3];
    sampleSize[0] = needingSampleSize::x_bar(0.05, 0.07, 0.03);
    sampleSize[1] = needingSampleSize::x_bar(0.05, 0.07, 0.02);
    sampleSize[2] = needingSampleSize::x_bar(0.05, 0.07, 0.01);

    cout << "For (a): " << sampleSize[0] << endl
         << "For (b): " << sampleSize[1] << endl
         << "For (c): " << sampleSize[2] << endl;
}
