#include "statistics.hpp"
using namespace std;
// B073040047 楊志璿

int main() {
    auto alpha = 0.05;
    auto marginError = errorRadius(5.5, alpha, 10);
    cout << marginError << endl;
    alpha = 0.01;
    marginError = errorRadius(5.5, alpha, 10);
    cout << marginError << endl;
    return 0;
}
