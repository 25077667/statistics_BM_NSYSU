#include "statistics.hpp"
using namespace std;
// B073040047 楊志璿

int main() {
    cout << "In a: " << genTValue(12, 0.025) << endl;
    cout << "In b: " << -genTValue(50, 0.05) << endl;
    cout << "In c: " << genTValue(30, 0.01) << endl;
    cout << "In d: " << -genTValue(25, 0.1) << ", " << genTValue(25, 0.1) << endl;
    cout << "In e: " << -genTValue(45, 0.05) << ", " << genTValue(45, 0.05) << endl;
    return 0;
}
