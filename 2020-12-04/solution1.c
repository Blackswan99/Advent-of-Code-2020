// solution 2020/12/04
#include <stdio.h>

int main(void)
{

    FILE *fp = fopen("passports.txt", "r");
    int line_size = 128;
    char line[128] = {'\0'};

    while (1)
    {
        fgets(line, line_size, fp);
        if (feof(fp))
        {
            break;
        }

        printf("%s", line);
    }
    return 0;
}
