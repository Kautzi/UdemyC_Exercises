#include <stdbool.h>
#include <stdio.h>
#include <stdint.h> // for uint32_t ...


//### Function Declaration ###
uint32_t is_numeric(char character); // returns 1 if its numerical checks if its a numerber = 1,2,3,4
uint32_t is_alpha(char character);  // checks if its an alphabetikal aA,bB,cC
uint32_t is_alpha_num(char character); // returns 1 if its alphanumerical  returns 0 if its a number checks if its 1,2,3,4,5 or aA,bB,cC
uint32_t is_upper_lower(char haracter); // returns 1 if upper case 0 if lower,check if its a or A, b or B
char converte_up_low(char character);
//### END Declaration ###

//### MAIN ###
int main()
{
    char character;

    printf("please insert one character:\n");
    scanf("%c",&character);

    if(is_alpha_num(character) == 1)
    {
        printf("Its alpha numerical "" %c ""\n",character);
        if (is_alpha(character) == 1)
    {
        printf("Its alpha "" %c ""\n",character);
        if(is_upper_lower(character) == 1)
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
    else if(is_numeric(character) == 1)
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

uint32_t is_numeric(char character)
{
    if(character >= 48 && character <= 57)
    {
    return 1;
    }
    return 0;
}

uint32_t is_alpha(char character)
{
    if(is_alpha_num(character) == 1 && is_numeric(character) == 0)
    {
        if((character >= 65 && character <= 90)||(character >= 97 && character <= 122 ))
        {
        return 1;
        }
        return 0;
    }
    return 0;
}

uint32_t is_alpha_num(char character) //checks if its a printable character and alpha numerical
{
    if(character <= 47 || (character >=58 && character <= 64)||(character >= 91 && character <= 96 ))//||(character >= 123 && character <= 127))
    {
    return 0;
    }
    return 1;

}

uint32_t is_upper_lower(char character)
{
    if(is_alpha(character) == 1)
    {
        if((character >= 65 && character <= 90))
        {
            return 1;//is upper
        }
        return 0;//is lower
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
