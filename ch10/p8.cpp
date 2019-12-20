#include "../statistics.hpp"
struct Company {
    Company(double _y1, double _y2) {
        y1 = _y1;
        y2 = _y2;
        p_value = 0;
    }
    void genSelfPValue(double coSigma) {
        p_value = genPValue((y2 - y1) / coSigma);
    }
    double y1, y2, p_value;
};

int main() {
    Company Aid(73, 71), Expedia(75, 77), Penney(77, 78);
    double sigma = 12, alpha = 0.05;
    int sampleSize = 60;
    auto coSigma = sqrt(sigma * sigma / sampleSize + sigma * sigma / sampleSize);
    auto radius = coSigma * genZValue(alpha, true);
    cout << "This is problem 7" << endl;

    Aid.genSelfPValue(coSigma);
    Expedia.genSelfPValue(coSigma);
    Penney.genSelfPValue(coSigma);

    cout << "In (a) Rite Aid p_value is " << Aid.p_value << endl
         << "\tHence we do " << ((Aid.p_value < alpha) ? "" : "not ") << "reject H0" << endl;

    auto interval = genConfidenceInterval(x_bar1 - x_bar2, radius);
    cout << "In (c) in " << (1 - alpha) * 100 << "% confidence interval is in " << interval << endl;

    return 0;
}