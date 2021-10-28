#pragma once
#ifndef CONVERTOR_H
#define CONVERTOR_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

class Convertor
{
private:
	string pathForFirstFile;
	vector<float> coordinatesForFile; // should be shape 
public:
	Convertor() {
	}
	Convertor(string path1) {
		pathForFirstFile = path1;
		try {
			GetAllCoordinatesFromFile(path1, 1);
		}
		catch (exception& err) {
			cout << "Error-->" << err.what();
		}
	}
	vector<float> GetCoordinatesForFirstFile() { return coordinatesForFile; }
	~Convertor() {}
	void GetAllCoordinatesFromFile(string path, int fileNo) {
		ifstream file;
		file.open(path);
		if (!file.is_open() || !file.good()) {
			throw exception("File didn't open check your path.");
		}
		string lineOfFile;
		while (file >> lineOfFile) {
			if (lineOfFile.find("CARTESIAN_POINT") != string::npos) {
				GetCoordinatesFromLineOfFile(lineOfFile, fileNo);
			}
		}
		file.close();
	}
	void GetCoordinatesFromLineOfFile(string lineOfFile, int fileNo) {
		vector<string> v(4);
		int cnt = 0;
		for (int i = 0; i < lineOfFile.length(); i++) {
			if (lineOfFile[i] >= '0' && lineOfFile[i] <= '9' || lineOfFile[i] == '.') {
				v[cnt] += lineOfFile[i];
			}
			else if (lineOfFile[i] == 'E' && (lineOfFile[i - 1] >= '0' && lineOfFile[i - 1] <= '9') && (lineOfFile[i + 1] >= '0' && lineOfFile[i + 1] <= '9')) {
				v[cnt] += lineOfFile[i];
			}
			else if (lineOfFile[i] == '-' && (lineOfFile[i + 1] >= '0' && lineOfFile[i + 1] <= '9')) {
				v[cnt] += lineOfFile[i];
			}
			else {
				if (cnt == 0 && v[cnt] != "")
					cnt++;
				else if (cnt == 1 && v[cnt] != "")
					cnt++;
				else if (cnt == 2 && v[cnt] != "")
					cnt++;
			}
		}
		convertToNumbers(v, fileNo);
	}
	void convertToNumbers(vector<string> vectorOfCoordinatesInString, int fileNo) { // here we get point x,y,z 
		cout << setprecision(30);
		cout << fixed;
		cout << scientific;
		for (int i = 0; i < vectorOfCoordinatesInString.size(); i++) {
			if (vectorOfCoordinatesInString[i] != "" && fileNo == 1)
				coordinatesForFile.push_back(stod(vectorOfCoordinatesInString[i]));
		}
	}
};
#endif // !CONVERTOR
