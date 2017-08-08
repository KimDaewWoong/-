#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int T, n, m;
struct abc {
	int first;
	int second;
}arr[10010];
bool X_cmp(const abc &a, const abc &b)
{
	if (a.first == b.first) { return a.second < b.second; }
	return a.first < b.first;
}
bool X_cmp2(const abc &a, const abc &b)
{
	if (a.first == b.first) { return a.second > b.second; }
	return a.first < b.first;
}
bool X_cmp3(const abc &a, const abc &b)
{
	if (a.first == b.first) { return a.second < b.second; }
	return a.first > b.first;
}

bool Y_cmp(const abc &a, const abc &b)
{
	if (a.second == b.second) { return a.first < b.first; }
	return a.second < b.second;
}
bool Y_cmp2(const abc &a, const abc &b)
{
	if (a.second == b.second) { return a.first < b.first; }
	return a.second > b.second;
}

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		memset(arr, 0, sizeof(arr));
		scanf("%d %d", &n, &m);
		for (int i = 0; i < m; i++)
			scanf("%d %d", &arr[i].first, &arr[i].second);
		int cnt = 0;
		int key = 1;
		if (n != 360 && n != 180)
		{
			if (n == 45 || n == 225)
			{
				sort(arr, arr + m, X_cmp);
				for (int j = 0; j < m; j++)
				{
					for (int q = j + 1; q < m; q++)
					{
						if (arr[m - j - 1].second >= arr[m - q - 1].second)
						{
							cnt++;
						}
					}
				}
			}
			else if (n == 90)
			{
				sort(arr, arr + m, X_cmp3);
				key = 1;
				for (int j = 0; j < m; j++)
				{
					if (arr[j].first == arr[j + 1].first)
					{
						key++;
					}
					else if (key != 1)
					{
						cnt += (m - j - 1)*key;
						cnt += (key) * (key - 1);
						key = 1;
					}
					else
					{
						cnt += m - j - 1;
					}
				}
			}
			else if (n == 270)
			{
				sort(arr, arr + m, X_cmp);
				key = 1;
				for (int j = 0; j < m; j++)
				{
					if (arr[j].first == arr[j + 1].first)
					{
						key++;
					}
					else if (key != 1)
					{
						cnt += (m - j - 1)*key;
						cnt += (key) * (key - 1);
						key = 1;
					}
					else
					{
						cnt += m - j - 1;
					}
				}
			}
			else if (n == 135 || n == 315)
			{
				sort(arr, arr + m, X_cmp2);
				for (int j = 0; j < m; j++)
				{
					for (int q = j + 1; q < m; q++)
					{
						if (arr[m - j - 1].second <= arr[m - q - 1].second)
						{
							cnt++;
						}
					}
				}
			}
		}
		else {
			if (n== 360)
			{
				sort(arr, arr + m, Y_cmp2);
				key = 1;
				for (int j = 0; j < m; j++)
				{
					if (arr[j].second == arr[j + 1].second)
					{
						key++;
					}
					else if (key != 1)
					{
						cnt += (m - j - 1)*key;
						cnt += (key) * (key - 1);
						key = 1;
					}
					else
					{
						cnt += m - j - 1;
					}
				}
			}
			else if (n == 180)
			{
				sort(arr, arr + m, Y_cmp);
				key = 1;
				for (int j = 0; j < m; j++)
				{
					if (arr[j].second == arr[j + 1].second)
					{
						key++;
					}
					else if (key != 1)
					{
						cnt += (m - j - 1)*key;
						cnt += (key) * (key - 1);
						key = 1;
					}
					else
					{
						cnt += m - j - 1;
					}
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}