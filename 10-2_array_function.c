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
