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

double TOneDimensionNormalDistribution::_GetTheorFreq( const TCommonSample<unsigned long long> &Sample, unsigned long long _leftBound, unsigned long long _rightBound ) {
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
		leftBound = rightBound;
		rightBound += intervalLength;
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
		leftBound = rightBound;
		rightBound += intervalLength;
	}
	//???????????????? Поиск в boost ???????????????????????????????????
	if( khiSquare < /*расчет квантили по заданному уровню значимости и степени свободы = (size - 2)*/  ) {
		return true;
	} else {
		return false;
	}
}

//----------------------------------------------------------------------

TOneDimensionNormalDistribution&  TOneDimensionNormalDistribution::SetAppropriateParameters(const TCommonSample<long double> &Sample) {
	if( _SetParameters( Sample ) == true ) {
		_m = _mPointEstimation( Sample );
		_sigma = _sigmaPointEstimation( Sample );
		return *this;
	} else {
		_sigma = -1;
//???????????????????????????? Иссключение ??????????????????????????????
		return; //возвращаем иссключение
	}
}

TOneDimensionNormalDistribution&  TOneDimensionNormalDistribution::SetAppropriateParameters(const TCommonSample<unsigned long long> &Sample) {
	if( _SetParameters( Sample ) == true ) {
		_m = _mPointEstimation( Sample );
		_sigma = _sigmaPointEstimation( Sample );
		return *this;
	} else {
		_sigma = -1;
//???????????????????????????? Иссключение ??????????????????????????????
		return; //возвращаем иссключение
	}
}



