#include "../statistics.hpp"
using namespace std;

int main() {
    map<string, int> table;
    string title = readSingleLineCSV(table, "LawSuit.csv");
    int sampleSize = table.at("Yes") + table.at("No");
    double p_0 = 0.5, alpha = 0.01, p_bar = (table.at("Yes") * 1.0 / sampleSize);
    double sd = genPercentageStandardDeviation(p_0, sampleSize);
    cout << "this is problem 44" << endl;

    auto test_statistic = (p_bar - p_0) / sd;
    auto p_value = genPValue(test_statistic);
    cout << "In (a) please look hand-write paper." << endl;
    cout << "In (b) test statistic is " << test_statistic << " and p-value is " << p_value << endl;
    cout << "In (c) we do " << ((p_value < alpha) ? "" : "not ") << "reject H0" << endl;
    return 0;
}
