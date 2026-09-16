# 미로 탈출 - 재귀를 이용한 DFS

2차원 배열로 주어진 미로에서 `(0, 0)`부터 출발하여 출구까지 도달할 수 있는지 확인하는 프로그램입니다.

재귀 함수를 이용하여 상하좌우를 탐색하며, 이미 방문한 위치는 `visited` 배열을 이용해 다시 방문하지 않도록 구현했습니다.

## 문제 구조

- `0` : 이동할 수 있는 길
- `1` : 벽
- 시작 위치 : `(0, 0)`
- 출구 : 미로의 아래쪽 또는 오른쪽 경계
- 이동 방향 : 상, 하, 좌, 우

예시 입력:

5 5

0 1 0 0 0  
0 0 0 1 0  
1 1 0 1 0  
0 0 0 0 0  
1 1 1 1 0

## 실행 코드

```c
#include <stdio.h>

#define MAX 20

int maze[MAX][MAX];
int visited[MAX][MAX];
int n, m;

int findexit(int x, int y)
{
    // 미로 범위를 벗어난 경우
    if (x >= n || y >= m || x < 0 || y < 0)
        return 0;

    // 이미 방문한 위치인 경우
    if (visited[x][y] == 1)
        return 0;

    // 벽인 경우
    if (maze[x][y] == 1)
        return 0;

    // 현재 위치 방문 처리
    visited[x][y] = 1;

    // 출구에 도착한 경우
    if (x == n - 1 || y == m - 1)
        return 1;

    // 상하좌우 탐색
    if (findexit(x - 1, y)) return 1;
    if (findexit(x + 1, y)) return 1;
    if (findexit(x, y - 1)) return 1;
    if (findexit(x, y + 1)) return 1;

    return 0;
}

int main(void)
{
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &maze[i][j]);
        }
    }

    if (findexit(0, 0))
        printf("True");
    else
        printf("False");

    return 0;
}
```
