#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <iterator>
#include "Point.h"
#include "Shape.h"
#include "Generator.h"
#include "SimilarityFunctions.h"

using namespace std;

const char* crt = "\n-----------------------------------------\n";

int main() {
	//test for basic case where shape 1 is equal to shape 2
	Shape shape1;
	Shape shape2;
	GenerateFromInterval(shape1, 1);
	GenerateFromInterval(shape2, 1);
	char relevantSize;
	char relevantColor;
	cout << "Is size of the shape important/relevant for similarity?(y/n)" << endl;
	cin >> relevantSize;
	cout << "Is color of the shape important/relevant for similarity?(y/n)" << endl;
	cin >> relevantColor;
	float similarity = 0.0;
	if (relevantSize == 'y')
		similarity += GetSimilarityPercentageWhereSizeIsImportant(shape1, shape2);
	else if (relevantSize == 'n') {
		cout << "Do you want to calculate absolute similarity or strictly that object but not important size?(a/s)";
		char strict;
		cin >> strict;
		if (strict == 's')
			similarity += GetSimilarityPercentageWhereSizeIsNotImportant(shape1, shape2);
		else if (strict == 'a')
			similarity += GetAbsoluteSimilarity(shape1, shape2);
	}
	if (relevantColor == 'y') {
		similarity += GetSimilarityPercentageWhereColorIsImportant(shape1, shape2);
		similarity /= 2.0;
	}
	cout << "Similarity is: " << similarity * 100 << "%" << crt;
	//case where color is important
	Shape shape3;
	Shape shape4;
	GenerateFromInterval(shape3, 1);
	GenerateFromInterval(shape4, 1);
	cout << "Similarity is: " << GetSimilarityPercentageWhereColorIsImportant(shape3, shape4) * 100 << "%" << crt;
	//case where color is important
	Shape shape5;
	Shape shape6;
	GenerateFromInterval(shape5, 2);
	GenerateFromIntervalDifferentSize(shape6, 2, 10);
	cout << "case where size is not important: " << GetSimilarityPercentageWhereSizeIsNotImportant(shape3, shape4) * 100 << "%" << crt;
	//case to calculate absolute similarity
	Shape shape7;
	Shape shape8;
	GenerateFromInterval(shape7, 2);
	GenerateFromInterval(shape8, 2);
	GenerateRandom(shape8, 30);
	cout << "absolute similarity is: " << GetAbsoluteSimilarity(shape7, shape8) * 100 << "%" << crt;
	return 0;
}