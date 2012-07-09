/*
 * Copyright 2011-2012 Marshmallow Engine. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are
 * permitted provided that the following conditions are met:
 *
 *   1. Redistributions of source code must retain the above copyright notice, this list of
 *      conditions and the following disclaimer.
 *
 *   2. Redistributions in binary form must reproduce the above copyright notice, this list
 *      of conditions and the following disclaimer in the documentation and/or other materials
 *      provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY MARSHMALLOW ENGINE ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL MARSHMALLOW ENGINE OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * The views and conclusions contained in the software and documentation are those of the
 * authors and should not be interpreted as representing official policies, either expressed
 * or implied, of Marshmallow Engine.
 */

#include "math/point2.h"

/*!
 * @file
 *
 * @author Guillermo A. Amaral B. (gamaral) <g@maral.me>
 */

#include "math/vector2.h"

MARSHMALLOW_NAMESPACE_USE
using namespace Math;

Point2::Point2(float ax, float ay)
{
	m_value[0] = ax;
	m_value[1] = ay;
}

bool
Point2::operator==(const Point2 &rhs) const
{
	return(m_value[0] == rhs.m_value[0]
	    && m_value[1] == rhs.m_value[1]);
}

Vector2
Point2::difference(const Point2 &rhs) const
{
	return(Vector2(rhs.x() - x(), rhs.y() - y()));
}

Point2 &
Point2::operator*=(float rhs)
{
	m_value[0] *= rhs;
	m_value[1] *= rhs;
	return(*this);
}

Point2 &
Point2::operator+=(float rhs)
{
	m_value[0] += rhs;
	m_value[1] += rhs;
	return(*this);
}

Point2 &
Point2::operator-=(float rhs)
{
	m_value[0] -= rhs;
	m_value[1] -= rhs;
	return(*this);
}

Point2 &
Point2::operator*=(const Point2 &rhs)
{
	m_value[0] *= rhs.m_value[0];
	m_value[1] *= rhs.m_value[1];
	return(*this);
}

Point2 &
Point2::operator+=(const Point2 &rhs)
{
	m_value[0] += rhs.m_value[0];
	m_value[1] += rhs.m_value[1];
	return(*this);
}

Point2 &
Point2::operator-=(const Point2 &rhs)
{
	m_value[0] -= rhs.m_value[0];
	m_value[1] -= rhs.m_value[1];
	return(*this);
}

Point2 &
Point2::operator*=(const Vector2 &rhs)
{
	m_value[0] *= rhs.x();
	m_value[1] *= rhs.y();
	return(*this);
}

Point2 &
Point2::operator+=(const Vector2 &rhs)
{
	m_value[0] += rhs.x();
	m_value[1] += rhs.y();
	return(*this);
}

Point2 &
Point2::operator-=(const Vector2 &rhs)
{
	m_value[0] -= rhs.x();
	m_value[1] -= rhs.y();
	return(*this);
}

Point2
Point2::operator*(const Point2 &rhs) const
{
	return(Point2(m_value[0] * rhs[0], m_value[1] * rhs[1]));
}

Point2
Point2::operator+(const Point2 &rhs) const
{
	return(Point2(m_value[0] + rhs.m_value[0],
	              m_value[1] + rhs.m_value[1]));
}

Point2
Point2::operator-(const Point2 &rhs) const
{
	return(Point2(m_value[0] - rhs.m_value[0],
	              m_value[1] - rhs.m_value[1]));
}

Point2
Point2::operator*(const Vector2 &rhs) const
{
	return(Point2(m_value[0] * rhs[0], m_value[1] * rhs[1]));
}

Point2
Point2::operator+(const Vector2 &rhs) const
{
	return(Point2(m_value[0] + rhs.x(),
	              m_value[1] + rhs.y()));
}

Point2
Point2::operator-(const Vector2 &rhs) const
{
	return(Point2(m_value[0] - rhs.x(),
	              m_value[1] - rhs.y()));
}

Point2::operator Vector2(void) const
{
	return(Vector2(m_value[0], m_value[1]));
}

