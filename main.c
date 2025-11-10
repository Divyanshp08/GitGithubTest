#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBERS 10

void inputNumbers(int arr[], int *n)
{
    printf("How many numbers (max %d)? ", MAX_NUMBERS);
    // Note: It's good practice to check the return value of scanf for robustness,
    // but keeping it simple for this fix.
    scanf("%d", n);
    if (*n > MAX_NUMBERS || *n < 1)
    {
        printf("Invalid count! Please enter a number between 1 and %d.\n", MAX_NUMBERS);
        *n = 0;
        return;
    }
    printf("Enter %d numbers:\n", *n);
    for (int i = 0; i < *n; i++)
    {
        // Another good practice: check scanf return value here too.
        scanf("%d", &arr[i]);
    }
}

/**
 * Fix 1: The loop condition was 'i > n', which is false initially (i=0, n>0),
 * so the loop never executed. Changed to 'i < n'.
 */
int sumArray(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

/**
 * Fix 2: The division 'sum / n' performs integer division since both 'sum' (int) 
 * and 'n' (int) are integers. To get a floating-point average, one of them
 * must be explicitly cast to a float before division.
 */
float averageArray(int arr[], int n)
{
    // Re-calculating sum here for simplicity, but calling sumArray is also fine.
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    // Cast 'sum' to float to ensure floating-point division
    return (float)sum / n; 
}

int findMin(int arr[], int n)
{
    // Add check for n > 0 to prevent accessing arr[0] on an empty array,
    // although inputNumbers handles n=0 and main() checks for it.
    if (n <= 0) return 0; // Or some error indicator
    
    int min = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}

int findMax(int arr[], int n)
{
    // Add check for n > 0
    if (n <= 0) return 0; // Or some error indicator
    
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

int main()
{
    int numbers[MAX_NUMBERS];
    int n;

    inputNumbers(numbers, &n);
    if (n == 0)
    {
        printf("No valid numbers entered. Exiting.\n");
        return 1;
    }

    // Now uses the corrected sumArray and averageArray functions
    printf("Sum: %d\n", sumArray(numbers, n));
    printf("Average: %.2f\n", averageArray(numbers, n));
    printf("Minimum: %d\n", findMin(numbers, n));
    printf("Maximum: %d\n", findMax(numbers, n));

    return 0;
}