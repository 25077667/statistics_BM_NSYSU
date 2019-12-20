#include "../statistics.hpp"
#include "twoPopulation.hpp"

bool isGreatherThanAverage(Company c, double alpha) {
    double nationalAvg = 75.7;
    auto p_value = genPValue((c.year2 - nationalAvg) / (6 / sqrt(60)));
    return p_value < alpha;
}

int main() {
    double sigma = 6, alpha = 0.05;
    int sampleSize = 60;
    Company Aid(73, 76, sigma, sigma, sampleSize),
        Expedia(75, 77, sigma, sigma, sampleSize),
        Penney(77, 78, sigma, sigma, sampleSize);
    cout << "This is problem 8" << endl;
    cout << "In (a) Rite Aid test statistic is " << Aid.testStatistic << " and p_value is " << Aid.p_value << endl
         << "\tHence we do " << ((Aid.p_value < alpha) ? "" : "not ") << "reject H0" << endl;
    cout << "In (b) is " << ((Aid.p_value < alpha && isGreatherThanAverage(Aid, alpha)) ? "" : "not ") << "reject H0." << endl;

    cout << "In (c) Expedia test statistic is " << Expedia.testStatistic << " and p_value is " << Expedia.p_value << endl
         << "\tHence we do " << ((Expedia.p_value < alpha) ? "" : "not ") << "reject H0" << endl;

    cout << "In (d) Please look at hand-write paper." << endl;
    cout << "In (e) Expedia test statistic is " << Penney.testStatistic << " and p_value is " << Penney.p_value << endl;

    return 0;
}