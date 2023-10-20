#ifndef POINT_H
#define POINT_H

/**
* Simple Class to define a 2D Point position,
* scale, color, and weight. allows forces to be applied
*
* @
* @author Chris Turner
* @version 0.1.8.1.2020
* @since 0.1.8.1.2020
* @see Object.h
* @see Point.cpp
*/

#include "Object.h"

class Point : public Object
{
public:
	Point();
	Point(const String& _id);
	Point(const Point& _cpy);

	//void update(int _time);
	virtual List<Message*> update(int _time);
	Point& operator = (const Point& _rhs);

	void translate(float _x, float _y);
	void setPosition(float _x, float _y);
	void addLinearForce(float _x, float _y);
	void setLinearForce(float _x, float _y);
	void addLinearAcceleration(float _x, float _y);
	void setLinearAcceleration(float _x, float _y);
	void addLinearVelocity(float _x, float _y);
	void setLinearVelocity(float _x, float _y);
	void setMaxLinearVelocity(float _m);
	void setPositionWeight(float kg);

	void setScale(float _s);
	void setRelaviveScale(float _s);
	void addScalarForce(float _s);
	void setScalarForce(float _s);
	void addScalarAcceleration(float _s);
	void setScalarAcceleration(float _s);
	void addScalarVelocity(float _s);
	void setScalarVelocity(float _s);
	void setMaxScalarVelocity(float _s);
	void setScalarWeight(float kg);

	void setColor(unsigned char _r, unsigned char _b, unsigned char _g);
	void setRelativeColor(unsigned char _r, unsigned char _b, unsigned char _g);
	void addChromaticForce(float _r, float _b, float _g);
	void setChromaticForce(float _r, float _b, float _g);
	void addChromaticAcceleration(float _r, float _b, float _g);
	void setChromaticAcceleration(float _r, float _b, float _g);
	void addChromaticVelocity(float _r, float _b, float _g);
	void setChromaticVelocity(float _r, float _b, float _g);
	void setMaxChromaticVelocity(float _c);
	void setChromaticWeight(float kg);

	void setAlpha(unsigned char _a);
	void setRelativeAlpha(char _a);
	void addAlphaForce(float _s);
	void setAlphaForce(float _s);
	void addAlphaAcceleration(float _s);
	void setAlphaAcceleration(float _s);
	void addAlphaVelocity(float _s);
	void setAlphaVelocity(float _s);
	void setMaxAlphaVelocity(float _s);

	float getX();
	float getY();
	float getVerticalForce();
	float getHoriozontalForce();
	float getLinearForceMagnatude();
	float getVerticalAcceleration();
	float getHoriozontalAcceleration();
	float getLinearAccelerationMagnatude();
	float getVerticalVelocity();
	float getHoriozontalVelocity();
	float getLinearVelocityMagnatude();
	float getMaxLinearVelocity();
	float getPositionWeight();

	float getScale();
	float getScalarFoce();
	float getScalarAcceleration();
	float getScalarVelocity();
	float getMaxScalarVelocity();
	float getScalarWeight();

	unsigned char getRed();
	unsigned char getGreen();
	unsigned char getBlue();
	float getRedForce();
	float getGreenForce();
	float getBlueForce();
	float getChromaticForceMagnatude();
	float getRedAcceleration();
	float getGreenAcceleration();
	float getBlueAcceleration();
	float getChromaticAccelerationMagnatude();
	float getRedVelocity();
	float getGreenVelocity();
	float getBlueVelocity();
	float getChromaticVelocityMagnatude();
	float getMaxChromaticVelocity();
	float getChromaticWeight();

	unsigned char getAlpha();
	float getAlphaForce();
	float getAlphaAcceleration();
	float getAlphaVelocity();
	float getAlphaMaxVelocity();

