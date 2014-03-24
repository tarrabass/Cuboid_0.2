#include "testApp.h"



//--------------------------------------------------------------
void testApp::setup(){
	ofSetFrameRate(60);
	//ofSetLogLevel(OF_LOG_NOTICE);
	ofSetVerticalSync(true);
    ofSetDrawBitmapMode(OF_BITMAPMODE_MODEL);
	//glEnable(GL_DEPTH_TEST);
    
    
    //// 3d model ////
    //we need to call this for textures to work on models
    ofDisableArbTex();
	
	//this makes sure that the back of the model doesn't show through the front
	ofEnableDepthTest();
    //model.loadModel("dog/dog.3ds");
	//model.setPosition(200,200, 500);
    
    
    // Setup post-processing chain
    /*
    post.init(ofGetWidth(), ofGetHeight());
       post.createPass<SSAOPass>()->setEnabled(false);
    post.createPass<FxaaPass>()->setEnabled(false);
    post.createPass<BloomPass>()->setEnabled(false);
 
    post.createPass<KaleidoscopePass>()->setEnabled(false);
    post.createPass<BleachBypassPass>()->setEnabled(false);
    post.createPass<ToonPass>()->setEnabled(false);
    post.createPass<DofAltPass>()->setEnabled(false);
    post.createPass<FakeSSSPass>()->setEnabled(false);
    post.createPass<LimbDarkeningPass>()->setEnabled(false);
     */

 
	///myFont.loadFont("Impact.ttc",20, true,true,true, 0.3, 200);
    //myFont.loadFont("Impact.ttc",20, false,false,true, 0.3, 200);
    myFont.loadFont("Impact.ttc",10,true,true,true,0.1,300);
    
    mainOutputSyphonServer.setName("Screen Output");
	ofEnableSmoothing();
	//timer = 5000;
	xMax = 768.0;
	yMax = 1024.0;
	zMax = -1990;	
    myShader.load("shaders/noise.vert", "shaders/noise.frag"); 
    
    

    
    
    ofEnableDepthTest();
	counter2 = 0;
	
	myBoids.clear();
    int reelIndex;
	titleArray[0] = "Cube";
	titleArray[1] = "Sphere";
	titleArray[2] = "Vortex";
    titleArray[3] = "Spiral";
    
    plane.set(2000,2000);   ///dimensions for width and height in pixels
    plane.setPosition(0, 0, 0); /// position in x y z
    plane.setResolution(50,50);
    plane.rotate(90, 1.0, 0.0, 0.0);

	gui.addToggle("usecamera", usecamera);
    gui.addToggle("doShader",doShader);


    gui.addSlider("shaderPerlinFrequency",shaderPerlinFrequency,1.0, 1000.0);
	gui.addSlider("shaderPerlinScale",shaderPerlinScale,0.0, 10.0);
    gui.addSlider("fog_intensity",fog_intensity, 0.0, 0.003);
    gui.addToggle("_light", _light);
    gui.addToggle("_drawParticle", _drawParticle);

    gui.addToggle("_activeBox2d",_activeBox2d);
    gui.addToggle("_planFace",_planFace);
    gui.addToggle("_planWireFrame",_planWireFrame);

    
    gui.addSlider2d("PlanePosition", planPosition, -500, 500, -500,500);
	gui.addSlider("timer",timer,  1,5000);//1
	gui.addSlider("camera FOV",fov,0.0, 100.0);
	
		
	float camera1x;
	float camera1y;
	float camera1z;
	float camera2x;
	float camera2y;
	float camera2z;
	float camera3x;
	float camera3y;
	float camera4x;
	float camera4y;
	float camera4z;
    
	gui.addButton("_getXml",_getXml);
	gui.addToggle("_drawVideo", _drawVideo);
	gui.addSlider("limit",limit,  0,250);//1
		    
    gui.addPage("Boids");
    gui.addSlider("addNbBoids",addNbBoids,  1,100);//1
	gui.addSlider("nbBoidsTotal",nbBoidsTotal, 0, 10000);
    
	gui.addSlider("modeLink", mode_links, 1,3);
	gui.addButton("addSomeFish", addFish);
	gui.addSlider("radius",radius, 0.5, 5);
	gui.addButton("_clearBoids",_clearBoids);
	gui.addSlider("nbBoids",nbBoids,1,2048);
	gui.addSlider("scaleUp",scaleUp,0,1);
    	gui.addToggle("_renderName",myBoids._renderName);
	gui.addToggle("_renderParticle",myBoids._renderParticle);
	gui.addToggle("renderLink",myBoids.renderLink);
	gui.addSlider("distanceMini",myBoids.distanceMini, 1,1000);//1
	gui.addSlider("maxSpeed",myBoids.maxSpeed,  0.001,10);//1
	gui.addToggle("_flockEffect", _flockEffect);
	gui.addToggle("_patrolPolyLine",_patrolPolyLine);
	gui.addToggle("_gotoPolyLine", _gotoPolyLine);
	gui.addComboBox("typeForm",typeForm,3,titleArray);
	gui.addSlider("rayonSphere",rayonSphere,1,3000);//4,
	gui.addSlider("nbSlice",nbSlice,1,100);//4,

	gui.addToggle("_vectorField",_vectorField);	
	
	gui.addToggle("_dephtAlpha", _dephtAlpha);
	gui.addSlider("VortexOffcetX",VortexOffcetX,-2000,2000);//4,
	gui.addSlider("VortexOffcetY",VortexOffcetY,-200,200);//4,
	gui.addSlider("VortexOffcetZ",VortexOffcetZ,-100,1000);//4,
	
	gui.addToggle("_addCentripedeForce",_addCentripedeForce);
	gui.addToggle("_seek",_seek);
	
    
	gui.addSlider("perpendicularForce",perpendicularForce,0,2);
	gui.addSlider("centerForce",centerForce,0,1);

	
	gui.addToggle("randomPatrol",randomPatrol);
	gui.addToggle("_perlin",_perlin);
	gui.addSlider("PerlinDiv",PerlinDiv, 0.001,1000);//4,
	gui.addSlider("coeffPerlin",coeffPerlin, 0.1,10);//4,
	gui.addSlider("scaledVol", scaledVol, 0, 5);
	gui.addSlider("coeffSound",coeffSound, 0,1);

    
	gui.addPage("box2d");
    
	gui.addSlider("box2d_Gravity",box2d_gravity,-20,20);
	gui.addSlider("box2d_Wind",box2d_wind,-20,20);
    
    gui.addPage("bullet");
	
	
	gui.loadFromXML();
	mainOutputSyphonServer.setName("faceBookVortex");

	//addSomeFish(22);
	///mode_links = 2;

	
	///lighting///
	// ofSetSmoothLighting(true);
	//center.set(ofGetWidth()*.5, ofGetHeight()*.5, 2000);
	//pointLight.setPosition(center.x, center.y, 0);


	//shader.load("shaders/blur.vert","shaders/noise.vert", "shaders/noise.frag");


	_getXml = true;
	
	soundStream.listDevices();
	
	//sound//
	int bufferSize = 256;
	
	
	left.assign(bufferSize, 0.0);
	right.assign(bufferSize, 0.0);
	
	
	bufferCounter	= 0;
	drawCounter		= 0;
	smoothedVol     = 0.0;
	scaledVol		= 0.0;
	coeffSound = 1;

	soundStream.setup(this, 0, 2, 44100, bufferSize, 4);
	
	
	viewport1.x = 0;
	viewport1.y =0;
	viewport1.width = 768;
	viewport1.height = 768;
	
	viewport2.x = 768;
	viewport2.y =0;
	viewport2.width = 768;
	viewport2.height = 768;
	
	viewport3.x = 1536;
	viewport3.y =0;
	viewport3.width = 768;
	viewport3.height = 768;
	
	viewport4.x = 2304;
	viewport4.y =0;
	viewport4.width = 768;
	viewport4.height = 768;
	
	camera1.setAspectRatio(1);
	camera2.setAspectRatio(1);
	camera3.setAspectRatio(1);
	camera4.setAspectRatio(1);
	

	camera1.pan(0);
	camera2.pan(270);
	camera3.pan(180);
	camera4.pan(90);
	
	wordTab.push_back("Francois");
	wordTab.push_back("Ramona");
	wordTab.push_back("Emilie");
	wordTab.push_back("Beatrice");
	wordTab.push_back("Kevin");
	wordTab.push_back("F");
	wordTab.push_back("R");
	wordTab.push_back("E");
	wordTab.push_back("B");
	wordTab.push_back("F");
	
	
	// Box2d
	drawing.addVertex(1, 0, 0);
	drawing.addVertex(1, 768, 0);
	drawing.addVertex(768, 768, 0);
	drawing.addVertex(768, 0, 0);
	drawing.addVertex(768, 768, 0);
	drawing.addVertex(1536, 768, 0);
	drawing.addVertex(1536, 0, 0);
	drawing.addVertex(1536, 768, 0);
	drawing.addVertex(2304, 768, 0);
	drawing.addVertex(2304, 0, 0);
	drawing.addVertex(2304, 768, 0);
	drawing.addVertex(3072, 768, 0);
	drawing.addVertex(3072,0, 0);
	drawing.addVertex(3072, 768, 0);
	
	
	box2d.init();
	box2d.setGravity(0, 10);
	box2d.createBounds();
	box2d.setFPS(30.0);
	
	drawing.setClosed(false);
	drawing.simplify();
	edgeLine.addVertexes(drawing);
	
	//polyLine.simplifyToMaxVerts(); // this is based on the max box2d verts
	edgeLine.setPhysics(0.0, 0.5, 0.5);
	edgeLine.create(box2d.getWorld());
    planPosition.x = 0;

	
     light1.setPosition(0,0,0);
     light2.setPosition(0,0,0);
     light3.setPosition(0,0,0);
     light4.setPosition(0,0,0);
    
    light1.setParent(camera1);
    light2.setParent(camera2);
    light3.setParent(camera3);
    light4.setParent(camera4);

    
    //// fog setup ////
    ofDisableArbTex();
    
   // ofEnableLighting();
    
  	camera1.setFov(fov);
	camera2.setFov(fov);
	camera3.setFov(fov);
	camera4.setFov(fov);
    

}

