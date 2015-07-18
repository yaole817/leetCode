#include<iostream>
using namespace std;
int singleRomanToInt(char s)
{
	if (s == 'I')return 1;
	else if (s == 'V')return 5;
	else if (s == 'X')return 10;
	else if (s == 'L')return 50;
	else if (s == 'C')return 100;
	else if (s == 'D')return 500;
	else if (s == 'M')return 1000;
	else return 0;
}
int romanToInt(char* s) {
	int sum = 0;
	while ((*s) != '\0')
	{
		if ((singleRomanToInt(*(s + 1)) != '\0') &&
			(singleRomanToInt(*(s + 1)) > (singleRomanToInt(*s)))
			)
		{
			sum = sum - singleRomanToInt(*s);
		}
		else{
			sum = sum + singleRomanToInt(*s);
		}
		s++;
	}
	return sum;
}
int main()
{
	cout << romanToInt("XL") << endl;
}