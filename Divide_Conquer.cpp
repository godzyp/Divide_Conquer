#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
using namespace std;
int P_count = 0;//非重复排列的个数
template<class Type>
void Permutation(Type *a, int x, int n)
//实现非重复全排列
{
	if (x == n)				//递归出口，条件是元素序号相等
	{
		P_count++;			//非重复排列的个数+1
		for (int i = 0; i <= n; i++)
			cout << a[i];	//输出排列结果
		cout << endl;
	}
	else {
		for (int i = x; i <= n; i++)		//对n个元素依次进行全排列
		{
			if (!Exist(a, x, i))			//若存在重复排序则终止递归
			{
				swap(a[x], a[i]);			//进行交换
				Permutation(a, x + 1, n);   //递归求子序列全排序
				swap(a[x], a[i]);
			}
		}
	}
}
template<class Type>
int Exist(Type *a, int x, int n)
//判断是否有重复元素,重复返回1，否则返回0
{
	for (; x < n; x++)//循环查找
		if (a[x] == a[n])
			return 1;
	return 0;
}
int main()
{
	int n;					//排列元素数量n
	string s;
	freopen("./input.txt", "r", stdin);		//输入重定向，从input.txt读取数据
	freopen("./output.txt", "w", stdout);	//输出重定向，向output.txt输出数据 
	cin >> n;
	char *r = new char[n];	//动态创建全排列数组r[n]
	cin >> r;
	Permutation(r, 0, n - 1);				//进行全排列递归
	cout << P_count << endl;

	freopen("CON", "w", stdout);			//输出重定向，将输出流重定向到控制台
	ifstream input("./input.txt");			//将input.txt文件内容显示在控制台中
	cout << "文件input.txt" << endl;
	while (getline(input, s))				//逐行输出
		cout << s << endl;
	ifstream output("./output.txt");		//将output.txt文件内容显示在控制台中
	cout << "文件output.txt" << endl;
	while (getline(output, s))
		cout << s << endl;
	fclose(stdin);			//关闭重定向输入
	fclose(stdout);			//关闭重定向输出
	return 0;
}

