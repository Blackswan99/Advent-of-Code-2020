// solution 2020/12/01
#include <stdio.h>

#define ARRAYSIZE 200

int main(void)
{
    int numbers[ARRAYSIZE];
    int i = 0, sum = 0, counter = 0;
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
                if (sum == 2020)
                {
                    printf("Solution found: num1 = %d, num2 = %d, num1*num2 = %d",
                           numbers[counter],
                           numbers[i],
                           numbers[counter] * numbers[i]);
                    return 0;
                }
            }
            counter++;
        }
    }
    return 0;
}
