#ifndef T_ONE_DIMENSION_NORMAL_DISTRIBUTION_H
#define T_ONE_DIMENSION_NORMAL_DISTRIBUTION_H

#include "TContinuousDistribution.h"

class TOneDimensionNormalDistribution : public TContinuousDistribution
{
public:
	// constructor & destructor block
	TOneDimensionNormalDistribution();
	TOneDimensionNormalDistribution(double m, double sigma);
	TOneDimensionNormalDistribution(long double m, long double sigma);
	TOneDimensionNormalDistribution(unsigned m, unsigned sigma);
	TOneDimensionNormalDistribution(unsigned long long m, unsigned long long sigma);

	virtual ~TOneDimensionNormalDistribution() {}
	
	virtual long double GetDensity(double x);
	virtual long double GetDensity(long double x);
	/* commented as defined backwards
	virtual long double GetProbability(unsigned n)
	{
		SendContinuousProbabilityException();
	}
	virtual long double GetProbability(unsigned long long n)
	{
		SendContinuousProbabilityException();
	}
	* */
	
	virtual long double GetFunctionValue(double x);
	virtual long double GetFunctionValue(long double x);
	virtual long double GetFunctionValue(unsigned n);
	virtual long double GetFunctionValue(unsigned long long n);
	virtual long double GetCumulativeFunctionValue(double x);
	virtual long double GetCumulativeFunctionValue(long double x);
	virtual long double GetCumulativeFunctionValue(unsigned n);
	virtual long double GetCumulativeFunctionValue(unsigned long long n);
	
	virtual long double GetIntervalProbability(double LeftBound, double RightBound);
	virtual long double GetIntervalProbability(long double LeftBound, long double RightBound)0;
	
	virtual long double GetExpectedValue();
	virtual long double GetDispersion();
	virtual long double GetStandardDevation();
	
	virtual bool CriteriaExpectedLeft(std::vector<double> Sample, long double DefaultExpectedValue, double Level);
	virtual bool CriteriaExpectedRight(std::vector<double> Sample, long double DefaultExpectedValue, double Level);
	virtual bool CriteriaExpectedCenter(std::vector<double> Sample, long double DefaultExpectedValue, double Level);
	virtual bool CriteriaDeviationLeft(std::vector<double> Sample, long double DefaultDeviation, double Level);
	virtual bool CriteriaDeviationRight(std::vector<double> Sample, long double DefaultDeviation, double Level);
	virtual bool CriteriaDeviationCenter(std::vector<double> Sample, long double DefaultDeviation, double Level);
	
	virtual bool CriteriaExpectedLeft(std::vector<long double> Sample, long double DefaultExpectedValue, double Level);
	virtual bool CriteriaExpectedRight(std::vector<long double> Sample, long double DefaultExpectedValue, double Level);
	virtual bool CriteriaExpectedCenter(std::vector<long double> Sample, long double DefaultExpectedValue, double Level);
	virtual bool CriteriaDeviationLeft(std::vector<long double> Sample, long double DefaultDeviation, double Level);
	virtual bool CriteriaDeviationRight(std::vector<long double> Sample, long double DefaultDeviation, double Level);
	virtual bool CriteriaDeviationCenter(std::vector<long double> Sample, long double DefaultDeviation, double Level);
	
	virtual bool CriteriaExpectedLeft(std::vector<unsigned> Sample, long double DefaultExpectedValue, double Level);
	virtual bool CriteriaExpectedRight(std::vector<unsigned> Sample, long double DefaultExpectedValue, double Level);
	virtual bool CriteriaExpectedCenter(std::vector<unsigned> Sample, long double DefaultExpectedValue, double Level);
	virtual bool CriteriaDeviationLeft(std::vector<unsigned> Sample, long double DefaultDeviation, double Level);
	virtual bool CriteriaDeviationRight(std::vector<unsigned> Sample, long double DefaultDeviation, double Level);
	virtual bool CriteriaDeviationCenter(std::vector<unsigned> Sample, long double DefaultDeviation, double Level);
	
