// 003.工資計算

// 假設工作一小時x元(整數) ，而全部薪資所得的8%取到小數第一位是稅金，每個月勞保費為最低工資y元(整數)的5%取到小數第一位。
// 請分開輸入二個月工作時數(整數) 、還有x與 y。
// 輸出扣完稅與勞保後實際所得、勞保費、稅金。
// (浮點數宣告請用float)

// ---------------
// Input
// 100
// 200
// 160
// 23000

// Output
// 43010.0
// 1150.0
// 3840.0

// ---------------
// Input
// 0
// 300
// 200
// 20000

// Output
// 54200.0
// 1000.0
// 4800.0

#include <stdio.h>

int main() {
    int hour1, hour2, money, lmoney;
    float income, lb, xg;
    scanf("%d", &hour1);
    getchar();
    scanf("%d", &hour2);
    getchar();
    scanf("%d", &money);
    getchar();
    scanf("%d", &lmoney);
    getchar();
    lb = lmoney*0.05;
    xg = (hour1+hour2)*money*0.08;
    income = (hour1+hour2)*money-lb-xg;
    printf("%.1f\n%.1f\n%.1f\n", income, lb, xg);
    return 0;
}