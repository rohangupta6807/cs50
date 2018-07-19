#include<stdio.h>
int main()
{
    int n, i, j, foo;
    do
    {
        //prompt for input
        printf("Height: ");
        foo = scanf("%d", &n);
    }
    while (n < 0 || n > 23 || foo != 1);
    for (i = 1; i <= n; i++)
    {
        //print spaces
        for (j = (n - i); j > 0; j--)
        {
            printf(" ");
        }
        //print hashes
        for (j = 1; j <= i; j++)
        {
            printf("#");
        }
        printf("  ");
        //print(hashes)
        for (j = 1; j <= i; j++)
        {
            printf("#");
        }
        //print new line character
        printf("\n");
    }
    return 0;
}
