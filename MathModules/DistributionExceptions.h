#ifndef DISTRIBUTION_EXCEPTIONS_H
#define DISTRIBUTION_EXCEPTIONS_H

#include "StandardExceptions.h"

class TNonRandomException : public TDistributionException
{
public:
	virtual ~TNonRandomException();
	virtual const char* GetMessage()
	{
		return "The value is not random!";
	}
};

class TInvalidParametersException : public TDistributionException
{
public:
	virtual ~TInvalidParametersException();
	virtual const char* GetMessage()
	{
		return "Some parameters of distribution are impossible or undefined!";
	}
};

class TExpectedValueNotExistsException : public TDistributionException
{
public:
	virtual ~TExpectedValueNotExistsException();
	virtual const char* GetMessage()
	{
		return "Expected value is undefined for this distribution!";
	}
};

class TDispersionNotExistsException : public TDistributionException
{
public:
	virtual ~TDispersionNotExistsException();
	virtual const char* GetMessage()
	{
		return "Dispersion and standard deviation are undefined for this distribution!";
	}
};

class TImpossibleFunctionValueException : TDistributionException
{
public:
	virtual ~TImpossibleFunctionValueException();
	virtual const char* GetMessage()
	{
		return "For each distribution its function value lies between 0.0 and 1.0";
	}
};

class TUndefinedDistributionMethod : TDistributionException
{
	virtual ~TUndefinedDistributionMethod();
	virtual const char* GetMessage()
	{
		return "This method was called while being undefined!";
	}
};

class TDiscreteDistributionException : public TDistributionException
{
};

class TContinuousDistributionException : public TDistributionException
{
};

class TMixedDistributionException : public TDistributionException
{
};

#endif
