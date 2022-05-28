/* Checks planet names */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_PLANETS 9

int string_equal(const char *str1, const char *str2);

int main(int argc, char *argv[])
{
    char *planets[] = {"Mercury", "Venus", "Earth", "Mars", "Jupiter",
                       "Saturn", "Uranus", "Neptune", "Pluto"};
    int i, j;

    for (i = 1; i < argc; i++) {
        for (j = 0; j < NUM_PLANETS; j++)
            if (string_equal(planets[j], argv[i])) {
                printf("%s is planet %d\n", argv[i], j + 1);
                break;
            }
        if (j == NUM_PLANETS)
            printf("%s is not a planet\n", argv[i]);
    }

    return 0;
}

int string_equal(const char *str1, const char *str2)
{
    int i;

    for (i = 0; tolower(str1[i]) == tolower(str2[i]); i++)
        if (str1[i])
            return 1;

    return 0;
}
