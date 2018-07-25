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
    char *k = args[1];
    int keyLen = strlen(args[1]);
    int x;
    //check all the character of key is aplhabet or not
    for (x = 0; x < keyLen; x++)
    {
        if (!isalpha(k[x]))
        {
            return 1;
        }
    }

    //dynamic alloca memory to character pointer
    char *s = (char *)malloc(1000 * sizeof(char));
    printf("plaintext:  ");
    //geting string as a input
    scanf("%[^\n]s", s);
    int i, len, j = 0;
    for (i = 0, len = strlen(s); i < len; i++)
    {
        //check whether the character is alphabet or not
        if (isalpha(s[i]))
        {
            //check the key character is lowecase or uppercase
            int a = (int)(k[(j % keyLen)]);
            if (islower(k[j % keyLen]))
            {
                a -= 97;
            }
            else
            {
                a -= 65;
            }
            //check whethter the character is lowercase or uppercase
            if (islower(s[i]))
            {
                s[i] = (char)(((int)s[i] + a - 97) % 26 + 97);
            }
            else
            {
                s[i] = (char)(((int)s[i] + a - 65) % 26 + 65);
            }
            j += 1;
        }
    }
    //print the cipher text
    printf("ciphertext: %s\n", s);
    return 0;
}