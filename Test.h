#pragma once
class test
{
	long double x;
public:
	test(int a)
	{
		x = a;
	}
	friend test operator "" _t(long double a)
	{
		return test(a);
	}
	static test doSth()
	{
		return 12.2_t; //work fine
	}
};