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

      size_t x1 = 4 * n + 0;
      size_t y1 = 4 * n + 1;
      size_t x2 = 4 * n + 2;
      size_t y2 = 4 * n + 3;

#ifdef DEBUG
      std::cout << "line " << n << ": ";
      std::cout << R[x1] << " " << R[y1] << " ";
      std::cout << R[x2] << " " << R[y2] << std::endl;
#endif

      lines.push_back(Line(R[x1], R[y1], R[x2], R[y2]));
    }

    IntersectionList il(lines);

    int M = countTriangles(il);

#ifdef DEBUG
    size_t ilN = il.getN();
    size_t ilM = il.getM();
    std::vector<bool> insec = il.getIntersections();

    std::cout << "Number of lines: " << lines.size() << std::endl;
    std::cout << "IL N: " << ilN << std::endl;
    std::cout << "IL M: " << ilM << std::endl;
    std::cout << "Insec: ";
    for (auto e : insec) {
      std::cout << e << " ";
    }
    std::cout << std::endl;
#endif
    printOutput(std::cout, M);
  }
}
