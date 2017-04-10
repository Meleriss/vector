#include <stdio.h>
#include <stdlib.h>
#include "IntVector.h"


int main(void) {
    
    //Создание вектора в структуре
    IntVector *StrucVec = int_vector_new(4);
    //Вывод полученного вектора
    printf_vector("Создать вектор", StrucVec);
    //Создание копии вектора
    IntVector *CopyStrucVec = int_vector_copy(StrucVec);
    //Вывод полученной копии
    printf_vector("Копия вектора", CopyStrucVec);
    //Изменить размер и емкость
    int_vector_resize(StrucVec, 6);
    int_vector_reserve(StrucVec, 10);
    printf_vector("Изменить размер и объем вектора", StrucVec);
    //Заполнение обоих векторотов двумя способами, значениями от 0 до X
    for(size_t i = 0; i < 20; i++){
       int_vector_set_item(StrucVec, i, (int)i);
       int_vector_push_back(CopyStrucVec, (int)i);
    }
    //Вывод заполненных векторов
    printf_vector("Заполненный вектор от 0 до Х", StrucVec);
    printf_vector("Копия вектор от 0 до Х", CopyStrucVec);
    int_vector_free(StrucVec);
    //Удалает последний элемент из массива
    int_vector_pop_back(CopyStrucVec);
    printf_vector("Удалает последний элемент из массива", CopyStrucVec);
    //Уменьшить емкость массива до его размера
    int_vector_shrink_to_fit(CopyStrucVec);
    printf_vector("Уменьшить емкость массива до его размера", CopyStrucVec);
    //Освобождение памяти использованных векторов
    int_vector_free(CopyStrucVec);
    return 0;
}