//--------------------------------------------------------------

int testApp::idSqlToReelId(vector<int> tab,int idSql){	
	for(int i = 0; i < tab.size();i++){
	
		if(tab[i] == idSql){
		
			return i;
		}
	}
}

void testApp::update(){
    

    
    plane.setPosition(planPosition.x, planPosition.y, 0);
    
    

    
	if(_activeBox2d){
		box2d.setGravity(box2d_wind,box2d_gravity);
		box2d.update();	
	}

	myBoids.rayonCircle = rayonCircle;
	 
	temps++;
	posSphere.x = 500 * cos(temps/15);
	posSphere.y = 0;
	posSphere.z = 500 * sin(temps/15);
	
	if(tempTimer>timer){
		tempTimer = 0;
		_getXml = true;
		counter2++;
	}
	if(counter2>300){
		counter2 = 0;
		myBoids.clear();
	}
	
		ofSoundUpdate();

	    myMovie.update();
			scaledVol = ofMap(smoothedVol, 0.0001, 0.01, 0.0001, 10.0, true);
	
	tempTimer++;

	pathLine.clear();
	
	
	if(_getXml){
	
		ofSaveURLAsync("http://chelmy.no-ip.org/peoples_xml.php","peoples.xml");
		if(XML.loadFile("peoples.xml")){
		//if(XML.loadFile("http://www.cenc.ch/plexus/get_xml_people.php")){
			XML.pushTag("peoples");
			int nbPeople = XML.getNumTags("people");
			
			if (nbPeople>0) {
				
			string myString;
			XML.copyXmlToString(myString);
				cout << "nbPeople"<<nbPeople<<"\n";
		
			
		for (int i = myBoids.boids.size(); i<nbPeople; i++) {
				XML.pushTag("people",i);
				
				string tempName;
            
            
				tempName = XML.getValue("name", "defaultNameXML");
          cout<<"tempName"<<tempName<<"\n";
				idSqlToReel[ofToInt(XML.getValue("id", "defaultNameXML"))] = i;
				XML.pushTag("friends",0);
				int nbFriends = XML.getNumTags("friend");
				vector<int> tempFriends;
				
				for(int ii=0;ii<nbFriends;ii++){
			
					tempFriends.push_back(XML.getValue("friend", 0,ii));
					
				}
				
				XML.popTag();
				 myBoids.addOneFish(tempName,tempFriends);
				XML.popTag();
				
			}
				
				
		}
	
		//getXml();
		}else{
			ofLogError("People fuck file did not load!");
		}
	
	
		_getXml = false;
	}
	if(_clearBoids){
		_clearBoids = false;
	 myBoids.clear();
	}
	if(addFish){
		addFish = false;
			
		 myBoids.addSomeFish(addNbBoids);
		
	}
	
	if(_seek){
		myBoids.seek(ofVec3f(1,0,0));
	}
	
	if(_gotoPolyLine){
switch (typeForm) {
	case 0:
		myBoids.gotoPolyLine(getCube());
		break;
		
	case 1:
		myBoids.gotoPolyLine(getSphereForm());
		break;
		
		
	case 2:
		myBoids.gotoPolyLine(getVortex());
		break;
		
	default:
		break;
}
		
	}
	
	
	
	if(_patrolPolyLine){
		
		switch (typeForm) {
			case 0:
				myBoids.patrol(getCube(),randomPatrol);
				break;
				
			case 1:
				myBoids.patrol(getSphereForm(),randomPatrol);
				break;
				
			case 2:
				myBoids.patrol(getVortex(),randomPatrol);
				break;
				
			default:
				break;
		}
			}
	
	if (_vectorField) {
		myBoids.addVectorFiledForce();
	}

	

	int nbCylinder;
	nbCylinder = 0;

		//myBoids.maxSpeed = maxSpeed;
		int time = ofGetFrameNum();
		if(_perlin){
			myBoids.coeffPerlin = coeffPerlin*(scaledVol*coeffSound);
			myBoids.PerlinDiv = PerlinDiv;
			myBoids.perlin();
		}
		
	
    
    if (_addCentripedeForce) {
        myBoids.addCentripedeForce(ofVec3f(VortexOffcetX,VortexOffcetY,VortexOffcetZ),perpendicularForce,centerForce);
    }
    
		if(_flockEffect){
			myBoids.flock();
		} 
		
			myBoids.update();
    
    
	nbBoidsTotal = myBoids.boids.size();
		
		/*
		if (mode_links==1) {
			
			
			if(boids[i].friends.size()>0){
			for(int iii=0;iii<boids[i].friends.size();iii++){
				ofVec3f deb(boids[i].position.x,boids[i].position.y,boids[i].position.z);
			
			
				ofVec3f fin(boids[idSqlToReel[boids[i].friends[iii]]].position.x,boids[idSqlToReel[boids[i].friends[iii]]].position.y,boids[idSqlToReel[boids[i].friends[iii]]].position.z);
				addCylinder(deb,fin);
			}
			}
			 
		}
		if (mode_links==3) {
			for (int ii = i; ii < boids.size(); ii++){
				/// on crer des lien en fonction de la distance 
				
				if (boids[i].position.distance(boids[ii].position) < distanceMini) {
					ofVec3f deb(boids[i].position.x,boids[i].position.y,boids[i].position.z);
					ofVec3f fin(boids[ii].position.x,boids[ii].position.y,boids[ii].position.z);
					addCylinder(deb,fin);
				}				
			}
			
			if(boids[i].friends.size()>0){
				for(int iii=0;iii<boids[i].friends.size();iii++){
					ofVec3f deb(boids[i].position.x,boids[i].position.y,boids[i].position.z);
					
					
					ofVec3f fin(boids[idSqlToReel[boids[i].friends[iii]]].position.x,boids[idSqlToReel[boids[i].friends[iii]]].position.y,boids[idSqlToReel[boids[i].friends[iii]]].position.z);
					addCylinder(deb,fin);
				}
			}
			
		}

	}*/
	
	float t = ofGetLastFrameTime();
	
}



