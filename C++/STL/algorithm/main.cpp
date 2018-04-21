#include"demo.h"

int main()
{
	cout << endl << "--------------------------------------" ;
	cout << endl << "计算元素个数：" << endl;
	count();

	cout << endl << "--------------------------------------";
	cout << endl << "最大值最小值算法示例：" << endl;
	max_min();

	cout << endl << "--------------------------------------";
	cout << "查找算法示例：" << endl;
	find_search();
	
	cout << endl << "--------------------------------------";
	cout << endl << "adjacent_find demo：" << endl;
	adjacent_find();

	cout << endl << "--------------------------------------";
	cout << endl << "binary_search demo：" << endl;
	binary_search();

	cout << endl << "--------------------------------------";
	cout << endl << "bound demo：" << endl;
	bound();

	cout << endl << "--------------------------------------";
	cout << endl << "for_each demo：" << endl;
	for_each();

	cout << endl << "--------------------------------------";
	cout << endl << "compare demo：" << endl;
	compare_demo();

	cout << endl << "--------------------------------------";
	cout << endl << "modify algorithm demo：" << endl;
	copy_modify();
	system("pause");

	return 0;
}