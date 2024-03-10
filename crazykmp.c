#include <stdio.h>

#include <string.h>

#include <ctype.h>

    int main()

    {

        char string[88], matchcase[20], c;

        int x = 0, j = 0, index;

        /*Scanning string*/

        printf("Enter string: ");

        do

        {

            fflush(stdin);

            c = getchar();

            string[x++] = tolower(c);

        } while (c != '\n');

        string[x - 1] = '\0';

        /*Scanning substring*/
\
        printf("Enter substring: ");

        x = 0;

        do

        {

            fflush(stdin);

            c = getchar();

            matchcase[x++] = tolower(c);

        } while (c != '\n');

        matchcase[x - 1] = '\0';

        for (x = 0; x < strlen(string) - strlen(matchcase) + 1; x++)

        {

            index = x;

            if (string[x] == matchcase[j])

            {

                do

                {

                    x++;

                    j++;

                } while(j != strlen(matchcase) && string[x] == matchcase[j]);

                if (j == strlen(matchcase))

                {

                    printf("Match found from position %d to %d.\n", index + 1, x);

                    return 0;

                }

                else

                {

                    x = index + 1;

                    j = 0;

                }

            }

        }

        printf("No substring match found in the string.\n");

        return 0;

    }