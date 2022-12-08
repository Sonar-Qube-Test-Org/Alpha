/******************************************************************************
 ***                   N E W  D E S I R E  S T U D I O S                    ***
 ******************************************************************************
 *                   Project Name : Dungeon                                   *
 *                                                                            *
 *                      File Name : Portal.h                                  *
 *                                                                            *
 *                     Programmer : Tony Skywalker                            *
 *                                                                            *
 *                     Start Date : August 4, 2022                            *
 *                                                                            *
 *                    Last Update : December 8, 2022                          *
 *                                                                            *
 * -------------------------------------------------------------------------- *
 * Over View:                                                                 *
 *   Portal.                                                                  *
 * -------------------------------------------------------------------------- *
 * Build Environment:                                                         *
 *   Windows 11 Pro                                                           *
 *   Visual Studio 2022 Community                                             *
 *   EasyX 20220901                                                           *
 ******************************************************************************/

#ifndef _PORTAL_H_
#define _PORTAL_H_

#include "Object.h"


/********************************************************************
** 2022/12/08 TS:
**   Now, Portal can not only do level up, but also jump to flashback
** point. :)
*/
class Flashback;

class Portal final : public Object
{
public:
	Portal(Scene* scene);
	virtual ~Portal() {}

	virtual Portal* Clone() const;
	virtual void Clone(Portal* clone) const {}

	virtual bool Load(XMLElement* node);

	void Initialize();

	void SetFlashback(Flashback* flashback) { m_pFlashback = flashback; }
	Flashback* GetFlashback() { return m_pFlashback; }

public:
	double GetRadius() const { return m_radius; }

protected:
	virtual void _InitBehavior(XMLElement* node = nullptr);

	double m_radius;

	Flashback* m_pFlashback;
};

#endif
