#include"sort_search.h"

void shifting(char *file_name) {
    struct line_table *lt = read_struct(file_name);
    struct line_table *tmp_lt = (line_table*)malloc(sizeof(line_table));
    int length_table = 0;
    while(lt[length_table].line_key != 0) {
        length_table++;
    }
    int rand_count_iterations = length_table + rand() % (length_table * (1 + rand() % (length_table)));
    int rand_i, rand_j;
    while (rand_count_iterations != 0) {
        rand_i = rand() % length_table;
        do {
            rand_j = rand() % length_table;
        } while(rand_i == rand_j);
        *tmp_lt = lt[rand_i];
        lt[rand_i] = lt[rand_j];
        lt[rand_j] = *tmp_lt;
        rand_count_iterations--;
    }
    write_struct(file_name, lt);
    printf("Shifting done\n");
}

void castling(char *file_name) {
    struct line_table *lt = read_struct(file_name);
    struct line_table *tmp_lt = (line_table*)malloc(sizeof(line_table));
    int length_table = 0;
    while(lt[length_table].line_key != 0) {
        length_table++;
    }
    for(int i = 0; i < (int)(length_table / 2); i++) {
        *tmp_lt = lt[i];
        lt[i] = lt[length_table - i - 1];
        lt[length_table - i - 1] = *tmp_lt;
    }
    write_struct(file_name, lt);
    printf("Castling done\n");
}