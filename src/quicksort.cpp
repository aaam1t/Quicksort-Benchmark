#include <iostream>
#include <vector>
#include <utility>
#include "quicksort.hpp"

// shorten the name so we don't have to
// write the namespace Quicksort::vecIter
using vecIter = Quicksort::vecIter;

// Lomuto Partition as given in lecture 4.7
vecIter lomutoPartition(vecIter begin, vecIter end) {
  vecIter leftEnd = begin + 1;
  for (vecIter j = begin + 1; j < end; ++j) {
    if (*j <= *begin) {
      std::swap(*leftEnd, *j);
      ++leftEnd;
    }
  }
  std::swap(*begin, *(leftEnd-1));
  return leftEnd - 1;
}

// basic quicksort using Lomuto Partition
void Quicksort::basic(vecIter begin, vecIter end) {
  if (end - begin <= 1) {
    return;
  }
  vecIter pivotIt = lomutoPartition(begin, end);
  basic(begin, pivotIt);
  basic(pivotIt + 1, end);
}

// based on lecture 3 notes
void insertionSort(vecIter begin, vecIter end) {
  int temp;
  vecIter j;
  for (vecIter i = begin + 1; i < end; i++) {
    temp = *i;
    for (j = i - 1; temp < *j && j >= begin; j--) {
      *(j + 1) = *j;
    }
    *(j + 1) = temp;
  }
}

void Quicksort::insertionSortBaseCase(vecIter begin, vecIter end) {
  if (end - begin <= 10) {
    insertionSort(begin, end);
    return;
  }
  vecIter pivotIt = lomutoPartition(begin, end);
  insertionSortBaseCase(begin, pivotIt);
  insertionSortBaseCase(pivotIt + 1, end);
}

void Quicksort::median3InsertionSortBaseCase(vecIter begin, vecIter end) {
  if (end - begin <= 10) {
    insertionSort(begin, end);
    return;
  }

  vecIter mid = begin + (end - begin) / 2;
  if ((*mid > *begin) ^ (*mid > *(end - 1))) {
    std::swap(*begin, *mid);
  }
  else if ((*(end - 1) < *mid) ^ (*(end - 1) < *begin)) {
    std::swap(*begin, *(end - 1));
  }

  vecIter pivotIt = lomutoPartition(begin, end);
  median3InsertionSortBaseCase(begin, pivotIt);
  median3InsertionSortBaseCase(pivotIt + 1, end);
}

// based on documentation linked in assignment description (Wikipedia)
vecIter hoarePartition(vecIter begin, vecIter end) {
  vecIter i = begin;
  vecIter j = end;
  while (i < j) {
    do {
      i++;
    } while (*i <= *begin);
    do {
      j--;
    } while (*j > *begin);
    if (i < j) {
      std::swap(*i, *j);
    }
  }
  std::swap(*begin, *j);
  return j;
}

void Quicksort::thirdVariation(vecIter begin, vecIter end) {
  if (end - begin <= 10) {
    insertionSort(begin, end);
    return;
  }

  vecIter mid = begin + (end - begin) / 2;
  if ((*mid > *begin) ^ (*mid > *(end - 1))) {
    std::swap(*begin, *mid);
  }
  else if ((*(end - 1) < *mid) ^ (*(end - 1) < *begin)) {
    std::swap(*begin, *(end - 1));
  }

  vecIter pivotIt = hoarePartition(begin, end);
  thirdVariation(begin, pivotIt);
  thirdVariation(pivotIt + 1, end);
}

void Quicksort::mySort(vecIter begin, vecIter end) {
  // you can call your different functions from here 
  // to test them in main.
  thirdVariation(begin, end);
}
