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
long double TCommonSample<T>::_SelectiveDispersion()
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
long double TCommonSample<T>::GetSelectiveDispersion()
{
	if (_size < 2)
		throw TIllicitSampleException;
	
	return _SelectiveDispersion();
}

template <typename T>
long double TCommonSample<T>::GetCorrectedSelectiveStandardDeviation()
{
	if (_size < 3)
		throw TIllicitSampleException;
	
	return sqrtl(_SelectiveDispersion() * _size / (_size-1));
}
template <typename T>
long double TCommonSample<T>::GetSelectiveStandardDeviation()
{
	if (_size < 2)
		throw TIllicitSampleException;
	
	return sqrtl(_SelectiveDispersion());
}

template <typename T>
long double TCommonSample<T>::GetCorrectedSelectiveDispersion()
{
	if (_size < 3)
		throw TIllicitSampleException;
	
	return _SelectiveDispersion() * _size / (_size-1);
}

template <typename T>
long double TCommonSample<T>::GetAverage() 
{
	if (_size <= 0)
		throw TIllicitSampleException;
	
	if (_is_modified)
	{
		T sum = T(0);
		for (unsigned index = 0; index < _size; index++)
		{
			sum += _base[index];
		}
		
		_is_modified = false;
		_average_value = (long double)sum / _size;
	}

	return _average_value;
}


#endif
