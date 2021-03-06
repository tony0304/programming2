// 十八骰子是一種常見的擲骰子遊戲，用四顆骰子計點。四顆一開始都是點數 1 朝上，點數 4 朝前，點數 2 朝右 (如下左圖所示)，骰子展開如下右圖所示。

// 接下來 N 次修改操作，每次操作包含四個整數 a, b, c, d 代表四個骰子操作。a, b, c, d意義為：
// 1. 1 表示向前滾一次。
// 2. 2 表示向後滾一次。
// 3. 3 表示向右滾一次。
// 4. 4 表示向左滾一次。
// 操作修正完成，請輸出點數，計點方式：
// 1. 若四顆點數均相同，稱一色，計18點，例如6, 6, 6, 6 或 3, 3, 3, 3。
// 2. 若四顆點數均不同；或有三顆點數相同，一顆不同，計 0點，例如 1, 2, 3, 4 或 2, 2, 2, 6。
// 3. 若兩顆點數相同，另兩顆點數也相同，但兩組兩顆點數不同，則點數計算為 - 加總兩顆較大點數，例如 2, 2, 5, 5，加總兩顆較大點數為 5+5=10點。
// 4. 若兩顆點數相同，另兩顆點數不同，則點數計算為加總兩顆不同點數，例如 2, 2, 4, 5，加總兩顆不同點數為 4+5=9點。

// Sample Input
// 1
// 1 1 1 1
// Sample Output
// 18

// Sample Input
// 2
// 1 2 3 4
// 1 2 3 4
// Sample Output
// 18

// Sample Input
// 2
// 1 2 3 4
// 4 3 2 1
// Sample Output
// 0