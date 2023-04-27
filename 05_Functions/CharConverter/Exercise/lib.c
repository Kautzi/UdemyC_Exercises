#include <stdbool.h>

#include "lib.h"

bool is_numeric(const char character)
{
     if(character >= 48 && character <= 57)
    {
    return true;
    }
    return false;
}

bool is_alpha(const char character)
{
    if(is_alpha_numeric(character) == 1 && is_numeric(character) == 0)
    {
        if((character >= 'A' && character <= 'Z')||(character >= 'a' && character <= 'z' ))
        {
        return true;
        }
        return false;
    }
    return false;
}

bool is_alpha_numeric(const char character)
{
    if(character <= 47 || (character >=58 && character <= 64)||(character >= 91 && character <= 96 ))//||(character >= 123 && character <= 127))
    {
    return false;
    }
    return true;
}

bool is_upper_case(const char character)
{
    if(is_alpha(character) == 1)
    {
        if((character >= 65 && character <= 90))
        {
            return true;//is upper
        }
        return false;//is lower
    }
    return false;
}

bool is_lower_case(const char character)
{

    return is_upper_case(character);
}

char to_upper_case( char character)
{
    if(is_upper_case(character)==true)
    {
        character += 32;
    }
    else
    {
        character -= 32;

    }
    return character;
}

char to_lower_case(const char character)
{
    return to_upper_case(  character);
}
