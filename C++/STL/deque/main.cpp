#include<iostream>
#include<queue>

using namespace std;

int main()
{
	deque<int> v;
	v.push_back(3);
	v.push_back(4);

	v.push_front(2);
	v.push_front(1);

	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}

	cout << endl << endl;
	v.pop_back();
	v.pop_front();

	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}

	system("pause");
	return 0;
}