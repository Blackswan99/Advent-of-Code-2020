// solution 2020/12/02
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *pwdstring = malloc(32 * sizeof(char));
    int *min = malloc(1000 * sizeof(int));
    int *max = malloc(1000 * sizeof(int));
    char *searchletter = malloc(1000 * sizeof(char));
    FILE *file;
    int rowcount = 0, anzahl = 0;

    if ((file = fopen("pwdpolicy.txt", "r")))
    {
        // read passwords from file
        while (fscanf(file, "%d-%d %c: %[^\n]", min, max, searchletter, pwdstring) != EOF)
        {
            if (((pwdstring[*min - 1] == *searchletter) && (pwdstring[*max - 1] != *searchletter)) ||
                ((pwdstring[*min - 1] != *searchletter) && (pwdstring[*max - 1] == *searchletter)))
            {
                anzahl++;
            }
            rowcount++;
        }
        fclose(file);
    }

    printf("\n\n%d passwords checked, %d valid passwords found.", rowcount, anzahl);
    return 0;
}
