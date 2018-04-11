#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(123);
	v.push_back(567);

	cout << "显示向量v里面的数据：" << endl;
	vector<int>::iterator i = v.begin();

	while (i != v.end())
	{
		cout << *i << endl;
		++i;
	}

	vector<int>::iterator iElement = find(v.begin(), v.end(), 123);
	if (iElement != v.end())
	{
		int iPosition = distance(v.begin(), iElement);
		cout << "value:" << *iElement << endl;
		cout << "位置：" << iPosition << endl;
	}
	cout << endl << endl;
	vector<int> ivec;
	//ivec.assign(5, 10);
	ivec.assign(v.begin(), v.end());

	vector<int>::iterator j = ivec.begin();

	while (j != ivec.end())
	{
		cout << *j << endl;
		++j;
	}

	vector<int> vec(5, 1);
	for (int ik = 0; ik < vec.size(); ik++) {
		cout << "Element " << ik << " is " << vec.at(ik)<< endl;
	}

	cout << "The front is : " << v.front() << endl;
	cout << "The last is : " << v.back() << endl;

	vector<string> strvec(10,"hi");
	strvec.push_back("baihl");
	strvec.push_back("hello");
	//cout << strvec.at(0) << endl;
	cout << strvec.capacity() << endl;
	cout << strvec.max_size() << endl;
	cout << endl << endl;
	vector<string>::const_iterator itrString;
	for (itrString = strvec.begin(); itrString != strvec.end(); itrString++)
		cout << *itrString << endl;
	strvec.pop_back();
	for (itrString = strvec.begin(); itrString != strvec.end(); itrString++)
		cout << *itrString << endl;

	cout << "\n\nhello STL!" << endl;
	system("pause"); 
	return 0;
}