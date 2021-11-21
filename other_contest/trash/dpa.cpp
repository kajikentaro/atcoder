#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
int dp[100][10001] = {};
int main()
{
	int n;
	cin >> n;
	int p[100];
	for (int i = 0; i < n; i++)
	{
		cin >> p[i];
	}
	int max = p[0];
	dp[0][0] = 1;
	dp[0][p[0]] = 1;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= max; j++)
		{
			if (dp[i-1][j])
			{
				dp[i][j] = 1;
				dp[i][j + p[i]] = 1;
				max = std::max(max, j + p[i]);
			}
		}
	}
	int sum = 0;
	for (int i = 0; i <= max; i++)
	{
		if (dp[n-1][i])
			sum++;
	}
	cout << sum << endl;
	return 0;
}
