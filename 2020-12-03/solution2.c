// solution 2020/12/03

#include <stdio.h>
#include <string.h>

int getSlopes(int right, int down)
{
    int line_size = 33;
    unsigned int rowlength = 31;
    char line[33] = {'\0'};
    unsigned int iterator = 0;
    unsigned int row = 0;
    int amount_of_trees = 0;
    FILE *fp = fopen("forest.txt", "r");

    while (1)
    {
        fgets(line, line_size, fp);
        if (feof(fp))
        {
            break;
        }

        if (row == 0)
        {
            if (line[0] == '#')
            {
                amount_of_trees++;
            }
        }
        else
        {
            if (line[iterator] == '#')
            {
                amount_of_trees++;
            }
        }

        row += down;
        iterator += right;

        if (iterator >= rowlength)
        {
            iterator -= rowlength;
        }
        if (down > 1)
        {
            for (int y = 0; y < down - 1; y++)
            {
                fgets(line, line_size, fp);
            }
        }
    }
    rewind(fp);
    fclose(fp);

    return amount_of_trees;
}

int main(void)
{
    long solution = 1;

    solution *= getSlopes(1, 1);
    solution *= getSlopes(3, 1);
    solution *= getSlopes(5, 1);
    solution *= getSlopes(7, 1);
    solution *= getSlopes(1, 2);
    printf("Solution: %ld\n", solution);

    return 0;
}
