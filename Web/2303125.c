#include <stdio.h>
#include <stdlib.h>

// 최소 힙 구조체 정의
typedef struct {
    int *arr;  // 배열 포인터
    int capacity;  // 힙의 최대 크기
    int size;  // 현재 힙의 크기
} MinHeap;

// 최소 힙 초기화 함수
MinHeap* createMinHeap(int capacity) {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->arr = (int*)malloc(sizeof(int) * capacity);
    minHeap->capacity = capacity;
    minHeap->size = 0;
    return minHeap;
}

// 두 노드의 위치를 바꿔주는 함수
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 최소 힙의 노드를 올바른 위치로 이동시키는 함수 (Heapify)
void heapify(MinHeap* minHeap, int idx) {
    int smallest = idx;
    int leftChild = 2 * idx + 1;
    int rightChild = 2 * idx + 2;

    // 왼쪽 자식이 현재 노드보다 작으면 smallest를 업데이트
    if (leftChild < minHeap->size && minHeap->arr[leftChild] < minHeap->arr[smallest])
        smallest = leftChild;

    // 오른쪽 자식이 현재 노드보다 작으면 smallest를 업데이트
    if (rightChild < minHeap->size && minHeap->arr[rightChild] < minHeap->arr[smallest])
        smallest = rightChild;

    // 현재 노드가 가장 작지 않다면 위치를 교환하고 재귀적으로 heapify 호출
    if (smallest != idx) {
        swap(&minHeap->arr[idx], &minHeap->arr[smallest]);
        heapify(minHeap, smallest);
    }
}

// 최소 힙에 요소 추가
void insert(MinHeap* minHeap, int val) {
    if (minHeap->size == minHeap->capacity) {
        printf("Heap is full. Cannot insert.\n");
        return;
    }

    // 노드를 힙의 맨 끝에 추가
    int i = minHeap->size;
    minHeap->arr[i] = val;
    minHeap->size++;

    // 부모 노드와 비교하면서 올바른 위치로 이동
    while (i > 0 && minHeap->arr[i] < minHeap->arr[(i - 1) / 2]) {
        swap(&minHeap->arr[i], &minHeap->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// 최소 힙에서 최솟값을 반환하고 삭제
int extractMin(MinHeap* minHeap) {
    if (minHeap->size == 0) {
        printf("Heap is empty. Cannot extract.\n");
        return -1;
    }

    // 최솟값은 항상 루트에 위치
    int root = minHeap->arr[0];

    // 루트에 맨 끝 노드의 값을 넣고 힙 크기를 줄임
    minHeap->arr[0] = minHeap->arr[minHeap->size - 1];
    minHeap->size--;

    // 힙을 재정렬
    heapify(minHeap, 0);

    return root;
}

// 최소 힙에서 최솟값을 반환 (삭제하지 않음)
int getMin(MinHeap* minHeap) {
    if (minHeap->size == 0) {
        printf("Heap is empty. Cannot get minimum.\n");
        return -1;
    }
    return minHeap->arr[0];
}

int main() {
    MinHeap* minHeap = createMinHeap(10);

    insert(minHeap, 4);
    insert(minHeap, 8);
    insert(minHeap, 2);
    insert(minHeap, 5);

    printf("Minimum value: %d\n", getMin(minHeap));  // Output: 2

    extractMin(minHeap);

    printf("Minimum value after extraction: %d\n", getMin(minHeap));  // Output: 4

    free(minHeap->arr);
    free(minHeap);

    return 0;
}


