#include "TOneDimensionNormalDistribution.h"
#include <cmath>
#include <boost/math/distributions/normal.hpp>

TOneDimensionNormalDistribution::TOneDimensionNormalDistribution()
        : _m(-1.0), _sigma(-1.0)
{
}

TOneDimensionNormalDistribution::TOneDimensionNormalDistribution(double m, double sigma)
        : _m((long double)m), _sigma((long double)sigma)
{
        if (_sigma <=0.0)
                throw TInvalidParametersException;
}

TOneDimensionNormalDistribution::TOneDimensionNormalDistribution(long double m, long double sigma)
        : _m(m), _sigma(sigma)
{
        if (_sigma <=0.0)
                throw TInvalidParametersException;
}

TOneDimensionNormalDistribution::TOneDimensionNormalDistribution(unsigned m, unsigned sigma)
        : _m((long double)m), _sigma((long double)sigma)
{
        if (_sigma <=0.0)
                throw TInvalidParametersException;
}

TOneDimensionNormalDistribution::TOneDimensionNormalDistribution(unsigned long long m, unsigned long long sigma)
        : _m((long double)m), _sigma((long double)sigma)
{
        if (_sigma <=0.0)
                throw TInvalidParametersException;
}

long double TOneDimensionNormalDistribution::GetParameter_M() {
        return _m;
}

long double TOneDimensionNormalDistribution::GetParameter_Sigma() {
        return _sigma;
}

bool TOneDimensionNormalDistribution::_AreParamsValid() {
        return _sigma>0.0 ? true : false;
}

TOneDimensionNormalDistribution& TOneDimensionNormalDistribution::SetParameter_M(long double value_m) {
        _m=value_m;
        return *this;
}

TOneDimensionNormalDistribution& TOneDimensionNormalDistribution::SetParameter_Sigma(long double value_sigma) {
        if (value_sigma <= 0.0)
                throw TInvalidParametersException;

        _sigma = value_sigma;
        return *this;
}

long double TOneDimensionNormalDistribution::_Density(long double x) {
        //return boost::math::pdf(x,_m,_sigma);
        return 1/(_sigma*sqrt(2*M_PI)) * exp((-(x-_m)*(x-_m)) / (2 * _sigma * _sigma));
}

long double TOneDimensionNormalDistribution::_Function(long double _x) {
        //return boost::math::cdf()
        return (1+erfl((_x-_m)/sqrtl(2*_sigma*_sigma)))/2.0;
}

long double TOneDimensionNormalDistribution::_IntervalProbability(long double _left, long double _right) {
        return _Function(_right)-_Function(_left);
}

long double TOneDimensionNormalDistribution::_ExpectedValue() {
        return _m;
}

long double TOneDimensionNormalDistribution::_Dispersion() {
        return _sigma*_sigma;
}

long double TOneDimensionNormalDistribution::_StandardDeviation() {
        return _sigma;
}

long double TOneDimensionNormalDistribution::GetDensity(double x) {
        return _Density((long double)x);
}

long double TOneDimensionNormalDistribution::GetDensity(long double x) {
        return _Density(x);
}

long double TOneDimensionNormalDistribution::GetFunctionValue(double x) {
        return _Function((long double)x);
}

long double TOneDimensionNormalDistribution::GetFunctionValue(long double x) {
        return _Function(x);
}

long double TOneDimensionNormalDistribution::GetFunctionValue(unsigned n) {
        return _Function((long double)n);
}

long double TOneDimensionNormalDistribution::GetFunctionValue(unsigned long long n) {
        return _Function((long double)n);
}

long double TOneDimensionNormalDistribution::GetCumulativeFunctionValue(double x) {
        return _Function((long double)x);
}

long double TOneDimensionNormalDistribution::GetCumulativeFunctionValue(long double x) {
        return _Function(x);
}

long double TOneDimensionNormalDistribution::GetCumulativeFunctionValue(unsigned n) {
        return _Function((long double)n);
}

long double TOneDimensionNormalDistribution::GetCumulativeFunctionValue(unsigned long long n) {
        return _Function((long double)n);
}

long double TOneDimensionNormalDistribution::GetIntervalProbability(double LeftBound, double RightBound) {
        return GetIntervalProbability((long double) LeftBound, (long double) RightBound);
}

long double TOneDimensionNormalDistribution::GetIntervalProbability(long double LeftBound, long double RightBound) {
        if (LeftBound<RightBound)
                return _IntervalProbability(LeftBound, RightBound);
        else
                return _IntervalProbability(RightBound, LeftBound);
}

long double TOneDimensionNormalDistribution::GetExpectedValue() {
        return _ExpectedValue();
}

long double TOneDimensionNormalDistribution::GetDispersion() {
        return _Dispersion();
}

long double TOneDimensionNormalDistribution::GetStandardDeviation() {
        return _StandardDeviation();
}
