#include "SFML/Graphics.hpp"
#include <complex>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <utility>
#include <vector>

#define MAX_ITERATION 100
#define INFINITE 100000

std::vector<double> linspace(double start, double end, std::size_t num) {
  std::vector<double> result;
  if (num == 0)
    return result;
  if (num == 1) {
    result.push_back(start);
    return result;
  }
  double step = (end - start) / (num - 1);
  for (std::size_t i = 0; i < num; ++i) {
    result.push_back(start + i * step);
  }
  return result;
}

int convergence(std::complex<double> c) {
  int i(0);
  std::complex<double> z(0);
  while (i < MAX_ITERATION) {
    z += z * z + c;
    if (std::abs(z) > INFINITE)
      return i;
    i++;
  }
  return MAX_ITERATION;
}

std::vector<std::vector<int>> fulfill(int rows, std::vector<double> real,
                                      std::vector<double> imaginary) {
  std::complex<double> z1;
  std::vector<std::vector<int>> matrix(rows);
  for (int i = 0; i < rows; ++i) {
    matrix[i].resize(rows);
    for (int j = 0; j < rows; j++) {
      std::complex<double> z1(real[i], imaginary[j]);
      matrix[i][j] = convergence(z1);
    }
  }
  return matrix;
}

int main() {
  std::vector<double> real = linspace(
      -2, 2, 500); // Réduit le nombre de points pour un affichage plus rapide
  std::vector<double> imaginary = linspace(-2, 2, 500);
  std::vector<std::vector<int>> matrix = fulfill(500, real, imaginary);

  sf::RenderWindow window(sf::VideoMode({200, 200}), "SFML works!");
  sf::CircleShape shape(100.f);
  shape.setFillColor(sf::Color::Green);

  while (window.isOpen()) {
    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>())
        window.close();
      else if (sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Escape)
          window.close();
      };
    }

    window.clear();
    window.draw(shape);
    window.display();
  }
  return EXIT_SUCCESS;
}
