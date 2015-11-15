#ifndef SAMPLE_EXCEPTIONS_H
#define SAMPLE_EXCEPTIONS_H

#include "DataExceptions.h"

class TIllicitSampleException : public TSampleException
{
	virtual ~TIllicitSampleException();
	virtual const char* GetMessage()
	{
		return "Sample is extremely small to be rightly used!";
	}
};

class TEmptySampleException : public TSampleException
{
	virtual ~TIllicitSampleException();
	virtual const char* GetMessage()
	{
		return "Sample is empty so cannot export data from itself!";
	}
};

class TImpossibleSampleEliminationException : public TSampleException
{
	virtual ~TIllicitSampleException();
	virtual const char* GetMessage()
	{
		return "Sample cannot be eliminated with such parameters!";
	}
};

class TWrongSampleSortStandException : public TSampleException
{
	virtual ~TIllicitSampleException();
	virtual const char* GetMessage()
	{
		return "Sample is not already sorted in the necessary way!";
	}
};

#endif
