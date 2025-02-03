#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// Function to check if a number is already in the set (using array for simplicity)
bool is_in_set(double num, double set[], int set_size) {
    for (int i = 0; i < set_size; i++) {
        if (set[i] == num) {
            return true;
        }
    }
    return false;
}

int main() {
    int min_a, max_a, min_b, max_b;

    // Read input range from keyboard (Task 2)
    printf("Enter minimum value for a: ");
    scanf("%d", &min_a);
    printf("Enter maximum value for a: ");
    scanf("%d", &max_a);
    printf("Enter minimum value for b: ");
    scanf("%d", &min_b);
    printf("Enter maximum value for b: ");
    scanf("%d", &max_b);

    double set[100000]; // Large enough array to store potential values
    int set_size = 0;

    for (int a = min_a; a <= max_a; a++) {
        for (int b = min_b; b <= max_b; b++) {
            double result = pow(a, b);
            if (!is_in_set(result, set, set_size)) {
                set[set_size++] = result;
            }
        }
    }

    printf("Number of distinct terms: %d\n", set_size);

    return 0;
}
