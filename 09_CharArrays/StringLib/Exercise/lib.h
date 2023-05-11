#ifndef LIB_H
#define LIB_H

#include <stdint.h>

char *to_upper_case_str(char *text);

char *to_lower_case_str(char *text);

char *char_search(char *text, char character);

bool is_lower_case(char character);

bool is_upper_case(char character);

bool is_numeric(char character);

bool is_alpha(char character);

bool is_alpha_numeric(char character);

char to_upper_case(char character);

char to_lower_case(char character);





#endif
