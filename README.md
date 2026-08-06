# c-language-study
collection of C programming practice examples. 

C 언어를 공부하며 인상적인 예제 코드를 저장한 저장소입니다. 

## CONTENTS 
---c
-Variables 
-Operators
-Arrays
-Pointers
-Structures
-Functions
-File I/O
-Dynamic Memory 
---

1. 배열과 포인터와의 관계

---c
#include <stdio.h>

int main(void)
{
    int ary[5] = { 10, 20, 30, 40, 50 };

    int* pa = ary;      // 배열의 첫 번째 요소를 가리킴
    int* pb = pa + 3;   // 네 번째 요소(40)를 가리킴

    int i;

    // 포인터 주소 출력 (%p 사용)
    printf("pa address : %p\n", (void*)pa);
    printf("pb address : %p\n\n", (void*)pb);

    for (i = 0; i < 3; i++)
    {
        pa++;

        // 두 포인터 사이의 요소 개수
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
---

---text
pa address : 000000FCD09BFC58
pb address : 000000FCD09BFC64

pb - pa = 2
Current value : 20

pb - pa = 1
Current value : 30

pb - pa = 0
Current value : 40
---

-예제에서 배울 점 
1) 배열명은 첫 번째 요소의 주소이다.
2) 포인터에 배열명을 저장하면 포인터를 배열명처럼 사용할 수 있다.
3) 포인터의 뺄셈 결과는 배열 요소 간의 간격 차이를 의미한다.
4) 학교에서 배울때는 %u 를 사용했지만 이는 32비트와 64비트 환경에서 포인터 크기가 다를때 오류가 생길 수 있다. 때문에 표준 c언어 환경에서는 %p 를 사용한다. 이는 포인터 전용 형식 지정자이다. 

2. double 배열과 포인터

---c
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
---

실행결과 예시
---text
0000004C228FFB68
3.5
0000004C228FFB78
0.5
7.4
2
---
배운점과 실수한점 
1. 포인터 차이인 pb-pa 는 %td 를 써야한다.
2. 주소 출력 %p 에는 (void*) 를 형변환으로 표시해줘야 한다.
3. double 은 printf 에서 %f 를 써야한다. 
