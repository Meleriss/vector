#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "IntVector.h"

IntVector *int_vector_new(size_t initial_capacity) //Создание массива нулевого размера
{
	IntVector *v;
	v = malloc(sizeof(IntVector));
	if(v != NULL){
		v->data = malloc(initial_capacity * sizeof(int));
		if(v->data != NULL){
			v->cap = initial_capacity;
			v->size = 0;
		}
	}
	return v;
}

IntVector *int_vector_copy(const IntVector *v) //Копия вектора
{
	IntVector *copy;
	copy = int_vector_new(v->cap);
	if(v != NULL){
		memcpy(copy->data, v->data, v->size * sizeof(int));
		copy->size = v->size;
		copy->cap = v->cap;
	}
	return copy;
}

void int_vector_free(IntVector *v) //Освобождение памяти
{
	free(v->data);
	free(v);
	v->size = 0;
	v->cap = 0;
}

int int_vector_get_item(const IntVector *v, size_t index) //Вывод элемента вектора
{
	return v->data[index];
}

void int_vector_set_item(IntVector *v, size_t index, int item) //Присваивание элементу index, значение item
{
	if(index < v->size)	
		v->data[index] = item;
}

size_t int_vector_get_size(const IntVector *v)				//Размер вектора
{
	return v->size;
}

size_t int_vector_get_capacity(const IntVector *v)			//Емкость вектора
{
 	return v->cap;
}

int int_vector_push_back(IntVector *v, int item)	//Добавляет элемент в конец массива
{
	if(v->size >= v->cap){
		if(int_vector_realloc(v, v->cap * 2) == -1)
			return -1;
	}
	v->data[v->size] = item;
	v->size++;
	return 0;
}

void int_vector_pop_back(IntVector *v)		//Удалает последний элемент из массива
{	
	if(v->size > 0){
		v->data[v->size-1] = 0;
		v->size--;
	}
}

int int_vector_shrink_to_fit(IntVector *v)		//Уменьшает емкость массива до его размера
{
	if(v->size < v->cap)
		return int_vector_realloc(v, v->size);
	return 0;
}

int int_vector_reserve(IntVector *v, size_t new_capacity)	//Увеличить емкость массива на new_capacity
{
	if(new_capacity > v->cap)
		return int_vector_realloc(v, new_capacity);
	return 0;
}

int int_vector_resize(IntVector *v, size_t new_size)		//Изменяет размер массива на new_size
{
	if(new_size > v->size){
		v->size = new_size;
		if(new_size > v->cap)
			return int_vector_realloc(v, new_size);
	}
	if(new_size < v->size){
		v->size = new_size;
		v->cap = new_size;
		return int_vector_shrink_to_fit(v);
	}
	return 0;
}

int int_vector_realloc(IntVector *v, size_t new_capacity)	//Перераспределенние памяти на new_capacity
{
	int* t;
	t = realloc(v->data, new_capacity * sizeof(int));
	if(t == NULL) 
		return -1;
	v->data = t;
	v->cap = new_capacity;
	return 0;
}

void printf_vector(char head[90], IntVector *v){ //Вывод элементов вектора, его размера и емкости
    printf("%s:\n", head);
    for(size_t i = 0; i < int_vector_get_size(v); i++)
        printf("№%zu %d\n", i, int_vector_get_item(v, i));
    printf("Размер: %zu\nЕмкость: %zu\n\n", int_vector_get_size(v), int_vector_get_capacity(v));
}
