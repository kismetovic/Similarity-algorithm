#pragma once
#ifndef GENERATOR_H
#define GENERATOR_H
#include "Point.h"
#include "Shape.h"
#include <iostream>
#include <cstdlib>
using namespace std;

void GenerateFromInterval(Shape& s1, int number) {
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number; j++) {
			for (int k = 0; k < number; k++) {
				s1.AddVertex(Point(i, j, k));
			}
		}
	}
}
void GenerateFromIntervalDifferentSize(Shape& s1, int number, int difference) {
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number; j++) {
			for (int k = 0; k < number; k++) {
				s1.AddVertex(Point(i + difference, j + difference, k + difference));
			}
		}
	}
}
void GenerateRandom(Shape& s1, int number) {
	srand(time(0));
	for (int i = 0; i < number; i++) {
		s1.AddVertex(Point(rand() % 100, rand() % 100, rand() % 100));
	}
}


#endif // !GENERATOR_H
