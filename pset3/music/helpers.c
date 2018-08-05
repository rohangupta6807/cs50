// Helper functions for music

#include <cs50.h>
#include<stdio.h>
#include "helpers.h"
#include<string.h>
#include<math.h>

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    // TODO
    int len = strlen(fraction);
    int a = fraction[len - 3] - '0';
    int b = fraction[len - 1] - '0';
    return a * (8 / b);
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    // TODO
    float freq = 261.63;
    char a = note[0];
    char c[] = {'C', '1', 'D', '1', 'E', 'F', '1', 'G', '1', 'A', '1', 'B', '\0'};
    int i = 0;
    while (1)
    {
        if (a == c[i])
        {
            break;
        }
        i += 1;
    }
    if (note[1] == '#')
    {
        i += 1;
        freq /= pow(2, 4 - (note[2] - '0'));
    }
    else if (note[1] == 'b')
    {
        i -= 1;
        freq /= pow(2, 4 - (note[2] - '0'));
    }
    else
    {
        freq /= pow(2, 4 - (note[1] - '0'));
    }
    float z = (float)i / 12;
    freq *= (float)pow(2, z);
    return round(freq);
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    // TODO
    if (strlen(s) == 0)
    {
        return true;
    }
    return false;
}
