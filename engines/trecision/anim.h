/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#ifndef TRECISION_ANIM_H
#define TRECISION_ANIM_H

#include "trecision/trecision.h"

namespace Trecision {

struct ATFHandle {
	int16 _curFrame;
	int16 _lastFrame;
	uint16 _object;
	uint16 _status;
	SAnim *_curAnim;
};

class AnimTypeManager {
private:
	TrecisionEngine *_vm;
	void executeAtFrameDoit(ATFHandle *h, int doit, int obj);
	void process(ATFHandle *h, int type, int atf);
	void processAtFrame(ATFHandle *h, int type, int atf);

	ATFHandle AnimType[3]{};

public:
	AnimTypeManager(TrecisionEngine *vm);
	~AnimTypeManager();

	void init(uint16 an, uint16 obj);
	void next();
	void end(int type);
	void handler(int type);

}; // end of class

} // end of namespace
#endif
