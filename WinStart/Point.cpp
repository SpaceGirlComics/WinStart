#include "Point.h"
#include <math.h>

Point::Point() : Object()
{
	type = "Point";
	id = type + count;

	kg = ks = s = kc = 1.0f;
	fx = fy = ax = ay = dx = dy = x = y = fr = fg = fb = fa = fs = as = ds = ar = ag = ab = aa = dr = dg = db = da = 0.0f;
	r = g = b = a = 255;
}

Point::Point(const String& _id) : Object(_id)
{
	type = "Point";

	kg = ks = s = kc = 1.0f;
	fx = fy = ax = ay = dx = dy = x = y = fr = fg = fb = fa = fs = as = ds = ar = ag = ab = aa = dr = dg = db = da = 0.0f;
	r = g = b = a = 255;
}

Point::Point(const Point& _cpy) : Object((Object&)_cpy)
{
	x = _cpy.x;
	y = _cpy.y;
	fx = _cpy.fx;
	fy = _cpy.fy;
	dx = _cpy.dx;
	dy = _cpy.dy; 
	m = _cpy.m;

	s = _cpy.s;
	fs = _cpy.fs;
	ds = _cpy.ds;
	ms = _cpy.ms;

	r = _cpy.r;
	g = _cpy.g;
	b = _cpy.b;
	fr = _cpy.fr;
	fg = _cpy.fg;
	fb = _cpy.fb;
	dr = _cpy.dr;
	dg = _cpy.dg;
	db = _cpy.db;
	mc = _cpy.mc;

	a = _cpy.a;
	fa = _cpy.fa;
	da = _cpy.da;
	ma = _cpy.ma;
}

//void Point::update(int _time)
List<Message*> Point::update(int _time)
{
	ax = fx / kg;
	ay = fy / kg;
	dx += ax * delta;
	dy += ay * delta;
	fy = fx = 0.0f;
	x += dx*delta;
	y += dy*delta;

	as = fs / ks;
	ds += as*delta;
	fs = 0.0f;
	s += ds*delta;

	ar += fr / kc;
	ag += fg / kc;
	ab += fb / kc;
	aa += fa / kc;
	dr += ar*delta;
	dg += ag*delta;
	db += ab*delta;
	da += aa*delta;
	fr = fg = fb = fa = 0.0f;
	r += (unsigned char) dr*delta;
	g += (unsigned char) dg*delta;
	b += (unsigned char) db*delta;
	a += (unsigned char) da*delta;

	return(Object::update(_time));
	/*for (int x = 0; x < subs.getLength(); x++)
	{
		(*subs.pointTo())->update(_time);
		subs.next();
	}
	subs.reset();*/
}

Point& Point::operator = (const Point& _rhs)
{
	if (this == &_rhs)
	{
		return(*this);
	}

	x = _rhs.x;
	y = _rhs.y;
	fx = _rhs.fx;
	fy = _rhs.fy;
	dx = _rhs.dx;
	dy = _rhs.dy;
	m = _rhs.m;

	s = _rhs.s;
	fs = _rhs.fs;
	ds = _rhs.ds;
	ms = _rhs.ms;

	r = _rhs.r;
	g = _rhs.g;
	b = _rhs.b;
	fr = _rhs.fr;
	fg = _rhs.fg;
	fb = _rhs.fb;
	dr = _rhs.dr;
	dg = _rhs.dg;
	db = _rhs.db;
	mc = _rhs.mc;

	a = _rhs.a;
	fa = _rhs.fa;
	da = _rhs.da;
	ma = _rhs.ma;
	return(*this);
}

void Point::translate(float _x, float _y)
{
	x += _x;
	y += _y;
}

void Point::setPosition(float _x, float _y)
{
	x = _x;
	y = _y;
}

void Point::addLinearForce(float _x, float _y)
{
	fx += _x;
	fy += _y;
}

void Point::setLinearForce(float _x, float _y)
{
	fx = _x;
	fy = _y;
}

void Point::addLinearAcceleration(float _x, float _y)
{
	ax += _x;
	ay += _y;
}

void Point::setLinearAcceleration(float _x, float _y)
{
	ax = _x;
	ay = _y;
}

void Point::addLinearVelocity(float _x, float _y)
{
	dx += _x;
	dy += _y;
	float mag = getLinearVelocityMagnatude();
	if (mag > m)
	{
		dx *= m / mag;
		dy *= m / mag;
	}
}

void Point::setLinearVelocity(float _x, float _y)
{
	dx = _x;
	dy = _y;
	float mag = getLinearVelocityMagnatude();
	if (mag > m)
	{
		dx *= m / mag;
		dy *= m / mag;
	}
}

