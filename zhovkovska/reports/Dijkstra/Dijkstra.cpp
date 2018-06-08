#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <climits>
// #define SIZE 6

int main()
{
 
    int SIZE, NUM_FIN;
    std::cout<<"Input number of vertices: \n";
    std::cin>>SIZE;
    std::cout<<"Input number of final vertex: \n";
    std::cin>>NUM_FIN;
    
    int graph[SIZE][SIZE]; // матрица связей
    int dist[SIZE]; // минимальное расстояние
    int vert[SIZE]; // посещенные вершины
    int temp;
    int minindex, min;
    // Инициализация матрицы связей
    for (int i = 0; i<SIZE; i++)
    {
        graph[i][i] = 0;
        for (int j = i + 1; j<SIZE; j++) {
            printf("Input distance %d - %d: ", i + 1, j + 1);
            scanf("%d", &temp);
            graph[i][j] = temp;
            graph[j][i] = temp;
        }
    }
    // Вывод матрицы связей
    for (int i = 0; i<SIZE; i++)
    {
        for (int j = 0; j<SIZE; j++)
            printf("%5d ", graph[i][j]);
        printf("\n");
    }
    //Инициализация вершин и расстояний
    for (int i = 0; i<SIZE; i++)
    {
        dist[i] = INT_MAX;
        vert[i] = 1;
    }
    dist[0] = 0;
    // Шаг алгоритма
    while (minindex < INT_MAX) {
        minindex = INT_MAX;
        min = INT_MAX;
        for (int i = 0; i<SIZE; i++)
        { // Если вершину ещё не обошли и вес меньше min
            if ((vert[i] == 1) && (dist[i]<min))
            { // Переприсваиваем значения
                min = dist[i];
                minindex = i;
            }
        }
        // Добавляем найденный минимальный вес
        // к текущему весу вершины
        // и сравниваем с текущим минимальным весом вершины
        if (minindex != INT_MAX)
        {
            for (int i = 0; i<SIZE; i++)
            {
                if (graph[minindex][i] > 0)
                {
                    temp = min + graph[minindex][i];
                    if (temp < dist[i])
                    {
                        dist[i] = temp;
                    }
                }
            }
            vert[minindex] = 0;
        }
    }
    // Вывод кратчайших расстояний до вершин
    printf("\nShortest distance to vertices: \n");
    for (int i = 0; i<SIZE; i++)
        printf("%5d ", dist[i]);
    
    // Восстановление пути
    int ver[SIZE]; // массив посещенных вершин
    int end = NUM_FIN-1; // индекс конечной вершины = 5 - 1
    ver[0] = end + 1; // начальный элемент - конечная вершина
    int k = 1; // индекс предыдущей вершины
    int weight = dist[end]; // вес конечной вершины
    
    while (end > 0) // пока не дошли до начальной вершины
    {
        for(int i=0; i<SIZE; i++) // просматриваем все вершины
            if (graph[end][i] != 0)   // если связь есть
            {
                int temp = weight - graph[end][i]; // определяем вес пути из предыдущей вершины
                if (temp == dist[i]) // если вес совпал с рассчитанным
                {                 // значит из этой вершины и был переход
                    weight = temp; // сохраняем новый вес
                    end = i;       // сохраняем предыдущую вершину
                    ver[k] = i + 1; // и записываем ее в массив
                    k++;
                }
            }
    }
    // Вывод пути (начальная вершина оказалась в конце массива из k элементов)
    printf("\nShortest way\n");
    for (int i = k-1; i>=0; i--)
        printf("%3d ", ver[i]);
    getchar(); getchar();
    return 0;
}
