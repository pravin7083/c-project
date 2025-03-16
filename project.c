#include <stdio.h>

int main() {
    int choice, rows, cols, i, j, k, num;

    while (1) {
        // Display pattern menu
        printf("\nChoose a pattern to print:\n");
        printf("1. Rectangle (* pattern)\n");
        printf("2. Right-angled Triangle (* pattern)\n");
        printf("3. Inverted Triangle (* pattern)\n");
        printf("4. Pyramid (* pattern)\n");
        printf("5. Number Triangle\n");
        printf("6. Number Pyramid\n");
        printf("7. Floyd’s Triangle\n");
        printf("8. Diamond (* pattern)\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) { // Check valid input
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        if (choice == 9) {
            printf("Exiting the program.\n");
            break;
        }

        // Ask for number of rows
        printf("Enter the number of rows: ");
        if (scanf("%d", &rows) != 1 || rows <= 0) {
            printf("Invalid input! Rows must be a positive number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        if (choice == 1) { // Rectangle requires columns
            printf("Enter the number of columns: ");
            if (scanf("%d", &cols) != 1 || cols <= 0) {
                printf("Invalid input! Columns must be a positive number.\n");
                while (getchar() != '\n'); // Clear input buffer
                continue;
            }
        }

        printf("\n");

        // Switch-case for patterns
        switch (choice) {
            case 1: // Rectangle
                for (i = 0; i < rows; i++) {
                    for (j = 0; j < cols; j++) {
                        printf("* ");
                    }
                    printf("\n");
                }
                break;

            case 2: // Right-angled Triangle
                for (i = 1; i <= rows; i++) {
                    for (j = 0; j < i; j++) {
                        printf("* ");
                    }
                    printf("\n");
                }
                break;

            case 3: // Inverted Triangle
                for (i = rows; i > 0; i--) {
                    for (j = 0; j < i; j++) {
                        printf("* ");
                    }
                    printf("\n");
                }
                break;

            case 4: // Pyramid
                for (i = 1; i <= rows; i++) {
                    for (j = 0; j < rows - i; j++) {
                        printf("  ");
                    }
                    for (k = 0; k < (2 * i - 1); k++) {
                        printf("* ");
                    }
                    printf("\n");
                }
                break;

            case 5: // Number Triangle
                for (i = 1; i <= rows; i++) {
                    for (j = 1; j <= i; j++) {
                        printf("%d ", j);
                    }
                    printf("\n");
                }
                break;

            case 6: // Number Pyramid
                for (i = 1; i <= rows; i++) {
                    for (j = 0; j < rows - i; j++) {
                        printf("  ");
                    }
                    for (k = 1; k <= (2 * i - 1); k++) {
                        printf("%d ", k);
                    }
                    printf("\n");
                }
                break;

            case 7: // Floyd's Triangle
                num = 1; // Initialize inside case
                for (i = 1; i <= rows; i++) {
                    for (j = 1; j <= i; j++) {
                        printf("%d ", num++);
                    }
                    printf("\n");
                }
                break;

            case 8: // Diamond Pattern
                for (i = 1; i <= rows; i++) { // Upper half
                    for (j = 0; j < rows - i; j++) {
                        printf("  ");
                    }
                    for (k = 0; k < (2 * i - 1); k++) {
                        printf("* ");
                    }
                    printf("\n");
                }
                for (i = rows - 1; i > 0; i--) { // Lower half
                    for (j = 0; j < rows - i; j++) {
                        printf("  ");
                    }
                    for (k = 0; k < (2 * i - 1); k++) {
                        printf("* ");
                    }
                    printf("\n");
                }
                break;

            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}