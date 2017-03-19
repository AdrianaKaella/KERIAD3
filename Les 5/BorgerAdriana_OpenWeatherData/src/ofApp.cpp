#include "ofApp.h"


void ofApp::setup() {

}


void ofApp::update() {

}

void ofApp::draw() {

}

void ofApp::keyPressed(int key) {
    getData();
}

void ofApp::getData() {
    string url = "http://api.openweathermap.org/data/2.5/forecast?q=Amsterdam,nl&appid=37f584c9d170b496e7abe382b2237a5a&units=metric";

    bool success = json.open(url);
    if (success) {

        int elementCount = json["cnt"].asInt();
        ofLog() << json["cnt"].asInt() << " elementen gekregen" << endl;

        for (int i = 0; i < elementCount; i++) {
			string dateAndTime = json["list"][i]["dt_txt"].asString();
			ofLog() << "Datum van element #" << i << " : " << json["list"][i]["dt_txt"] << endl;
			ofLog() << "Weer van element #" << i << " : " << json["list"][i]["weather"][2]["main"][1] << endl;

			
			string result = ofSplitString(dateAndTime, " ")[1];
			ofLog() << result << endl;
        }

    } else {
        ofLog() << "Oops. No data!" << endl;
    }
}