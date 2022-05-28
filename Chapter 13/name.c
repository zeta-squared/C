#include <stdio.h>
#include <ctype.h>
#include <string.h>

void reverse_name(char *name);

int main(void)
{
    char name[51], surname[26];

	printf("Enter a first and last name: ");
    scanf("%s%s", name, surname);
    strcat(name, " ");
    strcat(name, surname);
    reverse_name(name);
    printf("%s\n", name);

	return 0;
}

void reverse_name(char *name)
{
    int i = 0;
    char initial[] = ",  .", new_name[51];

    initial[2] = toupper(*name);
    for (; *name != ' '; name++)
        ;

    name++;
    while (*name)
        new_name[i++] = *name++;

    new_name[i] = *name;
    printf("%s\n", new_name);
    strcpy(name, new_name);
    
    return;
}
