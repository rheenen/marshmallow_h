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

#pragma once

/*!
 * @file
 *
 * @author Guillermo A. Amaral B. (gamaral) <g@maral.me>
 */

#ifndef GRAPHICS_QUADGRAPHIC_H
#define GRAPHICS_QUADGRAPHIC_H 1

#include "graphics/graphicbase.h"

#include "math/rect2.h"
#include "math/vector2.h"

MARSHMALLOW_NAMESPACE_BEGIN

namespace Graphics
{

	/*! @brief Graphics Quad Graphic class */
	class GRAPHICS_EXPORT QuadGraphic : public GraphicBase
	{
		Math::Vector2 m_vectors[4];

		NO_COPY(QuadGraphic);

	public:

		QuadGraphic(const Math::Vector2 &tl,
		            const Math::Vector2 &bl,
		            const Math::Vector2 &br,
		            const Math::Vector2 &tr);
		QuadGraphic(const Math::Rect2 &rect);
		QuadGraphic(void);
		virtual ~QuadGraphic(void);

	public: /* operators */

		const Math::Vector2 & operator[](int index) const
		    { return(m_vectors[index % 4]); }

	public: /* virtual */

		VIRTUAL const Core::Type & type(void) const
		    { return(Type); }

		VIRTUAL bool serialize(TinyXML::TiXmlElement &node) const;
		VIRTUAL bool deserialize(TinyXML::TiXmlElement &node);

	public: /* static */

		static const Core::Type Type;
	};
	typedef Core::Shared<QuadGraphic> SharedQuadGraphic;
	typedef Core::Weak<QuadGraphic> WeakQuadGraphic;

}

MARSHMALLOW_NAMESPACE_END

#endif
