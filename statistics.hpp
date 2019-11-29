#include <boost/math/distributions/normal.hpp>
#include <boost/math/distributions/students_t.hpp>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <utility>
#include <vector>
// this header for all except for ch8
// MIT LICENSE
#ifndef STATISTICS_HPP
#define STATISTICS_HPP
using namespace std;

double genPValue(double z_value, bool isSingleTail) {
    // this is the conjugate function of genZValue
    boost::math::normal Ndistribution(0, 1);
    z_value = fabs(z_value);
    auto P = boost::math::cdf(boost::math::complement(Ndistribution, z_value));
    if (!isSingleTail)
        P *= 2;
    return P;
}

double genZValue(double subscript, bool isSingleTail) {
    /*
    * @subscript: the score below the "z", which means the cumulative distribution function of the area. 
    *             if subscript is negative meaning it is left tail, possitive otherwise
    * @isSingleTail: is only sigle tail of the reject area
    * return the z-score which lookup from the z-table 
    */
    boost::math::normal Ndistribution(0, 1);
    if (!isSingleTail)
        subscript /= 2;
    auto Z = boost::math::quantile(boost::math::complement(Ndistribution, fabs(subscript)));
    if (subscript < 0)
        Z = -Z;
    return Z;
}

double genTValue(int degree, double upperTailArea) {
    boost::math::students_t Tdistribution(degree);
    auto T = boost::math::quantile(boost::math::complement(Tdistribution, upperTailArea));
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
    return knownSigma / sqrt(sampleSize) * genZValue(alpha, false);
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
    double q = 1 - p, z = genZValue(alpha, false);
    auto sampleSize = p * q * z * z / marginError / marginError;
    return ceil(sampleSize);
}

int x_bar(double alpha, double knownTheta, double marginError) {
    /*
    * @knownTheta: the sigma which is the population standard deviation
    * @marginError: the margin error of confidence interval
    */
    double z = genZValue(alpha, false);
    auto sampleSize = z * z * knownTheta * knownTheta / marginError / marginError;
    return ceil(sampleSize);
}
}  // namespace needingSampleSize

double testStatistic(double x_bar, double mu_0, double psd, int sampleSize) {
    return (x_bar - mu_0) / (psd / sqrt(sampleSize));
}

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
