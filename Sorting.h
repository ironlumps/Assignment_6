#include <iostream>

using namespace std;

class Sorting
{
public:
  Sorting();
  Sorting(int newSize);
  ~Sorting();
  bool isFull();
  double* copyArray(double array[], int size);

  void BubbleSort(double array[], int size);
  void runBubble(string fileName);

  void InsertionSort(double array[], int size);
  void runInsertionSort(string fileName);

  void QuickSort(double array[], int left, int right);
  void runQuick(string fileName);

  void MergeSort(double array[], int p, int r);
  void Merge(double array[], int p, int q, int r);
  void runMerge(string fileName);

  int numElements;
  int tempSize;
  double bArray[];
  double iArray[];
  double qArray[];
  double mArray[];
};
