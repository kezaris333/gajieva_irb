//������ ������ ��������. ��������� ���������, 
// ��������� �� ������ ��� �������

#include <stdio.h>

void delete(char* str) {
    char* ptr = str; //�� �� ������

    //
    while (*ptr) {
        ptr++; //����� �� ������
    }

    //������������� ������� ������ � ������ ������
    str[0] = '\0'; 
}

int main() {
    char str[100]; 
    printf("������� ������: ");
    fgets(str, sizeof(str), stdin); 

    delete(str); 

    printf("������ ����� �������� ���� ��������: '%s'\n", str);
    return 0;
}