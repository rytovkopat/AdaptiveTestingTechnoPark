#ifndef T_COMMON_SAMPLE_H
#define T_COMMON_SAMPLE_H

#include <vector>
#include "SampleExceptions.h"
#include "AllocationExceptions.h"

enum SortFormate
{
	HEAP_MAX = 0,
	HEAP_MIN = 1,
	SORT_ASC = 2,
	SORT_DESC = 3,
	NOT_CONTROLLED = 4
}

enum AccumulatedModifications
{
	NOT_MODIFIED = 5,
	SMALL_MODIFY = 6,
	LARGE_MODIFY = 7
}

template <typename T>
class TCommonSample<T>
{
public:
	TCommonSample();
	TCommonSample(const TCommonSample<T>& SourceSample);
	TCommonSample& operator =(const TCommonSample<T>& SourceSample);
	template <typename SourceT>
		TCommonSample(const std::vector<SourceT> &SourceVector);
	~TCommonSample();
	
	bool IncludeElement(const T& NewValue);
	bool AppendVector(const std::vector<T> &AdditionalVector);
	
	T& GetMin();
	T& GetMax();
	long double GetAverage();
	long double GetSelectiveDispersion();
	long double GetSelectiveStandardDeviation();
	long double GetCorrectedSelectiveDispersion();
	long double GetCorrectedSelectiveStandardDeviation();
	long double GetSelectiveDistributionFunctionValue(const T& x);
	long double GetSelectiveDistributionCumulativeFunctionValue(const T& x);
	unsigned GetSize();
	
	std::vector<T> GetArrayAsIs();
	std::vector<T> GetSortedArray(bool ASCase);
	std::vector<T> GetHeapedArray(bool MaxCase);
	SortFormate GetSortStand();
protected:
	T* _base;
	unsigned _size;
	unsigned _capacity;
	SortFormate _sortStand;
	template <typename VT>
		void _InitFromVector(const std::vector<VT> &SourceVector, unsigned start_index = 0);
	
	bool _EnlargeCapacity(unsigned NewCapacity);
	void _SortASC();
	void _SortDeSC();
	void _BuildHeapMax();
	void _BuildHeapMin();
	
	long double _average_value;
	long double _standardDeviation;
	long double _correctedStandardDeviation;
	long double _dispersion;
	long double _correctedDispersion;
	T _max_value;
	T _min_value;
	AccumulatedModifications _isContainerModified;
	void _RecountMainValues();
private:
	void _RecountMinMaxValues() throw();
	void _RecountAverageValue() throw();
	void _RecountDispersion() throw();
	
	void _HeapPush(const T& elem, unsigned heap_size);
	T _HeapPop(unsigned heap_size);
};

//----------------------------------------------------------------------
// IMPLEMENTATION OF TCommonSample<T>
#include <algorithm>
#include <cmath>
#include <cstring>

// ----- Constructor & Destructor block ------
template <typename T>
TCommonSample<T>::TCommonSample()
	: _base(0), _size(0), _capacity(0), _sortStand(NOT_CONTROLLED),
		_isContainerModified(SMALL_MODIFY)
{
}

template <typename T, typename SourceT>
TCommonSample<T>::TCommonSample(const std::vector<SourceT> &SourceVector)
try : _capacity(0), _size(0), _base(0), _sortStand(NOT_CONTROLLED),
		_isContainerModified(LARGE_MODIFY)
{
	_EnlargeCapacity(SourceVector.size());
	
	_InitFromVector(SourceVector);
	if (_size <= 1)
		_isContainerModified = SMALL_MODIFY;
}
catch (TSampleInvalidAllocationException& ex)
{
	// may be permission for logging this fault;
	throw;
}

