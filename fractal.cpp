#include "SFML/Graphics.hpp"
#include <complex>
#include <cstdlib>
#include <iostream>
#include <vector>

#define MAX_ITERATION 100
#define INFINITE 100000

std::vector<double> linspace(double start, double end, std::size_t num) {
  std::vector<double> result;
  if (num == 0)
    return result; // Aucun point
  if (num == 1) {
    result.push_back(start); // Un seul point
    return result;
  }
  double step = (end - start) / (num - 1);
  for (std::size_t i = 0; i < num; ++i) {
    result.push_back(start + i * step);
  }
  return result;
}
int convergence(int c) {
  int i(0);
  int z(0);
  while (i < MAX_ITERATION) {
    z += z * z + c;
    if (std::abs(z) > INFINITE)
      return i;
    i++;
  }
  return MAX_ITERATION;
}

int main() { return EXIT_SUCCESS; }
