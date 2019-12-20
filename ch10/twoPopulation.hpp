#include <cmath>
struct Company {
    double year1, year2, coSigma, p_value, testStatistic;
    auto genSelfPValue() {
        return p_value = genPValue((year1 - year2) / coSigma);
    }
    auto genTestStatistic() {
        return testStatistic = (year1 - year2) / coSigma;
    }
    Company(double _year1, double _year2, double _coSigma) {
        year1 = _year1;
        year2 = _year2;
        coSigma = _coSigma;
        genSelfPValue();
        genTestStatistic();
    }
    Company(double _year1, double _year2, double sigma1, double sigma2, int sampleSize) {
        year1 = _year1;
        year2 = _year2;
        coSigma = std::sqrt((sigma1 * sigma1 / sampleSize) + (sigma2 * sigma2 / sampleSize));
        genSelfPValue();
        genTestStatistic();
    }
};