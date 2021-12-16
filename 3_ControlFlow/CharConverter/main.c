#include <stdbool.h>
#include <stdio.h>

bool is_numeric(char character);

bool is_alpha(char character);

bool is_alpha_numeric(char character);

bool is_upper_case(char character);

bool is_lower_case(char character);

char to_upper_case(char character);

char to_lower_case(char character);

int main()
{
    char input_character;

    printf("Please enter any ASCII character: ");
    scanf("%c", &input_character);

    printf("is_numeric: %d\n", is_numeric(input_character));
    printf("is_alpha: %d\n", is_alpha(input_character));
    printf("is_alpha_numeric: %d\n", is_alpha_numeric(input_character));
    printf("is_upper_case: %d\n", is_upper_case(input_character));
    printf("is_lower_case: %d\n", is_lower_case(input_character));

    printf("to_upper_case: %c\n", to_upper_case(input_character));
    printf("to_lower_case: %c\n", to_lower_case(input_character));

    return 0;
}

bool is_numeric(char character)
{
    if ((character >= '0') && (character <= '9'))
    {
        return true;
    }

    return false;
}

bool is_alpha(char character)
{
    if (is_upper_case(character) || is_lower_case(character))
    {
        return true;
    }

    return false;
}

bool is_alpha_numeric(char character)
{
    return (is_numeric(character) || is_alpha(character));
}

bool is_upper_case(char character)
{
    if ((character >= 'A') && (character <= 'Z'))
    {
        return true;
    }

    return false;
}

bool is_lower_case(char character)
{
    if ((character >= 'a') && (character <= 'z'))
    {
        return true;
    }

    return false;
}

char to_upper_case(char character)
{
    if (is_lower_case(character))
    {
        return character - 32;
    }

    return character;
}

char to_lower_case(char character)
{
    if (is_upper_case(character))
    {
        return character + 32;
    }

    return character;
}
