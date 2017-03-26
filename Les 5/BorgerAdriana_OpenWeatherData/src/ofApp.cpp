#include "ofApp.h"


void ofApp::setup() {

	clearDay.load("ClearDay.png");
	clearNight.load("ClearNight.png");
	clouds.load("Clouds.png");
	rain.load("Rain.png");

	digitalClock.loadFont("DS-DIGI.TTF", 68);
	dateText.loadFont("ostrich-regular.ttf", 68);

	//getData();
}


void ofApp::update() {

	getData();

	int selectedMoment = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, elementCount, true);
	//ofLog() << selectedMoment << endl;

	dateAndTime = json["list"][selectedMoment]["dt_txt"].asString();
	string timeRaw = ofSplitString(dateAndTime, " ")[1];
	time = ofSplitString(timeRaw, ":")[0];
	timeInt = ofToInt(time);
	date = ofSplitString(dateAndTime, " ")[0];

	weather = json["list"][selectedMoment]["weather"][0]["main"].asString();

	ofLog() << "Time: " << timeRaw << "   Weather: " << weather << endl;


	if (timeInt >= 9 && timeInt <= 18)
	{
		daytime = true;
		nighttime = false;
	}

	if (timeInt < 9 || timeInt > 18)
	{
		nighttime = true;
		daytime = false;
	}

}

void ofApp::draw() {

	ofSetColor(ofColor::white);

	if (daytime == true)
	{
		ofBackgroundGradient(ofColor::white, ofColor(165, 201, 255));
	}

	if (nighttime == true)
	{
		ofBackgroundGradient(ofColor(13, 25, 43), ofColor::black);
	}

	if (weather == "Clear")
	{
		if (daytime == true)
		{
			clearDay.draw((ofGetWidth() / 2) - (512/2), (ofGetHeight()/2) - (512/2));
		}

		if (nighttime == true)
		{
			clearNight.draw((ofGetWidth() / 2) - (512 / 2), (ofGetHeight() / 2) - (512 / 2));
		}		
	}

	if (weather == "Clouds")
	{
		clouds.draw((ofGetWidth() / 2) - (512 / 2), (ofGetHeight() / 2) - (512 / 2));
	}

	if (weather == "Rain")
	{
		rain.draw((ofGetWidth() / 2) - (512 / 2), (ofGetHeight() / 2) - (512 / 2));
	}

	ofSetColor(ofColor(130, 130, 130));
	digitalClock.drawString(time + ":00", 30, 88);	
	dateText.drawString(date, ofGetWidth() - 300, 88);

}

void ofApp::keyPressed(int key) {
    
}

void ofApp::getData() {
    string url = "http://api.openweathermap.org/data/2.5/forecast?q=Amsterdam,nl&appid=37f584c9d170b496e7abe382b2237a5a&units=metric";

    bool success = json.open(url);
    if (success) {

        elementCount = json["cnt"].asInt();
        //ofLog() << json["cnt"].asInt() << " elementen gekregen" << endl;

        for (int i = 0; i < elementCount; i++) {
			/*dateAndTime = json["list"][i]["dt_txt"].asString();
			string timeRaw = ofSplitString(dateAndTime, " ")[1];
			string time = ofSplitString(timeRaw, ":")[0];*/

			//weather = json["list"][i]["weather"][0]["main"].asString();

			//ofLog() << "Time: " << timeRaw << "   Weather: " << weather << endl;
			
			//timeInt = ofToInt(time);

			

        }

    } else {
        ofLog() << "Oops. No data!" << endl;
    }
}