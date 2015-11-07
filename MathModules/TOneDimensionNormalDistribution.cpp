#include "TOneDimensionNormalDistribution.h"


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

long double TOneDimensionNormalDistribution::GetQuantile(double Level)
{
	if (Level < 0.0 || Level > 1.0)
	{
		throw TImpossibleFunctionValueException;
	}
	
	if (!_AreParamsValid())
	{
		throw TInvalidParametersException;
	}
	
	return _Quantile(Level);
}

long double TOneDimensionNormalDistribution::_Quantile(double _level)
{
	if (Level < 0.0 || Level > 1.0)
	{
		throw TImpossibleFunctionValueException;
	}
	
	if (!_AreParamsValid())
	{
		throw TInvalidParametersException;
	}
	
	return quantile(normal(_m, _sigma), _level);
}

// Protected, left, long double
bool TOneDimensionNormalDistribution::_CriteriaExpectedLeft
	(const TCommonSample<long double> &Sample, long double _expected_value, double _level)
{
	unsigned size = Sample.GetSize();
	if (size < MIN_ALLOWED_SAMPLE_SIZE)
	{
		throw "Too small sample!";
	}
	if (_level < 0.0 || _level > 1.0)
	{
		throw TImpossibleFunctionValueException;
	}
	
	// not safe; create new type of exception
	long double CorrectedStandardDeviation = Sample.GetCorrectedSelectiveStandardDeviation();
	
	long double Mean = Sample.GetAverage();
	
	long double T_Stats = (_expected_value - Mean) * sqrtl((long double)size) / CorrectedStandardDeviation;

	if (T_Stats >= quantile(student_t(size-1), _level))
		return false;
	else
		return true;
}
// Protected, left, unsigned long long
bool TOneDimensionNormalDistribution::_CriteriaExpectedLeft
	(const TCommonSample<unsigned long long> &Sample, long double _expected_value, double _level)
{
	unsigned size = Sample.GetSize();
	if (size < MIN_ALLOWED_SAMPLE_SIZE)
	{
		throw "Too small sample!";
	}
	if (_level < 0.0 || _level > 1.0)
	{
		throw TImpossibleFunctionValueException;
	}
	
	// not safe; create new type of exception
	long double CorrectedStandardDeviation = Sample.GetCorrectedSelectiveStandardDeviation();
	
	long double Mean = Sample.GetAverage();
	
	long double T_Stats = (_expected_value - Mean) * sqrtl((long double)size) / CorrectedStandardDeviation;

	if (T_Stats >= quantile(student_t(size-1), 1.0-_level))
		return false;
	else
		return true;
}
// Protected, right, long double
bool TOneDimensionNormalDistribution::_CriteriaExpectedRight
	(const TCommonSample<long double> &Sample, long double _expected_value, double _level)
{
	unsigned size = Sample.GetSize();
	if (size < MIN_ALLOWED_SAMPLE_SIZE)
	{
		throw "Too small sample!";
	}
	if (_level < 0.0 || _level > 1.0)
	{
		throw TImpossibleFunctionValueException;
	}
	
	// not safe; create new type of exception
	long double CorrectedStandardDeviation = Sample.GetCorrectedSelectiveStandardDeviation();
	
	long double Mean = Sample.GetAverage();
	
	long double T_Stats = (_expected_value - Mean) * sqrtl((long double)size) / CorrectedStandardDeviation;

	if (T_Stats <= quantile(student_t(size-1), _level))
		return false;
	else
		return true;
}
// Protected, right, unsigned long long
bool TOneDimensionNormalDistribution::_CriteriaExpectedRight
	(const TCommonSample<unsigned long long> &Sample, long double _expected_value, double _level)
{
	unsigned size = Sample.GetSize();
	if (size < MIN_ALLOWED_SAMPLE_SIZE)
	{
		throw "Too small sample!";
	}
	if (_level < 0.0 || _level > 1.0)
	{
		throw TImpossibleFunctionValueException;
	}
	
	// not safe; create new type of exception
	long double CorrectedStandardDeviation = Sample.GetCorrectedSelectiveStandardDeviation();
	
	long double Mean = Sample.GetAverage();
	
	long double T_Stats = (_expected_value - Mean) * sqrtl((long double)size) / CorrectedStandardDeviation;

	if (T_Stats <= quantile(student_t(size-1), _level))
		return false;
	else
		return true;
}
// Protected, center, long double
bool TOneDimensionNormalDistribution::_CriteriaExpectedCenter
	(const TCommonSample<long double> &Sample, long double _expected_value, double _level)
{
	unsigned size = Sample.GetSize();
	if (size < MIN_ALLOWED_SAMPLE_SIZE)
	{
		throw "Too small sample!";
	}
	if (_level < 0.0 || _level > 1.0)
	{
		throw TImpossibleFunctionValueException;
	}
	
	// not safe; create new type of exception
	long double CorrectedStandardDeviation = Sample.GetCorrectedSelectiveStandardDeviation();
	
	long double Mean = Sample.GetAverage();
	
	long double T_Stats = (_expected_value - Mean) * sqrtl((long double)size) / CorrectedStandardDeviation;

	if (T_Stats <= quantile(student_t(size-1), _level/2) || T_Stats >= quantile(student_t(size-1), 1-_level/2))
		return false;
	else
		return true;
}
// Protected, center, unsigned long long
bool TOneDimensionNormalDistribution::_CriteriaExpectedCenter
	(const TCommonSample<unsigned long long> &Sample, long double _expected_value, double _level)
{
	unsigned size = Sample.GetSize();
	if (size < MIN_ALLOWED_SAMPLE_SIZE)
	{
		throw "Too small sample!";
	}
	if (_level < 0.0 || _level > 1.0)
	{
		throw TImpossibleFunctionValueException;
	}
	
	// not safe; create new type of exception
	long double CorrectedStandardDeviation = Sample.GetCorrectedSelectiveStandardDeviation();
	
	long double Mean = Sample.GetAverage();
	
	long double T_Stats = (_expected_value - Mean) * sqrtl((long double)size) / CorrectedStandardDeviation;
	
	if (T_Stats <= quantile(student_t(size-1), _level/2) || T_Stats >= quantile(student_t(size-1), 1-_level/2))
		return false;
	else
		return true;
}


