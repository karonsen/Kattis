#include "io.h"
#include <iostream>
#include <vector>

// TODO When does the program end? Upon reading N = 0?
int main(int argc, char *argv[]) {
  bool notDone = true;

  while (notDone) {

    // Input variables.
    // N - Numbers of line segments.
    // R - Vector with line segments represented by 2 pairs of coordinates.
    size_t N;
    std::vector<double> R;

    readInput(std::cin, N, R);

#ifdef DEBUG
    std::cout << "Debug mode." << std::endl;
    std::cout << "N: " << N << std::endl;
    std::cout << "R: ";
    for (auto r : R) {
      std::cout << r << " ";
    }
    std::cout << std::endl;
#endif

    // TODO Find all line intersections.
    //  For each pair of lines compute intersection.

    // TODO For each line:
    //	For each pair of intersections:
    // 	  Determine if the intersecting lines also intersect with each others.
  }

  return 0;
}
