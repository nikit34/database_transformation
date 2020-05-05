#pragma pack()
#ifndef SORT_SEARCH_H
#define SORT_SEARCH_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef struct line_table{
    int line_key;
    char *line_data;
} line_table;

// sort_search.c
void sort_Shell_empitical_sequence(char *file_name); // сортировка по индексу
void search_binary(char *file_name); // двоичный поиск по индексу

// padding_table.c
void shifting(char *file_name); // перемешать
void castling(char *file_name); // обратить

// controller.c
struct line_table * read_struct(char *file_name);
void write_struct(char *file_name, struct line_table * lt);
void read_table(char *file_name);
void write_table(char *file_name);
void info();

#endif