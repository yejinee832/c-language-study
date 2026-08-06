# c-language-study
collection of C programming practice examples. 

C 언어를 공부하며 인상적인 예제 코드를 저장한 저장소입니다. 

## CONTENTS 

-Variables 
-Operators
-Arrays
-Pointers
-Structures
-Functions
-File I/O
-Dynamic Memory 

1. 배열과 포인터와의 관계

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

-실행결과예시
pa address : 000000FCD09BFC58
pb address : 000000FCD09BFC64

pb - pa = 2
Current value : 20

pb - pa = 1
Current value : 30

pb - pa = 0
Current value : 40

-예제에서 배울 점 
1) 배열명은 첫 번째 요소의 주소이다.
2) 포인터에 배열명을 저장하면 포인터를 배열명처럼 사용할 수 있다.
3) 포인터의 뺄셈 결과는 배열 요소 간의 간격 차이를 의미한다.
4) 학교에서 배울때는 %u 를 사용했지만 이는 32비트와 64비트 환경에서 포인터 크기가 다를때 오류가 생길 수 있다. 때문에 표준 c언어 환경에서는 %p 를 사용한다. 이는 포인터 전용 형식 지정자이다. 