void testApp::renderScene(ofVec3f camPos){

    
 
	ofSetColor(255, 255, 255,255);
   
    if(_drawParticle){
        myBoids.render(&myFont);
    }
    

    if(_planFace){
        plane.draw();
    }
    
    ///drawWithMesh();

    if(_planWireFrame){
        

       	glLineWidth(2);
          plane.drawWireframe();

    }
 
}

//--------------------------------------------------------------
void testApp::draw(){
 

	
	ofBackground(0, 0, 0, 255);
    
    

    
    glClearDepth(1.0);
    glEnable(GL_DEPTH_TEST);                       // Enables Depth Testing
    glDepthFunc(GL_LEQUAL);                        // Type of Depth Test to perform
    
    
    
    glShadeModel(GL_SMOOTH);
    
    
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    
    

    
    
    if (_light) {
        
        ofEnableLighting();
        light1.enable();
          light2.enable();
          light3.enable();
          light4.enable();
    }
    
  
   
    ofEnableArbTex();
    
    if(doShader) {
        myShader.begin();
        
        //we want to pass in some varrying values to animate our type / color
        myShader.setUniform1f("timeValX", ofGetElapsedTimef() * 0.1 );
        myShader.setUniform1f("timeValY", -ofGetElapsedTimef() * 0.18 );
        myShader.setUniform1f("shaderPerlinFrequency",shaderPerlinFrequency);
        myShader.setUniform1f("shaderPerlinScale",shaderPerlinScale);
        myShader.setUniform1f("fog_intensity",fog_intensity);
        myShader.setUniformTexture("tex",myFont.getFontTexture(),1);
       
        
        //we also pass in the mouse position
        //we have to transform the coords to what the shader is expecting which is 0,0 in the center and y axis flipped.
        myShader.setUniform2f("mouse", mouseX - ofGetWidth()/2, ofGetHeight()/2-mouseY );
        
        
    }

    
   
    
	glPushAttrib(GL_ENABLE_BIT);


	
	camera1.begin(viewport1);
	renderScene(camera1.getPosition());
	camera1.end();
	
	camera2.begin(viewport2);
	renderScene(camera1.getPosition());
    camera2.end();
		
	camera3.begin(viewport3);
	renderScene(camera1.getPosition());
	camera3.end();
		
	camera4.begin(viewport4);
	renderScene(camera1.getPosition());
	camera4.end();

      
    

    
     glPopAttrib();
 

    if(doShader)
    {
        myShader.end();
       
    }
    
    
	if (_activeBox2d) {
		for(int i=0; i<particles.size(); i++) {
			particles[i].get()->draw();
		}
	}
    if (_light) {
        light1.disable();
          light2.disable();
          light3.disable();
          light4.disable();
        ofDisableLighting();
    }
    
    
    // setup gl state
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_CULL_FACE);


	mainOutputSyphonServer.publishScreen();
	///drawing.draw();
	gui.draw();
    // draw help



}



