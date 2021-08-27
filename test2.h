#pragma once
#include <utility>

class test2
{
	long double x;
public:
	explicit test2 (const long double _x)
	{
		x = _x;
	}
	explicit test2 (const test2& t)
	{
		x = t.x;
	}

	friend test2 operator"" _t (const long double _x)
	{
		return test2(_x);
	}
	static test2 doSth ()
	{
		test2 t(1.3_t);
		return t;
	}
};

