#include <SQLiteCpp/include/SQLiteCpp/Database.h>
#include "ofApp.h"

void ofApp::setup() {
    string databasePath = ofToDataPath("bevolking.sqlite", true);
    db = new SQLite::Database(databasePath);
	ofSetCircleResolution(100);
}

void ofApp::update() {
    int year = ofMap(ofGetMouseX(), 0, ofGetWidth() - 100, 1900, 2016, true);

	scaleNorth = ofMap(north, 0, 10000, ofGetHeight() / 2, 0, true);
	ofLog() << "Noord" << north << "->" << scaleNorth << endl;

	scaleEast = ofMap(ofGetWidth() / 2, ofGetWidth(), 0, 10000, true);
	scaleSouth = ofMap(ofGetHeight() / 2, ofGetHeight(), 0, 10000, true);
	scaleWest = ofMap(ofGetWidth() / 2, 0, 0, 10000, true);


    if (year != selectedYear) {
        selectedYear = year;
        string sql = "SELECT year, north, east, south, west, north+east+south+west AS total FROM bevolking WHERE year=?";

        SQLite::Statement query(*db, sql);

        query.bind(1, selectedYear); // vervang 1e vraagteken door de waarde van de variabele
        if (query.executeStep()) {
            total = query.getColumn("total").getInt();
            year = query.getColumn("year").getInt();
            north = query.getColumn("north").getInt();
            east = query.getColumn("east").getInt();
            south = query.getColumn("south").getInt();
            west = query.getColumn("west").getInt();
           /* ofLog() << selectedYear << " TOT: " << total << " N: "
                    << north << " E: " << east << " S: " << south << " W: " << west
                    << endl;*/
        }

        query.reset();
    }

}

void ofApp::draw() {
    ofBackgroundGradient(ofColor::darkGrey, ofColor::black);

    /*ofDrawCircle(ofGetWidth() / 2 * 0.5, ofGetHeight() / 2 * 0.5, west * 1.0f / total * 200);
    ofDrawCircle(ofGetWidth() / 2 * 1.5, ofGetHeight() / 2 * 0.5, east * 1.0f / total * 200);
    ofDrawCircle(ofGetWidth() / 2 * 0.5, ofGetHeight() / 2 * 1.5, north * 1.0f / total * 200);
    ofDrawCircle(ofGetWidth() / 2 * 1.5, ofGetHeight() / 2 * 1.5, south * 1.0f / total * 200);
	*/

	/*Noord*/ ofDrawCircle(ofGetWidth() / 2, north, 100);

}