void testApp::getXml()

{
	
	XML.pushTag("peoples");
	nbBoids = XML.getNumTags("people");
	///nbBoids = nbBoids - limit;
	

}


ofPolyline testApp::getSpiral(){
	
	ofPolyline tempPolyLIne;
	
	
	for (int ii = 0; ii < 180; ii++)
	{
		float tempX;
		float tempY;
		float tempZ;
		tempY = 350-(ii*(768/180))+VortexOffcetY;
		tempX = (((768-tempY) * scaleUp)+rayonSphere ) * cos(ii) + VortexOffcetX;
		tempZ = (((768-tempY) * scaleUp)+rayonSphere ) * sin(ii) + VortexOffcetZ;
		
		tempPolyLIne.addVertex(ofVec3f(tempX,tempY,tempZ));
	}
	
	return tempPolyLIne;
	
}

ofPolyline testApp::getVortex(){
	
	ofPolyline tempPolyLIne;
	
	
	for (int ii = 0; ii < 180; ii++)
	{
		float tempX;
		float tempY;
		float tempZ;
		tempY = 350-(ii*(768/180))+VortexOffcetY;
		tempX = (((768-tempY) * scaleUp)+rayonSphere/10 ) * cos(ii) + VortexOffcetX;
		tempZ = (((768-tempY) * scaleUp)+rayonSphere/10 ) * sin(ii) + VortexOffcetZ;
		
	tempPolyLIne.addVertex(ofVec3f(tempX,tempY,tempZ));
	}
	
	return tempPolyLIne;
	
}

