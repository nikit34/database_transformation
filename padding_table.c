#include"sort_search.h"

void shifting(char *file_name) {
    struct line_table *lt = read_struct(file_name);
    int tmp_key;
    char *tmp_data;
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
        } while(rand_i != rand_j);
        tmp_key = lt[rand_i].line_key;
        tmp_data = lt[rand_i].line_data;
        lt[rand_i].line_key = lt[rand_j].line_key;
        lt[rand_i].line_data = lt[rand_j].line_data;
        lt[rand_j].line_key = tmp_key;
        lt[rand_j].line_data = tmp_data;
        rand_count_iterations--;
    }
    write_struct(file_name, lt);
    printf("\nShifting done\n");
}

void castling(char *file_name) {
    struct line_table *lt = read_struct(file_name);
    int tmp_key;
    char *tmp_data;
    int length_table = 0;
    while(lt[length_table].line_key != 0) {
        length_table++;
    }
    for(int i = 0; i < (int)(length_table / 2); i++) {
        tmp_key = lt[i].line_key;
        tmp_data = lt[i].line_data;
        lt[i].line_key = lt[length_table - i - 1].line_key;
        lt[i].line_data = lt[length_table - i - 1].line_data;
        lt[length_table - i - 1].line_key = tmp_key;
        lt[length_table - i - 1].line_data = tmp_data;
    }
    write_struct(file_name, lt);
    printf("\nCastling done\n");
}