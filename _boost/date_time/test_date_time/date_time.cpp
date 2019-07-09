// date_time.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

#define BOOST_DATE_TIME_SOURCE

#include <libs/date_time/src/gregorian/greg_names.hpp>
#include <libs/date_time/src/gregorian/date_generators.cpp>
#include <libs/date_time/src/gregorian/greg_month.cpp>
#include <libs/date_time/src/gregorian/greg_weekday.cpp>
#include <libs/date_time/src/gregorian/gregorian_types.cpp>
#include <boost/date_time/posix_time/ptime.hpp>
#include <boost/date_time.hpp>

using namespace boost::gregorian;
using namespace boost::posix_time;
using namespace std;

int main()
{
	//初始化格式：
	date d1(2019,7,9);//使用数字构造日期
	date d2 = from_string("2019-07-09");//使用字符串

	//输出
	string str = to_simple_string(d1);//转换为YYYY-MMM-DD 中间的月是英文简写 eg Jan
	str = to_iso_string(d1);//转换为YYYYMMDD
	str = to_iso_extended_string(d1);//转换为YYYY-MMM-DD数字字符串

	cout << "str is " << str << endl;

	date_period t(date(2019,7,9), days(20));//日期区间
	
	t.shift(days(3)); //shift()将日期区间平移n天而长度不变
	t.expand(days(3)); //expand()将日期区间向两端延伸n天

	ptime p = time_from_string("2019-7-9 20:17:00");//时间点对象

	time_duration td;//时间区间对象 提供交集、并集

	cout << d1.day() << endl;
    std::cout << "Hello World!\n";
}
