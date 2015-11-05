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
	
	static bool _CriteriaDeviationLeft(const TCommonSample<unsigned long long> &Sample _Sample, long double _deviation, double _level);
	static bool _CriteriaDeviationRight(const TCommonSample<unsigned long long> &Sample, long double _deviation, double _level);
	static bool _CriteriaDeviationCenter(const TCommonSample<unsigned long long> &Sample, long double _deviation, double _level);
	
	//рачет хи квадрат для данной выборки и сравнение с табличной, здесь я затупил, признаю)
	bool _SetParameters(const TCommonSample<long double> &Sample);
	bool _SetParameters(const TCommonSample<unsigned long long> &Sample);
private:	
	//определение частоты  на заданном интервале
	long double _GetFreqInInterval( const TCommonSample<long double> &Sample, long double _leftBound, long double _rightBound ); 
	unsigned long long _GetFreqInInterval( const TCommonSample<unsigned long long> &Sample, unsigned long long _leftBound, unsigned long long _rightBound );
	
	//точечная оценка матожидания
	long double _mPointEstimation( const TCommonSample<long double> &Sample );
	unsigned long long _mPointEstimation( const TCommonSample<unsigned long long> &Sample );
	
	//точечная оценка средне-квадратического отклонения
	long double _sigmaPointEstimation( const TCommonSample<long double> &Sample );
	unsigned long long _sigmaPointEstimation( const TCommonSample<unsigned long long> &Sample );
	
	//определение теоретических частот
	double _GetTheorFreq( const TCommonSample<long double> &Sample, long double _leftBound, long double _rightBound );
	double _GetTheorFreq( const TCommonSample<unsigned long long> &Sample, unsigned long long _leftBound, unsigned long long _rightBound );
	
};

//----------------------------------------------------------------------
// IMPLEMENTATION OF TOneDimensionNormalDistribution.h by Temirlan
#include <math.h>
//----------------------------------------------------------------------
long double TOneDimensionNormalDistribution::_GetFreqInInterval( const TCommonSample<long double> &Sample, long double _leftBound, long double _rightBound ) {
	int count = 0; //подаем на вход отсортированную выборку
	int size = Sample.GetSize();
	if( _rightBound == Sample[size - 1] ) {
		for( int i = 0; i < size; i++ ) {
			if( Sample[i] >= _leftBound && Sample[i] <= _rightBound ) {
				count++;
			}
		}
	} else {
		for( int i = 0; i < size; i++ ) {
			if( Sample[i] >= _leftBound && Sample[i] < _rightBound ) {
				count++;
			}
		}
	}
	return count / size;
}

unsigned long long TOneDimensionNormalDistribution::_GetFreqInInterval( const TCommonSample<unsigned long long> &Sample, unsigned long long _leftBound, unsigned long long _rightBound ) {
	int count = 0; //подаем на вход отсортированную выборку
	int size = Sample.GetSize();
	if( _rightBound == Sample[size - 1] ) {
		for( int i = 0; i < size; i++ ) {
			if( Sample[i] >= _leftBound && Sample[i] <= _rightBound ) {
				count++;
			}
		}
	} else {
		for( int i = 0; i < size; i++ ) {
			if( Sample[i] >= _leftBound && Sample[i] < _rightBound ) {
				count++;
			}
		}
	}
	return count / size;
}

//----------------------------------------------------------------------
long double TOneDimensionNormalDistribution::_mPointEstimation( const TCommonSample<long double> &Sample ) {
	Sample.GetSortedArray(true);
	int size = Sample.GetSize();
	int intervalsCount = ceil(log2(size)); // число интервалов
	long double intervalLength = (Sample[size - 1] - Sample[0]) / intervalsCount; //длина одного интервала
	
	long double leftBound = Sample[0];
	long double rightBound = Sample[0] + intervalLength;
	long double mPointEstimation = 0;
	for( int i = 0; i < intervalsCount; i++ ) {
		mPointEstimation += (rightBound + leftBound) * _GetFreqInInterval( Sample, leftBound, rightBound )  / 2;  
	}
	return mPointEstimation;
}

unsigned long long TOneDimensionNormalDistribution::_mPointEstimation( const TCommonSample<unsigned long long> &Sample ) {
	Sample.GetSortedArray(true);
	int size = Sample.GetSize();
	int intervalsCount = ceil(log2(size)); // число интервалов
	unsigned long long intervalLength = (Sample[size - 1] - Sample[0]) / intervalsCount; //длина одного интервала
	
	unsigned long long leftBound = Sample[0];
	unsigned long long rightBound = Sample[0] + intervalLength;
	unsigned long long mPointEstimation = 0;
	for( int i = 0; i < intervalsCount; i++ ) {
		mPointEstimation += (rightBound + leftBound) * _GetFreqInInterval( Sample, leftBound, rightBound )  / 2;  
	}
	return mPointEstimation;
}

