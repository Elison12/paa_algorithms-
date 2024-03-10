// CPP program to find minimum deletions to make
// palindrome.
#include <bits/stdc++.h>
using namespace std;


int getLevenstein(string const& input)
{
	// Find reverse of input string
	string revInput(input.rbegin(), input.rend());

	// Create a DP table for storing edit distance
	// of string and reverse.
	int n = input.size();
	vector<vector<int> > dp(n + 1, vector<int>(n + 1, -1));
	for (int i = 0; i <= n; ++i) {
		dp[0][i] = i;
		dp[i][0] = i;
	}

	// Find edit distance between input and revInput
	// considering only delete operation.
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (input[i - 1] == revInput[j - 1])
				dp[i][j] = dp[i - 1][j - 1];		
			else
				dp[i][j] = 1 + min({ dp[i - 1][j], dp[i][j - 1] });		
		}
	}

    cout << dp[n][n];
	/*Go from bottom left to top right and find the minimum*/
	int res = numeric_limits<int>::max();
	for (int i = n, j = 0; i >= 0; --i, ++j) {
		res = min(res, dp[i][j]);
		if (i < n)
			res = min(res, dp[i + 1][j]);	
		if (i > 0)
			res = min(res, dp[i - 1][j]);	
	}
	return res;
}

// Driver code
int main()
{
	string input("MADAM");
	cout << getLevenstein(input);
	return 0;
}