ofPolyline testApp::getCube(){
	
	ofPolyline targetPolyLine;
	targetPolyLine.addVertex(-1*rayonSphere, 1*rayonSphere, -1*rayonSphere);
	targetPolyLine.addVertex(1*rayonSphere, 1*rayonSphere, -1*rayonSphere);
	targetPolyLine.addVertex(1*rayonSphere, -1*rayonSphere, -1*rayonSphere);
	targetPolyLine.addVertex(-1*rayonSphere, -1*rayonSphere, -1*rayonSphere);
	targetPolyLine.addVertex(-1*rayonSphere, 1*rayonSphere, -1*rayonSphere);
	
	
	
	targetPolyLine.addVertex(1*rayonSphere, 1*rayonSphere, 1*rayonSphere);
	targetPolyLine.addVertex(1*rayonSphere, -1*rayonSphere, 1*rayonSphere);
	targetPolyLine.addVertex(1*rayonSphere, -1*rayonSphere, -1*rayonSphere);
	targetPolyLine.addVertex(1*rayonSphere, 1*rayonSphere, -1*rayonSphere);
	
	targetPolyLine.addVertex(-1*rayonSphere, 1*rayonSphere, 1*rayonSphere);
	targetPolyLine.addVertex(1*rayonSphere, 1*rayonSphere, 1*rayonSphere);
	targetPolyLine.addVertex(1*rayonSphere, 1*rayonSphere, -1*rayonSphere);
	targetPolyLine.addVertex(-1*rayonSphere,1*rayonSphere, -1*rayonSphere);
	targetPolyLine.addVertex(-1*rayonSphere, 1*rayonSphere, 1*rayonSphere);
	
	
	
	targetPolyLine.addVertex(1*rayonSphere, 1*rayonSphere, 1*rayonSphere);
	targetPolyLine.addVertex(-1*rayonSphere, 1*rayonSphere, 1*rayonSphere);
	targetPolyLine.addVertex(-1*rayonSphere,-1*rayonSphere, 1*rayonSphere);
	targetPolyLine.addVertex(1*rayonSphere,-1*rayonSphere, 1*rayonSphere);
	targetPolyLine.addVertex(1*rayonSphere, 1*rayonSphere, 1*rayonSphere);
	
	
	targetPolyLine.addVertex(-1*rayonSphere, 1*rayonSphere, 1*rayonSphere);
	targetPolyLine.addVertex(-1*rayonSphere, 1*rayonSphere, -1*rayonSphere);
	targetPolyLine.addVertex(-1*rayonSphere,-1*rayonSphere,-1*rayonSphere);
	targetPolyLine.addVertex(-1*rayonSphere,-1*rayonSphere, 1*rayonSphere);
	targetPolyLine.addVertex(-1*rayonSphere, 1*rayonSphere, 1*rayonSphere);
	
	
	targetPolyLine.addVertex(-1*rayonSphere,-1*rayonSphere,-1*rayonSphere);
	targetPolyLine.addVertex(1*rayonSphere, -1*rayonSphere, -1*rayonSphere);
	targetPolyLine.addVertex(-1*rayonSphere,-1*rayonSphere, 1*rayonSphere);
	targetPolyLine.addVertex(1*rayonSphere,-1*rayonSphere,1*rayonSphere);
	
	return targetPolyLine;

}

