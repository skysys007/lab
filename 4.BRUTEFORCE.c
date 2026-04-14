#include <stdio.h>
int comparisons = 0;

int length(char str[]){
    int i = 0;
    while(str[i] != '\0'){
        i++;
    }
    return i;
}

int bruteForce(char text[], char pattern[]){
    int n = length(text);
    int m = length(pattern);
    int i = 0;
    while (i<=n-m)
    {
        int j = 0;
        while (j<m)
        {
            comparisons++;
            if (text[i+j] != pattern[j])
            {
                break;
            }
            j++;
        }
        if (j==m)
        {
            printf("Pattern found at index : %d\n", i);
            return i;
        }
        i++;
    }
    return -1;
}

int main() {
    char text[] = "HELLO HELLNO HELLOWWWWW";
    char pattern[] = "HELLNO";
    bruteForce(text, pattern);
    printf("Number of comparisons: %d\n", comparisons);
    return 0;
}