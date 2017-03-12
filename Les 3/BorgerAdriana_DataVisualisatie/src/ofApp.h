#pragma once

#include "SQLiteCpp.h"
#include "ofMain.h"

class ofApp : public ofBaseApp {

public:
	void setup();

	void update();

	void draw();

private:
	SQLite::Database* db;
	int selectedDirectionNS;
	int selectedDirectionWE;
	int north;
	int east;
	int south;
	int west;

	int x;
	int y;
	int radius;
	ofColor color;

};
