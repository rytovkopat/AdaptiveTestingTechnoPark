#ifndef T_DISTRIBUTION_H
#define T_DISTRIBUTION_H

#include <vector>
#include "DistributionExceptions.h"

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
	
	virtual bool CriteriaExpectedLeft(std::vector<double> Sample, long double DefaultExpectedValue, double Level) = 0;
	virtual bool CriteriaExpectedRight(std::vector<double> Sample, long double DefaultExpectedValue, double Level) = 0;
	virtual bool CriteriaExpectedCenter(std::vector<double> Sample, long double DefaultExpectedValue, double Level) = 0;
	virtual bool CriteriaDeviationLeft(std::vector<double> Sample, long double DefaultDeviation, double Level) = 0;
	virtual bool CriteriaDeviationRight(std::vector<double> Sample, long double DefaultDeviation, double Level) = 0;
	virtual bool CriteriaDeviationCenter(std::vector<double> Sample, long double DefaultDeviation, double Level) = 0;
	
	virtual bool CriteriaExpectedLeft(std::vector<long double> Sample, long double DefaultExpectedValue, double Level) = 0;
	virtual bool CriteriaExpectedRight(std::vector<long double> Sample, long double DefaultExpectedValue, double Level) = 0;
	virtual bool CriteriaExpectedCenter(std::vector<long double> Sample, long double DefaultExpectedValue, double Level) = 0;
	virtual bool CriteriaDeviationLeft(std::vector<long double> Sample, long double DefaultDeviation, double Level) = 0;
	virtual bool CriteriaDeviationRight(std::vector<long double> Sample, long double DefaultDeviation, double Level) = 0;
	virtual bool CriteriaDeviationCenter(std::vector<long double> Sample, long double DefaultDeviation, double Level) = 0;
	
	virtual bool CriteriaExpectedLeft(std::vector<unsigned> Sample, long double DefaultExpectedValue, double Level) = 0;
	virtual bool CriteriaExpectedRight(std::vector<unsigned> Sample, long double DefaultExpectedValue, double Level) = 0;
	virtual bool CriteriaExpectedCenter(std::vector<unsigned> Sample, long double DefaultExpectedValue, double Level) = 0;
	virtual bool CriteriaDeviationLeft(std::vector<unsigned> Sample, long double DefaultDeviation, double Level) = 0;
	virtual bool CriteriaDeviationRight(std::vector<unsigned> Sample, long double DefaultDeviation, double Level) = 0;
	virtual bool CriteriaDeviationCenter(std::vector<unsigned> Sample, long double DefaultDeviation, double Level) = 0;
	
	virtual bool CriteriaExpectedLeft(std::vector<unsigned long long> Sample, long double DefaultExpectedValue, double Level) = 0;
	virtual bool CriteriaExpectedRight(std::vector<unsigned long long> Sample, long double DefaultExpectedValue, double Level) = 0;
	virtual bool CriteriaExpectedCenter(std::vector<unsigned long long> Sample, long double DefaultExpectedValue, double Level) = 0;
	virtual bool CriteriaDeviationLeft(std::vector<unsigned long long> Sample, long double DefaultDeviation, double Level) = 0;
	virtual bool CriteriaDeviationRight(std::vector<unsigned long long> Sample, long double DefaultDeviation, double Level) = 0;
	virtual bool CriteriaDeviationCenter(std::vector<unsigned long long> Sample, long double DefaultDeviation, double Level) = 0;
	
	virtual bool CriteriaExpectedLeft(std::vector<double> Sample, double Level) = 0;
	virtual bool CriteriaExpectedRight(std::vector<double> Sample, double Level) = 0;
	virtual bool CriteriaExpectedCenter(std::vector<double> Sample, double Level) = 0;
	virtual bool CriteriaDeviationLeft(std::vector<double> Sample, double Level) = 0;
	virtual bool CriteriaDeviationRight(std::vector<double> Sample, double Level) = 0;
	virtual bool CriteriaDeviationCenter(std::vector<double> Sample, double Level) = 0;
	
	virtual bool CriteriaExpectedLeft(std::vector<long double> Sample, double Level) = 0;
	virtual bool CriteriaExpectedRight(std::vector<long double> Sample, double Level) = 0;
	virtual bool CriteriaExpectedCenter(std::vector<long double> Sample, double Level) = 0;
	virtual bool CriteriaDeviationLeft(std::vector<long double> Sample, double Level) = 0;
	virtual bool CriteriaDeviationRight(std::vector<long double> Sample, double Level) = 0;
	virtual bool CriteriaDeviationCenter(std::vector<long double> Sample, double Level) = 0;
	
	virtual bool CriteriaExpectedLeft(std::vector<unsigned> Sample, double Level) = 0;
	virtual bool CriteriaExpectedRight(std::vector<unsigned> Sample, double Level) = 0;
	virtual bool CriteriaExpectedCenter(std::vector<unsigned> Sample, double Level) = 0;
	virtual bool CriteriaDeviationLeft(std::vector<unsigned> Sample, double Level) = 0;
	virtual bool CriteriaDeviationRight(std::vector<unsigned> Sample, double Level) = 0;
	virtual bool CriteriaDeviationCenter(std::vector<unsigned> Sample, double Level) = 0;
	
	virtual bool CriteriaExpectedLeft(std::vector<unsigned long long> Sample, double Level) = 0;
	virtual bool CriteriaExpectedRight(std::vector<unsigned long long> Sample, double Level) = 0;
	virtual bool CriteriaExpectedCenter(std::vector<unsigned long long> Sample, double Level) = 0;
	virtual bool CriteriaDeviationLeft(std::vector<unsigned long long> Sample, double Level) = 0;
	virtual bool CriteriaDeviationRight(std::vector<unsigned long long> Sample, double Level) = 0;
	virtual bool CriteriaDeviationCenter(std::vector<unsigned long long> Sample, double Level) = 0;
	
	virtual void SetAppropriateParameters(std::vector<double> Sample) = 0;
	virtual void SetAppropriateParameters(std::vector<long double> Sample) = 0;
	virtual void SetAppropriateParameters(std::vector<unsigned> Sample) = 0;
	virtual void SetAppropriateParameters(std::vector<unsigned long long> Sample) = 0;

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