#include <stdbool.h>
#include <stdio.h>
#include <stdint.h> // for uint32_t ...


//### Function Declaration ###
uint32_t is_numeric(char chracter); // checks if its a numerber = 1,2,3,4
uint32_t is_alpha(char character);  // checks if its an alphabetikal aA,bB,cC
uint32_t is_alpha_num(char character); // checks if its 1,2,3,4,5 or aA,bB,cC
uint32_t is_upper_lower(character); // check if its a or A, b or B
//### END Declaration ###

//### MAIN ###
int main()
{
    char character;

    printf("please insert one character:\n");
    scanf("%c",&character);

    if(is_alpha_num(character) == 1)
    {
        printf("Its alpha numerical\n");

    }
    else
    {
        printf("NOT alpha numerical\n");
    }
    return 0;
}
//### END MAIN ###


//### Function Definition ###

uint32_t is_alpha_num(char character) //checks if its a printable character and alpha numerical
{
    if(character <= 47 || (character >=58 && character <= 64))
    {
    return 0;
    }
    return 1;

}
