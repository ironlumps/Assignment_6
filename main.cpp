#include <iostream>
#include "Sorting.h"
#include <fstream>
#include <chrono>

using namespace std;

int main(int argc, char** argv)
{
  if(argc > 1)
  {
    string fileName = argv[1];
    Sorting sorting;
    // Run the program
    sorting.runBubble(fileName);
    sorting.runInsertionSort(fileName);
    sorting.runQuick(fileName);
    sorting.runMerge(fileName);
  }
  else
  {
    cout << "No File Entered" << endl;
  }
}
