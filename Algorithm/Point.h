#pragma once
#ifndef POINT_H
#define POINT_H

#include <iostream>

using namespace std;

class Point {
private:
	int coordinateX;
	int coordinateY;
	int coordinateZ;
	int colorR;
	int colorG;
	int colorB;
public:
	Point() {
		coordinateX = 0;
		coordinateY = 0;
		coordinateZ = 0;
		colorR = 0;
		colorG = 0;
		colorB = 0;
	}
	Point(int x, int y, int z) {
		coordinateX = x;
		coordinateY = y;
		coordinateZ = z;
		colorR = 0;
		colorG = 0;
		colorB = 0;
	}
	Point(int x, int y, int z, int r, int g, int b) {
		coordinateX = x;
		coordinateY = y;
		coordinateZ = z;
		colorR = r;
		colorG = g;
		colorB = b;
	}
	Point(const Point& p) {
		coordinateX = p.coordinateX;
		coordinateY = p.coordinateY;
		coordinateZ = p.coordinateZ;
		colorR = p.colorR;
		colorG = p.colorG;
		colorB = p.colorB;
	}
	Point& operator = (const Point& p) {
		if (this != &p) {
			coordinateX = p.coordinateX;
			coordinateY = p.coordinateY;
			coordinateZ = p.coordinateZ;
			colorR = p.colorR;
			colorG = p.colorG;
			colorB = p.colorB;
		}
		return *this;
	}
	bool operator < (const Point& p) {
		return coordinateX < p.coordinateX && coordinateY < p.coordinateY && coordinateZ < p.coordinateZ;
	}
	bool operator == (const Point& p) {
		return coordinateX == p.coordinateX && coordinateY == p.coordinateY && coordinateZ == p.coordinateZ;
	}
	bool operator != (const Point& p) {
		return coordinateX != p.coordinateX && coordinateY != p.coordinateY && coordinateZ != p.coordinateZ;
	}
	~Point() {} //destructor
	int getCoordinateX() { return coordinateX; }
	int getCoordinateY() { return coordinateY; }
	int getCoordinateZ() { return coordinateZ; }
	int getColorR() { return colorR; }
	int getColorG() { return colorG; }
	int getColorB() { return colorB; }
	void setCoordinateX(int x) { this->coordinateX = x; }
	void setCoordinateY(int y) { this->coordinateY = y; }
	void setCoordinateZ(int z) { this->coordinateZ = z; }
	void setColorR(int R) { this->colorR = R; }
	void setColorG(int G) { this->colorG = G; }
	void setColorB(int B) { this->colorB = B; }
	friend ostream& operator << (ostream& COUT, Point p) {
		COUT << "Coordinate x: " << p.getCoordinateX() << "\nCoordinate y: " << p.getCoordinateY() << "\nCoordinate z: " << p.getCoordinateZ() << endl;
		COUT << "Color of the point is(RGB): (" << p.getColorR() << "," << p.getColorG() << "," << p.getColorB() << ")." << endl;
		return COUT;
	}
};

#endif
