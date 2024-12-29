#include <iostream>
#include <ctime>
using namespace std;

// Заполнения масива случайными числами [0;9]
void FillArray(int* const arr, const int size){
    for(int i =0; i<size; i++){
        arr[i] = rand()%10;
    }
}

// Вывод массива на экран
void ShowArray(const int* const arr, const int size){
    for(int i =0; i<size; i++){
        cout << arr[i]<< "\t";
    }
}

// Добавление елемента в конец
void push_back(int *&arr, int &size, const int value){
    int* newArray = new int [size+1];
    
    for(int i =0; i<size; i++){
        newArray[i] = arr[i];
    }
    
    newArray[size] = value;
    
    delete[] arr;

    arr = newArray;
    
    size++;
}

// Удаление конечного елемента
void pop_back(int *&arr, int &size){
    
    size--;
    
    int* newArray = new int [size];
    
    for(int i =0; i<size; i++){
        newArray[i] = arr[i];
    }
    
    delete[] arr;

    arr = newArray;
}

// Добавление елемента в начало
void push_start(int *&arr, int &size, const int value){
    size++;
    
    int* newArray = new int [size];
    
    for(int i =1; i<size; i++){
        newArray[i] = arr[i-1];
    }
    
    newArray[0] = value;
    
    delete[] arr;

    arr = newArray;
}

// Удаление елемента с начала
void pop_start(int *&arr, int &size){
    size--;
    
    int* newArray = new int [size];
    
    for(int i =0; i<size; i++){
        newArray[i] = arr[i+1];
    }
    
    delete[] arr;

    arr = newArray;
}

// Добавление елемента по индексу
void push_index(int *&arr, int &size, const int index, const int value){
    
    int *newArray = new int [size+1];
    
    for(int i=0; i != index; i++){
        newArray[i] = arr[i];
    }
    
    newArray[index] = value;
    
    size++;
    
    for(int i=index+1; i < size; i++){
        newArray[i] = arr[i-1];
    }
    
    delete arr;
    
    arr = newArray;
    
}

// Удаление елемента по индексу
void pop_index(int *&arr, int &size, const int index){
    
    size--;
    
    int *newArray = new int [size];
    
    for(int i=0; i != index; i++){
        newArray[i] = arr[i];
    }
    
    for(int i=index; i < size; i++){
        newArray[i] = arr[i+1];
    }
    
    delete arr;
    
    arr = newArray;
    
}

int main(int argc, const char * argv[]) {
    
    srand((unsigned int)time(nullptr));
    setlocale(LC_ALL, "UTF-8");
    
    int size = 5;
    
    int *arr = new int [size];
    FillArray(arr, size);
    
    cout << "\nArray:\t";
    ShowArray(arr, size);
    
    push_back(arr, size, 111);
    
    cout << "\nArray:\t";
    ShowArray(arr, size);
    
    pop_back(arr, size);
    
    cout << "\nArray:\t";
    ShowArray(arr, size);
    
    push_start(arr, size, 10);
    
    cout << "\nArray:\t";
    ShowArray(arr, size);
    
    pop_start(arr, size);
    
    cout << "\nArray:\t";
    ShowArray(arr, size);
    
    push_index(arr, size, 2, 666);
    
    cout << "\nArray:\t";
    ShowArray(arr, size);
    
    pop_index(arr, size, 1);
    
    cout << "\nArray:\t";
    ShowArray(arr, size);

    delete[] arr;
    cout << "\n\n";
    
    return 0;
}

