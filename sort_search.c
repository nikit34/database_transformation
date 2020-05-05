#include"sort_search.h"

void sort_Shell(char *file_name){
    struct line_table *lt = read_struct(file_name);
    struct line_table *tmp_lt = (line_table*)malloc(sizeof(line_table));
    int step;
    printf("\nEnter value for range: ");
    scanf("%d", &step);
    int length_table = 0;
    while(lt[length_table].line_key != 0) {
        length_table++;
    }
    while(step > 0) {
		for (int i = step; i < length_table; i++) {
			for (int j = i - step; j >= 0; j -= step) {
                if(lt[j].line_key > lt[j + step].line_key) {
                    *tmp_lt = lt[j];
                    lt[j] = lt[j + step];
                    lt[j + step] = *tmp_lt;
                }
            }
        }
        step /= 2;
	}
    write_struct(file_name, lt);
    printf("Sort by Shell done\n");
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