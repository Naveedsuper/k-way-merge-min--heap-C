#include <stdio.h>

#define K 3
#define N 12

int L1[] = {10, 30, 50, 70};
int L2[] = {20, 40, 60, 80};
int L3[] = {15, 35, 55, 75};

typedef struct {
    int value, list, index;
} Node;

Node heap[3];
int size = 0;
int heapComparisons = 0;
int pairComparisons = 0;

/* Swap two heap elements */
void swap(Node *a, Node *b) {
    Node t = *a;
    *a = *b;
    *b = t;
}

/* Insert an element into Min Heap */
void insert(Node x) {
    int i = size++;
    heap[i] = x;

    while (i > 0) {
        int p = (i - 1) / 2;
        heapComparisons++;

        if (heap[i].value >= heap[p].value)
            break;

        swap(&heap[i], &heap[p]);
        i = p;
    }
}

/* Remove the smallest element */
Node removeMin() {
    Node result = heap[0];
    heap[0] = heap[--size];

    int i = 0;

    while (size > 0) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size) {
            heapComparisons++;
            if (heap[left].value < heap[smallest].value)
                smallest = left;
        }

        if (right < size) {
            heapComparisons++;
            if (heap[right].value < heap[smallest].value)
                smallest = right;
        }

        if (smallest == i)
            break;

        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }

    return result;
}

/* Display heap values */
void showHeap() {
    printf("Heap: ");
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i].value);
    printf("\n");
}

/* K-way merge using Min Heap */
void kWayMerge() {
    int *lists[] = {L1, L2, L3};
    int result[N], count = 0;
    int len[] = {4, 4, 4};

    for (int i = 0; i < K; i++) {
        Node x = {lists[i][0], i, 0};
        insert(x);
    }

    printf("\nK-WAY MERGE\n");
    printf("Initial ");
    showHeap();

    while (size > 0) {
        Node x = removeMin();
        result[count++] = x.value;

        int next = x.index + 1;

        if (next < len[x.list]) {
            Node y = {lists[x.list][next], x.list, next};
            insert(y);
        }

        printf("Output %d | ", x.value);
        showHeap();
    }

    printf("Sorted result: ");
    for (int i = 0; i < count; i++)
        printf("%d ", result[i]);

    printf("\nHeap comparisons: %d\n", heapComparisons);
}

/* Merge two sorted arrays */
int merge(int a[], int n, int b[], int m, int out[]) {
    int i = 0, j = 0, k = 0;

    while (i < n && j < m) {
        pairComparisons++;

        if (a[i] <= b[j])
            out[k++] = a[i++];
        else
            out[k++] = b[j++];
    }

    while (i < n) out[k++] = a[i++];
    while (j < m) out[k++] = b[j++];

    return k;
}

/* Pairwise merge */
void pairwiseMerge() {
    int a[12], temp[12], count = 4;

    for (int i = 0; i < 4; i++)
        a[i] = L1[i];

    count = merge(a, count, L2, 4, temp);

    for (int i = 0; i < count; i++)
        a[i] = temp[i];

    printf("\nAfter merging L1 and L2: ");
    for (int i = 0; i < count; i++)
        printf("%d ", a[i]);

    count = merge(a, count, L3, 4, temp);

    printf("\nFinal pairwise result: ");
    for (int i = 0; i < count; i++)
        printf("%d ", temp[i]);

    printf("\nPairwise comparisons: %d\n", pairComparisons);
}

int main() {
    printf("K-WAY MERGE USING MIN HEAP VS PAIRWISE MERGE\n");

    kWayMerge();
    pairwiseMerge();

    printf("\nCOMPLEXITY\n");
    printf("Min Heap: O(N log K)\n");
    printf("Pairwise: O(NK) for sequential merging\n");

    return 0;
}
