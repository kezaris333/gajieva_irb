#include <stdio.h>
#include <string.h>

//
void reverse_string(char str[]) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

int main() {
    char str[] = "hello world";
    reverse_string(str);
    printf("Реверс строки: %s\n", str);
    return 0;
}
