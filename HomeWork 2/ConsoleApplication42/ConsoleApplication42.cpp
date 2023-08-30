#include <iostream>

using namespace std;

#define EndLine cout << endl 

//https://github.com/okovtun/BV_011/blob/master/ControlStructures/Geometria/Task/HardChess.jpg;

template<class T> void ShowChess(T size) {
    for (int sizeX = 0; sizeX < size * 5; sizeX++) {
        for (int sizeY = 0; sizeY < size * 5; sizeY++) {
            if ((sizeY / size + sizeX / size) & 1)
                cout << "  ";
            else
                cout << "* ";
        }
        cout << endl;
    }
} // Размер шахматной доски
/*
В проекте 'Arrays' написать код, который:
-позволяет ввести элементы массива с клавиатуры;
-выводит массив на экран в прямом порядке(от 0 - го элемента до последнего);
-выводит массив на экран в обратном порядке(от последнего элемента до 0 - го);
-вычисляет сумму элементов массива;
-вычисляет среднее - арифметическое элементов массива;
-находит минимальное и максимальное значение в массиве;*/

template<class T, class T2> void FillArr(T mass, T2 size) {
    for (int i = 0; i < size; i++) {
        cout << "Введите элементы массива - >"; cin >> mass[i]; cout << endl;
    }
    for (int i = 0; i < size; i++) {
        cout << mass[i] << " ";
    }
    EndLine;
    for (int i = 9; i > -1; i--) {
        cout << mass[i] << " ";
    }
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += mass[i];
    }
    EndLine;
    cout << "Сумма элементов массива равна " << sum << endl;
    sum = 0;
    for (int i = 0; i < size; i++) {
        sum += mass[i];
    }
    cout << "Cреднее - арифметическое элементов массива равно " << sum/size << endl;
    int min = mass[0];
    int max = mass[0];
    for (int i = 0; i < size; i++) {
        if (min > mass[i])
            min = mass[i];
        if (max < mass[i])
            max = mass[i];
    }
    cout << "min = " << min << "\t" << "max = " << max << endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T, class T2> void Allocate(T*** mass, T2* pRows, T2* pCols) {
    cout << "Введите высоту и длину массива: " << endl;
    cout << "Длина -> "; cin >> (*pCols);
    cout << "Высота -> "; cin >> (*pRows);

    (*mass) = new int* [*pRows] {};
    for (int i = 0; i < *pRows; i++) {
        (*mass)[i] = new int[*pCols] {};
    }

    for (int i = 0; i < *pRows; i++) 
        for (int j = 0; j < *pCols; j++) 
            (*mass)[i][j] = i+j;

    for (int i = 0; i < *pRows; i++) {
        for (int j = 0; j < *pCols; j++) {
            cout << (*mass)[i][j] << " ";
        }
        EndLine;
    }
    EndLine;
}
template <class T, class T2> void Clear(T*** mass, T2* pRows, T2* pCols) {
    for (int i = 0; i < *pRows; i++) {
        delete[](*mass)[i];
    }
    delete[](*mass);
}

template <class T, class T2> void push_row_front(T*** mass, T2* pRows, T2* pCols) {
    int ADD{};

    EndLine << "Какое кол-во строк вы хотите добавить? ->"; cin >> ADD;
    
    for (int i = *pRows; i < *pRows + ADD; i++) {
        (*mass)[i] = new int[*pCols];
        for (int j = 0; j < *pCols; j++) {
            (*mass)[i][j] = (*mass)[i - *pRows][j];
            (*mass)[i - *pRows][j] = 0;
        }
    }
    *pRows += ADD;

    /////////////////////////////////////////////
    for (int i = 0; i < *pRows; i++) {
        for (int j = 0; j < *pCols; j++) {
            cout << (*mass)[i][j] << " ";
        }
        EndLine;
    }
    EndLine;
}	//добавляет строку в начало массива
template <class T, class T2> void insert_row(T*** mass, T2* pRows, T2* pCols) {
    int ADD{}, index;

    EndLine << "Какое кол-во строк вы хотите добавить + индекс? ->"; cin >> ADD; cin >> index;
    for (int i = *pRows; i < *pRows + ADD;i++) {
        (*mass)[i] = new int[*pCols];
        for (int j = 0; j < *pCols; j++) {
            (*mass)[i][j] = (*mass)[i - *pRows + index][j];
            (*mass)[i - *pRows + index][j] = 0;
        }
    }
    *pRows += ADD;
    /////////////////////////////////////////////
    for (int i = 0; i < *pRows; i++) {
        for (int j = 0; j < *pCols; j++) {
            cout << (*mass)[i][j] << " ";
        }
        EndLine;
    }
    EndLine;
}      //вставляет строку в массив по указанному индексу

