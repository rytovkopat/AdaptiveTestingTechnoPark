#ifndef MIXED_DISTRIBUTION_EXCEPTIONS_H
#define MIXED_DISTRIBUTION_EXCEPTIONS_H

#include "DistributionExceptions.h"

class TMixedProbabilityException : TMixedDistributionException
{
public:
	~TMixedProbabilityException();
	const char* GetMessage()
	{
		return "For this input the mixed distribution does not have a probability!";
	}
};

class TMixedDensityException : TMixedDistributionException
{
public:
	~TMixedDensityException();
	const char* GetMessage()
	{
		return "For this input the mixed distribution does not have a density!";
	}
};

class TMixedProbabilityException : public TMixedDistributionException
{
	~TMixedProbabilityException();
	const char* GetMessage()
	{
		return "For this input the mixed distribution does not have a probability!";
	}
};

#endif
