/*
 ================ QUESTION PROMPT ===================
 Problem Introduction
 In this problem you will convert an array of integers into a heap. This is the crucial step of the sorting algorithm called HeapSort. It has guaranteed worst-case running time of π(π log π) as opposed to QuickSortβs average running time of π(π log π). QuickSort is usually used in practice, because typically it is faster, but HeapSort is used for external sort when you need to sort huge files that donβt fit into memory of your computer.
 
 Problem Description
 Task. The first step of the HeapSort algorithm is to create a heap from the array you want to sort. By the way, did you know that algorithms based on Heaps are widely used for external sort, when you need to sort huge files that donβt fit into memory of a computer?
 Your task is to implement this first step and convert a given array of integers into a heap. You will do that by applying a certain number of swaps to the array. Swap is an operation which exchanges elements ππ and ππ of the array π for some π and π. You will need to convert the array into a heap using only π(π) swaps, as was described in the lectures. Note that you will need to use a min-heap instead of a max-heap in this problem.
 
 Input Format. The first line of the input contains single integer π. The next line contains π space-separated integers ππ.
 
 Constraints. 1β€πβ€100000;0β€π,πβ€πβ1;0β€π0,π1,...,ππβ1 β€109.Allππ aredistinct.
 
 Output Format. The first line of the output should contain single integer π β the total number of swaps. π must satisfy conditions 0 β€ π β€ 4π.
 The next π lines should contain the swap operations used to convert the array π into a heap.
 Each swap is described by a pair of integers π,π β the 0-based indices of the elements to be swapped.
 After applying all the swaps in the specified order the array must become a heap, that is, for each π where 0 β€ π β€ π β 1 the following conditions must be true:
            1. If2π+1β€πβ1,then ππ <π2π+1.
            2. If2π+2β€πβ1,then ππ <π2π+2.
 Note that all the elements of the input array are distinct. Note that any sequence of swaps that has length at most 4π and after which your initial array becomes a correct heap will be graded as correct.
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> // for floor() function

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;
using namespace std;
class HeapBuilder {
 private:
    vector<int> data_;
    vector< pair<int, int> > swaps_;

    void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

    void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
  }
    //Some utility functions for heap
    int Parent(int i) {return floor(static_cast<double>(i-1)/2);} //Returns index of parent
    int LeftChild(int i) {return (2*i + 1);} // Returns left child of parent
    int RightChild(int i) {return (2*i + 2);} // Returns right child of parent
    
    // Implement the SiftDown Function
    void SiftDown(int i)
    {
        // minindex is used to store the SMALLEST value of that subtree
        int minIndex = i;
        int leftChild = LeftChild(i);
        // If left child is smaller than the element at minIndex
        if ((leftChild < data_.size()/* zero index array*/)
            && (data_[leftChild] < data_[minIndex]))
        {
            minIndex = leftChild;
        }
        int rightChild = RightChild(i);
        if ((rightChild < data_.size()) && (data_[rightChild] < data_[minIndex]))
        {
            minIndex = rightChild;
        }
        if (i != minIndex)
        {
            swaps_.push_back(make_pair(i, minIndex)); // insert at the end of the swaps vector
            swap(data_[i], data_[minIndex]); // swap the data in place
            SiftDown(minIndex); // recursively siftdown if heap structure is still violated.
        }
    }
    // This function should accept an index as input,
    void GenerateSwaps() {
      
        swaps_.clear();
        // The following naive implementation just sorts
        // the given sequence using selection sort algorithm
        // and saves the resulting sequence of swaps.
        // This turns the given array into a heap,
        // but in the worst case gives a quadratic number of swaps.
        
        // ------ MY CODE BETWEEN THE LINES ------
        for (int i = floor(static_cast<double>(data_.size())/2); i >= 0; i--)
        {
            SiftDown(i);
        }
        
        // ---------------------------------------
        /*//
    // TODO: replace by a more efficient implementation
    for (int i = 0; i < data_.size(); ++i)
      for (int j = i + 1; j < data_.size(); ++j) {
        if (data_[i] > data_[j]) {
          swap(data_[i], data_[j]);
          swaps_.push_back(make_pair(i, j));
        }
      }  */
      
  }
    
 public:
    void Solve() {
        ReadData();
        GenerateSwaps();
        WriteResponse();
    }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
