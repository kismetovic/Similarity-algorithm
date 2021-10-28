#pragma once
#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <map>
#include "Point.h"
using namespace std;


class Shape {
private:
	map<int, Point> shapeVerticies;
	int mapSize;
public:
	Shape() {
		mapSize = 0;
	}
	Shape(const Shape& s) {
		mapSize = 0;
		for (int i = 0; i < s.mapSize; i++) {
			shapeVerticies.insert(pair<int, Point>(mapSize, s.shapeVerticies.at(i)));
			mapSize++;
		}
	}
	~Shape() {} //destructor
	map<int, Point> getShapeVerticies() { return shapeVerticies; }
	int getMapSize() { return mapSize; }
	friend ostream& operator << (ostream& COUT, Shape s) {
		for (int i = 0; i < s.mapSize; i++) {
			COUT << s.shapeVerticies[i] << endl;
		}
		return COUT;
	}
	void AddVertex(Point point) {
		shapeVerticies.insert(pair<int, Point>(mapSize, point));
		mapSize++;
	}
};
#endif 
