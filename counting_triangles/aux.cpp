#include "aux.h"
#include <iostream>

int countTriangles(IntersectionList &il, size_t &N) {
  int M = 0;

  for (size_t n1 = 0; n1 < N - 2; n1++) {
    for (size_t n2 = n1 + 1; n2 < N - 1; n2++) {

      // For each line, check each other line for an intersection.
      bool int2 = il.checkIntersect(n1, n2);

      if (int2 == true) {
        for (size_t n3 = n2 + 1; n3 < N; n3++) {

          // For each intersection found, check each following intersections
          // with first line.
          bool int3 = il.checkIntersect(n1, n3);

          if (int3 == true) {

            // If both lines that intersect with first line also intersect with
            // each other a triangle has been found. Increment triangle counter.
            bool int23 = il.checkIntersect(n2, n3);
            if (int23 == true) {
              M++;
            }
          }
        }
      }
    }
  }

  return M;
}
