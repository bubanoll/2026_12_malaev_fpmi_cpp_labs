#include <iostream>
#include <random>

int **createMatrix(int row, int col)
{
    int **matrix = new int *[row];
    for (int i = 0; i < row; ++i)
    {
        matrix[i] = new int[col]{0};
    }
    return matrix;
}

void inputMatrix(int **matrix, int row, int col)
{
    int element = 0;
    for (int i = 0; i < row; ++i)
    {
        for (int q = 0; q < col; ++q)
        {
            std::cout << "Введите [" << i << "][" << q << "] элемент матрицы: ";
            std::cin >> element;
            matrix[i][q] = element;
        }
    }
}

void sqr_rect(bool &rect, int row, int col)
{

    if (row == col)
    {
        std::cout << "Матрица квадратная!" << "\n";
        rect = false;
    }
    else
    {
        std::cout << "Матрица не квадратная :()" << "\n";
        rect = true;
    }
}

int **transposeMatrix(int **matrix, int row, int col)
{
    int **t_matrix = createMatrix(col, row);
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            t_matrix[j][i] = matrix[i][j];
        }
    }
    return t_matrix;
}

int **multiplication(int **matrix, int **matrix2, bool rect, int row, int col, int col2)
{
    if (rect == true)
    {
        int row3 = row;
        int col3 = col2;
        int **matrix3 = createMatrix(row3, col3);
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col2; ++j)
            {
                for (int k = 0; k < col; ++k)
                {
                    matrix3[i][j] += matrix[i][k] * matrix2[k][j];
                }
            }
        }
        return matrix3;
    }
    else
    {
        int row3 = row;
        int col3 = col2;
        int **matrix3 = createMatrix(row3, col3);
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col2; ++j)
            {
                for (int k = 0; k < col; ++k)
                {
                    matrix3[i][j] += matrix[i][k] * matrix2[k][j];
                }
            }
        }
        return matrix3;
    }
}

void deleteMatrix(int **matrix, int row)
{
    for (int i = 0; i < row; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int **randomMatrix(int &array, int &row, int &col)
{
    std::cout << "random - 1; ввод в ручную - 2: ";
    std::cin >> array;
    if (array == 2)
    {
        std::cout << "Введите длину строки матрицы: ";
        std::cin >> col;
        std::cout << "Введите длину столбца матрицы: ";
        std::cin >> row;
        if (col <= 0 || row <= 0)
        {
            std::cout << "Введена некорректная запись :(";
            return nullptr;
        }
        int **matrix = createMatrix(row, col);
        inputMatrix(matrix, row, col);
        return matrix;
    }
    else if (array == 1)
    {
        int a = 0;
        int b = 0;
        std::cout << "Введите границу a: ";
        std::cin >> a;
        std::cout << "Введите границу b: ";
        std::cin >> b;
        std::cout << "Введите длину строки матрицы (до 10): ";
        std::cin >> row;
        std::cout << "Введите длину столбца матрицы (до 10): ";
        std::cin >> col;
        if (col <= 0 || row <= 0 || row > 10 || col > 10)
        {
            std::cout << "Введена некорректная запись :(";
            return nullptr;
        }
        int **matrix = createMatrix(row, col);
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> distrib(a, b);
        for (int i = 0; i < row; ++i)
        {
            for (int q = 0; q < col; ++q)
            {
                int random_number = distrib(gen);
                matrix[i][q] = random_number;
            }
        }
        return matrix;
    }
    else
    {
        std::cout << "Введено неверное число :(";
        return nullptr;
    }
}

void printMatrix(int **matrix3, int row3, int col3)
{
    for (int i = 0; i < row3; ++i)
    {
        for (int q = 0; q < col3; ++q)
        {
            std::cout << matrix3[i][q] << "\t";
        }
        std::cout << "\n";
        ;
    }
}

void matrixOperations(int **matrix, int row, int col)
{
    bool rect = false;
    sqr_rect(rect, row, col);
    int **matrix2 = nullptr;
    int **matrix3 = nullptr;
    int col2 = 0;
    if (rect == true)
    {
        matrix2 = transposeMatrix(matrix, row, col);
        col2 = row;
        matrix3 = multiplication(matrix, matrix2, rect, row, col, col2);
    }
    else
    {
        matrix2 = matrix;
        col2 = col;
        matrix3 = multiplication(matrix, matrix2, rect, row, col, col2);
    }
    printMatrix(matrix3, row, col2);
    if (rect == true)
    {
        deleteMatrix(matrix2, col);
    }
    deleteMatrix(matrix3, row);
}

int main()
{
    bool rect = false;
    int row = 0;
    int col = 0;
    int array = 0;
    std::setlocale(LC_ALL, ".UTF8");
    int **matrix = randomMatrix(array, row, col);
    if (matrix == nullptr)
        return 0;
    std::cout << "\n Исходная матрица: \n";
    printMatrix(matrix, row, col);
    matrixOperations(matrix, row, col);
    deleteMatrix(matrix, row);
    return 0;
}