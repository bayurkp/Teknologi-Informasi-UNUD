#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

int validation() {
    char value[100], notValid;
    int num;
    bool okay = false;
        
    do {
        printf("masukkan angka: ");
        scanf("%[^\n]", value);
        int isValid = sscanf(value, "%d%c", &num, &notValid);
        getchar();
        if(isValid != 1) {
            printf("salah\n");
        } else {
            printf("benar\n");
            return num;
            okay = true;
        }
    } while(!okay);
}

int main() {
    int x = validation();
    printf("x = %d", x);
    return 0;
}
