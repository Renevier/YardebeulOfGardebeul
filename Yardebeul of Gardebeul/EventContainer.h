#pragma once
#include "cEvent.h"
#include "pch.h"
#include "Tool.h"

class EventContainer
{
protected:
	map<string, cEvent> container;

private:
	void Fill();

public:
	EventContainer();
	~EventContainer();

};
