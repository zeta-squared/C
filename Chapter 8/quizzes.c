#include <stdio.h>

#define STUDENTS 5
#define QUIZZES 5

int main(void)
{
    double a[STUDENTS + 1][QUIZZES + 1] = {0}; // added an additional row so that index matches row index
    double student[STUDENTS + 1][2] = {0}, quiz[QUIZZES + 1][3] = {0};
    for (int i = 1; i <= STUDENTS; i++) {
        printf("Enter student %d quiz grades: ", i);
        for (int j = 1; j <= QUIZZES; j++) {
            scanf("%lf", &a[i][j]);
            student[i][0] += a[i][j];
            quiz[j][0] += a[i][j];
            if (i == 1) {
                quiz[j][1] = a[i][j];
                quiz[j][2] = a[i][j];
            }
            if (a[i][j] > quiz[j][1])
                quiz[j][1] = a[i][j];
            if (a[i][j] < quiz[j][2])
                quiz[j][2] = a[i][j];
        }
    }

    printf("\n");
    for (int i = 1; i <= STUDENTS; i++) {
        student[i][1] += student[i][0] / ((double) STUDENTS);
        quiz[i][0] /= ((double) QUIZZES);
        printf("Student %d (total/average):\n");
        printf("\t%.2lf/%.2lf\n",
               i, student[i][0], student[i][1]);
    }
    for (int j = 1; j <= QUIZZES; j++) {
        printf("Quiz %d (average/highest/lowest):\n");
        printf("\t%.2lf/%.2lf/%.2lf\n",
                j, quiz[j][0], quiz[j][1], quiz[j][2]);
    }

    return 0;
}
