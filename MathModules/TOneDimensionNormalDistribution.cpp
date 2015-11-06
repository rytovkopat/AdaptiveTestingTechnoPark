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

<<<<<<< HEAD
=======
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