	static const unsigned int TRN = 0x00000039; // void translate(float _x, float _y);
	static const unsigned int POS = 0x0000003A; // void setPosition(float _x, float _y)
	static const unsigned int LFA = 0x0000003B; // void addLinearForce(float _x, float _y)
	static const unsigned int LFS = 0x0000003C; // void setLinearForce(float _x, float _y)
	static const unsigned int LAA = 0x0000003D; // void addLinearAcceleration(float _x, float _y)
	static const unsigned int LAS = 0x0000003E; // void setLinearAcceleration(float _x, float _y);
	static const unsigned int LVA = 0x0000003F; // void addLinearVelocity(float _x, float _y)
	static const unsigned int LVS = 0x00000040; // void setLinearVelocity(float _x, float _y)
	static const unsigned int LVM = 0x00000041; // void setMaxLinearVelocity(float _m);
	static const unsigned int PWS = 0x00000042; // void setPositionWeight(float kg);
	static const unsigned int SCS = 0x00000043; // void setScale(float _s);
	static const unsigned int SCR = 0x00000044; // void setRelaviveScale(float _s);
	static const unsigned int SFA = 0x00000045; // void addScalarForce(float _s);
	static const unsigned int SFS = 0x00000046; // void setScalarForce(float _s);
	static const unsigned int SAA = 0x00000047; // void addScalarAcceleration(float _s);
	static const unsigned int SAS = 0x00000048; // void setScalarAcceleration(float _s);
	static const unsigned int SVA = 0x00000049; // void addScalarVelocity(float _s);
	static const unsigned int SVS = 0x0000004A; // void setScalarVelocity(float _s);
	static const unsigned int SVM = 0x0000004B; // void setMaxScalarVelocity(float _s);
	static const unsigned int SWS = 0x0000004C; // void setScalarWeight(float kg);
	static const unsigned int CLR = 0x0000004D; // void setColor(unsigned char _r, unsigned char _b, unsigned char _g);
	static const unsigned int CRS = 0x0000004E; // void setRelativeColor(unsigned char _r, unsigned char _b, unsigned char _g);
	static const unsigned int CFA = 0x0000004F; // void addChromaticForce(float _r, float _b, float _g);
	static const unsigned int CFS = 0x00000050; // void setChromaticForce(float _r, float _b, float _g);
	static const unsigned int CAA = 0x00000051; // void addChromaticAcceleration(float _r, float _b, float _g);
	static const unsigned int CAS = 0x00000052; // void setChromaticAcceleration(float _r, float _b, float _g);
	static const unsigned int CVA = 0x00000053; // void addChromaticVelocity(float _r, float _b, float _g);
	static const unsigned int CVS = 0x00000054; // void setChromaticVelocity(float _r, float _b, float _g);
	static const unsigned int CVM = 0x00000055; // void setMaxChromaticVelocity(float _c);
	static const unsigned int CWS = 0x00000056; // void setChromaticWeight(float kg);
	static const unsigned int APL = 0x00000057; // void setAlpha(unsigned char _a);
	static const unsigned int APS = 0x00000058; // void setRelativeAlpha(char _a);
	static const unsigned int AFA = 0x00000059; // void addAlphaForce(float _s);
	static const unsigned int AFS = 0x0000005A; // void setAlphaForce(float _s);
	static const unsigned int AAA = 0x0000005B; // void addAlphaAcceleration(float _s);
	static const unsigned int AAS = 0x0000005C; // void setAlphaAcceleration(float _s);
	static const unsigned int AVA = 0x0000005D; // void addAlphaVelocity(float _s);
	static const unsigned int AVS = 0x0000005E; // void setAlphaVelocity(float _s);
	static const unsigned int AVM = 0x0000005F; // void setMaxAlphaVelocity(float _s);

	~Point();
protected:
	float x, y;																				/** Position */
	float fx, fy;																			/** net forces */
	float ax, ay;																			/** acceleration */
	float dx, dy;																			/** current speed */
	float kg;																				/** weight/mass */
	float m;																				/** max speed */

	float s;																				/** scale */
	float fs;																				/** net scalar force */
	float as;																				/** scale accel */
	float ds;																				/** scalar speed */
	float ks;																				/** scale weight */
	float ms;																				/** max scalar speed */

	unsigned char r, g, b, a;																/** Red, Green, Blue, Alpha */
	float fr, fg, fb, fa;																	/** net chromatic forces */
	float ar, ag, ab, aa;																	/** color accel */
	float dr, dg, db, da;																	/** current chromatic rate of change */
	float kc;																				/** color weight; */
	float mc;																				/** max chromatic speed */
	float ma;																				/** max alpha speed */

	//virtual void pump();
	void proc(unsigned int _oc, XPARAM _wParam, YPARAM _lParam);						/** Processes messages specific to Point objects */
};
#endif

