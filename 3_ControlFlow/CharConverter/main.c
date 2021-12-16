#include <stdbool.h>
#include <stdio.h>

int main()
{
    char character;

    printf("Please enter any ASCII character: ");
    scanf("%c", &character);

    // is_numeric
    bool is_numeric = false;

    if ((character >= '0') && (character <= '9'))
    {
        is_numeric = true;
    }

    printf("is_numeric: %d\n", is_numeric);

    // is_upper_case
    bool is_upper_case = false;
    if ((character >= 'A') && (character <= 'Z'))
    {
        is_upper_case = true;
    }
    printf("is_upper_case: %d\n", is_upper_case);

    // is_lower_case
    bool is_lower_case = false;
    if ((character >= 'a') && (character <= 'z'))
    {
        is_lower_case = true;
    }
    printf("is_lower_case: %d\n", is_lower_case);

    // is_alpha
    bool is_alpha = false;

    if (is_upper_case || is_lower_case)
    {
        is_alpha = true;
    }

    printf("is_alpha: %d\n", is_alpha);

    // is_alpha_numeric
    bool is_alpha_numeric = (is_numeric || is_alpha);
    printf("is_alpha_numeric: %d\n", is_alpha_numeric);

    // to_upper_case
    char result1 = character;
    if (is_lower_case)
    {
        result1 = character - 32;
    }
    printf("to_upper_case: %c\n", result1);

    // to_lower_case
    char result2 = character;
    if (is_upper_case)
    {
        result2 = character + 32;
    }
    printf("to_lower_case: %c\n", result2);

    return 0;
}
