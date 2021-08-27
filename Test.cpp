#include <iostream>
#include <vector>
#include "cfraction.h"
using namespace std;

int main()
{
	int a;
	vector <fraction> vector;
	while (cin >> a)
	{
		vector.emplace_back(a);
	}
	for (fraction x:vector)
	{
		cout << fraction::simplify(x);
	}
}