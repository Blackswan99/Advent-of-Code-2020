// solution 2020/12/03
#include <stdio.h>
#include <string.h>

int main(void)
{
    int line_size = 33;
    char line[33] = {'\0'};

    FILE *fp = fopen("forest.txt", "r");
    unsigned int iterator = 0;
    unsigned int row = 1;
    int amount_of_trees = 0;

    while (1)
    {
        fgets(line, line_size, fp);
        if (feof(fp))
        {
            break;
        }

        if (row == 1)
        {
            if (line[1] == '#')
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

        row += 1;
        iterator += 3;
        if (iterator >= 31)
        {
            iterator -= 31;
        }
    }

    fclose(fp);

    printf("Read %d lines, found %d trees", row, amount_of_trees);

    return 0;
}
