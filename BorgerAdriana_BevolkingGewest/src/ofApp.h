#pragma once

#include "ofMain.h"
#include "SQLiteCpp.h"

class ofApp : public ofBaseApp {

    public:
        void setup();

        void update();

        void draw();

    private:
        SQLite::Database* db;
        int selectedYear = 1900;

        int total;
        int north;
        int east;
        int south;
        int west;

		int scaleNorth;
		int scaleEast;
		int scaleSouth;
		int scaleWest;
};
