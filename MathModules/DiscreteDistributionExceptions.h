#ifndef DISCRETE_DISTRIBUTION_EXCEPTIONS_H
#define DISCRETE_DISTRIBUTION_EXCEPTIONS_H

#include "DistributionExceptions.h"

class TFloatArgumentException : public TDiscreteDistributionException
{
public:
	~TFloatArgumentException();
	const char* GetMessage()
	{
		return "Discrete distribution expects only unsigned integer arguments!";
	}
};

class TDiscreteDensityException : public TDiscreteDistributionException
{
public:
	~TDiscreteDensityException();
	const char* GetMessage()
	{
		return "Discrete distribution does not have a density!";
	}
};

#endif
