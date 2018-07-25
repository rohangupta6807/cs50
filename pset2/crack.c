#include <crypt.h>
#include <stdio.h>
#include <string.h>
#include<vector.h>

vector<vector<char>>v;
void combinationUtil(char arr[], int data[], int start, int end, int index, int r);
void printCombination(char arr[], int n, int r)
{
    int data[r];
    combinationUtil(arr, data, 0, n-1, 0, r);
}

void combinationUtil(char arr[], int data[], int start, int end, int index, int r)
{
    if (index == r)
    {
        int j;
        vector<char>c;
        for (j=0; j<r; j++)
            c.push_back(data[j]);
        v.push_back(c);
        return;
    }
    int i;
    for (i=start; i<=end && end-i+1 >= r-index; i++)
    {
        data[index] = arr[i];
        combinationUtil(arr, data, i+1, end, index+1, r);
    }
}
 
int main(int argc, char * argv[])
{
    if(argc!=2)
    {
        printf("ERROR");
        return 1;
    }
    char salt[3];
    salt[0] = argv[1][0];
    salt[1] = argv[1][1];
    salt[2] = '\0';
    
    char keys[53];keys[53]='\0';
    long long int j,c=0;
    unsigned long long i;
    for(i=65;i<91;i++)
    {
        keys[c]=(char)i;
        c+=1;
    }
    for( i=97;i<97+26;i++)
    {
        keys[c]=(char)i;
        c+=1;
    }
    
    printCombination(keys,52,5);
    
    if(strcmp(crypt("fdwa",salt),argv[1]))
    {
        printf("yes");
    }
    return 0;
}