#include "../statistics.hpp"

int main() {
    auto alpha = 0.05;
    vector<double> math = {540, 432, 528, 574, 448, 502, 480, 499, 610, 572, 390, 593};
    vector<double> writing = {474, 380, 463, 612, 420, 526, 430, 459, 615, 541, 335, 613};
    vector<double> di;
    for (size_t i = 0; i < math.size(); i++) {
        di.push_back(math.at(i) - writing.at(i));
    }
    auto mean = genMean(di);
    auto ssd = genSampleStandardDeviation(di, mean, di.size());
    auto p_value = genPValue(math.size() - 1, mean / (ssd / sqrt(di.size())), yes);
    cout << "This is problem 25" << endl;

    cout << "In (a) The p_value is " << p_value << endl;
    cout << "In (b) the D_bar is " << mean << endl;

    return 0;
}