//----------------------------------------------------------------------
long double TOneDimensionNormalDistribution::_sigmaPointEstimation( const TCommonSample<long double> &Sample ) {
	Sample.GetSortedArray(true);
	int size = Sample.GetSize();
	int intervalsCount = ceil(log2(size)); // число интервалов
	long double intervalLength = (Sample[size - 1] - Sample[0]) / intervalsCount; // длина одного интервала
	
	long double leftBound = Sample[0];
	long double rightBound = Sample[0] + intervalLength;
	long double sigmaPointEstimation = 0;
	long double mPointEstimation = _mPointEstimation( Sample ); // оценка матожидания
	long double temp = 0;
	for( int i = 0; i < intervalsCount; i++ ) {
		temp = (rightBound + leftBound) / 2 - mPointEstimation;
		sigmaPointEstimation += pow( temp, 2 ) * _GetFreqInInterval( Sample, leftBound, rightBound );  
	}
	return sqrt( sigmaPointEstimation * size / (size - 1) );
}

unsigned long long TOneDimensionNormalDistribution::_sigmaPointEstimation( const TCommonSample<unsigned long long> &Sample ) {
	Sample.GetSortedArray(true);
	int size = Sample.GetSize();
	int intervalsCount = ceil(log2(size)); // число интервалов
	unsigned long long intervalLength = (Sample[size - 1] - Sample[0]) / intervalsCount; // длина одного интервала
	
	unsigned long long leftBound = Sample[0];
	unsigned long long rightBound = Sample[0] + intervalLength;
	unsigned long long sigmaPointEstimation = 0;
	unsigned long long mPointEstimation = _mPointEstimation( Sample ); // оценка матожидания
	unsigned long long temp = 0;
	for( int i = 0; i < intervalsCount; i++ ) {
		temp = (rightBound + leftBound) / 2 - mPointEstimation;
		sigmaPointEstimation += pow( temp, 2 ) * _GetFreqInInterval( Sample, leftBound, rightBound );  
	}
	return sqrt( sigmaPointEstimation * size / (size - 1) );
}

//----------------------------------------------------------------------
double TOneDimensionNormalDistribution::_GetTheorFreq( const TCommonSample<long double> &Sample, long double _leftBound, long double _rightBound ) {
	Sample.GetSortedArray(true);
	_m = _mPointEstimation( Sample );
	_sigma = _sigmaPointEstimation( Sample );
	return Sample.GetIntervalProbability( _leftBound, _rightBound) * Sample.GetSize();
}

unsigned long long TOneDimensionNormalDistribution::_GetTheorFreq( const TCommonSample<unsigned long long> &Sample, unsigned long long _leftBound, unsigned long long _rightBound ) {
	Sample.GetSortedArray(true);
	_m = _mPointEstimation( Sample );
	_sigma = _sigmaPointEstimation( Sample );
	return Sample.GetIntervalProbability( _leftBound, _rightBound) * Sample.GetSize();
}

//----------------------------------------------------------------------
bool TOneDimensionNormalDistribution::_SetParameters(const TCommonSample<long double> &Sample) {
	long double khiSquare = 0;
	
	Sample.GetSortedArray(true);
	int size = Sample.GetSize();
	int intervalsCount = ceil(log2(size)); // число интервалов
	long double intervalLength = (Sample[size - 1] - Sample[0]) / intervalsCount; // длина одного интервала
	
	long double leftBound = Sample[0];
	long double rightBound = Sample[0] + intervalLength;
	long double temp1 = 0;
	long double temp2 = 0;
	for( int i = 0; i < intervalsCount; i++ ) {
		temp1 = _GetFreqInInterval( Sample, leftBound, rightBound );
		temp2 = _GetTheorFreq( Sample, leftBound, rightBound );
		khiSquare += pow( (temp1 - temp2), 2 ) / temp2;
	}
	//???????????????? Поиск в boost ???????????????????????????????????
	if( khiSquare < /*расчет квантили по заданному уровню значимости и степени свободы = (size - 2)*/  ) {
		return true;
	} else {
		return false;
	}
}

bool TOneDimensionNormalDistribution::_SetParameters(const TCommonSample<unsigned long long> &Sample) {
	unsigned long long khiSquare = 0;
	
	Sample.GetSortedArray(true);
	int size = Sample.GetSize();
	int intervalsCount = ceil(log2(size)); // число интервалов
	unsigned long long intervalLength = (Sample[size - 1] - Sample[0]) / intervalsCount; // длина одного интервала
	
	unsigned long long leftBound = Sample[0];
	unsigned long long rightBound = Sample[0] + intervalLength;
	unsigned long long temp1 = 0;
	unsigned long long temp2 = 0;
	for( int i = 0; i < intervalsCount; i++ ) {
		temp1 = _GetFreqInInterval( Sample, leftBound, rightBound );
		temp2 = _GetTheorFreq( Sample, leftBound, rightBound );
		khiSquare += pow( (temp1 - temp2), 2 ) / temp2;
	}
	//???????????????? Поиск в boost ???????????????????????????????????
	if( khiSquare < /*расчет квантили по заданному уровню значимости и степени свободы = (size - 2)*/  ) {
		return true;
	} else {
		return false;
	}
}

//----------------------------------------------------------------------

};

#endif
