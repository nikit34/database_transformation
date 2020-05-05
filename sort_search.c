#include"sort_search.h"

void sort_Shell_empitical_sequence(char *file_name){
    struct line_table *lt = read_struct(file_name);
    int step;
    printf("\nEnter value for range: ");
    scanf("%d", &step);
    printf("\n");
    int length_table = 0;
    while(lt[length_table].line_key != 0) {
        length_table++;
    }
    for(int i = step; i < length_table + step; i = i + step){
        if(lt[i - step].line_key > lt[i % length_table].line_key) {
            printf("\n1");
        }
    }
    write_struct(file_name, lt);
    printf("\nSort by Shell done\n");
}

void search_binary(char *file_name) {
    struct line_table *lt = read_struct(file_name);
    int length_table = 0;
    while(lt[length_table].line_key != 0) {
        length_table++;
    }
    int res = -1, search_index;
    int border = (int)(length_table / 2), count_iteration = (int)sqrt(length_table);
    printf("\nEnter search index: ");
    scanf("%d", &search_index);
    printf("\n");
    while(count_iteration > 0) {
        if(search_index < lt[border].line_key) {
            border = (int)(border / 2) + 1;
        }
        else if(search_index > lt[border].line_key) {
            border = border + (int)(border / 2) + 1;
        } else {
            res = border;
        }
        count_iteration--;
    }
    printf("Search Binary done\n");
    if(res == -1)
        printf("Element dont search\n");
    else
        printf("Result search: %d\n", res);
}