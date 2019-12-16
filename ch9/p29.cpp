#include <sstream>
#include "../statistics.hpp"
using namespace std;

void convertMoneyList(vector<double>& moneyList, map<string, map<string, int>>& originTable) {
    for (auto i : originTable) {
        for (auto j : i.second) {
            string s(j.first.begin() + 1, j.first.end());
            stringstream ss;
            double tmp;
            ss << s;
            ss >> tmp;
            for (int k = 0; k < j.second; k++)
                if (tmp)
                    moneyList.push_back(tmp);
        }
    }
}

int main() {
    double mu_0 = 21.62, alpha = 0.05;
    int sampleSize = 42;
    map<string, map<string, int>> table;
    auto title = readMultiLineCSV(table, string("ResidentialWater.csv"));
    vector<double> moneyList;
    convertMoneyList(moneyList, table);
    double x_bar = genMean(moneyList);
    double ssd = genSampleStandardDeviation(moneyList, x_bar, moneyList.size());

    cout << "this is problem 29" << endl;
    auto p_value = genPValue((x_bar - mu_0) * sqrt(sampleSize) / ssd, true);
    auto interval = genConfidenceInterval(mu_0, errorRadius(moneyList));

    cout << "In (a) please look hand-write paper." << endl;
    cout << "In (b) the p-value is " << p_value << " by the samle mean: " << x_bar << endl;
    cout << "In (c) we do " << ((p_value < alpha) ? "" : "not ") << "reject H0" << endl;
    cout << "In (d) the ciritical value is " << interval.first << " and " << interval.second << endl;

    return 0;
}
