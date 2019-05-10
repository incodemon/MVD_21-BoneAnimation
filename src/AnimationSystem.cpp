//
//  AnimationSystem.cpp
//

#include "AnimationSystem.h"
#include "extern.h"

//destructor
AnimationSystem::~AnimationSystem() {

}

//set initial state 
void AnimationSystem::init() {

}

//called after loading everything
void AnimationSystem::lateInit() {

    
}

//increments the current keyframe model matrix for the given joint
//(loops after reaching maximum keyframes)
//then recursively calls function for children joints
void AnimationSystem::incrementJointFrame_(Joint* joint) {
    

}

void AnimationSystem::update(float dt) {
    //create global frame trigger here

    
}
