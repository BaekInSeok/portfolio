#pragma once
#include <gl\glut.h>
#include <iostream>
#include "glm\glm.hpp"
#include "glm\gtx\norm.hpp"
#include <iostream>
using namespace glm;
using namespace std;
class CParticle
{
public:
	CParticle();
	~CParticle();

	void update(float dt);

	void setPos(vec3 Pos);
	void setVel(vec3 Vel);
	void setAcc(vec3 Acc);
	void setForce(vec3 Force);

	void setMass(float mass);
	void setLifetime(float time);


	vec3 getPos();
	vec3 getVel();
	vec3 getAcc();
	vec3 getForce();

	float getMass();
	float getLifeTime();

	//simulation interface
	void Init();
	void UpdateState(float h, int method);
public:
	vec3 mPosition;
	vec3 mVelocity;
	vec3 mAcceleration;
	vec3 mForce;

	float mMass;
	float mLifeTime;

};

