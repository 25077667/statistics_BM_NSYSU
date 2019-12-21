#include "../statistics.hpp"

int main() {
    auto alpha = 0.05;
    auto privateCollege = {52.8, 43.2, 45.0, 33.3, 44.0, 30.6, 45.8, 37.8, 50.5, 42.0};
    auto publicCollege = {20.3, 22.0, 28.2, 15.6, 24.1, 28.5, 22.8, 25.8, 18.5, 25.6, 14.4, 21.8};
    auto privateMean = genMean(privateCollege), publicMean = genMean(publicCollege);
    auto privateSSD = genSampleStandardDeviation(privateCollege, privateMean, privateCollege.size());
    auto publicSSD = genSampleStandardDeviation(publicCollege, publicMean, publicCollege.size());
    auto coSigma = sqrt(privateSSD * privateSSD / privateCollege.size() + publicSSD * publicSSD / publicCollege.size());
    auto df = twoPopulationDegreeFreedom(privateCollege, publicCollege);
    auto radius = coSigma * genTValue(df, alpha / 2);
    auto interval = genConfidenceInterval(privateMean - publicMean, radius);
    cout << "This is problem 13" << endl;

    cout << "In (a) \nPrivate College: " << endl
         << "\tmean is " << privateMean << " and sample standard deviation is " << privateSSD << endl
         << "Public College: " << endl
         << "\tmean is " << publicMean << " and sample standard deviation is " << publicSSD << endl;

    cout << "In (b) the point estimate of the difference between these two " << privateMean - publicMean << endl;
    cout << "In (c) in " << (1 - alpha) * 100 << "% confidence interval is in " << interval << endl;

    return 0;
}