#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetLineWidth(5);
	ofNoFill();
	ofEnableDepthTest();
}


//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	auto radius = 300;
	auto deg = 0;
	auto deg_param = (int)ofGetFrameNum() * 12 % 1560 - 180;
	vector<glm::vec3> vertices;

	for (auto z = -300.f;  z <= 300; z += 0.5) {

		vertices.push_back(glm::vec3(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD), z));
		deg += 1;

		if (deg % 30 == 0) {

			if (deg >= deg_param - 180 && deg <= deg_param + 180) {

				vertices.push_back(glm::vec3(0, 0, z));

				ofFill();
				ofSetColor(239);
				ofBeginShape();
				ofVertices(vertices);
				ofEndShape(true);

				ofNoFill();
				ofSetColor(39);
				ofBeginShape();
				ofVertices(vertices);
				ofEndShape(true);
			}

			vertices.clear();
		}
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}