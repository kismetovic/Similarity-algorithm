#pragma once
#ifndef SIMILARITYFUNCTIONS_H
#define SIMILARITYFUNCTIONS_H
#include "Shape.h";
#include "Point.h"
#include <iostream>
#include <map>
using namespace std;
float GetSimilarityPercentageWhereSizeIsImportant(Shape& s1, Shape& s2) {
	float similarity = 0.00;
	if (s1.getMapSize() != s2.getMapSize() || s1.getMapSize() == 0 || s2.getMapSize() == 0)
		return similarity;
	for (int i = 0; i < s1.getMapSize(); i++) {
		if (s1.getShapeVerticies().at(i) == s2.getShapeVerticies().at(i)) {
			similarity++;
		}
	}
	return similarity / s1.getMapSize();
}

float GetSimilarityPercentageWhereSizeIsNotImportant(Shape& s1, Shape& s2) {
	float similarity = 0.00;
	if (s1.getMapSize() != s2.getMapSize() || s1.getMapSize() == 0 || s2.getMapSize() == 0)
		return similarity;
	bool foundDifference = false;
	int difference = 0;
	int differenceX, differenceY, differenceZ;
	for (int i = 0; i < s1.getMapSize(); i++) {
		if (s1.getShapeVerticies().at(i) < s2.getShapeVerticies().at(i) && foundDifference == false) {
			s2.getShapeVerticies().at(i).setCoordinateX(s2.getShapeVerticies().at(i).getCoordinateX() - abs(s2.getShapeVerticies().at(i).getCoordinateX() - s1.getShapeVerticies().at(i).getCoordinateX()));
			s2.getShapeVerticies().at(i).setCoordinateY(s2.getShapeVerticies().at(i).getCoordinateY() - abs(s2.getShapeVerticies().at(i).getCoordinateY() - s1.getShapeVerticies().at(i).getCoordinateY()));
			s2.getShapeVerticies().at(i).setCoordinateZ(s2.getShapeVerticies().at(i).getCoordinateZ() - abs(s2.getShapeVerticies().at(i).getCoordinateZ() - s1.getShapeVerticies().at(i).getCoordinateZ()));
			differenceX = abs(s2.getShapeVerticies().at(i).getCoordinateX() - s1.getShapeVerticies().at(i).getCoordinateX());
			differenceY = abs(s2.getShapeVerticies().at(i).getCoordinateY() - s1.getShapeVerticies().at(i).getCoordinateY());
			differenceZ = abs(s2.getShapeVerticies().at(i).getCoordinateZ() - s1.getShapeVerticies().at(i).getCoordinateZ());
			foundDifference = true;
		}
		else if (s2.getShapeVerticies().at(i) < s1.getShapeVerticies().at(i)&& foundDifference == false) {
			s1.getShapeVerticies().at(i).setCoordinateX(s1.getShapeVerticies().at(i).getCoordinateX() - abs(s1.getShapeVerticies().at(i).getCoordinateX() - s2.getShapeVerticies().at(i).getCoordinateX()));
			s1.getShapeVerticies().at(i).setCoordinateY(s1.getShapeVerticies().at(i).getCoordinateY() - abs(s1.getShapeVerticies().at(i).getCoordinateY() - s2.getShapeVerticies().at(i).getCoordinateY()));
			s1.getShapeVerticies().at(i).setCoordinateZ(s1.getShapeVerticies().at(i).getCoordinateZ() - abs(s1.getShapeVerticies().at(i).getCoordinateZ() - s2.getShapeVerticies().at(i).getCoordinateZ()));
			differenceX = abs(s1.getShapeVerticies().at(i).getCoordinateX() - s2.getShapeVerticies().at(i).getCoordinateX());
			differenceY = abs(s1.getShapeVerticies().at(i).getCoordinateY() - s2.getShapeVerticies().at(i).getCoordinateY());
			differenceZ = abs(s1.getShapeVerticies().at(i).getCoordinateZ() - s2.getShapeVerticies().at(i).getCoordinateZ());
			foundDifference = true;
		}
		else if (foundDifference == true) {
			if (s1.getShapeVerticies().at(i) != s2.getShapeVerticies().at(i)) {
				if (s1.getShapeVerticies().at(i) < s2.getShapeVerticies().at(i)) {
					s2.getShapeVerticies().at(i).setCoordinateX(s2.getShapeVerticies().at(i).getCoordinateX() - differenceX);
					s2.getShapeVerticies().at(i).setCoordinateY(s2.getShapeVerticies().at(i).getCoordinateY() - differenceY);
					s2.getShapeVerticies().at(i).setCoordinateZ(s2.getShapeVerticies().at(i).getCoordinateZ() - differenceZ);
				}
				if (s2.getShapeVerticies().at(i) < s1.getShapeVerticies().at(i)) {
					s1.getShapeVerticies().at(i).setCoordinateX(s1.getShapeVerticies().at(i).getCoordinateX() - differenceX);
					s1.getShapeVerticies().at(i).setCoordinateY(s1.getShapeVerticies().at(i).getCoordinateY() - differenceY);
					s1.getShapeVerticies().at(i).setCoordinateZ(s1.getShapeVerticies().at(i).getCoordinateZ() - differenceZ);
				}
			}
		}
	}
	return GetSimilarityPercentageWhereSizeIsImportant(s1, s2);
}

