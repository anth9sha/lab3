#include <iostream>
#include <ctime>
#include <Windows.h>

using namespace std;

const int N = 6;
const int width = 4;

HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
COORD destCoord;

void fillMatrix(int matrix[][N], int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            *(*(matrix + j) + i) = rand() % 100;
        }
    }
}

void printMatrix(int matrix[][N], int N, int offsetx, int offsety) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            destCoord.X = (i + offsetx) * width;
            destCoord.Y = j + offsety;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << *(*(matrix + j) + i);
        }
    }
}

void printFloatMatrix(float matrix[][N], int N, int offsetx, int offsety) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            destCoord.X = (i + offsetx) * width;
            destCoord.Y = j + offsety;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << *(*(matrix + j) + i);
        }
    }
}

void shuffle_a(int matrix[][N], int newmatrix[][N]) {
    for (int i = 0; i < N / 2; i++) {
        for (int j = 0; j < N / 2; j++) {
            *(*(newmatrix + j) + i) = *(*(matrix + j + N / 2) + i);
            *(*(newmatrix + j) + (i + N / 2)) = *(*(matrix + j) + i);
            *(*(newmatrix + (j + N / 2)) + (i + N / 2)) = *(*(matrix + j) + i + N / 2);
            *(*(newmatrix + (j + N / 2)) + i) = *(*(matrix + j + N / 2) + i + N / 2);
        }
    }
}

void shuffle_b(int matrix[][N], int newmatrix[][N]) {
    for (int i = 0; i < N / 2; i++) {
        for (int j = 0; j < N / 2; j++) {
            *(*(newmatrix + j) + i) = *(*(matrix + j + N / 2) + i + N / 2);
            *(*(newmatrix + j) + (i + N / 2)) = *(*(matrix + j + N / 2) + i);
            *(*(newmatrix + (j + N / 2)) + (i + N / 2)) = *(*(matrix + j) + i);
            *(*(newmatrix + (j + N / 2)) + i) = *(*(matrix + j) + i + N / 2);
        }
    }
}
void shuffle_c(int matrix[][N], int newmatrix[][N]) {
    for (int i = 0; i < N / 2; i++) {
        for (int j = 0; j < N / 2; j++) {
            *(*(newmatrix + j) + i) = *(*(matrix + j + N / 2) + i);
            *(*(newmatrix + j) + (i + N/2)) = *(*(matrix + j + N / 2) + i + N / 2);
            *(*(newmatrix + (j + N / 2)) + (i + N / 2)) = *(*(matrix + j) + i + N / 2);
            *(*(newmatrix + (j + N / 2)) + i) = *(*(matrix + j) + i);
        }
    }

}

void shuffle_d(int matrix[][N], int newmatrix[][N]) {
    for (int i = 0; i < N / 2; i++) {
        for (int j = 0; j < N / 2; j++) {
            *(*(newmatrix + j) + i) = *(*(matrix + j) + i + N / 2);
            *(*(newmatrix + j) + (i + N / 2)) = *(*(matrix + j) + i);
            *(*(newmatrix + (j + N / 2)) + (i + N / 2)) = *(*(matrix + j + N / 2) + i);
            *(*(newmatrix + (j + N / 2)) + i) = *(*(matrix + j + N / 2) + i + N / 2);
        }
    }

}

void quicksort(int arr[][N], int begin, int end) {
    int b = begin;
    int e = end;
    int midl = (b + e) / 2;
    int mid = (*(*(arr + midl / N) + midl % N));
    while (b < e) {
        while (*(*(arr + b / N) + b % N) < mid) b++;
        while (*(*(arr + e / N) + e % N) > mid) e--;
        if (b <= e) {
            swap(*(*(arr + b / N) + b % N), *(*(arr + e / N) + e % N));
            b++;
            e--;
        }
    }
    if (begin < e) quicksort(arr, begin, e);
    if (e < end) quicksort(arr, b, end);
}

