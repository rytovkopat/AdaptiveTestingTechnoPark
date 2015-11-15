#ifndef ALLOCATION_EXCEPTIONS_H
#define ALLOCATION_EXCEPTIONS_H

#include "DataExceptions.h"

class TDistributionParamsAllocationException : public TAllocationException
{
	virtual ~TDistributionParamsAllocationException();
	virtual const char* GetMessage()
	{
		return "Cannot allocate enough memory for the distribution parameters!";
	}
};

class TSampleAllocationException : public TAllocationException
{
	virtual ~TSampleAllocationException();
	virtual const char* GetMessage()
	{
		return "Cannot allocate enough memory for the sample!";
	}
};

#endif
