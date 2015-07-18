#include <iostream>
using namespace std;
long long  abs_1(long long x)
{
	if (x < 0)return (-x);
	else return x;
}
int reverse(int x) {
	long long  y = x;
	long long  a = 0, b = 0, c = 0;
	c = 0;
	if (abs_1(x) / 10 == 0)return x;
	while (abs_1(x) / 10 != 0)
	{
		a = x / 10;
		b = x % 10;
		if (abs_1(a) < 10)
		{
			if (abs_1(c * 10 + b * 10 + a)>2147483648)return 0;
			else
				return (c * 10 + b * 10 + a);
		}
		else
		{
			c = c * 10 + b * 10;
			x = a;
		}
	}
}
bool isPalindrome(int x) {
	int y = reverse(x);
	if (x<0)return 0;
	if (x == y)return 1;
	else return 0;

}
int main()
{
	cout << isPalindrome(456654) << endl;
}