template <class T, class T2> void pop_row_back(T*** mass, T2* pRows, T2* pCols) {
    if (*pRows > 0) {
        delete[](*mass)[*pRows - 1];

        T** newMass = new T * [*pRows - 1];
        for (int i = 0; i < *pRows - 1; i++) {
            newMass[i] = (*mass)[i];
        }

        delete[](*mass);
        (*mass) = newMass;
        --(*pRows);
        /////////////////////////////////////////////
        for (int i = 0; i < *pRows; i++) {
            for (int j = 0; j < *pCols; j++) {
                cout << (*mass)[i][j] << " ";
            }
            EndLine;
        }
        EndLine;
    }
}		//удаляет последнюю строку из массива
template <class T, class T2> void pop_row_front(T*** mass, T2* pRows, T2* pCols) {
    if (*pRows > 0) {
        delete[](*mass)[0];

        T** newMass = new T * [*pRows - 1];
        for (int i = 0; i < *pRows - 1; i++) {
            newMass[i] = (*mass)[i + 1];
        }

        delete[](*mass);
        (*mass) = newMass;
        --(*pRows);
        /////////////////////////////////////////////
        for (int i = 0; i < *pRows; i++) {
            for (int j = 0; j < *pCols; j++) {
                cout << (*mass)[i][j] << " ";
            }
            EndLine;
        }
        EndLine;
    }
}		//удаляет нулевую строку из массива
template <class T, class T2> void erase_row(T*** mass, T2* pRows, T2* pCols) {
    if (*pRows > 0) {
        int index;

        back:
        EndLine << "Какую строку вы хотите удалить? Введите индекс ->"; cin >> index;

        if (index < 0 || index >= *pRows) {
            cout << "Неверный индекс строки." << endl;
            goto back;
        }
        delete[](*mass)[index];

        T** newMass = new T * [*pRows - 1];
        int newRow = 0;
        for (int i = 0; i < *pRows; i++) {
            if (i != index) {
                newMass[newRow++] = (*mass)[i];
            }
        }

        delete[](*mass);
        (*mass) = newMass;
        --(*pRows);
        /////////////////////////////////////////////
        for (int i = 0; i < *pRows; i++) {
            for (int j = 0; j < *pCols; j++) {
                cout << (*mass)[i][j] << " ";
            }
            EndLine;
        }
        EndLine;
    }
}			//удаляет строку из массива по заданному индексу

template <class T, class T2> void push_col_back(T*** mass, T2* pRows, T2* pCols) {
    for (int i = 0; i < *pRows; i++) {
        T* newMass = new T [*pCols + 1];
        for (int j = 0; j < *pCols; j++) {
            newMass[j] = (*mass)[i][j];
        }
        newMass[*pCols] = 0;

        delete[](*mass)[i];
        (*mass)[i] = newMass;
    }

    ++(*pCols);
    /////////////////////////////////////////////
    for (int i = 0; i < *pRows; i++) {
        for (int j = 0; j < *pCols; j++) {
            cout << (*mass)[i][j] << " ";
        }
        EndLine;
    }
    EndLine;
}
template <class T, class T2> void push_col_front(T*** mass, T2* pRows, T2* pCols) {
    for (int i = 0; i < *pRows; i++) {
        T* newMass = new T[*pCols + 1];
        newMass[0] = 0;
        for (int j = 0; j < *pCols; j++) {
            newMass[j + 1] = (*mass)[i][j];
        }

        delete[](*mass)[i];
        (*mass)[i] = newMass;
    }

    ++(*pCols);
    /////////////////////////////////////////////
    for (int i = 0; i < *pRows; i++) {
        for (int j = 0; j < *pCols; j++) {
            cout << (*mass)[i][j] << " ";
        }
        EndLine;
    }
    EndLine;
}
template <class T, class T2> void insert_col(T*** mass, T2* pRows, T2* pCols) {
    int index;
back:
    EndLine << "Какую строку вы хотите добавить? Введите индекс ->"; cin >> index;

    if (index < 0 || index >= *pRows) {
        cout << "Неверный индекс строки." << endl;
        goto back;
    }

    for (int i = 0; i < *pRows; i++) {
        T* newMass = new T[*pCols + 1];
        for (int j = 0; j < *pCols + 1; j++) {
            if (j < index) {
                newMass[j] = (*mass)[i][j];
            }
            else if (j > index) {
                newMass[j] = (*mass)[i][j - 1];
            }
            else {
                newMass[j] = 0;
            }
        }
        delete[](*mass)[i];
        (*mass)[i] = newMass;
    }

    ++(*pCols);
    /////////////////////////////////////////////
    for (int i = 0; i < *pRows; i++) {
        for (int j = 0; j < *pCols; j++) {
            cout << (*mass)[i][j] << " ";
        }
        EndLine;
    }
    EndLine;
}

