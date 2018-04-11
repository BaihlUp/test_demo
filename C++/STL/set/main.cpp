//数据结构中的红黑树

#include<iostream>
#include<set>

using namespace std;

int main()
{
	set<int> v;
	multiset<int> muv;

	v.insert(1);
	v.insert(123);
	v.insert(12);
	v.insert(23);
	v.insert(199);
	v.insert(2);
	v.insert(199);

	muv.insert(v.begin(),v.end());
	muv.insert(199);

	cout << "显示set里面的数据: " << endl;
	set<int>::iterator iter = muv.begin();
	muv.insert(iter, 11);
	while (iter != muv.end())
	{
		cout << *iter << endl;
		++iter;
	}
	cout << endl << endl;
	multiset<int>::iterator muiter = muv.find(2);
	if (muiter != muv.end())
	{
		size_t Offset = distance(muv.begin(),muiter);

		cout << "找到了，在" << Offset << "  value:" << *muiter << endl;
	}
	else
		cout << "没找到" << endl;

	system("pause");
	return 0;
}