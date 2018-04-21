/*
二分查找算法：
	binary_search(b,e,v)
	binary_search(b,e,v,p)
	includes(b,e,sb,se)   //在b-e中查找是否包含sb-se
	includes(b,e,sh,se,p)  //p定义排序规则

*/
#include<iostream>
#include<list>
#include<vector>
#include<algorithm>

using namespace std;

void binary_search()
{
	list<int> li;
	vector<int> ivec;

	for (int i = 1; i < 10; i++)
	{
		li.push_back(i);
	}
	//li.push_back(3);

	for (list<int>::iterator iter = li.begin(); iter != li.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	bool bl = binary_search(li.begin(), li.end(), 3);
	if (bl)
		cout << "found it!!" << endl;
	else
		cout << "not found!!" << endl;

	ivec.push_back(3);
	ivec.push_back(4);
	ivec.push_back(7);

	bl = includes(li.begin(), li.end(), ivec.begin(), ivec.end());  //两个序列必须都是有序的，否则程序出现异常
	if (bl)
		cout << "found it!!" << endl;
	else
		cout << "not found!!" << endl;

	cout << endl;

}