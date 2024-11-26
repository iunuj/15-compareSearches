#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000

// ���� ���� ����
int compareCount = 0; // �� Ƚ�� ����

// ������ �迭 ���� �Լ�
void generateRandomArray(int* array) {
    for (int i = 0; i < SIZE; i++) {
        array[i] = rand() % 1000; // 0���� 999 ������ ���� ����
    }
}

// ���� Ž�� ��� �� Ƚ�� ���
float getAverageLinearSearchCompareCount(int* array) {
    int totalCompares = 0;

    for (int i = 0; i < 100; i++) { // 100�� ����
        int target = rand() % 1000; // ������ Ÿ�� ��
        int compares = 0;

        for (int j = 0; j < SIZE; j++) {
            compares++;
            if (array[j] == target) break; // ã���� �ߴ�
        }
        totalCompares += compares;
    }
    return (float)totalCompares / 100; // ��� �� Ƚ�� ��ȯ
}

// �� ���İ� �� Ƚ�� ����
void quickSort(int* array, int left, int right) {
    if (left >= right) return;

    int pivot = array[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        compareCount++; // �� Ƚ�� ����
        if (array[j] < pivot) {
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    int temp = array[i + 1];
    array[i + 1] = array[right];
    array[right] = temp;

    quickSort(array, left, i);
    quickSort(array, i + 2, right);
}

// �� ������ ȣ���ϰ� �� Ƚ�� ��ȯ
void getQuickSortCompareCount(int* array) {
    compareCount = 0; // �ʱ�ȭ
    quickSort(array, 0, SIZE - 1);
}

// ���� Ž�� ��� �� Ƚ�� ���
float getAverageBinarySearchCompareCount(int* array) {
    int totalCompares = 0;

    for (int i = 0; i < 100; i++) { // 100�� ����
        int target = rand() % 1000; // ������ Ÿ�� ��
        int left = 0, right = SIZE - 1;
        int compares = 0;

        while (left <= right) {
            compares++;
            int mid = (left + right) / 2;

            if (array[mid] == target) break; // ã���� �ߴ�
            else if (array[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        totalCompares += compares;
    }
    return (float)totalCompares / 100; // ��� �� Ƚ�� ��ȯ
}

// �迭 ���
void printArray(int* array) {
    printf("Array Sorting Result : \n");

    for (int i = 0; i < 20; i++)
        printf("%3d ", array[i]);
    printf("\n");
    for (int i = SIZE - 20; i < SIZE; i++)
        printf("%3d ", array[i]);
    printf("\n");
}

int main(int argc, char* argv[]) {
    srand(time(NULL));
    int array[SIZE];

    // �迭 ����
    generateRandomArray(array);

    // ���� Ž�� ��� �� Ƚ�� ���
    printf("Average Linear Search Compare Count : %.2f\n",
        getAverageLinearSearchCompareCount(array));

    // �� ���� �� Ƚ�� ���
    getQuickSortCompareCount(array);
    printf("Quick Sort Compare Count : %d\n", compareCount);

    // ���� Ž�� ��� �� Ƚ�� ���
    printf("Average Binary Search Compare Count : %.2f\n\n",
        getAverageBinarySearchCompareCount(array));

    // �迭 ���
    printArray(array);

    return 0;
}