void Point::setMaxLinearVelocity(float _m)
{
	m = _m;
	float mag = getLinearVelocityMagnatude();
	if (mag > m)
	{
		dx *= m / mag;
		dy *= m / mag;
	}
}

void Point::setPositionWeight(float _kg)
{
	kg = _kg;
}

void Point::setScale(float _s)
{
	s = _s;
}

void Point::setRelaviveScale(float _s)
{
	s += _s;
}

void Point::addScalarForce(float _s)
{
	fs += _s;
}

void Point::setScalarForce(float _s)
{
	fs = _s;
}

void Point::addScalarAcceleration(float _s)
{
	as += _s;
}

void Point::setScalarAcceleration(float _s)
{
	as = _s;
}

void Point::addScalarVelocity(float _s)
{
	ds += _s;
	if (ds > ms)
	{
		ds = ms;
	}
}

void Point::setScalarVelocity(float _s)
{
	ds = _s;
	if (ds > ms)
	{
		ds = ms;
	}
}

void Point::setMaxScalarVelocity(float _s)
{
	ms = _s;
	if (ds > ms)
	{
		ds = ms;
	}
}

void Point::setScalarWeight(float _kg)
{
	ks = _kg;
}

void Point::setColor(unsigned char _r, unsigned char _b, unsigned char _g)
{
	r = _r;
	g = _g;
	b = _b;
}

void Point::setRelativeColor(unsigned char _r, unsigned char _b, unsigned char _g)
{
	r += _r;
	g += _g;
	b += _b;
}

void Point::addChromaticForce(float _r, float _b, float _g)
{
	fr += _r;
	fg += _g;
	fb += _b;
}

void Point::setChromaticForce(float _r, float _b, float _g)
{
	fr = _r;
	fg = _g;
	fb = _b;
}

void Point::addChromaticAcceleration(float _r, float _b, float _g)
{
	ar += _r;
	ag += _g;
	ab += _b;
}

void Point::setChromaticAcceleration(float _r, float _b, float _g)
{
	ar = _r;
	ag = _g;
	ab = _b;
}

void Point::addChromaticVelocity(float _r, float _b, float _g)
{
	dr += _r;
	dg += _g;
	db += _b;
	float mag = getChromaticVelocityMagnatude();
	if (mc > mag)
	{
		dr *= mc / mag;
		dg *= mc / mag;
		db *= mc / mag;
	}
}

void Point::setChromaticVelocity(float _r, float _b, float _g)
{
	dr = _r;
	dg = _g;
	db = _b;
	float mag = getChromaticVelocityMagnatude();
	if (mc > mag)
	{
		dr *= mc / mag;
		dg *= mc / mag;
		db *= mc / mag;
	}
}

void Point::setMaxChromaticVelocity(float _c)
{
	mc = _c;
	float mag = getChromaticVelocityMagnatude();
	if (mc > mag)
	{
		dr *= mc / mag;
		dg *= mc / mag;
		db *= mc / mag;
	}
}

void Point::setChromaticWeight(float _kg)
{
	kc = _kg;
}

void Point::setAlpha(unsigned char _a)
{
	a = _a;
}

void Point::setRelativeAlpha(char _a)
{
	a += _a;
}

void Point::addAlphaForce(float _s)
{
	fa += _s;
}

void Point::setAlphaForce(float _s)
{
	fa = _s;
}

void Point::addAlphaAcceleration(float _s)
{
	aa += _s;
}

void Point::setAlphaAcceleration(float _s)
{
	aa = _s;
}

void Point::addAlphaVelocity(float _s)
{
	da += _s;
	if (da > ma)
	{
		da = ma;
	}
}

void Point::setAlphaVelocity(float _s)
{
	da = _s;
	if (da > ma)
	{
		da = ma;
	}
}

void Point::setMaxAlphaVelocity(float _s)
{
	ma = _s;
	if (da > ma)
	{
		da = ma;
	}
}

float Point::getX()
{
	return(x);
}

float Point::getY()
{
	return(y);
}

float Point::getVerticalForce()
{
	return(fy);
}

float Point::getHoriozontalForce()
{
	return(fx);
}

float Point::getLinearForceMagnatude()
{
	return((float)sqrt(fx*fx+fy*fy));
}

float Point::getVerticalAcceleration()
{
	return(ay);
}

float Point::getHoriozontalAcceleration()
{
	return(ax);
}

