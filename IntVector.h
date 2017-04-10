#ifndef INTVECTOR_H
#define INTVECTOR_H
#include <stddef.h>

typedef struct{
 	size_t cap;
	size_t size;
 	int *data;
} IntVector;

IntVector *int_vector_new(size_t initial_capacity);			//1 Создание вектора нулевого размера

IntVector *int_vector_copy(const IntVector *v);				//2 Копия вектора

void int_vector_free(IntVector *v);							//3 Освобождение памяти, выделенной для вектора

int int_vector_get_item(const IntVector *v, size_t index);	//4 Вывод элемента вектора

void int_vector_set_item(IntVector *v, size_t index, int item); //5 Присваивание элементу index, значение item

size_t int_vector_get_size(const IntVector *v);				//6 Размер вектора

size_t int_vector_get_capacity(const IntVector *v);			//7 Емкость вектора

int int_vector_push_back(IntVector *v, int item);			//8 Добавляет элемент в конец массива

void int_vector_pop_back(IntVector *v);						//9 Удалает последний элемент из массива

int int_vector_shrink_to_fit(IntVector *v);					//10 Уменьшает емкость массива до его размера

int int_vector_resize(IntVector *v, size_t new_size);		//11 Изменяет размер массива на new_size

int int_vector_reserve(IntVector *v, size_t new_capacity);	//12 Изменить емкость массива на new_capacity

void printf_vector(char head[90], IntVector *v); 			//Вывод элементов вектора, его размера и емкости

int int_vector_realloc(IntVector *v, size_t new_capacity);	//Функция вызова realloc

#endif