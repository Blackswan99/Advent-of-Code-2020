// solution 2020/12/02
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *pwdstring = malloc(32 * sizeof(char));
    int *min = malloc(1000 * sizeof(int));
    int *max = malloc(1000 * sizeof(int));
    char *searchletter = malloc(1000 * sizeof(char));
    bool firsttrue = false, secondtrue = false;
    FILE *file;
    int rowcount = 0, anzahl = 0;

    if ((file = fopen("pwdpolicy.txt", "r")))
    {
        // read passwords from file
        while (fscanf(file, "%d-%d %c: %[^\n]", min, max, searchletter, pwdstring) != EOF)
        {
            //int len = strlen(pwdstring);
            //for (int i = 0; i < len; i++)
            //{

            //if ((i + 1) == *min)
            //{
            //printf("Position 1: %d ", i + 1);
            if (pwdstring[*min + 1] == *searchletter)
            {
                printf("%d: true - ", rowcount + 1);
                firsttrue = true;
            }
            else
            {
                printf("%d: false - ", rowcount + 1);
                firsttrue = false;
            }
            //}
            // ((i + 1) == *max)
            //{
            //printf("Position 2: %d\n", i + 1);
            if (pwdstring[*max + 1] == *searchletter)
            {
                printf("true\n");
                //printf("Position 2: true\n");
                secondtrue = true;
            }
            else
            {
                printf("false\n");
                secondtrue = false;
            }
            //}

            if ((firsttrue && !secondtrue) || (!firsttrue && secondtrue))
            {
                printf(" Row %d = true\n", rowcount + 1);
                anzahl++;
            }
            //}
            //count = 0;
            firsttrue = false;
            secondtrue = false;
            rowcount++;
        }
        fclose(file);
    }

    printf("\n\n%d passwords checked, %d valid passwords found.", rowcount, anzahl);
    return 0;
}
