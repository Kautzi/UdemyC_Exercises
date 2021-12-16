# Exercise

Implement the following functions:

```cpp
char *to_upper_case_str(char *text);

char *to_lower_case_str(char *text);

size_t string_length(char *text);

char *char_search(char *text, char character);

bool string_equal(char *string1, char *string2);
```

- To Upper Case
  - Upper case all characters of the string
  - The upper case result is stored/overwritten in the input array
- To Lower Case
  - Lower case all characters of the string
  - The lower case result is stored/overwritten in the input array
- String Length
  - Return the length of the string
- Char Search
  - Return the pointer to the position where the **character** is found in the string
  - If not found, return **NULL**
- String Equal
  - Return true if both strings have only the same characters

Note: Make sure that the input pointer is valid.

## Main Function

```cpp
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
```
