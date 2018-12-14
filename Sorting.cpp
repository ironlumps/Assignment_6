#include "Sorting.h"
#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;

Sorting::Sorting()
{
  tempSize = 100;
}

Sorting::Sorting(int newSize)
{
  tempSize = newSize;
}

Sorting::~Sorting()
{

}

// Used to copy the array, but didn't end up getting used
double* Sorting::copyArray(double array[], int newSize)
{
  double tempArray[newSize];

  std::copy(array, array + tempSize, tempArray);

  return tempArray;
}

bool Sorting::isFull()
{
  return(numElements == tempSize);
}

void Sorting::BubbleSort(double array[], int size)
{
  // Iterates through the array and the index next to it and compares the 2
  for(int i = 0; i < size; i++)
  {
    double temp = 0;
    for(int j = i; i < size - 1; j++)
    {
      if(array[j] > array[j + 1])
      {
        // If they need to be swapped this swaps them
        temp = array[j + 1];
        array[j + 1] = array[i];
        array[i] = temp;
      }
    }

    numElements++;
  }
}
// Runs the bubble sort method
void Sorting::runBubble(string fileName)
{
  // Reads in file
  ifstream readfile(fileName);

  if(readfile.good())
  {
    string line;
    // gets size from first line of file
    getline(readfile, line);
    int size = stoi(line);
    int i = 0;
    double array[size];

    // reads the rest of the file and fills in array
    while(getline(readfile, line))
    {
      double tempNum = stod(line);
      array[i] = tempNum;
      i++;
    }

    // gets time in milliseconds
    __int64_t now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

    cout << "TimeStart: " << now << endl;
    //BubbleSort
    BubbleSort(array, size);
    now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    cout << "TimeEnd: " << now << endl;
    cout << endl;

    delete array;
  }
}

void Sorting::InsertionSort(double array[], int size)
{
  // iterates through the array
  for(int j = 1; j < size; j++)
  {
    double temp = array[j];
    int k = j;
    // if the data is partially sorted, does not enter this while loop
    while(k > 0 && array[k-1] >= temp)
    {
      array[j] == array[k-1];
      numElements++;
      k--;
    }
    array[k] = temp;
  }
}
// Runs InsertionSort method
void Sorting::runInsertionSort(string fileName)
{
  // Reads in file
  ifstream readfile(fileName);

  if(readfile.good())
  {
    string line;
    // gets size from first line of file
    getline(readfile, line);
    int size = stoi(line);
    int i = 0;
    double array[size];

    // reads in rest of the file into array
    while(getline(readfile, line))
    {
      double tempNum = stod(line);
      array[i] = tempNum;
      i++;
    }

    // gets time in milliseconds
    __int64_t now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

    cout << "TimeStart: " << now << endl;
    //InsertionSort
    InsertionSort(array, size);
    now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    cout << "TimeEnd: " << now << endl;
    cout << endl;

    delete array;
  }
}

void Sorting::QuickSort(double array[], int left, int right)
{
  // creates pivot point
  int i = left;
  int j = right;
  int tmp;
  int pivot = array[(left + right) / 2];

  /* partition */

  while (i <= j)
  {
    while (array[i] < pivot)
    {
      i++;
    }
    while (array[j] > pivot)
    {
      j--;
    }
    if (i <= j)
    {
      tmp = array[i];
      array[i] = array[j];
      array[j] = tmp;
      i++;
      j--;
    }
  }
  /* recursion */
  if (left < j)
  {
    QuickSort(array, left, j);
  }
  if (i < right)
  {
    QuickSort(array, i, right);
  }
}
// Runs quick sort method
void Sorting::runQuick(string fileName)
{
  // reads in file
  ifstream readfile(fileName);

  if(readfile.good())
  {
    string line;
    // gets size from first line of file
    getline(readfile, line);
    int size = stoi(line);
    int i = 0;
    double array[size];

    // reads in rest of file into array
    while(getline(readfile, line))
    {
      double tempNum = stod(line);
      array[i] = tempNum;
      i++;
    }

    // gets time in milliseconds
    __int64_t now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

    cout << "TimeStart: " << now << endl;
    //QuickSort
    QuickSort(array, 0, 0);
    now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    cout << "TimeEnd: " << now << endl;
    cout << endl;

    delete array;
  }
}
// method used to just merge the different arrays that are formed from the merge split
void Sorting::Merge(double array[], int p, int q, int r)
{
  int leftSize = q - p + 1;
  int rightSize = r - q;

  double left[leftSize];
  double right[rightSize];

  // fills in left array
  for(int i = 0; i < leftSize; i++)
  {
    left[i] = array[p + i];
  }

  // fills in right array
  for(int j = 0; j < rightSize; j++)
  {
    right[j] = array[q + j + 1];
  }

  int i = 0;
  int j = 0;
  int k = p;

  // creates the indices of the merge
  for(k = p; i < leftSize && j < rightSize; k++)
  {
    if(left[i] < right[j])
    {
      array[k] = left[i++];
    }
    else
    {
      array[k] = right[j++];
    }
  }
  while(i < leftSize)
  {
    array[k++] = left[i++];
  }
  while(j < rightSize)
  {
    array[k++] = right[j++];
  }

}

void Sorting::MergeSort(double array[], int p, int r)
{
  int q = 0;
  if(p < r)
  {
    // runs the recursion of merge sort
    q = (p + r)/2;
    MergeSort(array, p, q);
    MergeSort(array, q + 1, r);
    Merge(array, p, q, r);
  }
}

// runs merge sort method
void Sorting::runMerge(string fileName)
{
  // reads in file
  ifstream readfile(fileName);
  if(readfile.good())
  {
    string line;
    // gets size from first line of file
    getline(readfile, line);
    int size = stoi(line);
    int i = 0;
    double array[size];

    // reads in the rest of file into array
    while(getline(readfile, line))
    {
      double tempNum = stod(line);
      array[i] = tempNum;
      i++;
    }
    // gets time in milliseconds
    __int64_t now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

    cout << "TimeStart: " << now << endl;
    //MergeSort
    MergeSort(array, 0, 0);
    now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    cout << "TimeEnd: " << now << endl;
    cout << endl;

    delete array;
  }
}
