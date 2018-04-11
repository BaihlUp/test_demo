/*
最大值最小值函数：
	

*/

#include<iostream>
#include<algorithm>
#include<deque>

using namespace std;

bool absLess(int elem1, int elem2)
{
	return abs(elem1) < abs(elem2);
}

int main()
{
	deque<int> ideq;

	for (int i = -1; i < 8; i++)
	{
		ideq.insert(ideq.begin(),i);
	}
	ideq.push_back(9);

	deque<int>::iterator iter = ideq.begin();
	for (; iter != ideq.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	deque<int>::iterator result = min_element(ideq.begin(), ideq.end());
	cout << "最小值是： " << *result << endl;
	cout << "最大值是： " << *max_element(ideq.begin(), ideq.end()) << endl;
	cout << endl;

	cout << "绝对最大值： " << *max_element(ideq.begin(), ideq.end(), absLess) << endl;
	cout << "绝对最小值： " << *min_element(ideq.begin(), ideq.end(), absLess) << endl;

	system("pause");
	return 0;
}