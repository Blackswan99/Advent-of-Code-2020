// solution 2020/12/01
#include <stdio.h>

#define ARRAYSIZE 200

int main(void)
{
    int numbers[ARRAYSIZE];
    int i = 0, j = 0, sum = 0, counter = 0;
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
            for (i = counter + 1; numbers[i] != '\0'; i++)
            {
                sum = numbers[counter] + numbers[i];
                for (j = counter + 2; numbers[j] != '\0'; j++)
                {
                    sum = numbers[counter] + numbers[i] + numbers[j];
                    if (sum == 2020)
                    {
                        printf("Solution found: num1 = %d, num2 = %d, num3 = %d, num1*num2*num3 = %d",
                               numbers[counter],
                               numbers[i],
                               numbers[j],
                               numbers[counter] * numbers[i] * numbers[j]);
                        return 0;
                    }
                }
            }
            counter++;
        }
    }
    return 0;
}
