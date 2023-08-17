#include <cstdio>
#include <stdio.h>
void swap(int tree[], int c1, int c2) {
  int tmp = tree[c1];
  tree[c1] = tree[c2];
  tree[c2] = tmp;
}
void heapify(int tree[], int n, int i) {
  if (i >= n) return;

  int c1 = 2 * i + 1;
  int c2 = 2 * i + 2;
  int max = i;
  if (c1 < n && tree[c1] > tree[max]) {
    max = c1;
  }
  if (c1 < n && tree[c2] > tree[max]) {
    max = c2;
  }
  if (max != i) {
    swap(tree, max, i);
    heapify(tree, n, max);
  }
}
void build_heap(int tree[], int n) {
  int last_node = n - 1;
  int parent = (last_node - 1) / 2;
  for (int i = parent; i >= 0; --i) {
    heapify(tree, n, i);
  }
}
void heap_sort(int tree[], int n) {
  for (int last_node = n - 1; last_node >= 0; --last_node) {
    swap(tree, 0, last_node);
    heapify(tree, last_node, 0);
  }
}
int main() {
  int tree[] = {4, 10, 3, 5, 1, 2};
  heapify(tree, 6, 0);
  for (int i = 0; i < 6; ++i) {
    printf("%d\n", tree[i]);
  }
  int tree2[] = {2, 5, 3, 1, 10, 4};
  build_heap(tree2, 6);
  for (int i = 0; i < 6; ++i) {
    printf("%d\n", tree2[i]);
  }
  heap_sort(tree, 6);
  for (int i = 0; i < 6; ++i) {
    printf("%d\n", tree[i]);
  }

  return 0;
}
