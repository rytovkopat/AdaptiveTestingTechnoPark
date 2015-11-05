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
	TOneDimensionNormalDistribution(const TCommonSample<long double> &Sample);
	TOneDimensionNormalDistribution(const TCommonSample<unsigned long long> &Sample);
	
	TOneDimensionNormalDistribution(const TOneDimensionNormalDistribution &Source);
	TOneDimensionNormalDistribution& operator =(const TOneDimensionNormalDistribution &Source);

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
	
	long double GetParameter_M();
	long double GetParameter_Sigma();
	TOneDimensionNormalDistribution& SetParameter_M(long double value_m);
	TOneDimensionNormalDistribution& SetParameter_Sigma(long double value_sigma);
	
	virtual bool CriteriaExpectedLeft(const TCommonSample<long double> &Sample, long double DefaultExpectedValue, double Level);
	virtual bool CriteriaExpectedRight(const TCommonSample<long double> &Sample, long double DefaultExpectedValue, double Level);
	virtual bool CriteriaExpectedCenter(const TCommonSample<long double> &Sample, long double DefaultExpectedValue, double Level);
	virtual bool CriteriaDeviationLeft(const TCommonSample<long double> &Sample, long double DefaultDeviation, double Level);
	virtual bool CriteriaDeviationRight(const TCommonSample<long double> &Sample, long double DefaultDeviation, double Level);
	virtual bool CriteriaDeviationCenter(const TCommonSample<long double> &Sample, long double DefaultDeviation, double Level);
	
	virtual bool CriteriaExpectedLeft(const TCommonSample<unsigned long long> &Sample, long double DefaultExpectedValue, double Level);
	virtual bool CriteriaExpectedRight(const TCommonSample<unsigned long long> &Sample, long double DefaultExpectedValue, double Level);
	virtual bool CriteriaExpectedCenter(const TCommonSample<unsigned long long> &Sample, long double DefaultExpectedValue, double Level);
	virtual bool CriteriaDeviationLeft(const TCommonSample<unsigned long long> &Sample, long double DefaultDeviation, double Level);
	virtual bool CriteriaDeviationRight(const TCommonSample<unsigned long long> &Sample, long double DefaultDeviation, double Level);
	virtual bool CriteriaDeviationCenter(const TCommonSample<unsigned long long> &Sample, long double DefaultDeviation, double Level);
	
	virtual bool CriteriaExpectedLeft(const TCommonSample<long double> &Sample, double Level);
	virtual bool CriteriaExpectedRight(const TCommonSample<long double> &Sample, double Level);
	virtual bool CriteriaExpectedCenter(const TCommonSample<long double> &Sample, double Level);
	virtual bool CriteriaDeviationLeft(const TCommonSample<long double> &Sample, double Level);
	virtual bool CriteriaDeviationRight(const TCommonSample<long double> &Sample, double Level);
	virtual bool CriteriaDeviationCenter(const TCommonSample<long double> &Sample, double Level);
	
	virtual bool CriteriaExpectedLeft(const TCommonSample<unsigned long long> &Sample, double Level);
	virtual bool CriteriaExpectedRight(const TCommonSample<unsigned long long> &Sample, double Level);
	virtual bool CriteriaExpectedCenter(const TCommonSample<unsigned long long> &Sample, double Level);
	virtual bool CriteriaDeviationLeft(const TCommonSample<unsigned long long> &Sample, double Level);
	virtual bool CriteriaDeviationRight(const TCommonSample<unsigned long long> &Sample, double Level);
	virtual bool CriteriaDeviationCenter(const TCommonSample<unsigned long long> &Sample, double Level);
	
	virtual TOneDimensionNormalDistribution& SetAppropriateParameters(const TCommonSample<long double> &Sample);
	virtual TOneDimensionNormalDistribution& SetAppropriateParameters(const TCommonSample<unsigned long long> &Sample);
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
	
	static bool _CriteriaExpectedLeft(const TCommonSample<long double> &Sample, long double _expected_value, double _level);
	static bool _CriteriaExpectedRight(const TCommonSample<long double> &Sample, long double _expected_value, double _level);
	static bool _CriteriaExpectedCenter(const TCommonSample<long double> &Sample, long double _expected_value, double _level);
	
	static bool _CriteriaExpectedLeft(const TCommonSample<unsigned long long> &Sample, long double _expected_value, double _level);
	static bool _CriteriaExpectedRight(const TCommonSample<unsigned long long> &Sample, long double _expected_value, double _level);
	static bool _CriteriaExpectedCenter(const TCommonSample<unsigned long long> &Sample, long double _expected_value, double _level);
	
	static bool _CriteriaDeviationLeft(const TCommonSample<long double> &Sample _Sample, long double _deviation, double _level);
	static bool _CriteriaDeviationRight(const TCommonSample<long double> &Sample, long double _deviation, double _level);
	static bool _CriteriaDeviationCenter(const TCommonSample<long double> &Sample, long double _deviation, double _level);
	
	static bool _CriteriaDeviationLeft(const TCommonSample<unsigned long long> &Sample _Sample, long double _deviation, double _level);
	static bool _CriteriaDeviationRight(const TCommonSample<unsigned long long> &Sample, long double _deviation, double _level);
	static bool _CriteriaDeviationCenter(const TCommonSample<unsigned long long> &Sample, long double _deviation, double _level);
	
	bool _SetParameters(const TCommonSample<long double> &Sample);
	bool _SetParameters(const TCommonSample<unsigned long long> &Sample);
};

#endif
