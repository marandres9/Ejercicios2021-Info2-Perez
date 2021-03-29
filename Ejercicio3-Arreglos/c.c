#include <stdio.h>

int main(int argc, char const *argv[])
{
    int g[5];

    for (int i = 0; i < 5; i++)
    {
        g[i] = 8;
    }
    printf("A continuacion se muestran los valores del arreglo 'g[5]':\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d \t", g[i]);
    }
    
    return 0;
}