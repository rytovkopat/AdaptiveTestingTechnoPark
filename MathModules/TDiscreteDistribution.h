#ifndef T_DISCRETE_DISTRIBUTION_H
#define T_DISCRETE_DISTRIBUTION_H

#include "TDistribution.h"
#include "DiscreteDistributionExceptions.h"

class TDiscreteDistribution : public TDistribution
{
public:
	virtual ~TDiscreteDistribution() = 0;
	
	virtual long double GetDensity(double x)
	{
		SendDiscreteDensityException();
	}
	virtual long double GetDensity(long double x) = 0
	{
		SendDiscreteDensityException();
	}
	virtual long double GetProbability(unsigned n) = 0;
	virtual long double GetProbability(unsigned long long n) = 0;
	
	virtual long double GetFunctionValue(double x)
	{
		SendFloatArgumentException();
	}
	virtual long double GetFunctionValue(long double x)
	{
		SendFloatArgumentException();
	}
	virtual long double GetFunctionValue(unsigned n) = 0;
	virtual long double GetFunctionValue(unsigned long long n) = 0;
	virtual long double GetCumulativeFunctionValue(double x)
	{
		SendFloatArgumentException();
	}
	virtual long double GetCumulativeFunctionValue(long double x)
	{
		SendFloatArgumentException();
	}
	virtual long double GetCumulativeFunctionValue(unsigned n) = 0;
	virtual long double GetCumulativeFunctionValue(unsigned long long n) = 0;
	
	virtual unsigned long long GetQuantile(double Level) = 0;
	
	virtual long double GetIntervalProbability(double LeftBound, double RightBound) = 0;
	virtual long double GetIntervalProbability(long double LeftBound, long double RightBound) = 0;
	
	virtual long double GetExpectedValue() = 0;
	virtual long double GetDispersion() = 0;
	virtual long double GetStandardDeviation() = 0;

	virtual bool CriteriaExpectedLeft(const TCommonSample<long double> &Sample, long double DefaultExpectedValue, double Level)
	{
		SendFloatArgumentException();
	}
	virtual bool CriteriaExpectedRight(const TCommonSample<long double> &Sample, long double DefaultExpectedValue, double Level)
	{
		SendFloatArgumentException();
	}
	virtual bool CriteriaExpectedCenter(const TCommonSample<long double> &Sample, long double DefaultExpectedValue, double Level)
	{
		SendFloatArgumentException();
	}
	virtual bool CriteriaDeviationLeft(const TCommonSample<long double> &Sample, long double DefaultDeviation, double Level)
	{
		SendFloatArgumentException();
	}
	virtual bool CriteriaDeviationRight(const TCommonSample<long double> &Sample, long double DefaultDeviation, double Level)
	{
		SendFloatArgumentException();
	}
	virtual bool CriteriaDeviationCenter(const TCommonSample<long double> &Sample, long double DefaultDeviation, double Level)
	{
		SendFloatArgumentException();
	}
	
	virtual bool CriteriaExpectedLeft(const TCommonSample<unsigned long long> &Sample, long double DefaultExpectedValue, double Level) = 0;
	virtual bool CriteriaExpectedRight(const TCommonSample<unsigned long long> &Sample, long double DefaultExpectedValue, double Level) = 0;
	virtual bool CriteriaExpectedCenter(const TCommonSample<unsigned long long> &Sample, long double DefaultExpectedValue, double Level) = 0;
	virtual bool CriteriaDeviationLeft(const TCommonSample<unsigned long long> &Sample, long double DefaultDeviation, double Level) = 0;
	virtual bool CriteriaDeviationRight(const TCommonSample<unsigned long long> &Sample, long double DefaultDeviation, double Level) = 0;
	virtual bool CriteriaDeviationCenter(const TCommonSample<unsigned long long> &Sample, long double DefaultDeviation, double Level) = 0;
	
	virtual bool CriteriaExpectedLeft(const TCommonSample<long double> &Sample, double Level)
	{
		SendFloatArgumentException();
	}
	virtual bool CriteriaExpectedRight(const TCommonSample<long double> &Sample, double Level)
	{
		SendFloatArgumentException();
	}
	virtual bool CriteriaExpectedCenter(const TCommonSample<long double> &Sample, double Level)
	{
		SendFloatArgumentException();
	}
	virtual bool CriteriaDeviationLeft(const TCommonSample<long double> &Sample, double Level)
	{
		SendFloatArgumentException();
	}
	virtual bool CriteriaDeviationRight(const TCommonSample<long double> &Sample, double Level)
	{
		SendFloatArgumentException();
	}
	virtual bool CriteriaDeviationCenter(const TCommonSample<long double> &Sample, double Level)
	{
		SendFloatArgumentException();
	}
	
	virtual bool CriteriaExpectedLeft(const TCommonSample<unsigned long long> &Sample, double Level) = 0;
	virtual bool CriteriaExpectedRight(const TCommonSample<unsigned long long> &Sample, double Level) = 0;
	virtual bool CriteriaExpectedCenter(const TCommonSample<unsigned long long> &Sample, double Level) = 0;
	virtual bool CriteriaDeviationLeft(const TCommonSample<unsigned long long> &Sample, double Level) = 0;
	virtual bool CriteriaDeviationRight(const TCommonSample<unsigned long long> &Sample, double Level) = 0;
	virtual bool CriteriaDeviationCenter(const TCommonSample<unsigned long long> &Sample, double Level) = 0;
	
	virtual bool SetAppropriateParameters(const TCommonSample<long double> &Sample)
	{
		SendFloatArgumentException();
	}
	virtual bool SetAppropriateParameters(const TCommonSample<unsigned long long> &Sample) = 0;

protected:
	void SendDiscreteDensityException()
	{
		throw TDiscreteDensityException;
	}
	void SendFloatArgumentException()
	{
		throw TFloatArgumentException;
	}
};

TDiscreteDistribution::~TDiscreteDistribution {}

#endif
