/*----------------------------------------------------------------------------
                        _                              _ _       
        /\             | |                            | (_)      
       /  \   _ __   __| |_ __ ___  _ __ ___   ___  __| |_  __ _ 
      / /\ \ | '_ \ / _` | '__/ _ \| '_ ` _ \ / _ \/ _` | |/ _` |
     / ____ \| | | | (_| | | | (_) | | | | | |  __/ (_| | | (_| |
    /_/    \_\_| |_|\__,_|_|  \___/|_| |_| |_|\___|\__,_|_|\__,_|

    The contents of this file are subject to the Andromedia Public
	License Version 1.0 (the "License"); you may not use this file
	except in compliance with the License. You may obtain a copy of
	the License at http://www.andromedia.com/APL/

    Software distributed under the License is distributed on an
	"AS IS" basis, WITHOUT WARRANTY OF ANY KIND, either express or
	implied. See the License for the specific language governing
	rights and limitations under the License.

    The Original Code is Pueblo client code, released November 4, 1998.

    The Initial Developer of the Original Code is Andromedia Incorporated.
	Portions created by Andromedia are Copyright (C) 1998 Andromedia
	Incorporated.  All Rights Reserved.

	Andromedia Incorporated                         415.365.6700
	818 Mission Street - 2nd Floor                  415.365.6701 fax
	San Francisco, CA 94103

    Contributor(s):
	--------------------------------------------------------------------------
	   Chaco team:  Dan Greening, Glenn Crocker, Jim Doubek,
	                Coyote Lussier, Pritham Shetty.

					Wrote and designed original codebase.

------------------------------------------------------------------------------

	Implementation for GxQuaternion.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/portable/ChGraphx/GxQuaternion.cpp,v 1.7 1996/09/30 20:42:05 jimd Exp $


#include "GxQuaternion.h"


void GxQuaternion::set( float x, float y, float z, float angle )
{
	set(GxVec3f(x, y, z), angle);
}

void GxQuaternion::set( const GxVec3f& axis, float angle )
{
	double	sinHalfAngle;
	double	cosHalfAngle;

	/* The quaternion uses half angles. */
	sinHalfAngle = sin(angle / 2);
	cosHalfAngle = cos(angle / 2);
	m_v = axis;
	m_v *= sinHalfAngle;
	m_real = cosHalfAngle;

}

void GxQuaternion::set( GxVec3f dir, GxVec3f up )
{
	dir.normalize();					// make sure we start normalized
	up.normalize();						// this is why the args are not references
										// (so we can normalize what are really temp vars)
										 
										// Now compute v as the component 
										// of up perpendicular to dir
	float tempD = up.dot(dir);
	GxVec3f tempV(dir);
	tempV *= tempD;
	GxVec3f v(up);
	v -= tempV;
	v.normalize();						 // keep it a unit vector

										 // Use a cross product here
										 // to get the z-to-look rotation axis would 
										 // probably be more robust. Can change if 
										 // we have problems. Here's some code that might work
	GxVec3f 	dirZ (0.0f, 0.0f, -1.0f);
	GxVec3f 	axis = dirZ.cross(dir);
	if (axis.dot(axis) < 1e-12)
	{
		axis.set( 0, 1, 0);
	}
	else
	{
		axis.normalize();
	}
	double cosa = dirZ.dot(dir);
	GxQuaternion qLook(axis, float(acos(cosa)));


								// Rotate the world y vector to see where it ends up
								// then find the inverse rotation. 
								// Remember that to rotate a vector (x, y, z) by a quat q,
								// we make p the pure quaternion (0, x, y, z)
								// then we do: result = q * p * qConjugate
	GxQuaternion qInvLook = -qLook;

	//  Rotate the y axis by the look direction quaternion
	GxQuaternion qYAxis;
	qYAxis.m_real = 0.0;
	qYAxis.m_v.set(0, 1, 0);

	GxQuaternion qNewYAxis = qLook * qYAxis;
	qNewYAxis *= qInvLook;
	GxVec3f rotatedY = qNewYAxis.m_v;

	// Now find out how much to rotate about look dir to align ups
	cosa =  rotatedY.dot(v);
	if(cosa > 1.0) cosa = 1.0;		// even a little roundoff error can mess
	if(cosa < -1.0) cosa = -1.0;	// up the arccos's later.

								// This cross-product -oughta-
								// be +/- the look direction.
								// We'll trust it.
	GxVec3f cross = rotatedY.cross(v);

	GxQuaternion qUp;
	if(cross.dot(cross) > 1e-12)
	{
		cross.normalize();
		qUp.set(cross, float(acos(cosa)));
	}

	// Compose the 2 rotations 
	
	*this = qUp * qLook;
	normalize();
}

GxQuaternion& GxQuaternion::operator*=( const GxQuaternion& q )
{
	*this = *this * q;		// probably could be faster...
	return *this;
}

GxQuaternion GxQuaternion::operator*(GxQuaternion q) const
{
	GxQuaternion	prod;
	GxVec3f			v;

	prod.m_real = m_real * q.m_real - m_v.dot(q.m_v);
	prod.m_v = m_v.cross(q.m_v);
	v = m_v;
	v *= q.m_real;
	prod.m_v += v;

	v = q.m_v;
	v *= m_real;
	prod.m_v += v;


	return prod;
}

GxVec3f GxQuaternion::axis() const
{
	GxVec3f axis;
	float angle;
	AxisAngle(axis, angle);	 // extra call here - oh well
	return axis;	
}

float GxQuaternion::angle() const
{
	float	halfAngle;
	
	halfAngle = acos(m_real);
	return halfAngle * 2;
}

void GxQuaternion::AxisAngle(GxVec3f &axis, float &angle) const
{
	double	halfAngle;
	double	sinHalfAngle;
	
	halfAngle = acos(m_real);
	sinHalfAngle = sin(halfAngle);
	angle = halfAngle * 2;
	if ( sinHalfAngle < 1e-8 && sinHalfAngle > -1e-8 )
		axis.set(0,1,0);
	else
	{
		axis = m_v;
		sinHalfAngle = 1 / sinHalfAngle;
		axis *= sinHalfAngle;
	}
}

GxQuaternion GxQuaternion::slerp(const GxQuaternion &q, float u)
{
	// THIS ASSUMES UNIT QUATERNIONS: NORMALIZE FIRST!
	GxQuaternion q2(q);
	float cost = dot(q);

	if(cost < 0)
	{
		// use negative - it's closer along the great circle.
		cost = -cost;
		q2 *= -1.;
	}

	float theta = acos(cost);
	GxQuaternion	result;
	const float EPSILON = 1e-10;

	if(fabs(theta) > EPSILON)
	{
		float sint = sin(theta);
		float a = sin(theta * (1.- u)) / sint;
		float b = sin(theta * u) / sint;
		result.m_real = a * m_real + b * q2.m_real;
		GxVec3f v(q2.m_v);
		v *= b;
		result.m_v = m_v;
		result.m_v *= a;
		result.m_v += v;
	}
	else
	{
		return *this;
	}
	return result;
}

float GxQuaternion::dot(const GxQuaternion &q)
{
	return m_real * q.m_real +	 m_v.dot(q.m_v);
}

void GxQuaternion::normalize()
{
	float mag = dot(*this);
	if(mag != 0)
	{
		m_real /= mag;
		m_v *= 1. / mag;
	}
}


