#include <stdbool.h>
#include <stdio.h>

/* CHARS */

bool is_numeric(char character);

bool is_alpha(char character);

bool is_alpha_numeric(char character);

bool is_upper_case(char character);

bool is_lower_case(char character);

char to_upper_case(char character);

char to_lower_case(char character);

/* CHAR ARRAYS */

char *to_upper_case_str(char *text);

char *to_lower_case_str(char *text);

size_t string_length(char *text);

char *char_search(char *text, char character);

bool string_equal(char *string1, char *string2);

int main()
{
    char input_text[50] = {'\0'};
    char compare_text1[50] = {"jan"};
    char compare_text2[50] = {"ja"};

    printf("Please enter any text: ");
    scanf("%s", input_text);

    printf("to_upper_case: %s\n", to_upper_case_str(input_text));
    printf("to_lower_case: %s\n", to_lower_case_str(input_text));
    printf("string_length: %lu\n", string_length(input_text));
    printf("char_search: %s\n", char_search(input_text, 'a'));

    printf("equal(jan, jan): %u\n", string_equal(input_text, compare_text1));
    printf("equal(jan, ja): %u\n", string_equal(input_text, compare_text2));

    return 0;
}

/* CHARS */

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
    return is_numeric(character) || is_alpha(character);
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

/* CHAR ARRAYS */

char *to_upper_case_str(char *text)
{
    if (text == NULL)
    {
        return NULL;
    }

    char *current_character = text;

    while (*current_character != '\0')
    {
        *current_character = to_upper_case(*current_character);

        current_character++;
    }

    return text;
}

char *to_lower_case_str(char *text)
{
    if (text == NULL)
    {
        return NULL;
    }

    char *current_character = text;

    while (*current_character != '\0')
    {
        *current_character = to_lower_case(*current_character);

        current_character++;
    }

    return text;
}

size_t string_length(char *text)
{
    if (text == NULL)
    {
        return 0;
    }

    size_t length = 0;

    while (*text != '\0')
    {
        length++;
        text++;
    }

    return length;
}

char *char_search(char *text, char character)
{
    if (text == NULL)
    {
        return NULL;
    }

    while ((*text != character) && (*text != '\0'))
    {
        text++;
    }

    return text;
}

bool string_equal(char *string1, char *string2)
{
    if (string1 == NULL || string2 == NULL)
    {
        return false;
    }

    size_t length1 = string_length(string1);
    size_t length2 = string_length(string2);

    if (length1 != length2)
    {
        return false;
    }

    while (*string1 != '\0')
    {
        if (*string1 != *string2)
        {
            return false;
        }

        string1++;
        string2++;
    }

    return true;
}
