#include "fhndlr.h"
#include <stdio.h>

char* lowercase(char* string)
{
    int i = 0;
    while (string[i] != '\0')
    {
        if (string[i] >= 'A' && string[i] <='Z')
        {
            string[i] += ('a' - 'A');
        }
        i++;
    }
    return string;
}

    
char* uppercase(char* string)
{
    int i = 0;
    while (string[i] != '\0')
    {
        if (string[i] >= 'a' && string[i] <= 'z')
        {
            string[i] -= ('a' - 'A');
        }
        i++;
    }
    return string;
}

char* capitalize(char* input) {
    if (!input) return input;
    
    char* ptr = input;
    int new_word = 1; 

    while (*ptr != '\0') 
    {
        if ((*ptr >= 'a' && *ptr <= 'z') || (*ptr >= 'A' && *ptr <= 'Z')) 
        {
            if (new_word) 
            {
            
                if (*ptr >= 'a' && *ptr <= 'z') 
                {
                    *ptr = *ptr - 32;
                }
                new_word = 0;
            } else 
            {
            
                if (*ptr >= 'A' && *ptr <= 'Z') 
                {
                    *ptr = *ptr + 32;
                }
            }
        } else 
        {
        
            new_word = 1;
        }
        ptr++;
    }
    return input;
}