float Point::getLinearAccelerationMagnatude()
{
	return((float)sqrt(ax*ax + ay*ay));
}

float Point::getVerticalVelocity()
{
	return(dy);
}

float Point::getHoriozontalVelocity()
{
	return(dx);
}

float Point::getLinearVelocityMagnatude()
{
	return((float)sqrt(ax*ax + ay*ay));
}

float Point::getMaxLinearVelocity()
{
	return(m);
}

float Point::getPositionWeight()
{
	return(kg);
}

float Point::getScale()
{
	return(s);
}

float Point::getScalarFoce()
{
	return(fs);
}

float Point::getScalarAcceleration()
{
	return(as);
}

float Point::getScalarVelocity()
{
	return(ds);
}

float Point::getMaxScalarVelocity()
{
	return(ms);
}

float Point::getScalarWeight()
{
	return(ks);
}

unsigned char Point::getRed()
{
	return(r);
}

unsigned char Point::getGreen()
{
	return(g);
}

unsigned char Point::getBlue()
{
	return(b);
}

float Point::getRedForce()
{
	return(fr);
}

float Point::getGreenForce()
{
	return(fg);
}

float Point::getBlueForce()
{
	return(fb);
}

float Point::getChromaticForceMagnatude()
{
	return((float)sqrt(fr*fr + fg*fg + fb*fb));
}

float Point::getRedAcceleration()
{
	return(ar);
}

float Point::getGreenAcceleration()
{
	return(g);
}

float Point::getBlueAcceleration()
{
	return(ab);
}

float Point::getChromaticAccelerationMagnatude()
{
	return((float)sqrt(ar*ar + ag*ag + ab*ab));
}

float Point::getRedVelocity()
{
	return(dr);
}
float Point::getGreenVelocity()
{
	return(dg);
}

float Point::getBlueVelocity()
{
	return(db);
}

float Point::getChromaticVelocityMagnatude()
{
	return((float)sqrt(dr*dr + dg*dg + db*db));
}

float Point::getMaxChromaticVelocity()
{
	return(mc);
}

float Point::getChromaticWeight()
{
	return(kc);
}

unsigned char Point::getAlpha()
{
	return(a);
}

float Point::getAlphaForce()
{
	return(fa);
}

float Point::getAlphaAcceleration()
{
	return(aa);
}

float Point::getAlphaVelocity()
{
	return(da);
}

float Point::getAlphaMaxVelocity()
{
	return(ma);
}

Point::~Point()
{

}