	virtual bool CriteriaExpectedLeft(std::vector<unsigned long long> Sample, long double DefaultExpectedValue, double Level);
	virtual bool CriteriaExpectedRight(std::vector<unsigned long long> Sample, long double DefaultExpectedValue, double Level);
	virtual bool CriteriaExpectedCenter(std::vector<unsigned long long> Sample, long double DefaultExpectedValue, double Level);
	virtual bool CriteriaDeviationLeft(std::vector<unsigned long long> Sample, long double DefaultDeviation, double Level);
	virtual bool CriteriaDeviationRight(std::vector<unsigned long long> Sample, long double DefaultDeviation, double Level);
	virtual bool CriteriaDeviationCenter(std::vector<unsigned long long> Sample, long double DefaultDeviation, double Level);
	
	virtual bool CriteriaExpectedLeft(std::vector<double> Sample, double Level);
	virtual bool CriteriaExpectedRight(std::vector<double> Sample, double Level);
	virtual bool CriteriaExpectedCenter(std::vector<double> Sample, double Level);
	virtual bool CriteriaDeviationLeft(std::vector<double> Sample, double Level);
	virtual bool CriteriaDeviationRight(std::vector<double> Sample, double Level);
	virtual bool CriteriaDeviationCenter(std::vector<double> Sample, double Level);
	
	virtual bool CriteriaExpectedLeft(std::vector<long double> Sample, double Level);
	virtual bool CriteriaExpectedRight(std::vector<long double> Sample, double Level);
	virtual bool CriteriaExpectedCenter(std::vector<long double> Sample, double Level);
	virtual bool CriteriaDeviationLeft(std::vector<long double> Sample, double Level);
	virtual bool CriteriaDeviationRight(std::vector<long double> Sample, double Level);
	virtual bool CriteriaDeviationCenter(std::vector<long double> Sample, double Level);
	
	virtual bool CriteriaExpectedLeft(std::vector<unsigned> Sample, double Level);
	virtual bool CriteriaExpectedRight(std::vector<unsigned> Sample, double Level);
	virtual bool CriteriaExpectedCenter(std::vector<unsigned> Sample, double Level);
	virtual bool CriteriaDeviationLeft(std::vector<unsigned> Sample, double Level);
	virtual bool CriteriaDeviationRight(std::vector<unsigned> Sample, double Level);
	virtual bool CriteriaDeviationCenter(std::vector<unsigned> Sample, double Level);
	
	virtual bool CriteriaExpectedLeft(std::vector<unsigned long long> Sample, double Level);
	virtual bool CriteriaExpectedRight(std::vector<unsigned long long> Sample, double Level);
	virtual bool CriteriaExpectedCenter(std::vector<unsigned long long> Sample, double Level);
	virtual bool CriteriaDeviationLeft(std::vector<unsigned long long> Sample, double Level);
	virtual bool CriteriaDeviationRight(std::vector<unsigned long long> Sample, double Level);
	virtual bool CriteriaDeviationCenter(std::vector<unsigned long long> Sample, double Level);
	
	virtual void SetAppropriateParameters(std::vector<double> Sample);
	virtual void SetAppropriateParameters(std::vector<long double> Sample);
	virtual void SetAppropriateParameters(std::vector<unsigned> Sample);
	virtual void SetAppropriateParameters(std::vector<unsigned long long> Sample);
protected:
	/* commented as defined backwards
	void SendContinuousProbabilityException()
	{
		throw TContinuousProbabilityException;
	}
	*/
	// Defining parameters of distribution
	long double _m;
	long double _sigma;
	bool _AreParamsValid();
	
	// This method block is for calling for calculation
	long double _Density(long double _x);
	long double _Function(long double _x);
	long double _IntervalProbability(long double _left, long double _right);
	long double _ExpectedValue();
	long double _Dispersion();
	long double _StandardDeviation();
	
	bool _CriteriaExpectedLeft(std::vector<long double> _Sample, long double _expected_value, double _level);
	bool _CriteriaExpectedRight(std::vector<long double> _Sample, long double _expected_value, double _level);
	bool _CriteriaExpectedCenter(std::vector<long double> _Sample, long double _expected_value, double _level);
	
	bool _CriteriaDeviationLeft(std::vector<long double> _Sample, long double _deviation, double _level);
	bool _CriteriaDeviationRight(std::vector<long double> _Sample, long double _deviation, double _level);
	bool _CriteriaDeviationCenter(std::vector<long double> _Sample, long double _deviation, double _level);
	
	void _SetParameters(std::vector<long double> _Sample);
};

#endif
