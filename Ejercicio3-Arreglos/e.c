#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    double a[11] = {0};
    double b[34] = {0};

    for (int i = 0; i < 11; i++)
    {
        a[i] = rand();

        b[i] = a[i];
    }
    
    printf("Pos\ta[11]\tb[34]\n");

    for (int i = 0; i < 34; i++)
    {
        if(i >= 11)
        {
            printf("%d\t--\t%.1lf\n", i, b[i]);
            continue;
        }
        printf("%d\t%.1lf\t%.1lf\n", i, a[i], b[i]);
    }
    
    return 0;
}