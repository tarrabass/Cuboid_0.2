///toDo 
/*
 Connecter avec le XML en ligne
 scuter le Xml est si il y a des nouveau arrivant on ajoute some fish
 */

#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"
#include "ofxBoids.h"
#include "ofxSimpleGuiToo.h"
#include "ofxXmlSettings.h"
#include "ofxSyphon.h"
#include "CustomParticle.h"
//#include "ofxPostProcessing.h"
#include "ofxAssimpModelLoader.h"




// listen on port 12345
#define PORT 12345
#define NUM_MSG_STRINGS 20


class testApp : public ofBaseApp{
    
    
    struct Box {
        ofVec3f pos;
        float size;
        float angle;
        float axis_x;
        float axis_y;
        float axis_z;
        
        Box(ofVec3f pos=ofVec3f(0.0f, 0.0f, 0.0f), float angle=0.0f, float ax=0.0f, float ay=0.0f, float az=0.0f, float size=2.0f) :
        pos(pos),
        size(size),
        angle(angle),
        axis_x(ax),
        axis_y(ay),
        axis_z(az)
        {}
    };

	public:
		void setup();
		void update();
		void draw();
		void addOneFish(string _name,vector<int> friends);
		void addSomeFish(int nbNew);
		void addCylinder(ofVec3f deb,ofVec3f fin);
		void getXml();
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		int idSqlToReelId(vector<int> tab,int idSql);
        void createRandomBoxes();
        void geometryPass();
	
	
	int idSqlToReel[3000];
	ofxSyphonServer mainOutputSyphonServer;
    ofxSyphonServer individualTextureSyphonServer;
	vector<ofVec3f> pathLine;
		int nbBoids;
	int addNbBoids;
	ofxBoids myBoids;
	
	bool _perlin;
		
	float PerlinDiv;
		bool _patrolPolyLine;
	
		bool _flockEffect;
    
	bool _clearBoids;
	bool _renderName;
		bool randomPatrol;
	float perlinDetail;
	float perlinSeed;
	float coeffPerlin;

	bool _dephtAlpha;
	bool _drawVideo;
	float xMax;
	float yMax;
	float zMax;
	float distanceMini;
	float rayonCircle;
	bool addFish;
	int limit;

	float dephtVortex;
	float radius;

	ofEasyCam cam;
	int indexCylinder;
	ofLight pointLight;
	ofVec3f center;
	ofxXmlSettings XML;
	bool _getXml;
	int mode_links;
	int reelIndex;
	
	// DoF
	float focusDistance;
	float aperture;
	float pointBrightness;
	
	float rgbBrightness;
	float maxPointSize;
	float timer;
	float tempTimer;
	float VortexOffcetX;
	float VortexOffcetY;
	float VortexOffcetZ;
	float rayonTornado;
	
		ofSoundStream soundStream;
	/// sound 
	void audioIn(float * input, int bufferSize, int nChannels); 
	void renderScene(ofVec3f camPos);
	vector <float> left;
	vector <float> right;
	
	int 	bufferCounter;
	int 	drawCounter;
	
	float smoothedVol;
	float scaledVol;
	float coeffSound;
	
	ofVideoPlayer 		myMovie;

	ofSoundPlayer  sound;
	int MaxBoidDIsplay;
	int lastBoidsNum;
	 string tempName;
	int counter2;
	
	bool _addCentripedeForce;
	float perpendicularForce;
	float centerForce;
	ofVec3f centerVortex;
    
    
    // light //
    ofLight						light1;
        ofLight						light2;
        ofLight						light3;
        ofLight						light4;
    
    /// camera ///
	bool usecamera;
	
	ofCamera camera1;
	ofRectangle viewport1;
	ofCamera camera2;
	ofRectangle viewport2;
	ofCamera camera3;
	ofRectangle viewport3;
	ofCamera camera4;
	ofRectangle viewport4;
	ofVec3f posSphere;
	float temps;
	float fov;
	float cameraZ;
	float camera1x;
	float camera1y;
	float camera1z;
	float camera2x;
	float camera2y;
	float camera2z;
	float camera3x;
	float camera3y;
	float camera3z;
	float camera4x;
	float camera4y;
	float camera4z;
	ofTrueTypeFont myFont;
  

	int nbBoidsTotal;
	bool _seek;
	ofPolyline targetPolyLine;
	bool _gotoPolyLine;
	float scaleUp;
	bool _vectorField;
	int typeForm;
		string titleArray[5];
	ofPolyline getSphereForm();
	ofPolyline getVortex();
	ofPolyline getCube();
	ofPolyline getSpiral();
	float rayonSphere;
	int nbSlice;

	
	
	///------------Box2D-------------///
	bool _activeBox2d;
	
	ofxBox2d                            box2d;
	vector <ofPtr<CustomParticle> >		particles;
	
	vector<string> wordTab;
	vector <ofPtr<ofxBox2dEdge> >       edges;
	ofPolyline                              drawing;
	ofxBox2dEdge                            edgeLine;
	int box2d_gravity;
	int box2d_wind;
    

    
    ofPlanePrimitive plane;
    bool _planFace;
        bool _planWireFrame;
    ofVec3f planPosition;
    bool _light;
    bool _drawParticle;
    //this is our model we'll draw
	ofxAssimpModelLoader model;
    	void drawWithMesh();
    /// shader ///
	ofShader myShader;
	bool doShader;
    float shaderPerlinFrequency;
    float shaderPerlinScale;
	
	float fog_intensity;
    
    
 /// 3d stuff ///
   bool _useFbo;
    ofFbo myFbo;
    bool _drawFBO;
    

   
   };


