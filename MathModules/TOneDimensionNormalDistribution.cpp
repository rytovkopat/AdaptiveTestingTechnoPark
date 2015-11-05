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
}

TOneDimensionNormalDistribution::TOneDimensionNormalDistribution(long double m, long double sigma)
        : _m(m), _sigma(sigma)
{
}

TOneDimensionNormalDistribution::TOneDimensionNormalDistribution(unsigned m, unsigned sigma)
        : _m((long double)m), _sigma((long double)sigma)
{
}

TOneDimensionNormalDistribution::TOneDimensionNormalDistribution(unsigned long long m, unsigned long long sigma)
        : _m((long double)m), _sigma((long double)sigma)
{
}

long double TOneDimensionNormalDistribution::GetParameter_M() {
        return _m;
}

long double TOneDimensionNormalDistribution::GetParameter_Sigma() {
        return _sigma;
}

bool TOneDimensionNormalDistribution::_AreParamsValid() {
        return _sigma>0.0 ?: true, false;
}

TOneDimensionNormalDistribution& TOneDimensionNormalDistribution::SetParameter_M(long double value_m) {
        _m=value_m;
        return *this;
}

//add new Exception
OneDimensionNormalDistribution& TOneDimensionNormalDistribution::SetParameter_Sigma(long double value_sigma) {
	if (value_sigma <= 0.0)
		throw TInvalidParametersException;

	_sigma = value_sigma;
	return *this;
}

long double TOneDimensionNormalDistribution::_Density(long double x) {
        //return boost::math::pdf(x,_m,_sigma);
        return 1/(_sigma * sqrt(2*M_PI)) * exp((-(x-_m)*(x-_m)) / (2 * _sigma * _sigma));
}

long double TOneDimensionNormalDistribution::_Function(long double _x) {
        //return boost::math::cdf()
        return (1+erfl((_x-_m)/sqrtl(2*_sigma*_sigma)))/2.0;
}

long double TOneDimensionNormalDistribution::_IntervalProbability(long double _left, long double _right) {
        //boost::math::
        return 0.0;
}
