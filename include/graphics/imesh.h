/*
 * Copyright (c) 2011-2013, Guillermo A. Amaral B. (gamaral) <g@maral.me>
 * All rights reserved.
 *
 * This file is part of Marshmallow Game Engine.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   1. Redistributions of source code must retain the above copyright notice,
 *      this list of conditions and the following disclaimer.
 *
 *   2. Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 * EVENT SHALL THE CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * The views and conclusions contained in the software and documentation are
 * those of the authors and should not be interpreted as representing official
 * policies, either expressed or implied, of the project as a whole.
 */

#pragma once

/*!
 * @file
 *
 * @author Guillermo A. Amaral B. (gamaral) <g@maral.me>
 */

#ifndef MARSHMALLOW_GRAPHICS_IMESH_H
#define MARSHMALLOW_GRAPHICS_IMESH_H 1

#include <core/iserializable.h>

#include <graphics/config.h>

MARSHMALLOW_NAMESPACE_BEGIN
namespace Core { /******************************************** Core Namespace */
	class Type;
} /*********************************************************** Core Namespace */

namespace Math { /******************************************** Math Namespace */
	struct Vector2;
} /*********************************************************** Math Namespace */

namespace Graphics { /************************************ Graphics Namespace */

	class Color;
	struct ITextureCoordinateData;
	struct ITextureData;
	struct IVertexData;

	/*! @brief Graphics Mesh Interface */
	struct MARSHMALLOW_GRAPHICS_EXPORT
	IMesh : public Core::ISerializable
	{
		enum Flag {
			TextureCoordinateFree = (1 << 0),
			TextureDataFree       = (1 << 1),
			VertexDataFree        = (1 << 2),
			None                  = 0
		};

		virtual ~IMesh(void);

		virtual ITextureCoordinateData * textureCoordinateData(void) const = 0;
		virtual ITextureData * textureData(void) const = 0;
		virtual IVertexData * vertexData(void) const = 0;

		virtual const Graphics::Color & color(void) const = 0;
		virtual float rotation(void) const = 0;
		virtual void scale(float &x, float &y) const = 0;

		virtual int flags(void) const = 0;

		virtual Math::Vector2 vertex(uint16_t index) const = 0;
		virtual void textureCoordinate(uint16_t index, float &u, float &v) const = 0;
		virtual int count(void) const = 0;

		virtual const Core::Type & type(void) const = 0;
	};

} /******************************************************* Graphics Namespace */
MARSHMALLOW_NAMESPACE_END

#endif
