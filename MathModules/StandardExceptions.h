#ifndef STANDARD_EXCEPTIONS_H
#define STANDARD_EXCEPTIONS_H

class TStandardException
{
public:
	virtual ~TStandardException() = 0;
	virtual const char* GetMessage() = 0;
};

class TDistributionException : public TStandardException
{
};

class TDataException : public TStandardException
{
};

class TInterfaceException : public TStandardException
{
};

#endif
