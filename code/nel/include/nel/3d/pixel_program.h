/** \file pixel_program.h
 * Pixel program definition
 *
 * $Id: pixel_program.h,v 1.1.2.3 2007/07/06 15:58:45 legallo Exp $
 */

/* Copyright, 2000, 2001 Nevrax Ltd.
 *
 * This file is part of NEVRAX NEL.
 * NEVRAX NEL is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.

 * NEVRAX NEL is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with NEVRAX NEL; see the file COPYING. If not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston,
 * MA 02111-1307, USA.
 */

#ifndef NL_PIXEL_PROGRAM_H
#define NL_PIXEL_PROGRAM_H

#include <nel/misc/types_nl.h>
#include <nel/misc/smart_ptr.h>

#include <list>

namespace NL3D {

// List typedef.
class	IDriver;
class	IPixelProgramDrvInfos;
typedef	std::list<IPixelProgramDrvInfos*>	TPixelPrgDrvInfoPtrList;
typedef	TPixelPrgDrvInfoPtrList::iterator		ItPixelPrgDrvInfoPtrList;

// Class for interaction of pixel program with Driver.
// IPixelProgramDrvInfos represent the real data of the pixel program, stored into the driver.
class IPixelProgramDrvInfos : public NLMISC::CRefCount
{
private:
	IDriver						*_Driver;
	ItPixelPrgDrvInfoPtrList	_DriverIterator;

public:
	IPixelProgramDrvInfos (IDriver *drv, ItPixelPrgDrvInfoPtrList it);
	// The virtual dtor is important.
	virtual ~IPixelProgramDrvInfos(void);
};


//-------------------------------------------------------------------------------
class CPixelProgram : public NLMISC::CRefCount
{
public:

	/// Constructor
	CPixelProgram (const char* program);

	/// Destructor
	virtual ~CPixelProgram ();

	/// Get the program
	inline const std::string& getProgram() const { return _Program; };

	/// The driver informations. For the driver implementation only.
	NLMISC::CRefPtr<IPixelProgramDrvInfos>		_DrvInfo;

protected:

	/// The progam
	std::string									_Program;
};


} // NL3D


#endif // NL_PIXEL_PROGRAM_H

/* End of vertex_program.h */
