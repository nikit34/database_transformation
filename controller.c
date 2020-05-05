#include"sort_search.h"

void info(){
    printf("\n### Menu Actions ###\n");
    printf("0. Print information\n");
    printf("1. Write data\n");
    printf("2. Read data\n");
    printf("3. Search binary by key\n");
    printf("4. Sort Shell of empitical sequence\n");
    printf("5. Shifting data\n");
    printf("6. Castling data\n");
    printf("q. Symbol for exit\n");
    printf("Choice action ___ ");
}

void read_table(char *file_name) {
    int ch;
    FILE *f = fopen(file_name, "r");
    printf("\nDatabase in file:\n");
    while ((ch = getc(f)) != EOF) {
        putchar(ch);
    }
    printf("\n");
    fclose(f);
}

void write_table(char *file_name) {
    FILE *f = fopen(file_name, "w");
    char ch;
    char *key, *data;
    int count_enter = 0;
    int length_str;
    int separate_stat = 0;
    do {
        scanf("%c", &ch);
        if(ch == 10) { // codes "enter" key
            if(separate_stat == 3) {
                fprintf(f, "%s,%s\n", key, data);
                separate_stat = 0;
            }
            length_str = 0;
            count_enter++;
            key = (char*)malloc(sizeof(char));
            data = (char*)malloc(sizeof(char));
        } else {
            if((int)(ch - '0') >= 0 && (int)(ch - '0') <= 9 && separate_stat == 0) {
                separate_stat = 1;
                *key = ch;
                length_str++;
            } else if((int)(ch - '0') >= 0 && (int)(ch - '0') <= 9 && separate_stat == 1) {
                key = (char*)realloc(key, sizeof(char) * (length_str + 1));
                strcat(key, &ch);
                length_str++;
            } else if(ch == ' ' && separate_stat == 1) {
                separate_stat = 2;
                length_str = 0;
            } else if(ch != ' ' && separate_stat == 2) {
                separate_stat = 3;
                *data = ch;
                length_str++;
            } else if(ch != ' ' && separate_stat == 3) {
                data = (char*)realloc(data, sizeof(char) * (length_str + 1));
                strcat(data, &ch);
                length_str++;
            }
            count_enter = 0;
        }
    } while(count_enter != 3);
    fclose(f);
    printf("\nRecard from console to file - done\n");
}

struct line_table * read_struct(char *file_name) {
    FILE *f = fopen(file_name, "r");
    char ch;
    int length_word = 0, length_table = 0;
    bool separate = false, memory_call = false;
    struct line_table *lt = (line_table*)malloc(sizeof(line_table));
    do {
        ch = fgetc(f);
        if(ch == EOF) {
            break;
        }
        if(ch == '\n') {
            lt[length_table].line_data[length_word] = '\0';
            length_word = 0;
            length_table++;
            separate = false;
            memory_call = false;
            lt = (line_table*)realloc(lt, sizeof(line_table) * (length_table + 1));
            continue;
        }
        if(!separate) {
            if(ch == ',') {
                separate = true;
                length_word = 0;
                memory_call = false;
                continue;
            }
            if(!memory_call) {
                lt[length_table].line_key = 0;
                memory_call = true;
            }
            lt[length_table].line_key = lt[length_table].line_key * 10 + ((int)(ch - '0'));
        } else {
            if(!memory_call) {
                lt[length_table].line_data = (char*)malloc(sizeof(char));
                memory_call = true;
            }
            length_word++;
            lt[length_table].line_data[length_word - 1] = ch;
            lt[length_table].line_data = (char*)realloc(lt[length_table].line_data, sizeof(char) * (length_word + 1));
        }
    } while(1);
    fclose(f);

    printf("\nDatabase after proccessing in RAM:\n");
    int i = 0;
    while(lt[i].line_key != 0) {
        printf("%d - %s\n", lt[i].line_key, lt[i].line_data);
        i++;
    }
    return lt;
}

void write_struct(char *file_name, struct line_table * lt) {
    FILE *f = fopen(file_name, "w");
    int i = 0;
    while(lt[i].line_key != 0) {
        fprintf(f, "%d,%s\n", lt[i].line_key, lt[i].line_data);
        i++;
    }
    fclose(f);
    printf("\nRecard from RAM to file - done\n");
}

int main(){
    char ch, *file_name = "db.txt";
    info();
    do {
        ch = getchar();
        switch ((int)(ch - '0')) {
        case 0:
            info();
            break;
        case 1:
            write_table(file_name);
            break;
        case 2:
            read_table(file_name);
            break;
        case 3:
            //search_binary(file_name);
            break;
        case 4:
            //sort_Shell_empitical_sequence(file_name);
            break;
        case 5:
            //shifting(file_name);
            break;
        case 6:
            castling(file_name);
            break;
        default:
            printf("\nNOTE: for get info press: 0\n");
            break;
        }
    } while(ch != 'q');
    return 0;
}