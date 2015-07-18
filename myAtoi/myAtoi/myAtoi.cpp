#include<iostream>
using namespace std;
int myAtoi(char* str);
int main(void)
{
	char *a = "9223372036854775809";
	cout << myAtoi(a) << endl;
}
int myAtoi(char* str) {
	long long int result = 0;
	long long  num = 0;
	int flag = 0;
	int time = 0;
	int start_flag = 0;
	while ((*str) != '\0')
	{
		if ((*str) == '-'){ start_flag = 1; time++; flag = 1; }
		else if ((*str) == '+'){ start_flag = 1; time++; flag = 0; }
		else if ((*str) >= '0' && (*str) <= '9')
		{
			start_flag = 1;
			num = (long long)((*str) - '0');
			result = result * 10 + num;
			if (result >= 2147483648){ break; }
		}
		else if ((*str) != ' '){ break; }
		if (time >= 2){ result = 0; break; }
		str++;
		if (((*(str) > '9') | (*(str) < '0')) && (start_flag == 1)){ break; }

	}
	if (flag == 1)
	{
		//result = -result;
		if (result >= 2147483648)result = 2147483648;
		return (int)(-result);
	}
	else
	{
		if (result >= 2147483647)result = 2147483647;
		return (int)result;
	}
}