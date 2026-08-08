# Chapter 11 _ 문자

Chapter 11에서 공부하면서 인상 깊었던 코드를 정리했습니다.

## 코드_scanf_s 유의점 _크기 입력 

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

## 코드_ putchar(), getchar() 함수

```c
#include <stdio.h>

int main(void)
{
    int ch;

    ch = getchar();
    printf("입력한 문자: ");
    putchar(ch);
    putchar('\n');

    return 0;
}

## 배운점 
1) getchar 함수는 문자 상수나 문자의 아스키 코드 값을 인수로 주면 해당 문자를 화면에 출력한다. 
    그리고 출력한 문자를 다시 반환하며, 에러가 발생할시 -1 를 반환한다. 때문에 int 형이다. 

2) 입력은 int ch; ch = getchar(); 로 받고 출력은 printf("%c", ch); putchar(ch); 이다. 

# 11-2 버퍼를 사용하는 입력 함수 ⭐ 

버퍼는 프로그램에서 직접 할당하는 것이 아니라, 프로그램을 실행하는 중에 운영체제가 자동으로 할당하는 메모리의 저장 공간이다. 
키보드로 입력하는 데이터는 일단 버퍼에 저장된 후 scanf 함수에 의해 변수에 저장된다. 
    
## 코드 
    
```c
#include <stdio.h>

int main(void)
{
    char ch[100];
    int input_num;
    int output_num;
    int i;

    printf("입력받을 문자의 개수를 입력하세요: ");
    scanf_s("%d", &input_num);

    // 엔터 제거
    getchar();

    printf("%d개의 문자를 입력하세요: ", input_num);

    for (i = 0; i < input_num; i++)
    {
        scanf_s("%c", &ch[i], 1);
    }

    printf("출력하고 싶은 문자의 개수를 입력하세요: ");
    scanf_s("%d", &output_num);

    while (output_num > input_num)
    {
        printf("입력받은 문자보다 많습니다.\n");
        printf("다시 입력하세요: ");
        scanf_s("%d", &output_num);
    }

    printf("출력: ");

    for (i = 0; i < output_num; i++)
    {
        printf("%c", ch[i]);
    }

    return 0;
}

```

##실행결과 
입력받을 문자의 개수를 입력하세요: 5
5개의 문자를 입력하세요: apple
출력하고 싶은 문자의 개수를 입력하세요: 3
출력: app

## getchar 함수를 사용한 문자열 입력
```c
#include <stdio.h>

void my_gets(char* str, int size);

int main(void)
{
	char str[7];

	my_gets(str, sizeof(str));
	printf("입력한 문자열: %s \n", str);

	return 0; 
}

void my_gets(char* str, int size)
{
	int ch;
	int i = 0;

	ch = getchar();
	while ((ch != '\n') && (i < size - 1))
	{
		str[i] = ch;
		i++;
		ch = getchar();
	}
	str[i] = '\0';
}
```
void my_gets(char *str, int size) 설명 
: while 구문을 보면 엔터를 누르지 않았거나 i 가 배열의 크기보다 작다면 str[i] 를 ch 에 저장하고 
i 를 1씩 증가시키고 그 값을 출력한다. 
    
## 코드

```c
#include <stdio.h>

int main(void)
{
    int num;
    double grade;

    printf("학번 입력: ");
    scanf_s("%d", &num);

    printf("학점 입력: ");
    scanf_s("%lf", &grade);

    printf("학번: %d, 학점: %.1f", num, grade);

    return 0;
}
```

## 배운 점

1. `getchar()`로 `3.5`를 입력받으려고 했지만, `getchar()`는 **문자 하나만 읽는 함수**이므로 실수 입력에는 적합하지 않다.

2. 학점을 처음에 `int`로 선언했지만, `3.5`처럼 소수점이 있는 값은 `double`로 선언해야 한다.

3. `scanf_s("%.1f", &grade)`로 작성했더니 입력이 되지 않았다.
   - `double` 입력 → `%lf`
   - 소수점 한 자리 출력 → `%.1f`

> ⭐ `scanf_s()` 뒤에 항상 `getchar()`가 필요한 것은 아니다. 다음에 `%c`로 문자를 입력받는 경우처럼 `\n` 처리가 필요할 때 사용한다.
