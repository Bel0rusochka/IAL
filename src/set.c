#include "set.h"



void initSet(CharSet *set, size_t capacity) {
    set->elements = (char *)malloc(capacity * sizeof(char));
    if (set->elements == NULL) {
        fprintf(stderr, "Ошибка выделения памяти\n");
        exit(4);
    }
    set->size = 0;
    set->capacity = capacity;
}

void addToSet(CharSet *set, char value) {
    // Проверка, есть ли место для нового элемента
    if (set->size < set->capacity) {
        set->elements[set->size++] = value;
    } else {
        fprintf(stderr, "Множество полное, невозможно добавить элемент\n");
        exit(4);
    }
}

void removeFromSet(CharSet *set, char value) {
    // Поиск элемента в множестве
    for (size_t i = 0; i < set->size; ++i) {
        if (set->elements[i] == value) {
            for (size_t j = i; j < set->size - 1; ++j) {
                set->elements[j] = set->elements[j + 1];
            }
            set->size--;
            return;
        }
    }
    fprintf(stderr, "Элемент не найден в множестве\n");
    exit(4);
}

bool containsInSet(const CharSet *set, char value) {

    for (size_t i = 0; i < set->size; ++i) {
        if (set->elements[i] == value) {
            return true;
        }
    }
    return false;
}

void printSet(const CharSet *set) {
    printf("Set: { ");
    for (size_t i = 0; i < set->size; ++i) {
        printf("%c ", set->elements[i]);
    }
    printf("}\n");
}

void freeSet(CharSet *set) {
    free(set->elements);
    set->elements = NULL;
    set->size = 0;
    set->capacity = 0;
}

