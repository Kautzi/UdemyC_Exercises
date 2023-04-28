#include <stdbool.h>

#include "lib.h"

bool is_numeric(const char character)
{
     if(character >= '0' && character <= '9')
    {
    return true;
    }
    else
    {
    return false;
    }
}

bool is_alpha(const char character)
{


        if((character >= 'A' && character <= 'Z')||(character >= 'a' && character <= 'z' ))
        {
        return true;
        }
        else
        {
        return false;
        }


}

bool is_alpha_numeric(const char character)
{
    if(is_alpha(character)||is_numeric(character))
    {
    return true;
    }
    else
    {
    return false;
    }
}

bool is_upper_case(const char character)
{


        if((character >= 'A') && (character <= 'Z'))
        {
            return true;//is upper
        }
        else
        {
        return false;//is lower
        }

}

bool is_lower_case(const char character)
{

    if ((character >= 'a') && (character <= 'z'))
    {
        return true;
    }
    else
    {
        return false ;
    }

}


char to_upper_case( char character)
{
    if(is_lower_case(character)==true)
    {
        character -= 32;
    }
    else
    {
       return character;

    }

}

char to_lower_case( char character)
{
    if(is_upper_case(character)==true)
    {
        character += 32;
    }
    else
    {
       return character;

    }
}
