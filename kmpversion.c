#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void computeLPSArray(char *pat, int M, int *lps);

void KMPSearch(char *pat, char *txt)
{
	// printf("inside");
	int M = strlen(pat);
	int N = strlen(txt);

// 	printf("%s\n", txt);
// 	printf("%s\n", pat);

// 	printf("%d\n", M);
// 	printf("%d\n", N);

	int *lps = (int *)malloc(sizeof(int) * M);
	int j = 0; 

	int countmatches = 0;

	computeLPSArray(pat, M, lps);

	int i = 0;
	while (i < N)
	{
		if (pat[j] == txt[i])
		{
			j++;
			i++;
		}

		if (j == M)
		{
			printf("%d\n", i - j);
			j = lps[j - 1];
			countmatches++;

		}

		else if (i < N && pat[j] != txt[i])
		{
			if (j != 0)
				j = lps[j - 1];
			else
				i = i + 1;
		}
	}
	
	if (countmatches == 0)
		printf("%d", -1);
	free(lps);
}

void computeLPSArray(char *pat, int M, int *lps)
{
	// printf("compute");
	int len = 0;
	int i;

	lps[0] = 0;
	i = 1;

	while (i < M)
	{
		if (pat[i] == pat[len])
		{
			len++;
			lps[i] = len;
			i++;
		}
		else // (pat[i] != pat[len])
		{
			if (len != 0)
			{
				len = lps[len - 1];

			}
			else // if (len == 0)
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

int main()
{
	char *txt;
	char *pat;

	txt = malloc(2000000 * sizeof(char)); 
	pat = malloc(2000000 * sizeof(char)); 

	fgets(txt, 2000000, stdin);
	fgets(pat, 2000000, stdin);

	// printf("%s\n", txt);
	// printf("%s\n", pat);
	KMPSearch(pat, txt);

	free(txt);
	free(pat);
	return 0;
}