#include <bits/stdc++.h>
//includes all required header files
using namespace std;

// Returns the length of the longest palindromic subsequence in 'str'
int lps(string str)
{
	int n = str.size();
    
	// Create a table to store  results of subproblems
	int L[n][n];

	// Strings of length 1 are palindrome of length 1
	for (int i = 0; i < n; i++)
		L[i][i] = 0;
	for (int cl=2; cl<=n; cl++)
	{
		for (int i=0; i<n-cl+1; i++)
		{
			int j = i+cl-1;
		    if (str[i] == str[j])
				L[i][j] = L[i+1][j-1];
			else
				L[i][j] = min(L[i][j-1], L[i+1][j]) + 1;
		}
	}

	// length of longest palindrome
	return L[0][n-1];
}

// function to calculate least number of deletions
int minimumNumberOfDeletions(string str)
{
	int n = str.size();

	// Find longest palindromic subsequence
	int len = lps(str);
	return len;
}

int main()
{
	string str = "opengenus";
	cout << "\nMinimum number of deletions required = "
		<< minimumNumberOfDeletions(str);
	return 0;
}
