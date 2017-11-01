#include<iostream>
#include<ctime>
using namespace std;
typedef long long ll ;

ll power(ll a, ll b,ll c)
{
	ll r = 1;
	while (b-- > 0)
	{
		r = r*a%c;
	}
	return r;
}

bool FPT(int p, int k)
{
	if (p <= 3)
		return true;
	if (p % 2 == 0)
		return false;
	while (k-->0)
	{
		int a = rand() % (p-2) + 2;
		if (power(a, p-1, p) != 1)
			return false;
	}
	return true;
}
int main()
{
	srand(0);
	int a;
	while (cin >> a)
		cout << FPT(a, 5) << "\n";

	return 0;
}