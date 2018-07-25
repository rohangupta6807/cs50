#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc, char *args[])
{
    //check the number of aruments;
    if (argc != 2)
    {
        printf("command line arguments not match");
        return 1;
    }
    //convert string to integer
    int k = atoi(args[1]);
    //dynamic alloca memory to character pointer
    char *s = (char *)malloc(1000 * sizeof(char));
    printf("plaintext:  ");
    //geting string as a input
    scanf("%[^\n]s", s);
    int i, len;
    for (i = 0, len = strlen(s); i < len; i++)
    {
        //check whether the character is alphabet or not
        if (isalpha(s[i]))
        {
            //check whethter the character is lowercase or uppercase
            if (islower(s[i]))
            {
                s[i] = (char)(((int)s[i] + k - 97) % 26 + 97);
            }
            else
            {
                s[i] = (char)(((int)s[i] + k - 65) % 26 + 65);
            }
        }
    }
    //print the cipher text
    printf("ciphertext: %s\n", s);
    return 0;
}