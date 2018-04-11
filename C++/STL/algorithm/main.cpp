/*
算法函数：
计算个数：
	count
	count_if
查找：
	find
	find_if
计算下标：
	distance
查找多个：
	search
	search_n
*/
#include"demo.h"
#if DEFINE
#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<functional>

using namespace std;

template <typename elementType>
bool IsEven(const elementType& number)
{
	return ((number % 2) == 0);
}

int main()
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
	cout << "vector 有 " << nNumber << " 个数大于4" << endl<<endl;



	vector<int>::iterator itervec;
	/*itervec = find(vec.begin(), vec.end(), -1);
	if (itervec != vec.end())
	{
		cout << "find -1, distance is : " << distance(vec.begin(), itervec) << endl << endl;
	}*/
	itervec = find_if(vec.begin(), vec.end(), IsEven<int>);    //查找第一个偶数的位置
	if (itervec != vec.end())
	{
		cout << "发现偶数, distance is : " << distance(vec.begin(), itervec) << endl << endl;
	}
	
	for (int i = 1; i < 4; i++)
	{
		li.push_back(i);
	}
	vector<int>::iterator iterSearch;
	//iterSearch = search(vec.begin(), vec.end(), li.begin(), li.end());
	iterSearch = search_n(vec.begin(), vec.end(), 1, 3);  //在vector中查找1个3
	if (iterSearch != vec.end())
	{
		cout << "find list, distance is : " << distance(vec.begin(), iterSearch) << endl << endl;
	}
	else {
		cout << "not found!!" << endl;
	}


	system("pause");
	return 0;
}

#endif