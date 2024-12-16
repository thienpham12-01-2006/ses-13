#include <stdio.h>
int value, index;
int array[100];
int length;
int inputarray();
void displayMenu();
int printfarray();
int addvalue();
int fixarray();
int deletevalue();
int sortdescending();
int sortascending();
int linearsearch();
int binarysearch();
int main(){
	int array[100];
	int chosse, length;
	do{
		displayMenu();
	    printf("lua chon cua ban: ");
     	scanf("%d", &chosse);
     	switch(chosse){
     		case 1:
     			inputarray();
     			break;
     		case 2:
		        printfarray();
				break;
			case 3:
				addvalue();
				break;
			case 4:
				fixarray();
				break;
			case 5:
				deletevalue();
				break;
			case 6:
				printf("Chon kieu sap xep (a: Giam dan, b: Tang dan): ");
                char kieuSapXep;
                scanf(" %c", &kieuSapXep);
                if (kieuSapXep == 'a') {
                    sortdescending();
                } else if (kieuSapXep == 'b') {
                    sortascending();
                } else {
                    printf("Lua chon khong hop le.\n");
                }
                break;
            case 7:
            	printf("Nhap gia tri can tim: ");
                scanf("%d", &value);
                printf("Chon kieu tim kiem (a: Tuyen tinh, b: Nhi phan): ");
                char kieuTimKiem;
                scanf(" %c", &kieuTimKiem);
                int findindex;
                if (kieuTimKiem == 'a') {
                    findindex = linearsearch();
                } else if (kieuTimKiem == 'b') {
                    findindex = binarysearch();
                } else {
                    printf("Lua chon khong hop le.\n");
                    break;
                }
                if (findindex != -1) {
                    printf("Gia tri %d duoc tim thay tai vi tri %d.\n", value, findindex-1);
                } else {
                    printf("Khong tim thay gia tri %d trong mang.\n", value);
                }
                break;
            case 8:
            	printf("thoat chuong trinh");
            	return 0;
            default:
            	printf("so khong hop le");
            	break;
		}
	} while (chosse != 8);
}
void displayMenu(){
	printf("\n                    MENU          \n");
	printf("1. nhap so phan tu can nhap va gia tri cac phan tu\n");
	printf("2. in ra gia tri cac phan tu dang quan ly\n");
	printf("3. them mot phan tu vao vi tri chi dinh\n");
	printf("4. sua mot phan tu o vi tri chi dinh\n");
	printf("5. xoa mot phan tu o vi tri chi dinh\n");
	printf("6. sap xep cac phan tu\n");
	printf("7. tim kiem phan tu nhap vao\n");
	printf("8. thoat");
	printf("\n");
}
int inputarray(){
	printf("nhap so phan tu cua mang: ");
    scanf("%d", &length);
    for(int i = 0; i < length; i++){
        printf("gia tri cua phan tu thu %d: ", i + 1);
        scanf("%d", &array[i]);
	}
}
int printfarray(){
	printf("gia tri cac phan tu dang quan ly la: \n");
   	for(int i = 0; i < length; i++) {
     	printf("array[%d] = %d\n", i + 1, array[i]);
	}
}
int addvalue(){
	int value, index, addindex;
	printf("nhap gia tri muon them: ");
	scanf("%d", &value);
	printf("nhap vi tri muon them: ");
	scanf("%d", &index);
	for(int i = length; i > index; i--){
		array[i]=array[i-1];
	}
	length++;
	array[index-1]=value;
}
int fixarray(){
	printf("Nhap vi tri can sua: ");
    scanf("%d", &index );
    printf("Nhap gia tri moi: ");
    scanf("%d", &value);
	if (index >= 0 && index < 100) {
        array[index-1] = value;
    } else {
        printf("Vi tri khong hop le.\n");
    }
}
int deletevalue() {
    printf("Nhap vi tri can xoa: ");
    scanf("%d", &index);
    if (index >= 0 && index < length) {
        for (int i = index-1; i < length - 1; i++) {
            array[i] = array[i + 1];
        }
        length--;
    } else {
        printf("Vi tri khong hop le.\n");
    }
}
int sortdescending() {
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (array[i] < array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}
int sortascending() {
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (array[i] > array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}
int linearsearch() {
    for (int i = 0; i < length; i++) {
        if (array[i] == value) {
            return i;
        }
    }
    return -1;
}
int binarysearch() {
    int left = 0, right = length - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (array[mid] == value) {
            return mid;
        }
        if (array[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}
