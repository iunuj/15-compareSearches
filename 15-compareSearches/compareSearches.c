#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000

// 전역 변수 선언
int compareCount = 0; // 비교 횟수 저장

// 임의의 배열 생성 함수
void generateRandomArray(int* array) {
    for (int i = 0; i < SIZE; i++) {
        array[i] = rand() % 1000; // 0부터 999 사이의 숫자 저장
    }
}

// 순차 탐색 평균 비교 횟수 계산
float getAverageLinearSearchCompareCount(int* array) {
    int totalCompares = 0;

    for (int i = 0; i < 100; i++) { // 100번 실행
        int target = rand() % 1000; // 임의의 타겟 값
        int compares = 0;

        for (int j = 0; j < SIZE; j++) {
            compares++;
            if (array[j] == target) break; // 찾으면 중단
        }
        totalCompares += compares;
    }
    return (float)totalCompares / 100; // 평균 비교 횟수 반환
}

// 퀵 정렬과 비교 횟수 추적
void quickSort(int* array, int left, int right) {
    if (left >= right) return;

    int pivot = array[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        compareCount++; // 비교 횟수 증가
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

// 퀵 정렬을 호출하고 비교 횟수 반환
void getQuickSortCompareCount(int* array) {
    compareCount = 0; // 초기화
    quickSort(array, 0, SIZE - 1);
}

// 이진 탐색 평균 비교 횟수 계산
float getAverageBinarySearchCompareCount(int* array) {
    int totalCompares = 0;

    for (int i = 0; i < 100; i++) { // 100번 실행
        int target = rand() % 1000; // 임의의 타겟 값
        int left = 0, right = SIZE - 1;
        int compares = 0;

        while (left <= right) {
            compares++;
            int mid = (left + right) / 2;

            if (array[mid] == target) break; // 찾으면 중단
            else if (array[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        totalCompares += compares;
    }
    return (float)totalCompares / 100; // 평균 비교 횟수 반환
}

// 배열 출력
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

    // 배열 생성
    generateRandomArray(array);

    // 순차 탐색 평균 비교 횟수 출력
    printf("Average Linear Search Compare Count : %.2f\n",
        getAverageLinearSearchCompareCount(array));

    // 퀵 정렬 비교 횟수 출력
    getQuickSortCompareCount(array);
    printf("Quick Sort Compare Count : %d\n", compareCount);

    // 이진 탐색 평균 비교 횟수 출력
    printf("Average Binary Search Compare Count : %.2f\n\n",
        getAverageBinarySearchCompareCount(array));

    // 배열 출력
    printArray(array);

    return 0;
}
