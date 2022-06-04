#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "line.h"

#define DEBUG
#define MAX_LINE_LEN 60

struct word {
    char *str;
    struct word *next;
};

struct word *line = NULL;
int line_len = 0;
int num_words = 0;
bool at_start = true;

void clear_line(void)
{
    line = NULL;
    line_len = 0;
    num_words = 0;
}

void add_word(char *word)
{
    struct word *cur, *prev, *new_node;

    for (cur = line, prev = NULL;
            cur != NULL;
            prev = cur, cur = cur->next)
        ;

    new_node = malloc(sizeof(*new_node));
    if (new_node == NULL)
        printf("Error: Memory heap exhausted; can no longer store words.\n");
    else {
        new_node->str = word;
        new_node->next = NULL;
    }

    if (prev == NULL)
        line = new_node;
    else
        prev->next = new_node;

#ifdef DEBUG
#endif
    line_len += strlen(word);
    num_words++;
}

int space_remaining(void)
{
    return MAX_LINE_LEN - line_len;
}

void write_line(void)
{
    struct word *node;
    int extra_spaces, spaces_to_insert, i, j;

    extra_spaces = MAX_LINE_LEN - line_len;
    for (node = line; node != NULL; node = node->next) {
        printf("%s", node->str);
        spaces_to_insert = extra_spaces / (num_words - 1);
        if (at_start && extra_spaces > 0) {
            spaces_to_insert++;
            at_start = !at_start;
        }

        for (j = 1; j <= spaces_to_insert + 1; j++)
            putchar(' ');
        extra_spaces -= spaces_to_insert;
    }
    putchar('\n');
}

void flush_line(void)
{
}
