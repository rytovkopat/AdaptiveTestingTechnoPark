#ifndef DISTRIBUTION_EXCEPTIONS_H
#define DISTRIBUTION_EXCEPTIONS_H

#include "StandardExceptions.h"

class TNonRandomException : public TDistributionException
{
public:
	~TNonRandomException();
	const char* GetMessage()
	{
		return "The value is not random!";
	}
};

class TInvalidParametersException : public TDistributionException
{
public:
	~TInvalidParametersException();
	const char* GetMessage()
	{
		return "Some parameters of distribution are impossible or undefined!";
	}
};

class TExpectedValueNotExistsException : public TDistributionException
{
public:
	~TExpectedValueNotExistsException();
	const char* GetMessage()
	{
		return "Expected value is undefined for this distribution!";
	}
};

class TDispersionNotExistsException : public TDistributionException
{
public:
	~TDispersionNotExistsException();
	const char* GetMessage()
	{
		return "Dispersion and standard deviation are undefined for this distribution!";
	}
};

class TImpossibleFunctionValueException : TDistributionException
{
public:
	~TImpossibleFunctionValueException();
	const char* GetMessage()
	{
		return "For each distribution its function value lies between 0.0 and 1.0";
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
