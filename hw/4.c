// 004 .

// 輸入一浮點數a，為一圓形之半徑，計算面積和周長並依序輸出。(運用定義常數#define PI 3.14159定義PI=3.14159)

// 輸入說明

// 浮點數a

// ---------------
// 輸出說明

// 面積 = 半徑 * 半徑 * PI
// 周長 = 2 * 半徑 * PI

// 面積, 周長 輸出到小數點第三位

// ---------------
// Input
// 5.0

// Output
// 78.540
// 31.416

// ---------------
// Input
// 3.8

// Output
// 45.365
// 23.876

#include <stdio.h>
#define PI 3.14159

int main() {
    float radius, area, perimeter;
    scanf("%f", &radius);
    area = radius*radius*PI;
    perimeter = 2*radius*PI;
    printf("%.3f\n%.3f\n", area, perimeter);
    return 0;
}