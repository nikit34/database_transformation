#include"sort_search.h"

void shifting(char *file_name) {
    FILE *f = fopen(file_name, "rt");
    fclose(f);
}

void castling(char *file_name) {
    struct line_table *lt = read_struct(file_name);
    
}