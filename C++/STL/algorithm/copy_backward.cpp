/*
	copy
	copy_backward

*/

#include<iostream>
#include<algorithm>
#include<list>
#include<vector>
#include<iterator>
using namespace std;

template <class T>
void static print(T elem)
{
	cout << elem << " ";
}

void copy_modify()
{
	list<int> ilist;
	vector<int> ivec(20);
	for (int i = 0; i < 10; i++)
	{
		ilist.push_back(i);
	}
	for_each(ilist.begin(), ilist.end(), print<int>);
	cout << endl;

	copy(ilist.begin(), ilist.end(), ivec.begin());
	for_each(ivec.begin(), ivec.end(), print<int>);
	cout << endl;

	copy_backward(ilist.rbegin(), ilist.rend(), ivec.end());   //一次一次拷贝到vector后边,使用反向迭代器
	for_each(ivec.begin(), ivec.end(), print<int>);
	cout << endl;

	copy(ivec.begin(), ivec.end(), ostream_iterator<int>(cout, " "));  //copy到输出流
	cout << endl;
	cout << endl;

	vector<char> szvec(10, '.');
	for (char i = 'a'; i <= 'f'; i++)
	{
		szvec.push_back(i);
	}
	szvec.insert(szvec.end(), 10, '.');
	for_each(szvec.begin(), szvec.end(), print<char>);
	cout << endl;
	
	copy(szvec.begin()+10, szvec.begin()+16, szvec.begin()+7);
	for_each(szvec.begin(), szvec.end(), print<char>);
	cout << endl;
}