// 007
// 撲克牌
// A, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K
// A~10 點數為 1~10，J, K, Q 為 0.5。
// A, B 兩個人各發三張撲克牌，加總點數越接近 10.5 的贏；超過 10.5 ，爆掉且分數為 0。
// 程式：
// 輸入：A, B 兩個人的三張撲克牌。
// 輸出：兩個人的點數，以及A wins.或B wins.或It's a tie.。

// Sample Input：
// A
// 2
// 3
// 2
// 3
// 4
// Sample Output：
// 6.0
// 9.0
// B wins.

// Sample Input：
// A
// 2
// 3
// A
// 2
// 3
// Sample Output：
// 6.0
// 6.0
// It's a tie.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float cast(char* i) {
    if (!strcmp(i, "A")) {
        return 1;
    }
    else if (!strcmp(i, "J") || !strcmp(i, "Q") || !strcmp(i, "K")) {
        return 0.5;
    }
    return atoi(i);
}

void win(float a, float b) {
    if (a > 10.5 && b > 10.5) printf("It's a tie.\n");
    else if (a > 10.5) {
        printf("B wins.\n");
    }
    else if (b > 10.5) {
        printf("A wins.\n");
    }
    else {
        if (a > b) printf("A wins.\n");
        else if(b > a) printf("B wins.\n");
        else printf("It's a tie.\n");
    }
}

int main() {
    char i[10];
    int j;
    float p[6];
    for (j=0; j<6; j++) {
        scanf("%s", &i);
        p[j] = cast(i);
    }
    if (p[0] + p[1] + p[2] > 10.5) printf("0.0\n");
    else printf("%.1f\n", p[0]+p[1]+p[2]);
    if (p[3] + p[4] + p[5] > 10.5) printf("0.0\n");
    else printf("%.1f\n", p[3]+p[4]+p[5]);
    win(p[0]+p[1]+p[2], p[3]+p[4]+p[5]);

    return 0;
}