bool binarySearch(map<int, Point> mapa, int l, int r, Point p) {
	if (l > r)
		return false;
	int middle = l + (r - 1) / 2;
	if (mapa.at(middle) == p)
		return true;
	if (mapa.at(middle) < p)
		return binarySearch(mapa, middle + 1, r, p);
	else
		return binarySearch(mapa, l, middle - 1, p);

}

float GetAbsoluteSimilarity(Shape& s1, Shape& s2) {
	float similarity = 0.00;
	if (s1.getMapSize() == 0 || s2.getMapSize() == 0)
		return similarity;
	if (s1.getMapSize() < s2.getMapSize()) {
		for (int i = 0; i < s1.getMapSize(); i++) {
			if (binarySearch(s2.getShapeVerticies(), 0, s2.getMapSize() - 1, s1.getShapeVerticies().at(i))) {
				similarity++;
			}
		}
		return similarity / s2.getMapSize();
	}
	else if (s1.getMapSize() >= s2.getMapSize()) {
		for (int i = 0; i < s2.getMapSize(); i++) {
			if (binarySearch(s1.getShapeVerticies(), 0, s1.getMapSize() - 1, s2.getShapeVerticies().at(i)))
				similarity++;
		}
		return similarity / s1.getMapSize();
	}
}

float GetSimilarityPercentageWhereColorIsImportant(Shape& s1, Shape& s2) {
	if (s1.getMapSize() == 0 || s2.getMapSize() == 0)
		return 0.00;
	float similarity = 0.00;
	for (int i = 0; i < min(s1.getMapSize(), s2.getMapSize()); i++) {
		int colorR1 = s1.getShapeVerticies().at(i).getColorR();
		int colorG1 = s1.getShapeVerticies().at(i).getColorG();
		int colorB1 = s1.getShapeVerticies().at(i).getColorB();
		int colorR2 = s2.getShapeVerticies().at(i).getColorR();
		int colorG2 = s2.getShapeVerticies().at(i).getColorG();
		int colorB2 = s2.getShapeVerticies().at(i).getColorB();
		if (colorR1 == colorR2 && colorG1 == colorG2 && colorB1 == colorB2 && s1.getShapeVerticies().at(i) == s2.getShapeVerticies().at(i)) {
			similarity++;
		}
	}
	return similarity / max((int)s1.getMapSize(), (int)s2.getMapSize());
}
#endif // !SIMILARITYFUNCTIONS_H
