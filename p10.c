#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void swap(int a[], int i, int j)
{
    int temp;
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int partition(int a[], int l, int r)
{
    int i, j;
    int p;
    p = a[l];
    i = l;
    j = r + 1;

    do
    {
        do { i++; } while (i <= r && a[i] < p);
        do { j--; } while (a[j] > p);
        
        if (i < j)
            swap(a, i, j);

    } while (i < j);

    swap(a, l, j);

    return j;
}

void quicksort(int a[], int l, int r)
{
    int s;
    if (l < r)
    {
        s = partition(a, l, r);
        quicksort(a, l, s - 1);
        quicksort(a, s + 1, r);
    }
}

int main()
{
    int i, n, a[100000], choice;
    clock_t t;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("1. Read from file\n2. Random numbers\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("Reading numbers from file 'data.txt'\n");
        FILE *file = fopen("data.txt", "r");

        if (file == NULL)
        {
            printf("Error: Cannot open file.\n");
            return 1;
        }

        i = 0;
        while (i < n && fscanf(file, "%d", &a[i]) == 1)
        {
            printf("%d\n", a[i]);
            i++;
        }
        fclose(file);
        break;

    case 2:
        printf("Generating random numbers:\n");
        srand(time(NULL));
        for (i = 0; i < n; i++)
        {
            a[i] = rand() % 1000;
            printf("%d\n", a[i]);
        }
        break;

    default:
        printf("Invalid choice.\n");
        return 1;
    }

    t = clock();
    quicksort(a, 0, n - 1);
    t = clock() - t;

    printf("Numbers after sorting:\n");
    for (i = 0; i < n; i++)
        printf("%d\n", a[i]);

    double time_taken = ((double)t) / CLOCKS_PER_SEC;
    printf("Sort function took %f seconds to execute.\n", time_taken);

    return 0;
}
