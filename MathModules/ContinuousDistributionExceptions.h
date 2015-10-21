#ifndef CONTINUOUS_DISTRIBUTION_EXCEPTIONS_H
#define CONTINUOUS_DISTRIBUTION_EXCEPTIONS_H

#include "DistributionExceptions.h"

class TContinuousProbabilityException : public TContinuousDistributionException
{
public:
	~TContinuousProbabilityException();
	const char* GetMessage()
	{
		return "Continuous distribution does not have a probability!";
	}
};

#endif
