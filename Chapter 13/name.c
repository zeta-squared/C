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
    int i, j = 0;
    char initial[] = ",  .", new_name[51];

    initial[2] = toupper(*name);
    for (i = 0; name[i] != ' '; i++)
        ;

    while (name[++i])
        new_name[j++] = name[i];

    new_name[j] = name[i];
    new_name[0] = toupper(new_name[0]);
    strcpy(name, new_name);
    strcat(name, initial);
    
    return;
}
