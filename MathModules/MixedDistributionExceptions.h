#ifndef MIXED_DISTRIBUTION_EXCEPTIONS_H
#define MIXED_DISTRIBUTION_EXCEPTIONS_H

#include "DistributionExceptions.h"

class TMixedProbabilityException : TMixedDistributionException
{
public:
	virtual ~TMixedProbabilityException();
	virtual const char* GetMessage()
	{
		return "For this input the mixed distribution does not have a probability!";
	}
};

class TMixedDensityException : TMixedDistributionException
{
public:
	virtual TMixedDensityException();
	virtual const char* GetMessage()
	{
		return "For this input the mixed distribution does not have a density!";
	}
};

#endif
