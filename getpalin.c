#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
 
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))



int is_it_palindrome(const char* str)
{
    int lenght;
    int has_alnum = 0;
    lenght = strlen(str);
 
    const char* start = str + 0;
    const char* end = str + lenght - 1;
 
    while (start <= end)
    {
        if (!isalnum(*start))
        {
            start++;
        }
        else if (!isalnum(*end))
        {
            end--;
        }
        else if (toupper(*start) == toupper(*end))
        {
            has_alnum = 1;
            start++;
            end--;
        }
        else
        {
            return 0;
        }
    }
 
    return has_alnum;
}
int lps(char* str)
{
 
    int n = strlen(str);
    // int n = strlen(str);
    int ehpalindromo = is_it_palindrome(str);
    if (ehpalindromo == 1)
    {
        return n;
    }
 
    int L[n][n];
 
    for (int i = 0; i < n; i++)
    {
        L[i][i] = 1;
    }
    for (int cl = 2; cl <= n; cl++)
    {
        for (int i = 0; i < n - cl + 1; i++)
        {
            int j = i + cl - 1;
            if (str[i] == str[j] && cl == 2)
            {
                // L[i][j] = L[i + 1][j - 1];
                L[i][j] = 2;
            }
            if (str[i] == str[j])
            {
                L[i][j] = L[i + 1][j - 1] + 2;
            }
            
            else
                L[i][j] = MAX(L[i][j - 1], L[i + 1][j]);
        }
    }
    // printf("minimo de deletes");
    // printf(" %d\n", n - L[0][n-1]);
    return n - L[0][n - 1];
}
 
int minumumNumberOfDeletions(char* str)
{
    int n = sizeof(str);
 
    int len = lps(str);
    return len;
}

 
void main()
{
 
    int entradas;
    scanf("%d", &entradas);

    for (int i = 0; i < entradas; i++)
    {
        char* string;
        string = malloc(255 * sizeof(char));
        fgets(string, 255, stdin);
        // scanf("%s", string);
        // printf("%d\n", strlen(string));
        int deletions = largestPalindrome(lista[i]);
        printf("%d\n", deletions);
        // free(string);
    }   
}