void Point::proc(unsigned int _oc, XPARAM _wParam, YPARAM _lParam)
{
	switch (_oc)
	{
		case TRN: // void translate(float _x, float _y);
		{
			translate((float) _wParam, (float)_lParam);
			break;
		}
		case POS: // void setPosition(float _x, float _y)
		{
			setPosition((float)_wParam, (float)_lParam);
			break;
		}
		case LFA: // void addLinearForce(float _x, float _y)
		{
			addLinearForce((float)_wParam, (float)_lParam);
			break;
		}
		case LFS: // void setLinearForce(float _x, float _y)
		{
			setLinearForce((float)_wParam, (float)_lParam);
			break;
		}
		case LAA: // void addLinearAcceleration(float _x, float _y)
		{
			addLinearAcceleration((float)_wParam, (float)_lParam);
			break;
		}
		case LAS: // void setLinearAcceleration(float _x, float _y);
		{
			setLinearAcceleration((float)_wParam, (float)_lParam);
			break;
		}
		case LVA: // void addLinearVelocity(float _x, float _y)
		{
			addLinearVelocity((float)_wParam, (float)_lParam);
			break;
		}
		case LVS: // void setLinearVelocity(float _x, float _y)
		{
			setLinearVelocity((float)_wParam, (float)_lParam);
			break;
		}
		case LVM: // void setMaxLinearVelocity(float _m);
		{
			setMaxLinearVelocity((float)_wParam);
			break;
		}
		case PWS: // void setPositionWeight(float kg);
		{
			setPositionWeight((float)_wParam);
			break;
		}
		case SCS: // void setScale(float _s);
		{
			setScale((float)_wParam);
			break;
		}
		case SCR: // void setRelaviveScale(float _s);
		{
			setRelaviveScale((float)_wParam);
			break;
		}
		case SFA: // void addScalarForce(float _s);
		{
			addScalarForce((float)_wParam);
			break;
		}
		case SFS: // void setScalarForce(float _s);
		{
			setScalarForce((float)_wParam);
			break;
		}
		case SAA: // void addScalarAcceleration(float _s);
		{
			addScalarAcceleration((float)_wParam);
			break;
		}
		case SAS: // void setScalarAcceleration(float _s);
		{
			setScalarAcceleration((float)_wParam);
			break;
		}
		case SVA: // void addScalarVelocity(float _s);
		{
			addScalarVelocity((float)_wParam);
			break;
		}
		case SVS: // void setScalarVelocity(float _s);
		{
			setScalarVelocity((float)_wParam);
			break;
		}
		case SVM: // void setMaxScalarVelocity(float _s);
		{
			setMaxScalarVelocity((float)_wParam);
			break;
		}
		case SWS: // void setScalarWeight(float kg);
		{
			setScalarWeight((float)_wParam);
			break;
		}
		case CLR: // void setColor(unsigned char _r, unsigned char _b, unsigned char _g);
		{
			setColor((unsigned char)_wParam, (unsigned char)(_wParam>>8), (unsigned char)(_wParam>>16));
			break;
		}
		case CRS: // void setRelativeColor(unsigned char _r, unsigned char _b, unsigned char _g);
		{
			setRelativeColor((unsigned char)_wParam, (unsigned char)(_wParam >> 8), (unsigned char)(_wParam >> 16));
			break;
		}
		case CFA: // void addChromaticForce(float _r, float _b, float _g);
		{
			addChromaticForce(((LPTHREEFLOAT)_wParam)->r, 
							((LPTHREEFLOAT)_wParam)->b,
							((LPTHREEFLOAT)_wParam)->g);
			break;
		}
		case CFS: // void setChromaticForce(float _r, float _b, float _g);
		{
			setChromaticForce(((LPTHREEFLOAT)_wParam)->r,
							((LPTHREEFLOAT)_wParam)->b,
							((LPTHREEFLOAT)_wParam)->g);
			break;
		}
		case CAA: // void addChromaticAcceleration(float _r, float _b, float _g);
		{
			addChromaticAcceleration(((LPTHREEFLOAT)_wParam)->r,
									((LPTHREEFLOAT)_wParam)->b,
									((LPTHREEFLOAT)_wParam)->g);
			break;
		}
		case CAS: // void setChromaticAcceleration(float _r, float _b, float _g);
		{
			setChromaticAcceleration(((LPTHREEFLOAT)_wParam)->r,
									((LPTHREEFLOAT)_wParam)->b,
									((LPTHREEFLOAT)_wParam)->g);
			break;
		}
		case CVA: // void addChromaticVelocity(float _r, float _b, float _g);
		{
			addChromaticVelocity(((LPTHREEFLOAT)_wParam)->r,
								((LPTHREEFLOAT)_wParam)->b,
								((LPTHREEFLOAT)_wParam)->g);
			break;
		}
		case CVS: // void setChromaticVelocity(float _r, float _b, float _g);
		{
			setChromaticVelocity(((LPTHREEFLOAT)_wParam)->r,
								((LPTHREEFLOAT)_wParam)->b,
								((LPTHREEFLOAT)_wParam)->g);
			break;
		}
		case CVM: // void setMaxChromaticVelocity(float _c);
		{
			setMaxChromaticVelocity((float)_wParam);
			break;
		}
		case CWS: // void setChromaticWeight(float kg);
		{
			setChromaticWeight((float)_wParam);
			break;
		}
		case APL: // void setAlpha(unsigned char _a);
		{
			setAlpha((unsigned char)_wParam);
			break;
		}
		case APS: // void setRelativeAlpha(char _a);
		{
			setRelativeAlpha((char)_wParam);
			break;
		}
		case AFA: // void addAlphaForce(float _s);
		{
			addAlphaForce((float)_wParam);
			break;
		}
		case AFS: // void setAlphaForce(float _s);
		{
			setAlphaForce((float)_wParam);
			break;
		}
		case AAA: // void addAlphaAcceleration(float _s);
		{
			addAlphaAcceleration((float)_wParam);
			break;
		}
		case AAS: // void setAlphaAcceleration(float _s);
		{
			setAlphaAcceleration((float)_wParam);
			break;
		}
		case AVA: // void addAlphaVelocity(float _s);
		{
			addAlphaVelocity((float)_wParam);
			break;
		}
		case AVS: // void setAlphaVelocity(float _s);
		{
			setAlphaVelocity((float)_wParam);
			break;
		}
		case AVM: // void setMaxAlphaVelocity(float _s);
		{
			setMaxAlphaVelocity((float)_wParam);
			break;
		}
		
		default:
		{
			Object::proc(_oc, _wParam, _lParam);
			break;
		}
	}
}