ofPolyline testApp::getSphereForm(){

	ofPolyline tempPolyLIne;

	
		for (int i = 0; i < nbSlice; i++) {
		for (int ii = 0; ii < nbSlice; ii++) {

		
	
			ofVec3f tempPoint;
			float omega;
			omega = i*(PI/nbSlice)-(PI/2);
			
			
			tempPoint.x = rayonSphere * cos(i*(PI/nbSlice)-(PI/2)) * sin(ii*(2*PI/nbSlice)-PI);  
			
		
			tempPoint.y =rayonSphere * cos(i*(PI/nbSlice)-(PI/2)) * cos(ii*(2*PI/nbSlice)-PI);
			tempPoint.z =  rayonSphere * sin(i*(PI/nbSlice)-(PI/2));	 
		

			tempPolyLIne.addVertex(tempPoint);
			
		}
		
	}
	
	return tempPolyLIne;
	
}



//--------------------------------------------------------------
void testApp::keyPressed(int key){
	
	

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
	/*
    unsigned idx = key - '0';
    if (idx < post.size()) post[idx]->setEnabled(!post[idx]->getEnabled());
	*/
switch (key) {
		
	case OF_KEY_DOWN: gui.prevPage(); break;
	case OF_KEY_UP: gui.nextPage(); break;
	case 'g':
		gui.toggleDraw();
		break;
	case 'n':
		distanceMini-=5;
		break;
	case 'm':
		distanceMini+=5;
		break;
	case 'v':
		limit-=5;
		break;
	case 'b':
		limit+=5;
		break;
		
	default:
		break;
}

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){
	

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

	
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	if(_activeBox2d){
	ofPtr<CustomParticle> p = ofPtr<CustomParticle>(new CustomParticle);
	p.get()->setPhysics(1.0, 0.5, 0.3);
	string tempString;
	tempString = wordTab[(int)ofRandom(0,wordTab.size())];
	int lenghtString = tempString.size();
	p.get()->setup(box2d.getWorld(),x,y,lenghtString*15,25);
    p.get()->setVelocity(ofRandom(-10,10),ofRandom(-10,10));
	p.get()->setupTheCustomData((int)1,tempString,1);

	particles.push_back(p);
    }

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}

