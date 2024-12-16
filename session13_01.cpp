#include <stdio.h>
int cols, row;
int array[100][100];
int inputarray();
void printfarray();
int main() {
    printf("Nhap so hang: ");
    scanf("%d", &row);
    printf("Nhap so cot: ");
    scanf("%d", &cols);
    array[row][cols];
    inputarray();
    printfarray();
    return 0;
}
int inputarray() {
    printf("Nhap cac gia tri cho ma tran (%dx%d):\n", row, cols);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Phan tu [%d][%d]: ", i, j);
            scanf("%d", &array[i][j]);
        }
    }
}
void printfarray() {
    printf("Ma tran la:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}
