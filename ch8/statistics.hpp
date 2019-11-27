#include <boost/math/distributions/normal.hpp>
#include <boost/math/distributions/students_t.hpp>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <utility>
#include <vector>
// B073040047 楊志璿
#ifndef STATISTICS_HPP
#define STATISTICS_HPP
using namespace std;

double genZValue(double alpha) {
    // get how many times of standard error in Z distribution
    boost::math::normal Ndistribution(0, 1);
    auto Z = boost::math::quantile(complement(Ndistribution, alpha / 2));
    /*double sum = 0, i = 10, dx = 0.000001;
    for (; sum < alpha / 2; i -= dx)
        sum += dx / sqrt(2 * acos(-1)) * exp(-0.5 * i * i);
        https://www.boost.org/doc/libs/1_38_0/libs/math/doc/sf_and_dist/html/math_toolkit/dist/dist_ref/dists/normal_dist.html
    */
    return Z;
}

double genTValue(int degree, double upperTailArea) {
    boost::math::students_t Tdistribution(degree);
    auto T = boost::math::quantile(complement(Tdistribution, upperTailArea));  // some black magic
    return T;
}

double genMean(vector<double>& _dataSet) {
    double sum = 0;
    for (auto i : _dataSet)
        sum += i;
    return sum / _dataSet.size();
}

double genSampleStandardDeviation(vector<double>& _dataSet, double sampleMean, double size) {
    double sxx = 0;
    for (auto i : _dataSet)
        sxx += (i - sampleMean) * (i - sampleMean);
    return sqrt(1 / (size - 1) * sxx);
}

double errorRadius(vector<double>& _dataSet, int degree, int sampleSize, double upperTailArea) {
    double mean = genMean(_dataSet);
    double ssd = genSampleStandardDeviation(_dataSet, mean, sampleSize);
    return ssd / sqrt(sampleSize) * genTValue(degree, upperTailArea);
}

double errorRadius(vector<double>& _dataSet, double upperTailArea = 0.025) {
    /*
    * giving data set and the upper tail area of Student-T distribution
    * return the error radius
    * for too lazy to only input data set
    */
    int sampleSize = _dataSet.size();
    return errorRadius(_dataSet, sampleSize - 1, sampleSize, upperTailArea);
}

double errorRadius(double knownSigma, double alpha, int sampleSize) {
    /*
    * @knownSigma: the population sigma, which over sqrt(n)
    * giving alpha return the error radius for known Sigma of Z distribution
    * return the error radius
    */
    return knownSigma / sqrt(sampleSize) * genZValue(alpha);
}

pair<double, double> genConfidenceInterval(double theta, double errorRadius) {
    /*
     * @theta: the sample variable
     * @errorRadius: a radius of error, which might greater than 1,
     *               means the standardDeviation times (z or t) over sqrt(n)
     */
    return make_pair(theta - errorRadius, theta + errorRadius);
}

template <typename T, typename S>
ostream& operator<<(ostream& os, const pair<T, S>& v) {
    os << "[" << v.first << ", " << v.second << "]";
    return os;
}

namespace needingSampleSize {
int p(double alpha, double p = 0.5, double marginError = 0.95) {
    /*
    * @p: the p bar of sample proportions, which might be iid Ber(P) (Bernoulli distribution)
    * @marginError: the margin error of confidence interval
    */
    double q = 1 - p, z = genZValue(alpha);
    auto sampleSize = p * q * z * z / marginError / marginError;
    return ceil(sampleSize);
}

int x_bar(double alpha, double knownTheta, double marginError) {
    /*
    * @knownTheta: the sigma which is the population standard deviation
    * @marginError: the margin error of confidence interval
    */
    double z = genZValue(alpha);
    auto sampleSize = z * z * knownTheta * knownTheta / marginError / marginError;
    return ceil(sampleSize);
}
}  // namespace needingSampleSize

template <class T>
string readSingleLineCSV(vector<T>& _dataSet, string fileName) {
    /* will return the file's title
    * read only single line csv file
    * @_dataSet: a container you want to storge at
    * @fileName: fileName
    */
    ifstream inFile(fileName, ios::in);
    if (inFile.fail()) {
        cerr << "Open file failed" << endl;
        return "";
    }
    string title;
    T rawdata;
    getline(inFile, title);
    while (inFile >> rawdata)
        _dataSet.push_back(rawdata);
    inFile.close();
    return title;
}

template <class T>
string readSingleLineCSV(map<T, int>& proportionDataSet, string fileName) {
    /* 
    * only for reading proportion Data
    * will return the file's title
    * read only single line csv file
    * @proportionDataSet: a container you want to storge at
    * @fileName: fileName
    */
    ifstream inFile(fileName, ios::in);
    if (inFile.fail()) {
        cerr << "Open file failed" << endl;
        return "";
    }
    string title;
    T rawData;
    getline(inFile, title);
    while (getline(inFile, rawData)) {
        auto isInMap = proportionDataSet.find(rawData);
        if (isInMap != proportionDataSet.end())
            proportionDataSet.at(isInMap->first)++;
        else
            proportionDataSet.insert(pair<T, int>(rawData, 1));
    }
    inFile.close();
    return title;
}

#endif