int main() {
    srand(time(NULL));
    setlocale(0, "");
    int matrixA[N][N], matrixB[N][N], shufflematrix[N][N];
    fillMatrix(matrixA, N);
    cout << "1) Квадратичные матрицы (A и B): " << endl;
    for (int i = 0; i <= N * 2 - 1; i++) {
        int a = i % 4;
        switch (a) {
        case(0):
            for (int x = i / 4; x < N - i / 4; x++) {
                int y = i / 4;
                destCoord.X = x * width;
                destCoord.Y = y+1;
                SetConsoleCursorPosition(hStdout, destCoord);
                cout << *(*(matrixA + y) + x);
                Sleep(10);
            }
            break;
        case(1):
            for (int y = i / 4 + 1; y < N - i / 4; y++) {
                int x = N - i / 4 - 1;
                destCoord.X = x * width;
                destCoord.Y = y+1;
                SetConsoleCursorPosition(hStdout, destCoord);
                cout << *(*(matrixA + y) + x);
                Sleep(10);
            }
            break;
        case(2):
            for (int x = N - i / 4 - 2; x > 0 + i / 4; x--) {
                int y = N - i / 4 - 1;
                destCoord.X = x * width;
                destCoord.Y = y+1;
                SetConsoleCursorPosition(hStdout, destCoord);
                cout << *(*(matrixA + y) + x);
                Sleep(10);
            }
            break;
        case(3):
            for (int y = N - i / 4 - 1; y > 0 + i / 4; y--) {
                int x = i / 4;
                destCoord.X = x * width;
                destCoord.Y = y+1;
                SetConsoleCursorPosition(hStdout, destCoord);
                cout << *(*(matrixA + y) + x);
                Sleep(10);
            }
            break;
        }
    }
    fillMatrix(matrixB, N);

    for (int i = 0; i < N; i++) {
        int a = i % 2;
        switch (a) {
        case(0):
            for (int y = 0; y < N; y++) {
                destCoord.X = i*width + N*width+3;
                destCoord.Y = y + 1;
                SetConsoleCursorPosition(hStdout, destCoord);
                cout << *(*(matrixB + y) + i);
                Sleep(10);
            }
            break;
        case(1):
            for (int y = N - 1; y >= 0; y--) {
                destCoord.X = i*width + N * width + 3;
                destCoord.Y = y + 1;
                SetConsoleCursorPosition(hStdout, destCoord);
                cout << *(*(matrixB + y) + i);
                Sleep(10);
            }
            break;
        }
    }
    destCoord.X = 0;
    destCoord.Y = N + 2;
    SetConsoleCursorPosition(hStdout, destCoord);
    cout << "2) Перестановки блоков матрицы" << "\n" << "Выберите матрицу (A or B): ";
    char choice;
    cin >> choice;
    do
    {
        switch (choice)
        {
        case 'A':
            cout << "Выберите способ перестановки (a, b, c, d): ";
            char shufchoiceA;
            cin >> shufchoiceA;
            switch (shufchoiceA)
            {
            case 'a':
                shuffle_a(matrixA, shufflematrix);
                printMatrix(shufflematrix, N, 0, N + 6);
                choice = 0;
                cout << endl;
                break;
            case 'b':
                shuffle_b(matrixA, shufflematrix);
                printMatrix(shufflematrix, N, 0, N + 6);
                choice = 0;
                cout << endl;
                break;
            case 'c':
                shuffle_c(matrixA, shufflematrix);
                printMatrix(shufflematrix, N, 0, N + 6);
                choice = 0;
                cout << endl;
                break;
            case 'd':
                shuffle_d(matrixA, shufflematrix);
                printMatrix(shufflematrix, N, 0, N + 6);
                choice = 0;
                cout << endl;
                break;
            default:
                cout << "Некорректный ввод" << endl;
                choice = 0;
                break;
            }
            break;
        case 'B':
            cout << "Выберите способ перестановки (a, b, c ,d): ";
            char shufchoiceB;
            cin >> shufchoiceB;
            switch (shufchoiceB)
            {
            case 'a':
                shuffle_a(matrixB, shufflematrix);
                printMatrix(shufflematrix, N, 0, N + 6);
                choice = 0;
                cout << endl;
                break;
            case 'b':
                shuffle_b(matrixB, shufflematrix);
                printMatrix(shufflematrix, N, 0, N + 6);
                choice = 0;
                cout << endl;
                break;
            case 'c':
                shuffle_c(matrixB, shufflematrix);
                printMatrix(shufflematrix, N, 0, N + 6);
                choice = 0;
                cout << endl;
                break;
            case 'd':
                shuffle_d(matrixB, shufflematrix);
                printMatrix(shufflematrix, N, 0, N + 6);
                choice = 0;
                cout << endl;
                break;
            default:
                cout << "Некорректный ввод" << endl;
                choice = 0;
                break;
            }
            break;
        default:
            cout << "Некорректный ввод" << endl;
            choice = 0;
            break;
        }
    } while (choice != 0);

    system("pause");
    system("cls");

    destCoord.X = 0;
    destCoord.Y = 0;
    SetConsoleCursorPosition(hStdout, destCoord);
    cout << "3) Отсортированная матрицы A и B:";
    quicksort(matrixA, 0, N * N - 1);
    quicksort(matrixB, 0, N* N - 1);
    printMatrix(matrixA, N, 0, 1);
    printMatrix(matrixB, N, N+1, 1);
    destCoord.X = 0;
    destCoord.Y = N + 2;
    SetConsoleCursorPosition(hStdout, destCoord);
    cout << "4) Введите знак операции: ";
    char opsign; int number; float matrixfornull[N][N];
    cin >> opsign;
    if (opsign != '+' && opsign != '-' && opsign != '*' && opsign != '/') {
        cout << "Неверный знак. Матрицы остаются без изменения.";
    }
    else {
        cout << "Введите число: ";
        cin >> number;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++) {
                switch (opsign)
                {
                case '+':
                    *(*(matrixA + j) + i) += number;
                    *(*(matrixB + j) + i) += number;
                    break;
                case '-':
                    *(*(matrixA + j) + i) -= number;
                    *(*(matrixB + j) + i) -= number;
                    break;
                case '*':
                    *(*(matrixA + j) + i) *= number;
                    *(*(matrixB + j) + i) *= number;
                    break;
                case '/':
                    if (number == 0) {
                        *(*(matrixfornull + j) + i) /= number;
                    }
                    else {
                        *(*(matrixA + j) + i) /= number;
                        *(*(matrixB + j) + i) /= number;
                    }
                    break;
                }
            }
        }
    }
    if (opsign == '/' && number == 0)
    {
        printFloatMatrix(matrixfornull, N, 0, N + 5);
        printFloatMatrix(matrixfornull, N, N + 1, N + 5);
    }
    else {
        printMatrix(matrixA, N, 0, N + 5);
        printMatrix(matrixB, N, N + 1, N + 5);
    }
    cout << endl;
    system("pause");
    system("cls");
    destCoord.X = 0;
    destCoord.Y = 0;
    SetConsoleCursorPosition(hStdout, destCoord);

    // ИДЗ 1
    int IDZmatrix[N][N];
    fillMatrix(IDZmatrix, N);
    cout << "Сложение двух матриц";
    printMatrix(matrixA, N, 0, 1);
    destCoord.X = (N * width) + 2;
    destCoord.Y = N/2;
    SetConsoleCursorPosition(hStdout, destCoord);
    cout << '+';
    printMatrix(IDZmatrix, N, N + 2, 1);
    destCoord.X = (2*N * width) + 2*width;
    destCoord.Y = N / 2;
    SetConsoleCursorPosition(hStdout, destCoord);
    cout << '=';
    destCoord.X = 0;
    destCoord.Y = N + 1 + N / 2;
    SetConsoleCursorPosition(hStdout, destCoord);
    cout << '=';
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            destCoord.X = i * (width*2 + 1) + 2;
            destCoord.Y = (N+2)+j;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << *(*(matrixA + j) + i) << "+" << *(*(IDZmatrix + j) + i);
        }
    }
    destCoord.X = N * (width * 2 + 1) + 3;
    destCoord.Y = N + 1 + N / 2;
    SetConsoleCursorPosition(hStdout, destCoord);
    cout << '=';
    destCoord.X = 0;
    destCoord.Y = N + N + 2 + N / 2;
    SetConsoleCursorPosition(hStdout, destCoord);
    cout << '=';
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            destCoord.X = (i+1) * width;
            destCoord.Y = (N + N + 3) + j;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << *(*(matrixA + j) + i) + *(*(IDZmatrix + j) + i);
        }
    }
}