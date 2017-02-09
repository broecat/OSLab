#include <stdio.h>
#include<string.h>
#include<ctype.h>
#include <stdlib.h>

struct Student{
    char name[50];
    float GPA;
};

int compare (const void *a, const void *b)
{
    struct Student *A = (struct Student *)a;
    struct Student *B = (struct Student *)b;
   return (int)(100.0*A->GPA - 100.0*B->GPA);
}

int main(void) {
	
    struct Student students[20];

    int amount;
    printf("Please enter the amount of students in the class:\n");
    scanf("%d",&amount);

    for(int i=1;i<=amount;i++)
    {
        float temp;
        printf("Please enter the name of student %d:\n",i);
        scanf("%s",students[i-1].name);
        printf("Please enter the GPA of student %d:\n",i);
        scanf("%f",&temp);
        students[i-1].GPA=temp;
    }

    qsort(students, amount, sizeof(struct Student), compare);

    for(int i=1;i<=amount;i++)
    {
        printf("%d. Name: %s    GPA: %f\n",i,students[i-1].name,students[i-1].GPA);
    }

	return 0;
}