template <typename T>
TCommonSample<T>::TCommonSample(const TCommonSample &SourceSample)
try : _capacity(0), _size(0), _base(0),
		_sortStand(SourceSample.GetSortStand()),
		_isContainerModified(LARGE_MODIFY)
{
	_EnlargeCapacity(SourceSample.GetSize());
	
	std::vector<T> SourceVector_TCopy = SourceSample.GetArrayAsIs();
	_size = SourceVector_TCopy.size();
	
	_InitFromVector(SourceVector_TCopy);
	if (_size <= 1)
		_isContainerModified = SMALL_MODIFY;
}
catch (TSampleInvalidAllocationException& ex)
{
	// may be permission for logging this fault;
	throw;
}

template <typename T>
TCommonSample<T>& TCommonSample<T>::operator =(const TCommonSample &SourceSample)
try
{
	std::vector<T> SourceVector_TCopy = SourceSample.GetArrayAsIs();
	unsigned new_size = SourceSample.GetSize();
	
	if (new_size > _capacity)
		_EnlargeCapacity(new_size);
			
	_size = new_size;
	_InitFromVector(SourceVector_TCopy);
	_isContainerModified = LARGE_MODIFY;  // Want to make this better :(
	return *this;
}
catch (TSampleInvalidAllocationException& ex)
{
	// may be permission for logging this fault;
	throw;
}

template <typename T, typename VT>
void TCommonSample<T>::_InitFromVector(const std::vector<VT> &SourceVector, unsigned start_index = 0)
{
	for (unsigned index = start_index; index < _size; index++)
		_base[index] = T(SourceVector[index]);
}

template <typename T>
TCommonSample<T>::~TCommonSample()
{
	if (_capacity > 0)
		delete [] _base;
}

template <typename T>
bool TCommonSample<T>::_EnlargeCapacity(unsigned NewCapacity)
{
	if (NewCapacity > _capacity)
	{
		T* new_base = new T [(NewCapacity * 5) >> 2]; // equal to " = new T [unsigned (NewSize * 1.25)];"
		if (!new_base)
			throw TSampleInvalidAllocationException();
		
		if (_size > 0)
			memcpy(new_base, _base, _size * sizeof(T));
		delete [] _base;
		_base = _new_base;
		_capacity = (NewSize * 5) >> 2; // equal to " = unsigned (NewSize * 1.25);"
	}
	
	return true;
}

// ----- Average & Dispersion & StdDeviation block & Min-Max ------
template <typename T>
void TCommonSample<T>::_RecountMainValues()
{
	if (_size < 2)
		throw TIllicitSampleException();
		
	switch (_isContainerModified)
	{
		case NOT_MODIFIED:
			break;
		case LARGE_MODIFY:
			_RecountAverageValue();
			_RecountMaxMinValues();
			case SMALL_MODIFY:
			_RecountDispersion();
			_correctedDispersion = _dispersion * _size / (_size - 1);
			_standardDeviation = sqrtl(_dispersion);
			_correctedStandardDeviation = sqrtl(_correctedDispersion);
			break;
	}
	
	_isContainerModified = NOT_MODIFIED;
}

template <typename T>
void TCommonSample<T>::_RecountAverageValue()
{ // this method is guaranteed to be safe-called; _size >= 2
	long double sum_members = 0.0;
	for (unsigned index = 0; index < _size; index++)
	{
		sum_members += (long double)_base[index];
	}
	
	_average_value = sum_members / _size;
}

template <typename T>
void TCommonSample<T>::_RecountDispersion()
{ // this method is guaranteed to be safe-called; _size >= 2 and _average_value is already valid
	long double sum_deviations = 0.0;
	for (unsigned index = 0; index < _size; index++)
	{
		long double deviation_sqr = (long double)(_base[index]) - _average_value;
		deviation_sqr *= deviation_sqr;
		sum_deviations += deviation_sqr;
	}
	
	_dispersion = sum_deviations / _size;
}

