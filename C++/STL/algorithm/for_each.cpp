/*

for_each(b, e, q)
	b:迭代器
	e:迭代器
	q:函数对象
*/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

//template <class T>
void print(int elem)
{
	cout << elem << " ";
}

template <class T>
class AddValue
{
private:
	T theValue;

public:
	AddValue(const T& v) :theValue(v) {}
	void operator()(T& elem)const
	{
		elem += theValue;
	}
};


class MeanValue
{
private:
	long num;
	long sum;

public:
	MeanValue() :num(0), sum(0) {}
	void operator() (int elem)
	{
		num++;
		sum += elem;
	}
	double value()
	{
		return static_cast<double>(sum) / static_cast<double>(num);
	}

	operator double() {
		return static_cast<double>(sum) / static_cast<double>(num);
	}
};

void for_each()
{
	vector<int> ivec;
	for (int i = 0; i < 10; i++)
	{
		ivec.push_back(i);
	}

	for_each(ivec.begin(), ivec.end(), print);
	cout << endl;

	for_each(ivec.begin(), ivec.end(), AddValue<int>(10));
	for_each(ivec.begin(), ivec.end(), print);
	cout << endl;

	MeanValue mv = for_each(ivec.begin(), ivec.end(), MeanValue());
	cout << "avage is: " << mv.value() << endl;

	double reasult = for_each(ivec.begin(), ivec.end(), MeanValue());
	cout << "avage is: " << reasult << endl;

	cout << endl;
}