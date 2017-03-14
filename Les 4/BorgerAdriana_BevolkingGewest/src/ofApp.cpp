#include "ofApp.h"

void ofApp::setup() {
	db = new SQLite::Database("data/bevolking.sqlite");

	ofSetCircleResolution(100);
	radius = 12;

	barrioHeader.loadFont("Barrio-Regular.otf", 48);
	barrioText.loadFont("Barrio-Regular.otf", 26);
}

void ofApp::update() {
    int year = ofMap(ofGetMouseX(), 0, ofGetWidth() - 50, 1900, 2016, true);

    if (year != selectedYear) {
        selectedYear = year;
		string statement = "SELECT year, north, east, south, west \
							FROM bevolking \
							WHERE year=?";

        SQLite::Statement query(*db, statement);
		
		scaleNorth = ofMap(north, 0, 10000, ofGetHeight() / 2, 0);
		scaleEast = ofMap(east, 0, 10000, ofGetWidth() / 2, ofGetWidth());
		scaleSouth = ofMap(south, 0, 10000, ofGetHeight() / 2, ofGetHeight());
		scaleWest = ofMap(west, 0, 10000, ofGetWidth() / 2, 0);

        query.bind(1, selectedYear); // vervang 1e vraagteken door de waarde van de variabele
        if (query.executeStep()) {
            year = query.getColumn("year").getInt();
            north = query.getColumn("north").getInt();
            east = query.getColumn("east").getInt();
            south = query.getColumn("south").getInt();
            west = query.getColumn("west").getInt();
        }

        query.reset();
    }

}

void ofApp::draw() {
    ofBackgroundGradient(ofColor(22, 140, 140), ofColor(8, 115, 115));

	//lichtst blauw
	ofSetColor(ofColor(187, 236, 236));
	barrioHeader.drawString("N", ofGetWidth() / 2, 74);
	barrioHeader.drawString("E", ofGetWidth() - 74, ofGetHeight() / 2);
	barrioHeader.drawString("S", ofGetWidth() / 2, ofGetHeight() - 26);
	barrioHeader.drawString("W", 26, ofGetHeight() / 2);

	barrioHeader.drawString(ofToString(selectedYear), ofGetWidth() - 150, ofGetHeight() - 20);

	//lichtblauw
	ofSetColor(ofColor(85, 177, 177));
	/*Centre*/ ofDrawCircle(ofGetWidth() / 2, ofGetHeight() / 2, 5);
	barrioText.drawString("Population division", 24, 50);
	barrioText.drawString("0 - 10.000 people", 24, 90);
	
	//rood
	ofSetColor(ofColor(234, 37, 37));
	/*Noord*/ ofDrawCircle(ofGetWidth() / 2, scaleNorth, radius);
	/*East*/ ofDrawCircle(scaleEast, ofGetHeight() / 2, radius);
	/*South*/ ofDrawCircle(ofGetWidth() / 2, scaleSouth, radius);
	/*West*/ ofDrawCircle(scaleWest, ofGetHeight() / 2 , radius);

}