template <class T, class T2> void pop_col_back(T*** mass, T2* pRows, T2* pCols) {
    if (*pCols > 0) {
        for (int i = 0; i < *pRows; i++) {
            T* newMass = new T[*pCols - 1];
            for (int j = 0; j < *pCols - 1; j++) {
                newMass[j] = (*mass)[i][j];
            }

            delete[](*mass)[i];
            (*mass)[i] = newMass;
        }

        --(*pCols);

        /////////////////////////////////////////////
        for (int i = 0; i < *pRows; i++) {
            for (int j = 0; j < *pCols; j++) {
                cout << (*mass)[i][j] << " ";
            }
            EndLine;
        }
        EndLine;
    }
}
template <class T, class T2> void pop_col_front(T*** mass, T2* pRows, T2* pCols) {
    if (*pCols > 0) {
        for (int i = 0; i < *pRows; i++) {
            T* newMass = new T[*pCols - 1];
            for (int j = 0; j < *pCols - 1; j++) {
                newMass[j] = (*mass)[i][j + 1];
            }

            delete[](*mass)[i];
            (*mass)[i] = newMass;
        }

        --(*pCols);
        /////////////////////////////////////////////
        for (int i = 0; i < *pRows; i++) {
            for (int j = 0; j < *pCols; j++) {
                cout << (*mass)[i][j] << " ";
            }
            EndLine;
        }
        EndLine;
    }
}
template <class T, class T2> void erase_col(T*** mass, T2* pRows, T2* pCols) {
    int index;
back:
    EndLine << "Какую строку вы хотите удалить? Введите индекс ->"; cin >> index;

    if (index < 0 || index >= *pCols) {
        cout << "Неверный индекс строки." << endl;
        goto back;
    }
    if (*pCols > 0 && index >= 0 && index < *pCols) {
        for (int i = 0; i < *pRows; i++) {
            T* newMass = new T[*pCols - 1];
            int newСol = 0;
            for (int j = 0; j < *pCols; j++) {
                if (j != index) {
                    newMass[newСol++] = (*mass)[i][j];
                }
            }

            delete[](*mass)[i];
            (*mass)[i] = newMass;
        }

        --(*pCols);
        /////////////////////////////////////////////
        for (int i = 0; i < *pRows; i++) {
            for (int j = 0; j < *pCols; j++) {
                cout << (*mass)[i][j] << " ";
            }
            EndLine;
        }
        EndLine;
    }
}



int main()
{
    setlocale(LC_ALL, "");
    srand(time(NULL));
    int a;
    const int size = 10;
    cout << "Введите размер шахматной доски: "; cin >> a; // Размер шахматной доски
    ShowChess(a);

    int arr[size];
    FillArr(arr, size);


    int Rows = 1, Cols = 1;
    int* pRows = &Rows; int* pCols = &Cols;
    int** DinamArr = new int*[Rows];

    Allocate(&DinamArr, pRows, pCols);

    erase_col(&DinamArr, pRows, pCols);
}
