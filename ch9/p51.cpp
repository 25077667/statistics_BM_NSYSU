#include "../statistics.hpp"
using namespace std;

int main() {
    double psd = 0.8, mu_0 = 16, alpha = 0.05;
    int sampleSize = 30;
    cout << "this is problem 51" << endl;

    auto H0_interval = genConfidenceInterval(mu_0, errorRadius(psd, alpha, sampleSize), 0);
    cout << "In (a) please look hand-write paper." << endl;

    auto project2HaDistridution = standardlizeInterval(H0_interval, 16.5, psd / sqrt(sampleSize));
    auto type2error_area = intervalProbability(project2HaDistridution);
    cout << "In (b) the type 2 error_area is " << type2error_area << endl;
    cout << "In (c) the power of this case is " << 1 - type2error_area << endl;
    return 0;
}
