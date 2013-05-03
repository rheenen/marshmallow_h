/*
 * Copyright (c) 2012-2013, Guillermo A. Amaral B. (gamaral) <g@maral.me>
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

#include "event/inputevent.h"

/*!
 * @file
 *
 * @author Guillermo A. Amaral B. (gamaral) <g@maral.me>
 */

#include "core/platform.h"
#include "core/type.h"

MARSHMALLOW_NAMESPACE_BEGIN
namespace Event { /****************************************** Event Namespace */

struct InputEvent::Private
{
	InputType type;
	int code;
	int value;
	size_t source;
};

InputEvent::InputEvent(InputType type_, int code_, int value_, size_t source_,
                       MMTIME time_)
    : Event(time_, HighPriority)
    , PIMPL_CREATE
{
	PIMPL->type = type_;
	PIMPL->code = code_;
	PIMPL->value = value_;
	PIMPL->source = source_;
}

InputEvent::~InputEvent(void)
{
	PIMPL_DESTROY;
}

InputEvent::InputType
InputEvent::inputType(void) const
{
	return(PIMPL->type);
}

int
InputEvent::code(void) const
{
	return(PIMPL->code);
}

int
InputEvent::value(void) const
{
	return(PIMPL->value);
}

size_t
InputEvent::source(void) const
{
	return(PIMPL->source);
}

const Core::Type &
InputEvent::Type(void)
{
	static const Core::Type s_type("Event::InputEvent");
	return(s_type);
}

} /********************************************************** Event Namespace */
MARSHMALLOW_NAMESPACE_END

