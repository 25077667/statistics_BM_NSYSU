#include "statistics.hpp"
using namespace std;

int main() {
    double p_bar = 574.0 / 1007;
    double _errorRadius = errorRadius(p_bar , 0.1, 1007);
    cout << "In (a). p bar is " << p_bar << endl;
    cout << "In (b). margin error is " << _errorRadius << endl;
    cout << "In (c). the confidence interval " << genConfidenceInterval(p_bar, _errorRadius) << endl;
    cout << "In (d). the confidence interval " << genConfidenceInterval(p_bar, errorRadius(p_bar, 0.05, 1007)) << endl;
}