template <typename T>
void TCommonSample<T>::_RecountMaxMinValues()
{ // this method is guaranteed to be safe-called; _size >= 1
	switch (_sortStand)
	{
		case HEAP_MAX:
			_max_value = _base[0];
			_min_value = _base[_size>>1];
			for (unsigned index = (_size>>1) + 1; index < _size; index++)
			{
				if (_base[index] < _min_value)
					_min_value = _base[index];
			}
			break;
		case HEAP_MIN:
			_min_value = _base[0];
			_max_value = _base[_size>>1];
			for (unsigned index = (_size>>1) + 1; index < _size; index++)
			{
				if (_base[index] > _max_value)
					_max_value = _base[index];
			}
			break;
		case SORT_ASC:
			_min_value = _base[0];
			_max_value = _base[_size - 1];
			break;
		case SORT_DESC:
			_max_value = _base[0];
			_min_value = _base[_size - 1];
			break;
		case NOT_CONTROLLED:
			_min_value = _max_value = _base[0];
			for (unsigned index = 1; index < _size; index++)
			{
				if (_base[index] < _min_value)
					_min_value = _base[index];
				if (_base[index] > _max_value)
					_max_value = _base[index];
			}
			break;
	}
}

template <typename T>
long double TCommonSample<T>::GetSelectiveDispersion()
try
{
	if (_size < 2)
		throw TIllicitSampleException();
	if (_isContainerModified != NOT_MODIFIED)
		_RecountMainValues();	
	return _dispersion;
}
catch(TIllicitSampleException &ex)
{
	throw;
}

template <typename T>
long double TCommonSample<T>::GetCorrectedSelectiveDispersion()
try
{
	if (_size < 2)
		throw TIllicitSampleException();
	if (_isContainerModified != NOT_MODIFIED)
		_RecountMainValues();	
	return _correctedDispersion;
}
catch(TIllicitSampleException &ex)
{
	throw;
}

template <typename T>
long double TCommonSample<T>::GetSelectiveStandardDeviation()
try
{
	if (_size < 2)
		throw TIllicitSampleException();
	if (_isContainerModified != NOT_MODIFIED)
		_RecountMainValues();
	return _standardDeviation;
}
catch(TIllicitSampleException &ex)
{
	throw;
}

template <typename T>
long double TCommonSample<T>::GetCorrectedSelectiveStandardDeviation()
try
{
	if (_size < 2)
		throw TIllicitSampleException();
	if (_isContainerModified != NOT_MODIFIED)
		_RecountMainValues();
	return _correctedStandardDeviation;
}
catch(TIllicitSampleException &ex)
{
	throw;
}

template <typename T>
long double TCommonSample<T>::GetAverage()
try
{
	if (_size <= 0)
		throw TEmptySampleException();
	if (_isContainerModified == LARGE_MODIFY)
		_RecountMainValues();
	return _average_value;
}
catch(TIllicitSampleException &ex)
{
	throw;
}

template <typename T>
T& TCommonSample<T>::GetMin()
try
{
	if (_size <= 0)
		throw TEmptySampleException();
	if (_isContainerModified == LARGE_MODIFY)
		_RecountMainValues();
	return _min_value;
}
catch(TIllicitSampleException &ex)
{
	throw;
}

template <typename T>
T& TCommonSample<T>::GetMax()
try
{
	if (_size <= 0)
		throw TEmptySampleException();
	if (_isContainerModified == LARGE_MODIFY)
		_RecountMainValues();
	return _max_value;
}
catch(TIllicitSampleException &ex)
{
	throw;
}

