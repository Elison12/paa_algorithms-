/* C Program for Bad Character Heuristic of Boyer
Moore String Matching Algorithm */
# include <limits.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>


# define NO_OF_CHARS 256

int max (int a, int b) { return (a > b)? a: b; }


void badCharHeuristic( char *str, int size,
						int badchar[NO_OF_CHARS])
{
	int i;

	for (i = 0; i < NO_OF_CHARS; i++)
		badchar[i] = -1;


	for (i = 0; i < size; i++)
		badchar[(int) str[i]] = i;
}


void search(char *txt, char *pat)
{
	int m = strlen(pat) -1;
	int n = strlen(txt) -1;

	int notoccur = -1;
	int count = 0;
	// printf("tamanho do padrao %d\n", m);
	// printf("tamanho do texto %d\n", n);


	int badchar[NO_OF_CHARS];


	badCharHeuristic(pat, m, badchar);

	int s = 0; 
	while(s <= (n - m))
	{
		int j = m-1;


		while(j >= 0 && pat[j] == txt[s+j])
			j--;

		if (j < 0)
		{
			printf("%d\n", s);
			count++;

			s += (s+m < n)? m-badchar[txt[s+m]] : 1;

		}

		else

			s += max(1, j - badchar[txt[s+j]]);
	}
	if (count == 0) {
		printf("%d", notoccur);
	}
}

int main()
{
	char *txt;
	char *pat;

    txt = malloc(256 * sizeof(char));
    pat = malloc(256 * sizeof(char));

    fgets(txt, 256, stdin);
	fgets(pat, 256, stdin);
	
	search(txt, pat);

    free(txt);
	free(pat);
    return 0;
}
