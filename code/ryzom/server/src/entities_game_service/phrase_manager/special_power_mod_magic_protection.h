// Ryzom - MMORPG Framework <http://dev.ryzom.com/projects/ryzom/>
// Copyright (C) 2010  Winch Gate Property Limited
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as
// published by the Free Software Foundation, either version 3 of the
// License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Affero General Public License for more details.
//
// You should have received a copy of the GNU Affero General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.



#ifndef RYZOM_SPECIAL_POWER_MOD_MAGIC_PROTECTION_H
#define RYZOM_SPECIAL_POWER_MOD_MAGIC_PROTECTION_H

#include "special_power.h"


/**
 * Specialized class for power "ModMagicProtection"
 * \author Alain Saffray
 * \author Nevrax France
 * \date 2006
 */
class CSpecialPowerModMagicProtection : public CSpecialPower
{
public:
	/// Default Constructor
	CSpecialPowerModMagicProtection() : CSpecialPower()
	{}

	/// Constructor
	CSpecialPowerModMagicProtection(TDataSetRow actorRowId, CSpecialPowerPhrase *phrase, float durationInSeconds,  
		POWERS::TPowerType powerType, const std::string& protection, float modifier1, float modifier2 )
	{
		if(TheDataset.isAccessible(actorRowId))
			_ActorRowId = actorRowId;
		else
		{
			nlwarning("<CSpecialPowerModMagicProtection> invalid data set row passed as actor");
		}

		_Phrase = phrase;
		
		_Duration = NLMISC::TGameCycle(durationInSeconds / CTickEventHandler::getGameTimeStep());		
		_DisablePowerTime = _Duration;

		_PowerType = powerType;
		_AffectedProtection = protection;
		_Modifier1 = modifier1;
		_Modifier2 = modifier2;
	}

	/// apply effects
	virtual void apply();


protected:
	/// affected protection
	std::string	_AffectedProtection;

	// score modifier 
	float _Modifier1;
	float _Modifier2;

	/// Duration in ticks
	NLMISC::TGameCycle	_Duration;
};

#endif // RYZOM_SPECIAL_POWER_MOD_MAGIC_PROTECTION_H

/* End of special_power_mod_magic_protection.h */
