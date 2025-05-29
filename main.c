#include <stdio.h>
#include <ctype.h>

#define STUDENTS 5
#define TESTS 13
#define NAME_LEN 11

// Function to capitalize the first letter of a name
void capitalize(char *name) {
    name[0] = toupper(name[0]);
    for (int i = 1; name[i] != '\0'; i++) {
        name[i] = tolower(name[i]);
    }
}

int main() {
    char names[STUDENTS][NAME_LEN];
    int scores[STUDENTS][TESTS];
    float averages[STUDENTS];
    float total_sum = 0.0;

    // Instructions for the user
    printf("Enter 5 student names followed by 13 scores each:\n");

    // Input
    for (int i = 0; i < STUDENTS; i++) {
        scanf("%s", names[i]);
        int sum = 0;
        for (int j = 0; j < TESTS; j++) {
            scanf("%d", &scores[i][j]);
            sum += scores[i][j];
        }
        averages[i] = sum / (float)TESTS;
        total_sum += averages[i];
    }

    // Find student with highest average
    int highest_index = 0;
    for (int i = 1; i < STUDENTS; i++) {
        if (averages[i] > averages[highest_index]) {
            highest_index = i;
        }
    }

    // Print highest scoring student
    capitalize(names[highest_index]);
    printf("\nTop Student: %s\n", names[highest_index]);

    // Compute total average
    float total_avg = total_sum / STUDENTS;

    // Print students with below-average scores
    printf("Below Average Students:\n");
    for (int i = 0; i < STUDENTS; i++) {
        if (averages[i] < total_avg) {
            capitalize(names[i]);
            printf("%s\n", names[i]);
        }
    }

    return 0;
}