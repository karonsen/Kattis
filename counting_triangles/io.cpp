#include "io.h"
#include <iostream>

void readInput(std::istream &is, size_t &N, std::vector<double> &R) {

  is >> N;
  R.resize(N * 4);

  for (size_t n = 0; n < N; n++) {
    is >> R[4 * n];
    is >> R[4 * n + 1];
    is >> R[4 * n + 2];
    is >> R[4 * n + 3];
  }
}

void printOutput() {}
