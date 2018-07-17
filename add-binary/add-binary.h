/*
Given two binary strings, return their sum(also a binary string).
*/

#pragma once
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
	string addBinary(string a, string b)
	{
		string temp;
		string longstr, shortstr;
		if (a.size() > b.size())
		{
			longstr = a;
			shortstr = b;
		}
		else
		{
			longstr = b;
			shortstr = a;
		}

		string zero(longstr.size() - shortstr.size(), '0');
		shortstr = zero + shortstr;
		reverse(longstr.begin(), longstr.end());
		reverse(shortstr.begin(), shortstr.end());

		int flag = 0;
		for (int i = 0; i < longstr.size(); i++)
		{
			int num = (longstr[i] - '0') + (shortstr[i] - '0') + flag;
			temp += to_string(num % 2);
			flag = num / 2;
		}
		if (flag)
			temp += to_string(flag);
		reverse(temp.begin(), temp.end());
		return temp;

	}
};
