#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    w = 1000;
    h = 1280;
    
    ofSetWindowShape(w, h);
    
    gridX = 5;
    gridY = 4;
    
    tileW = w/gridX;
    tileH = h/gridY;
    
    numImages = gridX * gridY;
    
    string path = "horizontalGrid1";
    ofDirectory dir(path);
    dir.listDir();
    
    for(int i = 0; i<dir.size(); i++){
        ofImage im;
        string imgPath = dir.getPath(i);
        im.load(imgPath);
        allImages.push_back(im);
    }
    
    random_shuffle(allImages.begin(), allImages.end());
    
    fbo.allocate(w, h);
    fbo.begin();
    ofClear(0);
    fbo.end();
    
    save = false;
    
    int inc = 0;
    for(int i = 0; i<numImages; i++){
        if(inc % 2 == 0){
            allImages[i].mirror(false, true);
        }
         inc++;
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    if(save){
        ofPixels savePix;
        fbo.readToPixels(savePix);
        ofSaveImage(savePix, "saved/"+ofGetTimestampString()+".png");
        save = false;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    int yPos = 0;
    int xPos = 0;
    
    fbo.begin();
    for(int i = 0; i<numImages; i++){

        allImages[i].draw(xPos, yPos, tileW, tileH);
        
        xPos += tileW;
        if(xPos >= w){
            xPos = 0;
            yPos += tileH;
        }
        
       
    }
    fbo.end();
    
    fbo.draw(0,0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'a'){
        random_shuffle(allImages.begin(), allImages.end());
    }
    
    if(key == 's'){
        save = !save;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
