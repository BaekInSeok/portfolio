#include "CParticle.h"

CParticle:: CParticle() {
	setLifetime(5.0f);
}
CParticle::~CParticle() {

}



void CParticle::update(float dt) {
	mAcceleration = mForce / mMass;  // a = f/m  newton 2nd law
	mVelocity += mAcceleration * dt;// v = a*t
	mPosition += mVelocity * dt; // d = v*t

}



void CParticle::setPos(vec3 Pos) 
{
	this->mPosition = Pos;
}
void CParticle::setVel(vec3 Vel) 
{
	this->mVelocity = Vel;
}
void CParticle::setAcc(vec3 Acc) 
{
	this->mAcceleration = Acc;
}
void CParticle::setForce(vec3 Force) 
{
	this->mForce = Force;
}
void CParticle::setMass(float mass)
{
	this->mMass = mass;
}
void CParticle::setLifetime(float time) 
{
	this->mLifeTime = time;
}
vec3 CParticle::getPos()
{
	return this->mPosition;
}
vec3 CParticle::getVel()
{
	return this->mVelocity;
}
vec3 CParticle::getAcc()
{
	return this->mAcceleration;
}
vec3 CParticle::getForce()
{
	return this->mForce;
}
float CParticle::getMass()
{
	return this->mMass;
}
float CParticle::getLifeTime()
{
	return this->mLifeTime;
}