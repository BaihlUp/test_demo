#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	string strString("Hello String!");
	cout << strString << endl;
	cout << strString.size() << endl;
	cout << strString.c_str() << endl; //转换成了C风格的字符串
	const char *string1 = strString.c_str();
	cout << string1 << endl;

	string::const_iterator itr = strString.begin();
	while (itr != strString.end())
	{
		//cout << *itr << endl;
		++itr;
	}
	cout << endl << endl;
	/*字符串连接*/
	string strSample1("Hello");
	string strSample2("string!");
	strSample1 += strSample2;
	cout << strSample1 << endl;

	char *strSample3 = "I am baihl";
	strSample1.append(strSample3);  //字符串连接
	cout << strSample1 << endl;

	//字符串查找
	string strFind1("Good day String! Today is beautiful!");
	cout << strFind1 << endl;
	size_t nOffset = strFind1.find("day", 0);
	if (nOffset != string::npos)
	{
		cout << "在下标：" << nOffset << "找到了day!" << endl;
	}
	else
		cout << "没找到" << endl;
	
	//字符查找
	size_t nCharOffset = strFind1.find('a', 0);
	while (nCharOffset != string::npos)
	{
		cout << "在下标：" << nCharOffset << "找到了a" << endl;
		size_t nSearchOffset = nCharOffset + 1;
		nCharOffset = strFind1.find('a', nSearchOffset);
	}

	//字符串截断
	string strErase(strFind1);
	strErase.erase(13, 28);
	cout << endl << endl << strErase << endl;

	string::const_iterator iCharS = find(strErase.begin(), strErase.end(), 'S');
	if (iCharS != strErase.end())
	{
		strErase.erase(iCharS);
	}
	cout << strErase << endl;

	//字符串反转
	cout << endl << endl;
	string strReverse(strFind1);
	cout << strReverse << endl;
	reverse(strReverse.begin(), strReverse.end());
	cout << strReverse << endl;

	//字符串大小写转换
	string strTransform = "baihl";
	transform(strTransform.begin(), strTransform.end(), strTransform.begin(), toupper);
	cout << strTransform << endl;
	transform(strTransform.begin(), strTransform.end(), strTransform.begin(), tolower);
	cout << strTransform << endl;

	//find_first_of
	cout << endl << "find_first_of: " << endl;
	string numerics("0123456789");
	string name("r2d3k");
	string::size_type pos = name.find_first_of(numerics);
	if (pos != string::npos)
		cout << "找到了，下标： " << pos << endl;
	else
		cout << "not found!!" << endl;

	string::size_type pos1 = name.find_last_of(numerics);  //name从后往前匹配，找到首次匹配numerics的字符位置
	//string::size_type pos1 = name.find_first_not_of(numerics); //返回在字符串中首次出现的不匹配name任何字符的首字符索引, 从0开始搜索, 如果全部匹配则返回string::npos
	if (pos1 != string::npos)
		cout << "找到了，下标： " << pos1 << endl;
	else
		cout << "not found!!" << endl;
	cout << endl;
	system("pause");
	return 0;
}