#include "../statistics.hpp"
using namespace std;

int main() {
    double psd = 1.3, mu_0 = 10.6, alpha = 0.02;
    int sampleSize = 30;
    cout << "this is problem 49" << endl;

    auto H0_interval = genConfidenceInterval(mu_0, errorRadius(psd, alpha, sampleSize, true), -1);
    auto rejectRegin = invertInterval(H0_interval);
    cout << "In (a) the reject regin is ";
    for (auto i : rejectRegin)
        cout << i << " ";
    cout << endl;

    auto project2HaDistridution = standardlizeInterval(H0_interval, 9.7, psd / sqrt(sampleSize));
    auto type2error_area = intervalProbability(project2HaDistridution);
    cout << "In (b) the type 2 error_area is " << type2error_area << endl;

    project2HaDistridution = standardlizeInterval(H0_interval, 10.2, psd / sqrt(sampleSize));
    type2error_area = intervalProbability(project2HaDistridution);
    cout << "In (c) the type 2 error_area is " << type2error_area << endl;

    project2HaDistridution = standardlizeInterval(H0_interval, 10.8, psd / sqrt(sampleSize));
    type2error_area = intervalProbability(project2HaDistridution);
    cout << "In (d) the type 2 error_area is " << type2error_area << endl;
    return 0;
}
