# Chapter 11 _ 문자

Chapter 11에서 공부하면서 인상 깊었던 코드를 정리했습니다.

## 코드

```c
#include <stdio.h>

int main(void)
{
    char ch1, ch2;

    scanf_s("%c %c", &ch1, 1, &ch2, 1);
    printf("[%c%c]", ch1, ch2);

    return 0;
}
```

## 배운점
1) 책에서의 scanf 와는 다르게 scanf_s 를 쓸 경우 &ch1 과 함께 크기도 같이 넣어줘야 한다. 
2) printf("두 문자를 입력하세요: ") 이걸 생략하고 바로 scanf_s 를 쓸수도 있다. (사용자 목적 유의)
