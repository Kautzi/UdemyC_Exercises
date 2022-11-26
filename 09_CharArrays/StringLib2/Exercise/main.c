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
    printf("string_ends_with: %d\n", string_ends_with(text, "and"));

    printf("string_find_first_not_of: %s\n",
           string_find_first_not_of(text, "jan "));
    printf("string_find_first_not_of: %s\n",
           string_find_first_not_of(text, "an "));

    return 0;
}
