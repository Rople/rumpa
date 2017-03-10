#pragma once

#ifndef IENGINETRACE_H
#define IENGINETRACE_H

#include "Globals.h"

struct cplane_t;

class IEngineTrace {
public:
	virtual void pad1() = 0;
	virtual void pad2() = 0;
	virtual void pad3() = 0;
	virtual void pad4() = 0;
	virtual void TraceRay(const Ray_t &ray, unsigned int fMask, ITraceFilter *pTraceFilter, CGameTrace *pTrace) = 0;
};

struct cplane_t {
	Vector3D	normal;
	float	dist;
	byte	type;			// for fast side tests
	byte	signbits;		// signx + (signy<<1) + (signz<<1)
	byte	pad[2];
};

struct csurface_t
{
	const char	*name;
	short		surfaceProps;
	unsigned short	flags;
};

struct Ray_t {
	Vector3D  m_Start;	// starting point, centered within the extents
	Vector3D  m_Delta;	// direction + length of the ray
	Vector3D  m_StartOffset;	// Add this to m_Start to get the actual ray start
	Vector3D  m_Extents;	// Describes an axis aligned box extruded along a ray
	bool	m_IsRay;	// are the extents zero?
	bool	m_IsSwept;	// is delta != 0?
};

enum TraceType_t
{
	TRACE_EVERYTHING = 0,
	TRACE_WORLD_ONLY,				// NOTE: This does *not* test static props!!!
	TRACE_ENTITIES_ONLY,			// NOTE: This version will *not* test static props
	TRACE_EVERYTHING_FILTER_PROPS,	// NOTE: This version will pass the IHandleEntity for props through the filter, unlike all other filters
};

class ITraceFilter {
public:
	virtual bool ShouldHitEntity(CBaseEntity *pEntity, int contentsMask) = 0;
	virtual TraceType_t	GetTraceType() const = 0;
};


class CBaseTrace {
public:
	// these members are aligned!!
	Vector3D		startpos;				// start position
	Vector3D			endpos;					// final position
	cplane_t		plane;					// surface normal at impact

	float			fraction;				// time completed, 1.0 = didn't hit anything

	int				contents;				// contents on other side of surface hit
	unsigned short	dispFlags;				// displacement flags for marking surfaces with data

	bool			allsolid;				// if true, plane is not valid
	bool			startsolid;				// if true, the initial point was in a solid area

	CBaseTrace() {}

private:
	CBaseTrace(const CBaseTrace& vOther);
};

class CGameTrace : public CBaseTrace {
public:

	// Returns true if hEnt points at the world entity.
	// If this returns true, then you can't use GetHitBoxIndex().
	bool DidHitWorld() const;

	// Returns true if we hit something and it wasn't the world.
	bool DidHitNonWorldEntity() const;

	// Gets the entity's network index if the trace has hit an entity.
	// If not, returns -1.
	int GetEntityIndex() const;

	// Returns true if there was any kind of impact at all
	bool DidHit() const;

	float		fractionleftsolid;
	csurface_t	surface;
	int			hitgroup;
	short		physicsbone;
	CBaseEntity *m_pEnt;
	int			hitbox;

	CGameTrace() {}

private:
	CGameTrace(const CGameTrace& vOther);
};


bool CGameTrace::DidHitNonWorldEntity() const
{
	return m_pEnt != NULL && !DidHitWorld();
}


int CGameTrace::GetEntityIndex() const
{
	if (m_pEnt)
		return m_pEnt->GetIndex();
	else
		return -1;
}

inline bool CGameTrace::DidHit() const
{
	return fraction < 1 || allsolid || startsolid;
}

#endif // !IENGINETRACE_H