#include<stdio.h>
int main()
{
    long long int n, foo, sum = 0;
    do
    {
        //get input
        printf("Number: ");
        foo = scanf("%lld", &n);
    }
    while (n < 0 || foo != 1);
    long long int m = 0;
    int length = 0;
    //reverse a number
    while (n != 0)
    {
        m = (m + n % 10) * 10;
        n = n / 10;
        length += 1;
    }
    m = m / 10;
    long long int z = m;
    //store first two digit of number
    int firstTwoDigit = 0;
    int firstDigit = 0;
    firstTwoDigit = (firstTwoDigit + z % 10) * 10;
    firstDigit = z % 10;
    z = z / 10;
    firstTwoDigit = (firstTwoDigit + z % 10);
    int x = 0;
    //check length of number is even or odd
    if (length & 1)
    {
        x = 1;
    }
    //checksum
    while (m != 0)
    {
        if ((x & 1) == 0)
        {
            //add the single digits of number
            int a = ((m % 10) * 2);
            while (a)
            {
                sum += (a % 10);
                a /= 10;
            }
        }
        else
        {
            sum += (m % 10);
        }
        x += 1;
        m /= 10;
    }
    //check type of card
    if (length == 15 && (firstTwoDigit == 34 || firstTwoDigit == 37) && sum % 10 == 0)
    {
        printf("AMEX\n");
    }
    else if (length == 16 && (firstTwoDigit == 51 || firstTwoDigit == 52 || firstTwoDigit == 53 || firstTwoDigit == 54
                              || firstTwoDigit == 55) && sum % 10 == 0)
    {
        printf("MASTERCARD\n");
    }
    else if (firstDigit == 4 && sum % 10 == 0 && length > 12)
    {
        printf("VISA\n");
    }
    // no card exist
    else
    {
        printf("INVALID\n");
    }
}