// solution 2020/12/01
#include <stdio.h>

#define ARRAYSIZE 200

int main(void)
{
    int numbers[ARRAYSIZE];
    int i = 0, sum = 0, counter = 1, allcounter = 0;
    FILE *file;

    if ((file = fopen("numbers.txt", "r")))
    {
        while (fscanf(file, "%d", &numbers[i]) != EOF)
        {
            i++;
        }
        fclose(file);

        while (counter < ARRAYSIZE)
        {
            numbers[i] = '\0';
            for (i = counter - 1; numbers[i] != '\0'; i++)
            {
                if (i + 1 < ARRAYSIZE)
                {
                    sum = numbers[i] + numbers[i + 1];
                    if (sum == 2020)
                    {
                        printf("num(i): %d, num(+1): %d ==> Sum: %d\n", numbers[i], numbers[i + 1], sum);
                    }
                }
                allcounter++;
            }
            counter++;
        }
        printf("allcounter: %d\n", allcounter);
    }
    return 0;
}