void testApp::audioIn(float * input, int bufferSize, int nChannels){	
	float curVol = 0.0;
	// samples are "interleaved"
	int numCounted = 0;	
	//lets go through each sample and calculate the root mean square which is a rough way to calculate volume	
	for (int i = 0; i < bufferSize; i++){
		left[i]		= input[i*2]*0.5;
		right[i]	= input[i*2+1]*0.5;
		
		curVol += left[i] * left[i];
		curVol += right[i] * right[i];
		numCounted+=2;
	}
	//this is how we get the mean of rms :) 
	curVol /= (float)numCounted;
	// this is how we get the root of rms :) 
	curVol = sqrt( curVol );
	smoothedVol *= 0.93;
	smoothedVol += 0.07 * curVol;
	bufferCounter++;	
}


//draw the model manually
void testApp::drawWithMesh(){
    
	//get the model attributes we need
	ofVec3f scale = model.getScale();
	ofVec3f position = model.getPosition();
	float normalizedScale = model.getNormalizedScale();
	ofVboMesh mesh = model.getMesh(0);
	ofTexture texture = model.getTextureForMesh(0);
	ofMaterial material = model.getMaterialForMesh(0);
	
    ofPushMatrix();
	
	//translate and scale based on the positioning.
	ofTranslate(position);
	//ofRotate(-ofGetMouseX(), 0, 1, 0);
	//ofRotate(90,1,0,0);
    
	
	ofScale(normalizedScale, normalizedScale, normalizedScale);
	ofScale(scale.x,scale.y,scale.z);
	
	//modify mesh with some noise
	float liquidness = 5;
	float amplitude = mouseY/100.0;
	float speedDampen = 5;
    /*
	vector<ofVec3f>& verts = mesh.getVertices();
	for(unsigned int i = 0; i < verts.size(); i++){
		verts[i].x += ofSignedNoise(verts[i].x/liquidness, verts[i].y/liquidness,verts[i].z/liquidness, ofGetElapsedTimef()/speedDampen)*amplitude;
		verts[i].y += ofSignedNoise(verts[i].z/liquidness, verts[i].x/liquidness,verts[i].y/liquidness, ofGetElapsedTimef()/speedDampen)*amplitude;
		verts[i].z += ofSignedNoise(verts[i].y/liquidness, verts[i].z/liquidness,verts[i].x/liquidness, ofGetElapsedTimef()/speedDampen)*amplitude;
	}*/
    
	//draw the model manually
	texture.bind();
	material.begin();
	//mesh.drawWireframe(); //you can draw wireframe too
	mesh.drawFaces();
	material.end();
	texture.unbind();
	
	ofPopMatrix();
    
}

