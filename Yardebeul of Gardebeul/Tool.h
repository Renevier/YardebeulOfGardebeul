#pragma once

enum class Behaviour
{
    HELPFULL,
    PASSIFIC,
    AGRESSIF
};

enum class Element
{
	Feu,
	Eau,
	Plante,
	Neutre
};

static float tableDeType[4][4] =
{
	{ 0, 2, .5, 0 },
	{ .5, 0, 2, 0 },
	{ 2, .5, 0, 0 },
	{ 0, 0, 0,  0 }
};

enum class STATE_EVENT
{
	NOTHING,
	FIGHT,
	MEET,
	ENVIRONEMENT,
	PUZZLE
};

enum class BIOME
{
	NONE,
	FIRE,
	WATER,
	PLANT
};