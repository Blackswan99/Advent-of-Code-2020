// solution 2020/12/02
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *pwdstring = malloc(32 * sizeof(char));
    int *min = malloc(1000 * sizeof(int));
    int *max = malloc(1000 * sizeof(int));
    char *searchletter = malloc(1000 * sizeof(char));
    FILE *file;
    int count = 0, anzahl = 0;

    if ((file = fopen("pwdpolicy.txt", "r")))
    {
        // read passwords from file
        while (fscanf(file, "%d-%d %c: %[^\n]", min, max, searchletter, pwdstring) != EOF)
        {
            int len = strlen(pwdstring);
            for (int i = 0; i < len; i++)
            {
                if (pwdstring[i] == *searchletter)
                    count++;
            }
            if (count >= *min && count <= *max)
            {
                anzahl++;
            }
            count = 0;
        }
        fclose(file);
    }

    printf("\n\n%d valid passwords found.", anzahl);
    return 0;
}
