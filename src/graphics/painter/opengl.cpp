/*
 * Copyright 2011 Marshmallow Engine. All rights reserved.
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

#include "graphics/painter.h"

/*!
 * @file
 *
 * @author Guillermo A. Amaral B. (gamaral) <g@maral.me>
 */

#include <GL/gl.h>

#include "core/logger.h"
#include "graphics/linegraphic.h"
#include "graphics/pointgraphic.h"
#include "graphics/polygongraphic.h"
#include "graphics/quadgraphic.h"
#include "graphics/trianglegraphic.h"

MARSHMALLOW_NAMESPACE_USE;
using namespace Graphics;

struct Painter::Internal
{
	void
	drawPointGraphic(const PointGraphic &g)
	{
		UNUSED(g);
		glBegin(GL_POINTS);
		glVertex2f(0.f, 0.f);
		glEnd();
	}

	void
	drawLineGraphic(const LineGraphic &g)
	{
		glBegin(GL_LINES);
		for (int i = 0; i < 2; ++i) {
			const Math::Vector2 &l_p = g[i];
			glVertex2f(static_cast<GLfloat>(l_p.rx()),
			           static_cast<GLfloat>(l_p.ry()));
		}
		glEnd();
	}

	void
	drawTriangleGraphic(const TriangleGraphic &g)
	{
		glBegin(GL_TRIANGLES);
		for (int i = 0; i < 3; ++i) {
			const Math::Vector2 &l_p = g[i];
			glVertex2f(static_cast<GLfloat>(l_p.rx()),
			           static_cast<GLfloat>(l_p.ry()));
		}
		glEnd();
	}

	void
	drawQuadGraphic(const QuadGraphic &g)
	{
		static const GLfloat l_texcoords[4][2] = {{0,0},{0,1},{1,1},{1,0}};

		glBegin(GL_QUADS);
		for (int i = 0; i < 4; ++i) {
			const Math::Vector2 &l_p = g[i];
			glTexCoord2f(l_texcoords[i][0], l_texcoords[i][1]);
			glVertex2f(static_cast<GLfloat>(l_p.rx()),
			           static_cast<GLfloat>(l_p.ry()));
		}
		glEnd();
	}

	void
	drawPolygonGraphic(const PolygonGraphic &g)
	{
		glBegin(GL_POLYGON);
		const int l_c = g.count();
		for (int i = 0; i < l_c; ++i) {
			const Math::Vector2 &l_p = g[i];
			glVertex2f(static_cast<GLfloat>(l_p.rx()),
			           static_cast<GLfloat>(l_p.ry()));
		}
		glEnd();
	}
} MGP;

void
Painter::Initialize(void)
{
}

void
Painter::Finalize(void)
{
}

void
Painter::Draw(const IGraphic &g, const Math::Point2 &o)
{
	const bool  l_texture = (g.texture());
	const float l_rotate_angle = g.rotation();

	Blend(AlphaBlending);

	/* set color */
	const Graphics::Color &l_color = g.color();
	glColor4f(l_color[0], l_color[1], l_color[2], l_color[3]);

	/* set texture */
	if (l_texture)
		glBindTexture(GL_TEXTURE_2D, g.texture()->tid());

	glPushMatrix();
	glTranslatef(o.rx(), o.ry(), 0.f);

	if (l_rotate_angle)
		glRotatef(l_rotate_angle, 0, 0, 1);

	/* actually draw graphic */
	if (g.type() == QuadGraphic::Type)
		MGP.drawQuadGraphic(static_cast<const QuadGraphic &>(g));
	else if (g.type() == LineGraphic::Type)
		MGP.drawLineGraphic(static_cast<const LineGraphic &>(g));
	else if (g.type() == TriangleGraphic::Type)
		MGP.drawTriangleGraphic(static_cast<const TriangleGraphic &>(g));
	else if (g.type() == PolygonGraphic::Type)
		MGP.drawPolygonGraphic(static_cast<const PolygonGraphic &>(g));
	else if (g.type() == PointGraphic::Type)
		MGP.drawPointGraphic(static_cast<const PointGraphic &>(g));
	else WARNING1("Unknown graphic type");

	glPopMatrix();

	if (l_texture)
		glBindTexture(GL_TEXTURE_2D, 0);

	Blend(NoBlending);
}

void
Painter::Blend(BlendTypes b)
{
	switch (b) {
	case AdditiveBlending:
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE);
	break;
	case AlphaBlending:
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	break;
	case MultiplyBlending:
		glEnable(GL_BLEND);
		glBlendFunc(GL_ZERO, GL_SRC_COLOR);
	break;
	case NoBlending:
		glDisable(GL_BLEND);
	break;
	}
}

