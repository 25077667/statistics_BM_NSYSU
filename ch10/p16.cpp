#include "../statistics.hpp"

int main() {
    auto alpha = 0.05;
    auto collegeGrads = {485, 531, 650, 554, 550, 572, 497, 592, 487, 533, 526, 410, 515, 578, 448, 469};
    auto highSchoolGrads = {442, 580, 479, 486, 528, 524, 492, 478, 425, 485, 390, 535};
    auto collegeMean = genMean(collegeGrads), highSchoolMean = genMean(highSchoolGrads);
    auto collegeSSD = genSampleStandardDeviation(collegeGrads, collegeMean, collegeGrads.size());
    auto highSchoolSSD = genSampleStandardDeviation(highSchoolGrads, highSchoolMean, highSchoolGrads.size());
    auto coSigma = sqrt(collegeSSD * collegeSSD / collegeGrads.size() + highSchoolSSD * highSchoolSSD / highSchoolGrads.size());
    auto degreeOfFreedom = twoPopulationDegreeFreedom(collegeGrads, highSchoolGrads);
    auto p_value = genPValue(degreeOfFreedom, (collegeMean - highSchoolMean) / coSigma);
    cout << "This is problem 16" << endl;

    cout << "In (a) Please look at the hand-write paper." << endl;
    cout << "In (b) the point estimate of the difference between these two " << collegeMean - highSchoolMean << endl;
    cout << "In (c) the p-value is " << p_value << endl;
    cout << "In (d) We do " << ((p_value < alpha) ? "" : "not ") << "reject H0" << endl;

    return 0;
}