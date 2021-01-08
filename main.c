#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>

#define MY_FILE "./build/examples.txt"

int menu();
void build_file(int, int, int, char);
int generation(int *);

int main() {
    return menu();
}

int generation(int *bitness){
    switch (*bitness) {
        case 5: return 10000 + rand() % 90000;
        case 4: return 1000 + rand() % 9000;
        case 3: return 100 + rand() % 900;
        case 2: return 10 + rand() % 90;
        default:{
            *bitness = 1;   // В случае ввода разрядности больше 5, вернуть формат вывода 4 столбца
            return rand() % 10;
        }
    }
}

void build_file(int number_examples, int x_bitness, int y_bitness, char sign){
    FILE *file;
    int x, y;
    file = fopen(MY_FILE, "w");
    srand(time(NULL));
    for(int i = 1; i <= number_examples; i++) {
        x = generation(&x_bitness);
        y = generation(&y_bitness);
        fprintf(file, "%d %c %d =\t\t", x, sign, y);
        if (x_bitness + y_bitness > 6) {
            if (i % 3 == 0)
                fprintf(file, "\n");
        } else if (i % 4 == 0){
            fprintf(file, "\n");
        }
    }
    fclose(file);
}

int menu(){
    int number_examples, x_bitness, y_bitness;
    char sign, ans;
    while (true) {
        printf("Программа генерации примеров\n"
               "Введите количество примеров: ");
        scanf("%d", &number_examples);
        getchar();
        printf("Введите знак математического действия: ");
        scanf("%c", &sign);
        getchar();
        printf("Введите разрядность первого числа: ");
        scanf("%d", &x_bitness);
        getchar();
        printf("Введите разрядность второго числа числа: ");
        scanf("%d", &y_bitness);
        getchar();
        build_file(number_examples, x_bitness, y_bitness, sign);
        printf("Нажмите \"q\" для выхода или любую другую кнопку для продолжения: ");
        ans = getchar();
        switch (ans) {
            case 'q':
                return 0;
            default:
                continue;
            
        }
    }
}