#pragma once

#include "ofMain.h"
#include "ofxJSON.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);

        void getData();

        ofxJSONElement json;

		ofImage clearDay;
		ofImage clearNight;
		ofImage clouds;
		ofImage rain;

		int selectedMoment;
		int timeInt;
		int elementCount;
		bool nighttime;
		bool daytime;
		ofColor textColor;
		string dateAndTime;
		string weather;
		string time;
		string date;
		ofTrueTypeFont digitalClock;
		ofTrueTypeFont dateText;
		
};
