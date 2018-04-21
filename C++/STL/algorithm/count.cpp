#include<iostream>
#include<algorithm>
#include<functional>
#include<list>
#include<vector>

using namespace std;

template <typename elementType>
bool IsEven(const elementType& number)
{
	return ((number % 2) == 0);
}

void count()
{
	vector<int> vec;
	list<int> li;

	for (int i = -3; i < 6; i++)
	{
		vec.push_back(i);
	}

	for (vector<int>::iterator itervec = vec.begin(); itervec != vec.end(); itervec++)
	{
		cout << *itervec << " ";
	}
	cout << endl;

	cout << "在vector中4的个数是： " << count(vec.begin(), vec.end(), 4) << endl << endl;

	size_t nNumber = count_if(vec.begin(), vec.end(), IsEven<int>);   //计算vector中有几个偶数
	cout << "vector里有 " << nNumber << " 个偶数" << endl << endl;

	nNumber = count_if(vec.begin(), vec.end(), not1(bind2nd(modulus<int>(), 2))); //使用函数适配器
	cout << "vector里有 " << nNumber << " 个偶数" << endl << endl;

	nNumber = count_if(vec.begin(), vec.end(), bind2nd(greater<int>(), 4));  //函数适配器，预定义类型
	cout << "vector 有 " << nNumber << " 个数大于4" << endl << endl;
}

