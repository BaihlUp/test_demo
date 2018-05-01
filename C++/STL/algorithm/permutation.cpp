/*
排列组合算法：
	next_permutation()
		源数据为从小到大的数列
	prev_permutation()
		源数据为从大到小的数列

*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

template <class T>
void static print(T elem)
{
	cout << elem << " ";
}

void permutaion()
{
	vector<int> ivec;
	ivec.push_back(1);
	ivec.push_back(2);
	ivec.push_back(3);

	for_each(ivec.begin(), ivec.end(), print<int>);
	cout << endl;

	while (next_permutation(ivec.begin(), ivec.end()))
	{
		for_each(ivec.begin(), ivec.end(), print<int>);
		cout << endl;
	}

	cout << endl;

	ivec.clear();
	ivec.push_back(3);
	ivec.push_back(2);
	ivec.push_back(1);

	for_each(ivec.begin(), ivec.end(), print<int>);
	cout << endl;

	while (prev_permutation(ivec.begin(), ivec.end()))
	{
		for_each(ivec.begin(), ivec.end(), print<int>);
		cout << endl;
	}


}