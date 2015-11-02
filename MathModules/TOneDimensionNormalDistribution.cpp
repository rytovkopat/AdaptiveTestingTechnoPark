#include "TOneDimensionNormalDistribution.h"

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


