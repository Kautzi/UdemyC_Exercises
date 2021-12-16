# Exercise

Implement the following functions:

```cpp
char *to_upper_case(char *text);

char *to_lower_case(char *text);

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
    char input_text[50]{};
    char compare_text1[50]{"jan"};
    char compare_text2[50]{"ja"};

    printf("Please enter any text: ";
    scanf("%d", &input_text;

    printf("to_upper_case: " << to_upper_case(input_text) << endl;
    printf("to_lower_case: " << to_lower_case(input_text) << endl;
    printf("string_length: " << string_length(input_text) << endl;
    printf("char_search: " << char_search(input_text, 'a') << endl;
    printf(boolalpha;
    printf("equal(jan, jan): " << string_equal(input_text, compare_text1) << endl;
    printf("equal(jan, ja): " << string_equal(input_text, compare_text2) << endl;

    return 0;
}
```
