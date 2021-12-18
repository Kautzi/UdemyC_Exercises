#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool string_starts_with(char *string, char *substr);

bool string_ends_with(char *string, char *substr);

char *string_find_first_not_of(char *string, char *substr);

char *string_n_copy(char *dest, char *src, size_t count);

int main()
{
    char text[50] = "jan schaffranek";

    printf("string_starts_with: %d\n", string_starts_with(text, "jan"));
    printf("string_ends_with: %d\n", string_ends_with(text, "anek"));

    printf("string_starts_with: %d\n", string_starts_with(text, "an"));
    printf("string_ends_with: %d\n", string_ends_with(text, "ane"));

    printf("string_find_first_not_of: %s\n", string_find_first_not_of(text, "jan "));
    printf("string_find_first_not_of: %s\n", string_find_first_not_of(text, "an "));

    return 0;
}

bool string_starts_with(char *string, char *substr)
{
    if (string == NULL || substr == NULL)
    {
        return false;
    }

    while (*substr != '\0')
    {
        if ((*string == '\0') || (*string != *substr))
        {
            return false;
        }

        string++;
        substr++;
    }

    return true;
}


bool string_ends_with(char *string, char *substr)
{
    if (string == NULL || substr == NULL)
    {
        return false;
    }

    size_t string_length = strlen(string);
    size_t substr_length = strlen(substr);

    for (size_t i = string_length - substr_length; i < string_length; i++)
    {
        size_t offset_idx = i - (string_length - substr_length);

        if (string[i] != substr[offset_idx])
        {
            return false;
        }
    }

    return true;
}

char *string_find_first_not_of(char *string, char *substr)
{
    if (string == NULL || substr == NULL)
    {
        return NULL;
    }

    char *result = NULL;

    while (*string != '\0')
    {
        if (*string != *substr)
        {
            result = string;
            break;
        }

        string++;
        substr++;
    }

    return result;
}

char *string_n_copy(char *dest, char *src, size_t count)
{
    if (dest == NULL || src == NULL || count == 0)
    {
        return NULL;
    }

    char *result = NULL;

    while (*src != '\0')
    {
        *dest = *src;
    }

    return result;
}
