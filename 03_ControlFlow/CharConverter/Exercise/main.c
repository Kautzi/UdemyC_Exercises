#include <stdbool.h>
#include <stdio.h>
#include <stdint.h> // for uint32_t ...


//### Function Declaration ###
bool is_numeric(char character); // returns 1 if its numerical checks if its a numerber = 1,2,3,4
bool is_alpha(char character);  // checks if its an alphabetikal aA,bB,cC
bool is_alpha_num(char character); // returns 1 if its alphanumerical  returns 0 if its a number checks if its 1,2,3,4,5 or aA,bB,cC
bool is_upper_lower(char haracter); // returns 1 if upper case 0 if lower,check if its a or A, b or B
char converte_up_low(char character);
//### END Declaration ###

//### MAIN ###
int main()
{
    char character;

    printf("please insert one character:\n");
    scanf("%c",&character);

    if(is_alpha_num(character) == true)
    {
        printf("Its alpha numerical "" %c ""\n",character);
        if (is_alpha(character) == false)
    {
        printf("Its alpha "" %c ""\n",character);
        if(is_upper_lower(character) == true)
        {
            printf("And its upper case!\n");
            printf("And now its lower case ""%c""\n",converte_up_low(character));
        }
        else
        {
            printf("And its lower case!\n");
            printf("And now its upper case ""%c""\n",converte_up_low(character));
        }

    }
    else if(is_numeric(character) == true)
    {
        printf("Its numerical ""%c""\n",character);
    }
    }
    else
    {
        printf("Its NOT alpha numerical!!\n");
    }
    return 0;
}
//### END MAIN ###


//### Function Definition ###

bool is_numeric(char character)
{
    if(character >= 48 && character <= 57)
    {
    return true;
    }
    return false;
}

bool is_alpha(char character)
{
    if(is_alpha_num(character) == 1 && is_numeric(character) == 0)
    {
        if((character >= 65 && character <= 90)||(character >= 97 && character <= 122 ))
        {
        return true;
        }
        return false;
    }
    return true;
}

bool is_alpha_num(char character) //checks if its a printable character and alpha numerical
{
    if(character <= 47 || (character >=58 && character <= 64)||(character >= 91 && character <= 96 ))//||(character >= 123 && character <= 127))
    {
    return false;
    }
    return true;

}

bool is_upper_lower(char character)
{
    if(is_alpha(character) == 1)
    {
        if((character >= 65 && character <= 90))
        {
            return true;//is upper
        }
        return false;//is lower
    }
    return 2;
}

char converte_up_low(char character)
{
    if(is_upper_lower(character)==1)
    {
        character += 32;
    }
    else
    {
        character -= 32;

    }
    return character;
}
