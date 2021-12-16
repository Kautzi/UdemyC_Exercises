# Exercise

In this exercise, you have to use the datatype **char** to convert/check certain char values.

Implement the following checks:

- is numeric character
- is alpha character
- is alpha_numeric character
- is upper case character
- is lower case character

Meaning of the function names:

- Numeric: 0-9 (digits)
- Alpha: a-z, A-Z (alphabeth characters)
- Upper Case: A-Z
- Lower Case: a-z

Note:

The shift from **Upper Case** to **Lower Case** is 32 in the ASCII table.  

E.g. 'A' -> 'a' by subtracting 32
E.g. 'a' -> 'A' by adding 32

You do not have to look up the ASCII table for this exercise, but you can do so.

Afterward, implement the following conversion:

- to upper case character
- to lower case character

## Main Function

```cpp
int main()
{
    char character;

    printf("Please enter any ASCII character: ");
    scanf("%c", &character);

    // is_numeric

    // is_upper_case

    // is_lower_case

    // is_alpha

    // is_alpha_numeric

    // to_upper_case

    // to_lower_case

    return 0;
}
```
