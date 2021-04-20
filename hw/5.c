// 005
// 檢查三門課程是否衝堂，
// 依序輸入課程編號(數字)、
// 上課小時數(1-3小時)、
// 上課時間(星期1-5, 第1-9節)

// 輸入說明
// 1001 (第一門課課程編號)
// 3 (3小時)
// 11 (星期1 第1節課)
// 59 (星期5 第9節課)
// 25 (星期2 第5節課)
// 2020 (第二門課課程編號)
// 2
// 25
// 16
// 2030 (第三門課課程編號)
// …

// 輸出說明 (兩課程編號衝突在哪幾節)
// 1001 and 2020 conflict on 25

// Sample Input：
// 1001
// 3
// 11
// 12
// 13
// 1002
// 3
// 21
// 22
// 23
// 1003
// 3
// 31
// 32
// 13
// Sample Output：
// 1001 and 1003 conflict on 13

// Sample Input：
// 1001
// 1
// 11
// 1002
// 3
// 21
// 22
// 11
// 1003
// 3
// 31
// 32
// 33
// Sample Output：
// 1001 and 1002 conflict on 11

#include <stdio.h>
#define ROW 9
#define COLUMN 5

int main() {
    int class[ROW][COLUMN] = {0};
    int conflict[4];
    for (int x = 0; x < 3; x++) {
        int number, hour, t;
        scanf("%d", &number);
        getchar();
        scanf("%d", &hour);
        getchar();
        for (int i = 0; i < hour; i++) {
            int _day, _time;
            scanf("%d", &t);
            _day = t/10-1;
            _time = t%10-1;
            if (class[_time][_day] == 0) {
                class[_time][_day] = number;
            }
            else {
                conflict[0] = class[_time][_day];
                conflict[1] = number;
                conflict[2] = _day+1;
                conflict[3] = _time+1;
            }
        }
    }
    printf("%d and %d conflict on %d%d", conflict[0], conflict[1], conflict[2], conflict[3]);
    return 0;
}