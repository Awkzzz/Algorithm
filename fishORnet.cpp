# 某人从1990年1月1日开始“三天打渔两天晒网”，问此人在将来的某一天是打渔还是晒网
# 链接：http://blog.csdn.net/z_zhangyinqian/article/details/49444325

#include <stdio.h>
#include <tchar.h>
#include <iostream>

#define leapyear 1;
#define commonyear 0;

using namespace std;


typedef struct data {
	int year;
	int month;
	int day;
}Data;

int dayInMonth[2][12] = {
	{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},//平年每月天数
	{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} //闰年每月天数
};

int LeapYear(int year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return leapyear;
	return commonyear;
}

int days(Data a)
{
	int totaldays = 0;
	for (int y = 1990; y < a.year; y++)
	{
		if (LeapYear(y))
		{
			for (int m = 0; m < 12; m++)
				totaldays += dayInMonth[1][m];
		}
		else
		{
			for (int m = 0; m < 12; m++)
				totaldays += dayInMonth[0][m];
		}
	}
	if (LeapYear(a.year))
	{
		for (int m = 0; m < a.month -1; m++)
			totaldays += dayInMonth[1][m];
	}
	else
	{
		for (int m = 0; m < a.month -1; m++)
			totaldays += dayInMonth[0][m];
	}
	totaldays += a.day;
	return totaldays;
}

int main()
{
	Data riqi;
	int numOfDays;
	cout << "请输入日期信息（如2017.5.8）" << endl;
	//cin >> riqi.year >> riqi.month >> riqi.day;
	scanf_s("%d.%d.%d", &riqi.year, &riqi.month, &riqi.day);
	numOfDays = days(riqi);
	cout << "输入日期距1990.1.1有" << numOfDays << "天" << endl;
	if (numOfDays % 5 > 0 && numOfDays % 5 < 4)
		cout << "此人在打渔" << endl;
	else
		cout << "此人在晒网" << endl;
	system("pause");
    return 0;
}
