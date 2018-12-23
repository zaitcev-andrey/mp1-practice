#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define MAX_COUNT_OF_FILES 65535
#define SIZE_OF_BUFFER 2048

void Input_a(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &(a[i]));
    }
}

void Output_a(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

int ListDirectoryContents(const wchar_t *sDir, wchar_t **filesName, ULONGLONG *filesSize)
{
    WIN32_FIND_DATA fdFile;
    HANDLE hFind = NULL;
    wchar_t *sPath;
    unsigned long count = 0;

    sPath = (wchar_t*)malloc(SIZE_OF_BUFFER * sizeof(wchar_t));
    wsprintf(sPath, L"%s\\*.*", sDir);

    if ((hFind = FindFirstFile(sPath, &fdFile)) == INVALID_HANDLE_VALUE)
    {
        wprintf(L"Path not found: [%s].\n Try again: ", sDir);
        return -1;
    }

    do
    {
        if (wcscmp(fdFile.cFileName, L".") != 0 && wcscmp(fdFile.cFileName, L"..") != 0)
        {
            ULONGLONG fileSize = fdFile.nFileSizeHigh;
            fileSize <<= sizeof(fdFile.nFileSizeHigh) * 8;
            fileSize |= fdFile.nFileSizeLow;
            filesSize[count] = fileSize;

            filesName[count] = (wchar_t*)malloc(SIZE_OF_BUFFER * sizeof(wchar_t));
            wsprintf(sPath, L"%s\\%s", sDir, fdFile.cFileName);
            wsprintf(filesName[count++], L"%s", sPath);
        }
    } while (FindNextFile(hFind, &fdFile));

    FindClose(hFind);
    return count;
}

void Choose_Sort(int a[], int n)
{
    int i, j, min, min_idx;
    for (i = 0; i < n; i++)
    {
        min = a[i];
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < min)
            {
                min = a[j];
                min_idx = j;
            }
        }
        a[min_idx] = a[i];
        a[i] = min;
    }
}

void Insert_Sort(int a[], int n)
{
    int i, j, tmp;
    for (i = 1; i < n; i++)
    {
        tmp = a[i];
        j = i - 1;
        while ((j >= 0) && (a[j] > tmp))
        {
            a[j + 1] = a[j];
            a[j] = tmp;
            j--;
        }
    }
}

void Bubble_Sort(int a[], int n)
{
    int i, j, tmp;
    for (i = 0; i < n; i++)
    {
        for (j = 1; j < n - i; j++)
        {
            if (a[j - 1] > a[j])
            {
                tmp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = tmp;
            }
        }
    }
}

void Count_Sort(int a[], int n)
{
    int i, j, idx, k = 0;
    int *count;
    k = a[0];
    for (i = 1; i < n; i++)
    {
        if (a[i] > k)
        {
            k = a[i];
        }
        k++;
    }
    *count = (int *)malloc(k * sizeof(int));
    for (i = 0; i < k; i++)
    {
        count[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        *(count + a[i]) = *(count + a[i]) + 1;
        count - a[i];
    }
    idx = 0;
    for (j = 0; j < k; j++)
    {
        for (i = 0; i < count[j]; i++)
        {
            a[idx] = j;
            idx++;
        }
        count - j;
    }
}

void Quick_Split(int a[], int *i, int *j, int p)
{
    int tmp;
    do{
        while (a[(*i)] < p)
        {
            (*i)++;
        }
        while (a[(*j)] > p)
        {
            (*j)--;
        }
        if ((*i) <= (*j))
        {
            tmp = a[(*i)];
            a[(*i)] = a[(*j)];
            a[(*j)] = tmp;
        }
    }while ((*i) < (*j));
}

void Quick_Sort(int a[], int n1, int n2)
{
    int m, i, j;
    m = (n1 + n2) / 2;
    i = n1, j = n2;
    Quick_Split(a, &i, &j, a[m]);
    if (i > n1)
    {
        Quick_Sort(a, n1, i - 1);
    }
    if (j < n2)
    {
        Quick_Sort(a, j + 1, n2);
    }
}

void Merge(int *a, int left, int mid, int right)
{
    int i, j, k;
    int *c;
    i = j = 0;
    *c = (int *)malloc((right - left) * sizeof(int));
    while ((left + i < mid) && (mid + j < right))
    {
        if (a[left + i] < a[mid + j])
        {
            c[i + j] = a[left + i];
            i++;
        }
        else
        {
            c[i + j] = a[mid + j];
            j++;
        }
    }
    while (left + i < mid)
    {
        c[i + j] = a[left + i];
        i++;
    }
    while (mid + j < right)
    {
        c[i + j] = a[mid + j];
        j++;
    }
    for (k = 0; k < i + j; k++)
    {
        a[left + k] = c[k];
    }
    free(c);
}

void Merge_Sort(int a[], int left, int right)
{
    int mid, i;
    if (left + 1 >= right)
        return;
    mid = (right + left) / 2;
    Merge_Sort(a, left, mid);
    Merge_Sort(a, mid, right);
    Merge(a, left, mid, right);
}

void main()
{
    int N, choose, i;
    int a[] = {0};
    printf("Enter count of elements in array\n");
    scanf("%d", &N);
    printf("Enter array\n");
    Input_a(a, N);
    printf("Your array: ");
    Output_a(a, N);
    printf("\nChoose method of sort\n");
    printf("1)Choose Sort\n2)Insert Sort\n3)Bubble Sort\n4)Count Sort\n5)Quick Sort\n6)Merge Sort\n");
    do{
        scanf("%d", &choose);
    }while ((choose != 1) && (choose != 2) && (choose != 3) && (choose != 4) && (choose != 5) && (choose != 6));
    switch (choose)
    {
    case 1: Choose_Sort(a, N);
        break;
    case 2: Insert_Sort(a, N);
        break;
    case 3: Bubble_Sort(a, N);
        break;
    case 4: Count_Sort(a, N);
        break;
    case 5: Quick_Sort(a, 0, N - 1);
        break;
    case 6: Merge_Sort(a, 0, N);
        break;
    }
    printf("\n");
    Output_a(a, N);
}