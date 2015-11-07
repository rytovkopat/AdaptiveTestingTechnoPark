#ifndef T_COMMON_SAMPLE_H
#define T_COMMON_SAMPLE_H

#include <vector>

// WARNING: TCommonSample saves array of data as a heap!
template <typename T>
class TCommonSample<T>
{
public:
	TCommonSample();
	TCommonSample(const TCommonSample<T>& Source);
	TCommonSample& operator =(const TCommonSample<T>& Source);
	TCommonSample(std::vector<float> FloatVector);
	TCommonSample(std::vector<double> DoubleVector);
	TCommonSample(std::vector<long double> LongDoubleVector);
	TCommonSample(std::vector<unsigned char> UCharVector);
	TCommonSample(std::vector<unsigned short> UShortVector);
	TCommonSample(std::vector<unsigned int> UIntVector);
	TCommonSample(std::vector<unsigned long long> ULongLongIntVector);
	TCommonSample(std::vector<char> CharVector);
	TCommonSample(std::vector<short> ShortVector);
	TCommonSample(std::vector<int> IntVector);
	TCommonSample(std::vector<long long> LongLongIntVector);
	~TCommonSample();
	
	bool IncludeElement(const T& NewValue);
	T ReplaceWorseElement(const T& NewValue);
	T ExcludeWorseElement();
	bool EliminateDownto(const unsigned NewSize);
	bool MergeWith(TCommonSample<T>& OtherSample);
	
	long double GetAverage();
	long double GetSelectiveDispersion();
	long double GetSelectiveStandardDeviation();
	long double GetCorrectedSelectiveDispersion();
	long double GetCorrectedSelectiveStandardDeviation();
	long double GetSelectiveDistributionFunctionValue(const T& x);
	unsigned GetSize();
	
	std::vector<T> GetArrayAsIs();
	std::vector<T> GetSortedArray(bool Stand);
protected:
	T* _base;
	unsigned _size;
	unsigned _capacity;
	bool EnlargeSize();
	
	long double _average_value;
	bool _is_modified;
	bool _HeapSortStand;  // ASC == true, DSC == false
	
	long double _SelectiveDispersion();
};

//----------------------------------------------------------------------
// IMPLEMENTATION OF TCommonSample<T>
#include <algorithm>
#include <cmath>

template <typename T>
TCommonSample<T>::TCommonSample()
{
	
}

template <typename T>
long double TCommonSample<T>::GetSelectiveDispersion()
{
	if (_size < 2)
		throw TIllicitSampleException;
	
	long double AVG = GetAverage();
	long double sum = 0.0;
	
	for (unsigned i = 1; i <= _size; i++)
	{
		sum += (_base[i]-AVG) * (_base[i]-AVG);
	}
	
	return sum / _size;
	
}

template <typename T>
long double TCommonSample<T>::GetAverage() {
	Sample.GetSortedArray(true);
	int size = Sample.GetSize();
	int intervalsCount = ceil(log2(size)); // число интервалов
	long double intervalLength = (Sample[size - 1] - Sample[0]) / intervalsCount; //длина одного интервала
	
	long double leftBound = Sample[0];
	long double rightBound = Sample[0] + intervalLength;
	long double mPointEstimation = 0;
	for( int i = 0; i < intervalsCount; i++ ) {
		mPointEstimation += (rightBound + leftBound) * GetFreqInInterval( Sample, leftBound, rightBound )  / 2;  
	}
	return mPointEstimation;
}

template <typename T>
long double TCommonSample<T>::GetCorrectedSelectiveStandardDeviation() {
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
		sigmaPointEstimation += pow( temp, 2 ) * GetFreqInInterval( Sample, leftBound, rightBound );  
	}
	return sqrt( sigmaPointEstimation * size / (size - 1) );
}


#endif
