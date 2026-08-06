

````markdown
# C Language Study

Collection of C programming practice examples.

C 언어를 공부하며 인상적인 예제 코드와 학습 내용을 정리한 저장소입니다.

## Contents

- Variables
- Operators
- Arrays
- Pointers
- Structures
- Functions
- File I/O
- Dynamic Memory

---

## 1. 배열과 포인터의 관계

### 코드

```c 
#include <stdio.h>

int main(void)
{
    int ary[5] = {10, 20, 30, 40, 50};

    int *pa = ary;      // 배열의 첫 번째 요소를 가리킴
    int *pb = pa + 3;   // 네 번째 요소인 ary[3]을 가리킴

    int i;

    printf("pa address : %p\n", (void *)pa);
    printf("pb address : %p\n\n", (void *)pb);

    for (i = 0; i < 3; i++)
    {
        pa++;

        printf("pb - pa = %td\n", pb - pa);
        printf("Current value : ");

        if (pa < pb)
            printf("%d\n", *pa);
        else
            printf("%d\n", *pb);

        printf("\n");
    }

    return 0;
}
```
## 실행 결과 예시

```text
pa address : 000000FCD09BFC58
pb address : 000000FCD09BFC64

pb - pa = 2
Current value : 20

pb - pa = 1
Current value : 30

pb - pa = 0
Current value : 40
```

> **참고:** 메모리 주소는 실행 환경에 따라 달라질 수 있습니다.

## 배운 점

1. 배열 이름은 대부분의 표현식에서 첫 번째 요소를 가리키는 포인터로 변환된다.
2. 포인터에 배열의 시작 주소를 저장하면 배열처럼 사용할 수 있다.
3. 포인터의 뺄셈 결과는 바이트 수가 아니라 배열 요소 간의 거리이다.
4. 포인터 주소를 출력할 때는 `%p`를 사용하는 것이 표준 C 방식이다.
5. `pb - pa`의 반환형은 `ptrdiff_t`이므로 `%td`를 사용하여 출력한다.

---

# 2. double 배열과 포인터

## 코드

```c
#include <stdio.h>

int main(void)
{
    double ary[5] = {1.2, 3.5, 7.4, 0.5, 10.0};

    double *pa = ary;
    double *pb = ary + 2;

    printf("%p\n", (void *)ary);
    printf("%.1f\n", *(ary + 1));
    printf("%p\n", (void *)(pa + 2));
    printf("%.1f\n", pa[3]);
    printf("%.1f\n", *pb);
    printf("%td\n", pb - pa);

    return 0;
}
```

## 실행 결과 예시

```text
0000004C228FFB68
3.5
0000004C228FFB78
0.5
7.4
2
```

> **참고:** 메모리 주소는 실행 환경에 따라 달라질 수 있습니다.

## 배운 점

1. `ary + 1`은 `ary[1]`의 주소를 의미한다.
2. `*(ary + 1)`은 `ary[1]`과 같은 의미이며 값은 `3.5`이다.
3. `pa[3]`은 `*(pa + 3)`과 동일한 표현이다.
4. `pb`는 `ary + 2`를 가리키므로 `*pb`의 값은 `7.4`이다.
5. `pb - pa`는 주소 차이가 아니라 배열 요소의 개수를 반환한다.

## 실수한 점

1. 처음에는 `double` 값을 `%d`로 출력하려고 했다.
2. 주소 출력 %p 에는 (void*) 를 형변환으로 표시해줘야 한다.
3. double 은 printf 에서 %f 를 써야한다. 
