#include<iostream>
#include<queue>
#include<deque>

using namespace std;

int main()
{
	priority_queue<int> pq; //默认最大值优先级队列
	priority_queue<int, deque<int>> gpq;
	

	pq.push(1);
	pq.push(-1);
	pq.push(100);
	pq.push(23);
	
	cout <<"队列里的个数："<< pq.size() << endl;

	while (!pq.empty())
	{
		cout <<"删除 ： "<< pq.top() << endl;
		pq.pop();
	}
	cout << endl << endl;

	gpq.push(1);
	gpq.push(-1);
	gpq.push(100);
	gpq.push(23);
	cout << "队列里的个数：" << pq.size() << endl;

	while (!gpq.empty())
	{
		cout << "删除 ： " << gpq.top() << endl;
		gpq.pop();
	}

	system("pause");
	return 0;
}