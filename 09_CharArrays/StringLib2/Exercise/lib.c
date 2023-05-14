#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "lib.h"

bool string_starts_with(char *string, char *substr)
{
    if(string == NULL || substr == NULL)
    {
        return false;
    }

    char * compare = string;

    while(*substr != '\0')
    {
        if((*compare == '\0') || (*compare != *substr))
        {
            return false;
        }
        substr++;
        compare++;
    }
    return true;
}

bool string_ends_with(char *string, char *substr)
{
    if(string == NULL || substr == NULL)
    {
        return false;
    }


    size_t string_length = 0;
    size_t substring_length= 0;
    char* temp_sub = substr;
    char* temp_string = string;
    //find length of string
    while(*temp_string != '\0')
    {
        string_length ++;
        temp_string++;
    }
    //find length of substr
    while(*temp_sub != '\0')
    {
        substring_length ++;
        temp_sub++;
    }

    if(substring_length <= string_length)
    {
        for(size_t i= substring_length; i > 0;i--)
        {
            if(substr[i-1] != string[string_length-1])
            {
                return false;
            }
           string_length--;
        }
        return true;
    }
    return false;
}

char *string_find_first_not_of(char *string, char *substr)
{
    size_t count = 0;
    if(string_starts_with(string,substr))
    {
        while(*substr != '\0')
        {
            substr++;
            count++;
        }
        return &string[count-1];
    }
    return NULL;
}

char *string_n_copy(char *dest, char *src, size_t count)
{
    if(dest == 0 || src == NULL)
    {
        return NULL;
    }
    char* find_last = dest;
    //find '\0' in dest to get the adress where src starts
    while(*find_last != '\0')
    {
    find_last++;
    }
    //now replace the found '\0' through a ' '<= Space chracter
    *find_last = ' ';
    find_last++;

    // and lastly concatenate the src string with length count to the dest string
    // and append a '\0'
    for(size_t i = 0; i < count; i++)
    {
    *find_last= src[i];
    find_last++;
    }
    *find_last ='\0';

    return dest;
}