// ----- Add & Delete Sample Methods ------
template <typename T>
bool TCommonSample<T>::IncludeElement(const T& NewValue)
try
{
	if (_size == _capacity)
		_EnlargeCapacity(_size>15 ? _size+1 : 16);
	
	_base[_size++] = NewValue;
	if (size == 1)
	{
		_min_value = _max_value = _base[0];
		_average_value = (long double)_base[0];
		_isContainerModified = SMALL_MODIFY;
	}
	else if (size == 2)
	{
		_average_value = (_base[0] + _base[1]) / 2;
		if (_base[0] < _base[1])
		{
			_min_value = _base[0];
			_max_value = _base[1];
			_sortStand = SORT_ASC;
		}
		else
		{
			_max_value = _base[0];
			_min_value = _base[1];
			_sortStand = SORT_DESC;
		}
		_isContainerModified = SMALL_MODIFY;
	}
	else
	{
		_average_value = (_average_value * (_size - 1) + NewValue) / size;
		if (NewValue < _min_value)
		{
			min_value = NewValue;
		}
		if (NewValue > _max_value)
		{
			max_value = NewValue;
		}
		_isContainerModified = SMALL_MODIFY;
		
		switch (_sortStand)
		{
			case NOT_CONTROLLED:
				break;
			case SORT_ASC:
				for (unsigned cursor = _size-1; cursor>0 && _base[cursor] < _base[cursor-1]; cursor--)
					std::swap(_base[cursor-1], _base[cursor]);
				break;
			case SORT_DESC:
				for (unsigned cursor = _size-1; cursor>0 && _base[cursor] > _base[cursor-1]; cursor--)
					std::swap(_base[cursor-1], _base[cursor]);
				break;
			case HEAP_MIN:
				// _HeapPush(NewValue, _size-1); // code below to be moved into this private method
			
				T* _heap0elem = _base-1;
				for (unsigned cursor = _size; cursor>1; )
				{
					T& MinChild = _heap0elem[cursor];
					if (cursor+1 <= _size && _heap0elem[cursor+1] < MinChild)
						MinChild = _heap0elem[cursor+1];
					if (_heap0elem[cursor>>1] > MinChild)
					{
						std::swap(MinChild, _heap0elem[cursor>>1]);
						cursor >>= 1;
					}
					else
						break;
				}
				break;
			case HEAP_MAX:
				// _HeapPush(NewValue, _size-1); // code below to be moved into this private method
				T* _heap0elem = _base-1;
				for (unsigned cursor = _size; cursor>1; )
				{
					T& MaxChild = _heap0elem[cursor];
					if (cursor+1 <= _size && _heap0elem[cursor+1] > MaxChild)
						MaxChild = _heap0elem[cursor+1];
					if (_heap0elem[cursor>>1] < MaxChild)
					{
						std::swap(MaxChild, _heap0elem[cursor>>1]);
						cursor >>= 1;
					}
					else
						break;
				}
				
				break;
		}
	}
	return true;
}
catch (TSampleInvalidAllocationException& ex)
{
	// may be permission for logging this fault;
	throw;
}

template <typename T>
unsigned TCommonSample<T>::GetSize()
{
	return _size;
}

template <typename T>
SortFormate TCommonSample<T>::GetSortStand()
{
	return _sortStand;
}

template <typename T>
void TCommonSample<T>::_BuildHeapMax()
{
	// builds heap in the max case
	_sortStand = HEAP_MAX;
}

template <typename T>
void TCommonSample<T>::_BuildHeapMin()
{
	// builds heap in the min case
	_sortStand = HEAP_MIN;
}

template <typename T>
void TCommonSample<T>::_SortASC()
{
	// Here might be an optimization for another sorts before-made
	std::sort(_base, _base + _size);
	_sortStand = SORT_ASC;
}

template <typename T>
void TCommonSample<T>::_SortDeSC()
{
	// Here might be an optimization for another sorts before-made
	std::sort(_base, _base + _size, std::greater);
	_sortStand = SORT_DESC;
}

template <typename T>
long double TCommonSample<T>::GetSelectiveDistributionFunctionValue(const T& x)
{
	// Here might be an optimization for another sorts before-made
	_SortASC();
	if (x <= _min_value)
		return 0.0;
	if (x > _max_value)
		return 1.0;
	// binary search for first not_less than x
	unsigned pos_x = binary_search_greater_or_equal(x);
	return (long double)pos_x / _size;
}

template <typename T>
long double TCommonSample<T>::GetSelectiveDistributionCumulativeFunctionValue(const T& x)
{
	// Here might be an optimization for another sorts before-made
	_SortASC();
	if (x < _min_value)
		return 0.0;
	if (x >= _max_value)
		return 1.0;
	// binary search for first greater than x
	unsigned pos_x = binary_search_greater(x);
	return (long double)pos_x / _size;
}

#endif
