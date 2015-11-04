#ifndef T_DISTRIBUTION_H
#define T_DISTRIBUTION_H

#include <vector>
#include "DistributionExceptions.h"
#include "TCommonSample.h"

class TDistribution
{
public:
	virtual ~TDistribution() = 0;
	
	virtual long double GetDensity(double x) = 0;
	virtual long double GetDensity(long double x) = 0;
	virtual long double GetProbability(unsigned n) = 0;
	virtual long double GetProbability(unsigned long long n) = 0;
	
	virtual long double GetFunctionValue(double x) = 0;
	virtual long double GetFunctionValue(long double x) = 0;
	virtual long double GetFunctionValue(unsigned n) = 0;
	virtual long double GetFunctionValue(unsigned long long n) = 0;
	virtual long double GetCumulativeFunctionValue(double x) = 0;
	virtual long double GetCumulativeFunctionValue(long double x) = 0;
	virtual long double GetCumulativeFunctionValue(unsigned n) = 0;
	virtual long double GetCumulativeFunctionValue(unsigned long long n) = 0;
	
	virtual long double GetIntervalProbability(double LeftBound, double RightBound) = 0;
	virtual long double GetIntervalProbability(long double LeftBound, long double RightBound) = 0;
	
	virtual long double GetExpectedValue() = 0;
	virtual long double GetDispersion() = 0;
	virtual long double GetStandardDevation() = 0;
	
	virtual bool CriteriaExpectedLeft(const TCommonSample<long double> &Sample, long double DefaultExpectedValue, double Level) = 0;
	virtual bool CriteriaExpectedRight(const TCommonSample<long double> &Sample, long double DefaultExpectedValue, double Level) = 0;
	virtual bool CriteriaExpectedCenter(const TCommonSample<long double> &Sample, long double DefaultExpectedValue, double Level) = 0;
	virtual bool CriteriaDeviationLeft(const TCommonSample<long double> &Sample, long double DefaultDeviation, double Level) = 0;
	virtual bool CriteriaDeviationRight(const TCommonSample<long double> &Sample, long double DefaultDeviation, double Level) = 0;
	virtual bool CriteriaDeviationCenter(const TCommonSample<long double> &Sample, long double DefaultDeviation, double Level) = 0;
	
	virtual bool CriteriaExpectedLeft(const TCommonSample<unsigned long long> &Sample, long double DefaultExpectedValue, double Level) = 0;
	virtual bool CriteriaExpectedRight(const TCommonSample<unsigned long long> &Sample, long double DefaultExpectedValue, double Level) = 0;
	virtual bool CriteriaExpectedCenter(const TCommonSample<unsigned long long> &Sample, long double DefaultExpectedValue, double Level) = 0;
	virtual bool CriteriaDeviationLeft(const TCommonSample<unsigned long long> &Sample, long double DefaultDeviation, double Level) = 0;
	virtual bool CriteriaDeviationRight(const TCommonSample<unsigned long long> &Sample, long double DefaultDeviation, double Level) = 0;
	virtual bool CriteriaDeviationCenter(const TCommonSample<unsigned long long> &Sample, long double DefaultDeviation, double Level) = 0;
	
	virtual bool CriteriaExpectedLeft(const TCommonSample<long double> &Sample, double Level) = 0;
	virtual bool CriteriaExpectedRight(const TCommonSample<long double> &Sample, double Level) = 0;
	virtual bool CriteriaExpectedCenter(const TCommonSample<long double> &Sample, double Level) = 0;
	virtual bool CriteriaDeviationLeft(const TCommonSample<long double> &Sample, double Level) = 0;
	virtual bool CriteriaDeviationRight(const TCommonSample<long double> &Sample, double Level) = 0;
	virtual bool CriteriaDeviationCenter(const TCommonSample<long double> &Sample, double Level) = 0;
	
	virtual bool CriteriaExpectedLeft(const TCommonSample<unsigned long long> &Sample, double Level) = 0;
	virtual bool CriteriaExpectedRight(const TCommonSample<unsigned long long> &Sample, double Level) = 0;
	virtual bool CriteriaExpectedCenter(const TCommonSample<unsigned long long> &Sample, double Level) = 0;
	virtual bool CriteriaDeviationLeft(const TCommonSample<unsigned long long> &Sample, double Level) = 0;
	virtual bool CriteriaDeviationRight(const TCommonSample<unsigned long long> &Sample, double Level) = 0;
	virtual bool CriteriaDeviationCenter(const TCommonSample<unsigned long long> &Sample, double Level) = 0;
	
	virtual bool SetAppropriateParameters(const TCommonSample<long double> &Sample) = 0;
	virtual bool SetAppropriateParameters(const TCommonSample<unsigned long long> &Sample) = 0;

protected:
	void SendNonRandomException()
	{
		throw TNonRandomException;
	}
	void SendInvalidParametersException()
	{
		throw TInvalidParametersException;
	}
	void SendExpectedValueNotExistsException()
	{
		throw TExpectedValueNotExistsException;
	}
	void SendDispersionNotExistsException()
	{
		throw TDispersionNotExistsException;
	}
	void SendImpossibleFunctionValueException()
	{
		throw TImpossibleFunctionValueException;
	}
};

TDistribution::~TDistribution() {}

#endif
