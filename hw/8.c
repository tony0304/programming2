// 008
// 請使用 while loop或for loop
// 第一個輸入意義為選擇三種圖形:
// 1 三角形方尖方面向右邊
// 2 三角形方尖方面向左邊
// 3 菱形

// 第二個輸入意義為畫幾行
// (奇數，範圍為 3,5,7,9,....,21)

// input
// 1 (第一種圖形，三角形尖方面向右邊)
// 9 (共 9 行)
// --------------------------
// output
// *
// **
// ***
// ****
// *****
// ****
// ***
// **
// *
// ---------------------------
// input
// 2 (第二種圖形，三角形尖方面向左邊)
// 5 (共 5 行)
// ---------------------------
// output
// ..*
// .**
// ***
// .**
// ..*
// --------------------------
// input
// 3 (第三種圖形: 菱形 )
// 3 (共 3 行數)

// 輸出
// .*
// ***
// .*

#include<stdio.h>

void print_right(int column) {
    int i, j;
    for (i=1; i<column+1; i++) {
        if (i <= (column+1)/2)
            for (j=0; j<i; j++) printf("*");
        else
            for (j=0; j<=column-i; j++) printf("*");
        printf("\n");
    }
}

void print_left(int column) {
    int i, j;
    for (i=1; i<=(column+1)/2; i++) {
        for(j=0; j<(column+1)/2-i; j++) printf(".");
        for(j=0; j<i; j++) printf("*");
        printf("\n");
    }
    for (i=1; i<(column+1)/2; i++) {
        for (j=0; j<i; j++) printf(".");
        for (j=0; j<(column+1)/2-i; j++) printf("*");
        printf("\n");
    }
}

void print(int column) {
    int i, j;
    for (i=1; i<=(column+1)/2; i++) {
        for (j=0; j<(column+1)/2-i; j++) printf(".");
        for (j=0; j<i; j++) printf("*");
        for (j=0; j<i-1; j++) printf("*");
        printf("\n");
    }
    for (i=1; i<(column+1)/2; i++) {
        for (j=0; j<i; j++) printf(".");
        for (j=0; j<(column+1)/2-i; j++) printf("*");
        for (j=0; j<(column+1)/2-i-1; j++) printf("*");
        printf("\n");
    }
}

int main() {

    int type, column;

    scanf("%d", &type);
    scanf("%d", &column);

    switch(type) {
        case 1:
            print_right(column);
            break;
        case 2:
            print_left(column);
            break;
        case 3:
            print(column);
            break;
        default:
            return -1;
    }
    return 0;
}