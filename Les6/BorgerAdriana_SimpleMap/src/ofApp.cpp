#include "ofApp.h"

void ofApp::setup() {
    // statische kaart gegenereerd op http://staticmapmaker.com/google/

	ofSetBackgroundColor(ofColor::black);
    mapImage.load("staticmapAlphen.png");

    hotSpots[0] = ofRectangle(285, 135, 36, 30);
	hotSpots[1] = ofRectangle(180, 177, 73, 73);
	hotSpots[2] = ofRectangle(275, 256, 25, 19);
	hotSpots[3] = ofRectangle(183, 427, 42, 38);
}

void ofApp::update() {

}

void ofApp::draw() {
    ofSetColor(ofColor::white);
    mapImage.draw(0, 0);

    ofSetColor(ofColor::gray);
    ofDrawBitmapString("MouseX:" + ofToString(mouseX), 680, 20);
    ofDrawBitmapString("MouseY:" + ofToString(mouseY), 680, 40);


    for (int i = 0; i < HOTSPOT_COUNT; i++) {

		if (i == 0 || i == 2) {
			ofSetColor(ofColor(216, 34, 34, 65));
		}

		if (i == 1 || i == 3) {
			ofSetColor(ofColor(21, 196, 135, 65));
		}

		ofFill();
        ofDrawRectangle(hotSpots[i]);



		if (i == 0 || i == 2) {
			ofSetColor(ofColor(216, 34, 34, 100));
		}

		if (i == 1 || i == 3) {
			ofSetColor(ofColor(21, 196, 135, 100));
		}

		ofNoFill();
		ofDrawRectangle(hotSpots[i]);

    }

    ofSetColor(ofColor::white);
    for (int i = 0; i < HOTSPOT_COUNT; i++) {
        if (hotSpots[i].inside(mouseX, mouseY)) {

			if (i == 0) {
				ofDrawBitmapString("Schietincident Ridderhof, 9 april 2011", 680, 100);
			}

			if (i == 1) {
				ofDrawBitmapString("Vogelpark Avifauna, sinds kort ook apen!", 680, 100);
			}

			if (i == 2) {
				ofDrawBitmapString("Kraanongeluk Julianabrug, 3 augustus 2015", 680, 100);
			}

			if (i == 3) {
				ofDrawBitmapString("Historisch park Archeon, nu ook met museum!", 680, 100);
			}

        }
    }
}

void ofApp::keyPressed(int key) {

}

// 2e manier:
void ofApp::mouseMoved(int x, int y) {
    for (int i = 0; i < HOTSPOT_COUNT; i++) {
        if (hotSpots[i].inside(x, y)) {
            // doe iets met de hotspot
            ofLog() << "Hotspot " << i << endl;
        }
    }
}