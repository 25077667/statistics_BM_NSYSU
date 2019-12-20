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
#define yes true
#define no false

double genPValue(double z_value, bool isTwoTail = false, bool tailInvertSign = false) {
    // need to add two tail test!
    // add bool isTwotail = false
    // this is the conjugate function of genZValue
    boost::math::normal Ndistribution(0, 1);
    auto P = boost::math::cdf(boost::math::complement(Ndistribution, fabs(z_value)));
    if (isTwoTail && tailInvertSign)
        throw "error range";
    if (tailInvertSign)
        P = 1 - P;
    if (isTwoTail)
        P *= 2;
    return P;
}

double genPValue(double degree, double t_value, bool isTwoTail = false, bool tailInvertSign = false) {
    // this is the conjugate function of genTValue
    // @degree: the degree of freedom
    boost::math::students_t Tdistribution(degree);
    auto P = boost::math::cdf(boost::math::complement(Tdistribution, fabs(t_value)));
    if (isTwoTail && tailInvertSign)
        throw "error range";
    if (tailInvertSign)
        P = 1 - P;
    if (isTwoTail)
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

template <typename Iteratable>
double genMean(Iteratable& _dataSet) {
    double sum = 0;
    for (auto i : _dataSet)
        sum += i;
    return sum / _dataSet.size();
}

template <typename Iteratable>
double genSampleStandardDeviation(Iteratable& _dataSet, double sampleMean, double size) {
    double sxx = 0;
    for (auto i : _dataSet)
        sxx += (i - sampleMean) * (i - sampleMean);
    return sqrt(1 / (size - 1) * sxx);
}

double genPercentageStandardDeviation(double p, int sampleSize) {
    return sqrt(p * (1 - p) / sampleSize);
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

double errorRadius(double knownSigma, double alpha, int sampleSize, bool isSingleTail = false, bool isSample = false) {
    /*
    * @knownSigma: the population sigma, which over sqrt(n)
    * giving alpha return the error radius for known Sigma of Z distribution
    * return the error radius
    */

    if (isSample) {
        if (!isSingleTail)
            alpha /= 2;
        return knownSigma / sqrt(sampleSize) * genTValue(sampleSize - 1, alpha);
    }
    return knownSigma / sqrt(sampleSize) * genZValue(alpha, isSingleTail);
}

pair<double, double> genConfidenceInterval(double theta, double errorRadius, int tailOrient = 0) {
    /*
     * @theta: the sample variable
     * @errorRadius: a radius of error, which might greater than 1,
     *               means the standardDeviation times (z or t) over sqrt(n)
     * @tailOrient: if (tailOrient > 0) will reject right tail
     *              else if (tailOrient < 0) will reject left tail
     *              else will reject two tail
     */
    if (tailOrient > 0)
        return make_pair(-numeric_limits<double>::infinity(), theta + errorRadius);
    else if (tailOrient < 0)
        return make_pair(theta - errorRadius, numeric_limits<double>::infinity());
    else
        return make_pair(theta - errorRadius, theta + errorRadius);
}

vector<pair<double, double>> invertInterval(pair<double, double> originInterval) {
    if (originInterval.first == -numeric_limits<double>::infinity())
        return {make_pair(originInterval.second, numeric_limits<double>::infinity())};
    else if (originInterval.second == numeric_limits<double>::infinity())
        return {make_pair(-numeric_limits<double>::infinity(), originInterval.first)};
    else
        return {make_pair(-numeric_limits<double>::infinity(), originInterval.first),
                make_pair(originInterval.second, numeric_limits<double>::infinity())};
}

pair<double, double> standardlizeInterval(pair<double, double> originInterval, double mu, double standardDeviation) {
    /**
     * @originInterval: the interval need to be standardlized
     * @mu: the mean
     * @standardDeviation: the standard deviation of mu
     */
    return make_pair((originInterval.first - mu) / standardDeviation, (originInterval.second - mu) / standardDeviation);
}

double intervalProbability(pair<double, double> standardlizedInterval) {
    /*
    * this will return the probability with z distribution in some interval
    * @standardlizedInterval: the standardlized interval which want to get the probability
    */
    double leftTail = genPValue(standardlizedInterval.first, false, false),
           rightTail = genPValue(standardlizedInterval.second, false, false);
    return 1 - leftTail - rightTail;
}

template <typename T, typename S>
ostream& operator<<(ostream& os, const pair<T, S>& v) {
    pair<char, char> boundSign('[', ']');
    if (v.first == -numeric_limits<double>::infinity())
        boundSign.first = '(';
    if (v.second == numeric_limits<double>::infinity())
        boundSign.second = ')';
    os << boundSign.first << v.first << ", " << v.second << boundSign.second;
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
int hypothesis(double mu_0, double mu_a, double za, double zb, double sigma) {
    return ceil(pow((za + zb) * sigma / (mu_0 - mu_a), 2));
}
}  // namespace needingSampleSize

double testStatistic(double x_bar, double mu_0, double sd, int sampleSize, bool isSample = false) {
    /**
     * @x_bar: sampleMean
     * @sd: standard deviation
     * @mu_0: the null hypotheses
     * @sampleSize: the sample size which want to againest the H0
     * @isSample: Are we not know the population @sd?
     *          if(false): we don't know the population standard deviation
     */
    if (isSample)
        sampleSize -= 1;
    return (x_bar - mu_0) / (sd / sqrt(sampleSize));
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

string readMultiLineCSV(map<string, map<string, int>>& proportionDataSet, string fileName) {
    // @proportionDataSet: {title, {data, freq}}
    // return file name
    ifstream inFile(fileName, ios::in);
    if (inFile.fail()) {
        cerr << "Open file failed" << endl;
        return "";
    }
    string titles, singleLine;
    vector<string> titlesContainer;
    getline(inFile, titles);
    for (auto index = titles.find(','); index != string::npos; index = titles.find(',')) {
        string firstSubstring(titles.substr(0, index));
        titlesContainer.push_back(firstSubstring);
        titles.erase(0, firstSubstring.length() + 1);
    }
    titlesContainer.push_back(titles);  //push last title

    while (getline(inFile, singleLine)) {
        for (auto i : titlesContainer) {
            auto index = singleLine.find(',');
            string tmp;
            if (index != string::npos)
                tmp = singleLine.substr(0, index);
            else
                tmp = singleLine;  //the last element

            if (tmp.length()) {
                auto isTitleInTable = proportionDataSet.find(i);
                if (isTitleInTable != proportionDataSet.end()) {
                    auto isInMap = isTitleInTable->second.find(tmp);
                    if (isInMap != isTitleInTable->second.end())
                        isTitleInTable->second.at(isInMap->first)++;
                    else
                        isTitleInTable->second.insert(make_pair(tmp, 1));
                } else {
                    auto inMap = make_pair(tmp, 1);
                    proportionDataSet[i].insert(inMap);
                }
            }
            singleLine.erase(0, tmp.length() + 1);
        }
    }
    inFile.close();
    return fileName;
}
#endif
