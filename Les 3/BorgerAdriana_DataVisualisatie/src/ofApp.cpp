#include "ofApp.h"

/* Het idee is om de muispositie boven (noord), onder (zuid), rechts (oost) en links (west) te tracken.
Afhankelijk van de positie laat een visualisatie in het midden zien hoeveel mensen er wonen.

Idealiter zou je met een mousescroll door de jaren heen kunnen scrollen. Als dit niet lukt wordt het gewoon 2016.

Ik heb alleen nog geen idee in hoeverre dit gaat lukken.

EDIT: Scrollen lukt niet :( */


void ofApp::setup() {
	db = new SQLite::Database("data/bevolking.sqlite");

	x = ofGetWidth() / 2;
	y = ofGetHeight() / 2;
}

void ofApp::update() {

	int directionNS = ofMap(ofGetMouseY(), 0, ofGetHeight() - 50, 0, 3, true);
	int directionWE = ofMap(ofGetMouseX(), 0, ofGetWidth() - 50, 0, 3, true);

	if (directionNS != selectedDirectionNS || directionWE != selectedDirectionWE)
	{

		selectedDirectionNS = directionNS;
		selectedDirectionWE = directionWE;
		string statement = "SELECT north, east, south, west FROM bevolking WHERE year = 2016";

		SQLite::Statement query(*db, statement);
		if (query.executeStep()) {
			north = query.getColumn(0).getDouble();
			east = query.getColumn(1).getDouble();
			south = query.getColumn(2).getDouble();
			west = query.getColumn(3).getDouble();

			if (directionNS == 0) {
				ofLog() << selectedDirectionNS << " " << north << endl;
				radius = north / 24;
				color = ofColor(200, 50, 50);
			}
			if (directionNS == 3) {
				ofLog() << selectedDirectionNS << " " << south << endl;
				radius = south / 24;
				color = ofColor(50, 180, 200);
			}

			if (directionWE == 0) {
				ofLog() << selectedDirectionWE << " " << west << endl;
				radius = west / 24;
				color = ofColor(100, 200, 50);
			}
			if (directionWE == 3) {
				ofLog() << selectedDirectionWE << " " << east << endl;
				radius = east / 24;
				color = ofColor(225, 140, 30);
			}
		}
		query.reset();
	}
}

void ofApp::draw() {

	ofSetColor(color);
	ofDrawCircle(x, y, radius);

}