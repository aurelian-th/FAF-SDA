#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

// Function to check if a number is already in the set (using dynamic array)
bool is_in_set_ptr(double num, double *set, int *set_size) {
    for (int i = 0; i < *set_size; i++) {
        if (*(set + i) == num) {
            return true;
        }
    }
    return false;
}

//Function to add an element to the set
void add_to_set(double num, double **set, int *set_size, int *set_capacity) {
  if (!is_in_set_ptr(num, *set, set_size)) {
    if (*set_size == *set_capacity) {
      *set_capacity *= 2;
      *set = realloc(*set, *set_capacity * sizeof(double));
    }
    *(*set + *set_size) = num;
    (*set_size)++;
  }
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
    
    int set_capacity = 100;
    double *set = malloc(set_capacity * sizeof(double));
    int set_size = 0;

    for (int a = min_a; a <= max_a; a++) {
        for (int b = min_b; b <= max_b; b++) {
            double result = pow(a, b);
            add_to_set(result, &set, &set_size, &set_capacity);
        }
    }

    printf("Number of distinct terms: %d\n", set_size);
    
    free(set);

    return 0;
}
