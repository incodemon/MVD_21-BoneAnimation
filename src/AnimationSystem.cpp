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
    //avoid updating joint that don't have keyframes
    if (joint->num_keyframes > 0) {
        joint->current_keyframe++;
        if (joint->current_keyframe == joint->num_keyframes) {
            joint->current_keyframe = 0;
        }

        //set the joint matrix from the keyframe
        joint->matrix = joint->keyframes[joint->current_keyframe];

        for (auto& c : joint->children) {
            incrementJointFrame_(c);
        }
    }

}

void AnimationSystem::update(float dt) {
    //create global frame trigger here
    bool trigger_frame = false;
    //increment counter
    ms_counter_ += dt * 1000;

    if (ms_counter_ >= ms_per_frame_) {
        trigger_frame = true;
        ms_counter_ = 0;
    }
    auto& jointchain = ECS.getAllComponents<JointChain>();
    for (auto& sm : jointchain) {
        if (!sm.root) continue;
        if (trigger_frame)
            incrementJointFrame_(sm.root);
    }
}
