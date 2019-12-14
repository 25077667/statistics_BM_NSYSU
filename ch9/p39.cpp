#include "../statistics.hpp"
using namespace std;

int main() {
    cout << "this is problem 39" << endl;
    map<string, map<string, int>> table;
    string a = readMultiLineCSV(table, "HomeState.csv");
    double p_0 = 0.577, alpha = 0.05;
    int counter = 0;
    cout << "In (a) please look hand-write paper." << endl;
    for (auto i : table) {
        cout << "In (" << char('b' + counter++) << ") " << i.first << " ";
        unsigned int sampleSize = i.second.at("Yes") + i.second.at("No");
        auto p_bar = i.second.at("Yes") * 1.0 / sampleSize;
        double sd = genPercentageStandardDeviation(p_0, sampleSize);
        auto test_statistic = (p_bar - p_0) / sd;
        auto p_value = genPValue(test_statistic, true);
        cout << "The p bar is " << p_bar << ", the p-value is " << p_value << ". "
             << "We do " << ((p_value < alpha) ? "" : "not ") << "reject H0 in " << i.first << endl;
    }
    cout << "In (d) please look hand-write paper." << endl;

    return 0;
}
