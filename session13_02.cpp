#include <stdio.h>
int finducln();
int main() {
    int num1, num2;
    printf("Nhap so thu nhat: ");
    scanf("%d", &num1);
    printf("Nhap so thu hai: ");
    scanf("%d", &num2);
    int ucln = finducln();
    printf("uoc chung lon nhat cua %d va %d la: %d\n", num1, num2, ucln);
    return 0;
}
int finducln() {
	int a, b;
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
