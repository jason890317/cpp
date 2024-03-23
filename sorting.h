#ifndef SORTING_H
#define SORTING_H
#include<iostream>
#include<string>


template <class T>
void Insert(const T& e, T *a, int i)
{
    a[0] = e;
    while (e < a[i]) 
    {
        a[i+1] = a[i];
        i--; 
    }
    a[i+1] = e;
}
template <class T>
void InsertionSort(T *a, const int n)
{
    for (int j = 2; j <= n ; j++)
    {
        T temp = a[j];
        Insert(temp, a, j-1);
    }
}





#endif