```c

#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

struct student {
    int number;
    char name[50];
    double grade;
};

int main(void)
{
    struct student students[MAX_STUDENTS];

    int count = 0;
    int found = 0;
    char command;
    char search_name[50];

    while (count < MAX_STUDENTS)
    {
        printf("\n학번 이름 학점을 입력하세요: ");

        scanf_s("%d %49s %lf",
            &students[count].number,
            students[count].name,
            (unsigned)sizeof(students[count].name),
            &students[count].grade);

        count++;

        printf("계속 입력하려면 아무 키나, 검색하려면 Q를 누르세요: ");
        scanf_s(" %c", &command, 1);

        if (command == 'Q' || command == 'q')
        {
            break;
        }
    }

    printf("\n찾을 이름을 입력하세요: ");
    scanf_s("%49s", search_name, (unsigned)sizeof(search_name));

    for (int i = 0; i < count; i++)
    {
        if (strcmp(students[i].name, search_name) == 0)
        {
            printf("\n학생을 찾았습니다.\n");
            printf("학번: %d\n", students[i].number);
            printf("학점: %.1f\n", students[i].grade);

            found = 1;
        }
    }

    if (found == 0)
    {
        printf("\n해당 이름의 학생을 찾을 수 없습니다.\n");
    }

    return 0;
}

```c
