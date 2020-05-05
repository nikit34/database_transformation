#include"sort_search.h"

void shifting(char *file_name) {
    struct line_table *lt = read_struct(file_name);
    
    write_struct(file_name, lt);
    printf("\nShifting done\n");
}

void castling(char *file_name) {
    struct line_table *lt = read_struct(file_name);
    int i = 0;
    while(lt[i].line_key != 0) {
        printf("%d - %s\n", lt[i].line_key, lt[i].line_data);
        i++;
    }
    write_struct(file_name, lt);
    printf("\nCastling done\n");
}