/*
 *  CustomParticle.h
 *  example-CustomData
 *
 *  Created by mySquare on 12/7/13.
 *  Copyright 2013 Francois moncarey MySquare. All rights reserved.
 *
 */


// A Custom Particle extedning the box2d circle

#pragma once
#include "ofMain.h"
#include "ofxBox2d.h"
// A simple little Data class. This is were
// you can store anything you want.
class Data {
public:
	ofColor color;
	string  name;
	int		id;
};

class CustomParticle : public ofxBox2dRect{
	
public:
	
	void setupTheCustomData(int _id,string _name, int _color) {
		
		static int colors[] = {0xcae72b, 0xe63b8f, 0x2bb0e7};
	
		// we are using a Data pointer because 
		// box2d needs to have a pointer not 
		// a referance
		setData(new Data());
		Data * theData = (Data*)getData();
		
		theData->id = _id;
		//theData->name += abc[(int)ofRandom(0, abc.size())];
		theData->name += _name;
		theData->color.setHex(colors[_color]);
		
		printf("setting the custom data!\n");
		
	}

	void draw() {
		
		
		
		Data* theData = (Data*)getData();
		if(theData) {
			
			// Evan though we know the data object lets just 
			// see how we can get the data out from box2d
			// you would use this when using a contact listener
			// or tapping into box2d's solver.
			ofPushMatrix();
					ofSetColor(theData->color);
			ofTranslate(ofxBox2dBaseShape::getPosition());
			ofRotate(getRotation());
			mesh.draw(ofGetFill()==OF_FILLED?OF_MESH_FILL:OF_MESH_WIREFRAME);
				ofFill();  
			float textSize = 2;
			ofScale(textSize, textSize, 1);
			ofSetColor(255);
			string myName = theData->name;
		
			ofDrawBitmapString(theData->name, (int)-(myName.size()*(15/textSize))/2,5);
			ofPopMatrix();
			
	
		}
	}
	
	
};
