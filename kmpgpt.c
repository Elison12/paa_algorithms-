#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *compute_prefix(char *pattern, int len) {
    int *prefix = malloc(len * sizeof(int));
    prefix[0] = 0;
    int j = 0;
    for (int i = 1; i < len; i++) {
        while (j > 0 && pattern[j] != pattern[i]) {
            j = prefix[j-1];
        }
        if (pattern[j] == pattern[i]) {
            j++;
        }
        prefix[i] = j;
    }
    return prefix;
}

int kmp(char *text, char *pattern) {
    int text_len = strlen(text);
    int pattern_len = strlen(pattern);
    int *prefix = compute_prefix(pattern, pattern_len);
    int j = 0;
    for (int i = 0; i < text_len; i++) {
        while (j > 0 && pattern[j] != text[i]) {
            j = prefix[j-1];
        }
        if (pattern[j] == text[i]) {
            j++;
        }
        if (j == pattern_len) {
            free(prefix);
            return i - j + 1;
            // or you can add the index to an array of matches
        }
    }
    free(prefix);
    return -1;
}

int main() {
    char *txt;
	char *pat;

	txt = malloc(2000000 * sizeof(char)); 
	pat = malloc(2000000 * sizeof(char)); 

	fgets(txt, 2000000, stdin);
	fgets(pat, 2000000, stdin);
    
    // char text[] = "abcabcabc";
    // char pattern[] = "abc";
    int match = kmp(txt, pat);
    if (match == -1) {
        printf("Pattern not found\n");
    } else {
        printf("Pattern found at index %d\n", match);
    }
    return 0;
}
