# chapter 10 - 배열 

## 10-2 배열을 처리하는 함수 
### 코드
  
```c
#include <stdio.h>

void input_ary(double *pa, int size);
double find_max(double* pa, int size);

int main(void)
{
	double ary[5];
	double max;
	int size = sizeof(ary) / sizeof(ary[0]);
	input_ary(ary, size);
	max = find_max(ary, size);
	printf("배열의 최댓값: %1lf\n", max);

	return 0;
}

void input_ary(double* pa, int size)
{
	int i; 

	printf("%d개의 실수값 입력: ", size);
	for (i = 0; i < size; i++)
	{
		scanf_s("%lf", pa + i);
	}
}

double find_max(double* pa, int size)
{
	double max;
	int i; 

	max = pa[0];
	for (i = 1;i < size;i++)
	{
		if (pa[i] > max) max = pa[i];
	}

	return max;
}
```

### 실행 예시

```text 
5개의 실수값 입력 : 1.2 3.5  7.4 0.5 10.0
배열의 최댓값 : 10.0
```

### 배운 점

1. 배열을 함수의 매개변수로 전달하면 실제로는 배열의 시작 주소(포인터)가 전달된다.
2. `pa[i]`와 `*(pa + i)`는 같은 의미이다.
3. `sizeof(ary) / sizeof(ary[0])`를 이용하면 배열의 요소 개수를 자동으로 구할 수 있다.
4. 최댓값을 구할 때는 첫 번째 요소를 기준값으로 두고 비교하는 것이 일반적인 방법이다.

### 실수하기 쉬운 점

- 함수 안에서는 `sizeof(pa)`로 배열의 길이를 구할 수 없다.
- 함수의 매개변수 `pa`는 배열이 아니라 포인터이기 때문이다.
- 따라서 배열의 크기(`size`)를 함께 전달해야 한다.

## 추가 예제 문제( 각 달의 일수를 저장한 배열을 포인터를 이용해 5개씩 끊어서 표현하기)
```c
#include <stdio.h>

int month[12] = {
	31, 28, 31, 30, 31, 30,
	31, 31, 30, 31, 30, 31
};

void print_month(int* mo);

int main(void)
{
	print_month(month);
	return 0;
}

void print_month(int *mo)
{
	int i;
	for (i = 0; i < 12; i++)
	{
		printf("%5d", mo[i]);
		if ((i+1) % 5 ==0) printf("\n");

	}
}
```

실행예시
'''
   31   28   31   30   31
   30   31   31   30   31
   30   31
```

''' text
배운점 
1)print_month(month);에서 month는 배열이지만 함수 호출 시 첫 번째 요소의 주소가 전달된다.
2)따라서 함수는 int *mo 하나만 받아도 배열 전체를 처리할 수 있다.
3)함수 내부에서 mo[i]와 *(mo + i)는 같은 의미이다
'''
# 추가문제_ 로또 번호 입력 (배열과 함수) 문제

## 코드

```c
#include <stdio.h>

void input_nums(int *lotto_nums);
void print_nums(int *lotto_nums);

int main(void)
{
    int lotto_nums[6];

    input_nums(lotto_nums);
    print_nums(lotto_nums);

    return 0;
}

void input_nums(int *lotto_nums)
{
    int i, j;
    int duplicated;

    printf("번호 입력\n");

    for (i = 0; i < 6; i++)
    {
        do
        {
            duplicated = 0;

            printf("%d번째 번호 : ", i + 1);
            scanf_s("%d", &lotto_nums[i]);

            for (j = 0; j < i; j++)
            {
                if (lotto_nums[i] == lotto_nums[j])
                {
                    printf("같은 번호가 있습니다. 다시 입력하세요.\n");
                    duplicated = 1;
                    break;
                }
            }
        }
        while (duplicated);
    }
}

void print_nums(int *lotto_nums)
{
    int i;

    printf("입력한 번호 : ");

    for (i = 0; i < 6; i++)
    {
        printf("%d ", lotto_nums[i]);
    }

    printf("\n");
}
```

## 실행 예시

```text
번호 입력
1번째 번호 : 7
2번째 번호 : 12
3번째 번호 : 7
같은 번호가 있습니다. 다시 입력하세요.
3번째 번호 : 20
4번째 번호 : 31
5번째 번호 : 8
6번째 번호 : 45

입력한 번호 : 7 12 20 31 8 45
```

## 배운 점

1. 배열을 함수의 매개변수로 전달하면 배열의 시작 주소(포인터)가 전달된다.
2. `int *lotto_nums`를 이용하여 함수에서 배열의 모든 요소를 처리할 수 있다.
3. `lotto_nums[i]`와 `*(lotto_nums + i)`는 같은 의미이다.
4. 새로운 번호를 입력한 후 이전에 입력한 번호들과 비교하여 중복 여부를 검사할 수 있다.
5. `break`를 사용하면 중복을 발견한 즉시 반복문을 종료할 수 있다.
6. `do-while` 문은 **최소 한 번은 실행된 후 조건을 검사**하기 때문에 사용자 입력을 받을 때 자주 사용된다.

## 가장 인상 깊었던 점

`do-while` 문을 이용하면 **"일단 입력을 받고 → 검사한 뒤 → 중복이면 다시 입력"**이라는 흐름을 자연스럽게 구현할 수 있다는 점이 인상적이었다.

기존에는 `while` 문만 사용했는데, `do-while`이 사용자 입력을 처리하는 상황에 더 적합하다는 것을 이해하게 되었다.

## 실수한 점

1. `scanf_s("%d", lotto_nums[i]);`처럼 주소(`&`)를 붙이지 않아 입력이 제대로 저장되지 않았다.
2. `lotto_nums[i] == lotto_nums[i]`처럼 자기 자신과 비교하여 항상 참이 되는 코드를 작성했다.
3. 반복문을 `j = -1`부터 시작하여 배열 범위를 벗어난 접근을 할 뻔했다.
4. 중복 검사는 **입력을 받은 후** 수행해야 한다는 점을 배웠다.
