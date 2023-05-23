#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_MAX_LENGTH 20
#define MAX_INGREDIENTS_COUNT 10

struct _ingredient {
    char name[STR_MAX_LENGTH + 1];
    unsigned quantity; // Measured in grammes
};

typedef struct _ingredient Ingredient;

struct _dish {
    char name[STR_MAX_LENGTH + 1];
    char type[STR_MAX_LENGTH + 1];
    unsigned cooking_time; // Measured in minutes
    size_t ingredients_count;
    Ingredient ingredients[MAX_INGREDIENTS_COUNT];
};

typedef struct _dish Dish;

void read_ingredient(Ingredient *ingredient) {
    printf("Enter ingredient: ");
    scanf("%s", ingredient->name);
    scanf("%u", &ingredient->quantity);
}

void read_dish(Dish *dish) {
    printf("Enter dish: ");
    scanf("%s", dish->name);
    scanf("%s", dish->type);
    scanf("%u", &dish->cooking_time);
    printf("Enter ingredients count: ");
    scanf("%zu", &dish->ingredients_count);
    for (size_t i = 0; i < dish->ingredients_count; i++) {
        read_ingredient(&dish->ingredients[i]);
    }
}

void print_ingredient(const Ingredient *ingredient) {
    printf("%s (%ug)", ingredient->name, ingredient->quantity);
}

void print_dish(const Dish *dish) {
    printf("%s (%s, %u minutes): ", dish->name, dish->type, dish->cooking_time);
    for (size_t i = 0; i < dish->ingredients_count; i++) {
        print_ingredient(&dish->ingredients[i]);
        if (i < dish->ingredients_count - 1) {
            printf(", ");
        }
    }
    printf(".\n");
}

void add_new_dish(Dish **dishes, size_t *dishes_count, size_t *dishes_max_count) {
    if (*dishes_count == *dishes_max_count) {
        *dishes_max_count *= 2;
        *dishes = realloc(*dishes, (*dishes_max_count)*sizeof(Dish));
    }
    read_dish(*dishes + *dishes_count);
    (*dishes_count)++;
}

void read_name_and_print_dish(Dish **dishes, size_t *dishes_count) {
    char name[STR_MAX_LENGTH + 1];
    printf("Enter name: ");
    scanf("%s", name);
    for (size_t i = 0; i < *dishes_count; i++) {
        if (strcmp(name, (*dishes)[i].name) == 0) {
            print_dish(*dishes + i);
        }
    }
}

void read_type_and_print_dishes(Dish **dishes, size_t *dishes_count) {
    char type[STR_MAX_LENGTH + 1];
    printf("Enter type: ");
    scanf("%s", type);
    for (size_t i = 0; i < *dishes_count; i++) {
        if (strcmp(type, (*dishes)[i].type) == 0) {
            print_dish(*dishes + i);
        }
    }
}

int dish_has_ingredient(Dish *dish, char *ingredient) {
    for (size_t i = 0; i < dish->ingredients_count; i++) {
        if (strcmp(ingredient, dish->ingredients[i].name) == 0) {
            return 1;
        }
    }
    return 0;
}

void read_ingredient_and_print_dishes(Dish **dishes, size_t *dishes_count) {
    char ingredient[STR_MAX_LENGTH + 1];
    printf("Enter ingredient: ");
    scanf("%s", ingredient);
    for (size_t i = 0; i < *dishes_count; i++) {
        if (dish_has_ingredient(*dishes + i, ingredient)) {
            print_dish(*dishes + i);
        }
    }
}

void read_cooking_time_and_print_dishes(Dish **dishes, size_t *dishes_count) {
    unsigned cooking_time;
    printf("Enter cooking time: ");
    scanf("%u", &cooking_time);
    for (size_t i = 0; i < *dishes_count; i++) {
        if ((*dishes)[i].cooking_time <= cooking_time) {
            print_dish(*dishes + i);
        }
    }
}

void exe_command(int cmd, Dish **dishes, size_t *dishes_count, size_t *dishes_max_count) {
    switch (cmd) {
        case 0:
            puts("Exiting...");
            break;
        case 1:
            add_new_dish(dishes, dishes_count, dishes_max_count);
            break;
        case 2:
            read_name_and_print_dish(dishes, dishes_count);
            break;
        case 3:
            read_type_and_print_dishes(dishes, dishes_count);
            break;
        case 4:
            read_ingredient_and_print_dishes(dishes, dishes_count);
            break;
        case 5:
            read_cooking_time_and_print_dishes(dishes, dishes_count);
            break;
        default:
            puts("Unknown command.");
            break;
    }
}

int main() {
    Dish *dishes = malloc(sizeof(Dish));
    size_t dishes_max_count = 1;
    size_t dishes_count = 0;
    int cmd;
    do {
        printf("Enter command: ");
        scanf("%d", &cmd);
        exe_command(cmd, &dishes, &dishes_count, &dishes_max_count);
    } while (cmd != 0);
    free(dishes);
    return 0;
}