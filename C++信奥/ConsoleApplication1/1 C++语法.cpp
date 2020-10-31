#include<iostream>
using namespace std;

//1.4
#if 0
int main()
{
	int s1{ 15 * 20 };
	int s2{ 20 * 10 };
	int delta{ (s1 - s2)/10 };
	cout << "s=" << delta << endl;
}
#endif
//4.5辗转相除
#if 0
int main()
{
	int m, n, r;
	cin >> m >> n;
	r = m % n;
	while (r != 0)
	{
		m = n;
		n = r;
		r = m % n;
	}
	cout << "最大公约数:" << n << endl;
}
#endif
//5.4约瑟夫问题
#if 0
int main()
{
	int n, m;
	cin >> n >> m;
	bool a[101];
	memset(a, 0, sizeof(a));
	int cnt{ 0 }, cir{ 0 }, num{ 0 };

	while (cnt != n)
	{
		cir++;
		//-----绕了一圈就停下来
		if (cir == n)	cir = 0;			//因为数组元素没法踢出,因此每次都要循环圈
		//-----还有人就报数------
		if(a[cir] == false)	num++;
		//-----T人-------
		if (num == m)
		{
			a[cir] = true;		//出圈
			cout << cir << endl;
			cnt++;				//出圈人数+1
			num = 0;			//报道次数清零
		}
	}
}
#endif // 1
//5.6冒泡排序
#if 1
const int n = 10;
int main()
{
	int a[n + 1];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for(int i=0;i<n;i++)
		for(int j =n-2;j>=i;j--)
			if (a[j] < a[j + 1])
			{
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
	for (int i = 0; i < n; i++)
		cout << a[i] << endl;
}
#endif // 1

