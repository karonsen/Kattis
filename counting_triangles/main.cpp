#include "aux.h"
#include "class_intersectionList.h"
#include "class_line.h"
#include "io.h"
#include <iostream>
#include <vector>

int main() {

  // Keep looping until the input signals that the program is done.
  while (true) {

    // Input variables.
    // N - Numbers of line segments.
    // R - Vector with line segments represented by 2 pairs of coordinates.
    size_t N;
    std::vector<double> R;
    std::vector<Line> lines;

    // Read lines from standard in.
    readInput(std::cin, N, R);

    // If N == 0 the program is done.
    if (N == 0) {
      return 0;
    }

#ifdef DEBUG
    std::cout << "Debug mode." << std::endl;
    std::cout << "N: " << N << std::endl;
    std::cout << "R: ";
    for (auto r : R) {
      std::cout << r << " ";
    }
    std::cout << std::endl;
#endif

    // Construct Line objects from coordinates.
    for (size_t n = 0; n < N; n++) {
      lines.push_back(Line(R[n], R[n + 1], R[n + 2], R[n + 3]));
    }

    // TODO Find all line intersections.
    //  List (N-1) + (N-2) ... + 1 elements. Element 0 denotes whether or not
    //  lines 0 and 1 intersect by true or false, element 1 the intersection
    //  between lines 1 and 2 etc.
    // std::vector<bool> intersectionList;
    // fillIntersectionList(intersectionList, N, lines);
    IntersectionList il(lines);

    // TODO For each line:
    //	For each pair of intersections:
    // 	  Determine if the intersecting lines also intersect with each others.
    int M = countTriangles(il, N);
    printOutput(std::cout, M);
  }
}