bool TOneDimensionNormalDistribution::_CriteriaDeviationLeft
	(const TCommonSample<long double> &Sample _Sample, long double _deviation, double _level)
{
	if (_deviation <= 0.0)
	{
		throw TInvalidParametersException;
	}
	
	unsigned size = Sample.GetSize();
	if (size < MIN_ALLOWED_SAMPLE_SIZE)
	{
		throw "Too small sample!";
	}
	if (_level < 0.0 || _level > 1.0)
	{
		throw TImpossibleFunctionValueException;
	}
	
	// not safe; create new type of exception
	long double CorrectedDispersion = Sample.GetCorrectedSelectiveDispersion();
	
	long double T_Stats = (size - 1) * CorrectedDispersion / (_deviation * _deviation);

	if (T_Stats <= quantile(chi_squared(size-1), _level))
		return false;
	else
		return true;
}

bool TOneDimensionNormalDistribution::_CriteriaDeviationRight
	(const TCommonSample<long double> &Sample, long double _deviation, double _level)
{
	if (_deviation <= 0.0)
	{
		throw TInvalidParametersException;
	}
	
	unsigned size = Sample.GetSize();
	if (size < MIN_ALLOWED_SAMPLE_SIZE)
	{
		throw "Too small sample!";
	}
	if (_level < 0.0 || _level > 1.0)
	{
		throw TImpossibleFunctionValueException;
	}
	
	// not safe; create new type of exception
	long double CorrectedDispersion = Sample.GetCorrectedSelectiveDispersion();
	
	long double T_Stats = (size - 1) * CorrectedDispersion / (_deviation * _deviation);

	if (T_Stats >= quantile(chi_squared(size-1), 1-_level))
		return false;
	else
		return true;
}

bool TOneDimensionNormalDistribution::_CriteriaDeviationCenter
	(const TCommonSample<long double> &Sample, long double _deviation, double _level)
{
	if (_deviation <= 0.0)
	{
		throw TInvalidParametersException;
	}
	
	unsigned size = Sample.GetSize();
	if (size < MIN_ALLOWED_SAMPLE_SIZE)
	{
		throw "Too small sample!";
	}
	if (_level < 0.0 || _level > 1.0)
	{
		throw TImpossibleFunctionValueException;
	}
	
	// not safe; create new type of exception
	long double CorrectedDispersion = Sample.GetCorrectedSelectiveDispersion();
	
	long double T_Stats = (size - 1) * CorrectedDispersion / (_deviation * _deviation);

	if (T_Stats <= quantile(chi_squared(size-1), _level/2) || T_Stats >= quantile(chi_squared(size-1), 1-_level/2))
		return false;
	else
		return true;
}
	
bool TOneDimensionNormalDistribution::_CriteriaDeviationLeft
	(const TCommonSample<unsigned long long> &Sample _Sample, long double _deviation, double _level)
{
	if (_deviation <= 0.0)
	{
		throw TInvalidParametersException;
	}
	
	unsigned size = Sample.GetSize();
	if (size < MIN_ALLOWED_SAMPLE_SIZE)
	{
		throw "Too small sample!";
	}
	if (_level < 0.0 || _level > 1.0)
	{
		throw TImpossibleFunctionValueException;
	}
	
	// not safe; create new type of exception
	long double CorrectedDispersion = Sample.GetCorrectedSelectiveDispersion();
	
	long double T_Stats = (size - 1) * CorrectedDispersion / (_deviation * _deviation);
>>>>>>> 168f661... Добавлен виртуальный метод 2-го уровня в классы распределений, посвящённый квантилям.

