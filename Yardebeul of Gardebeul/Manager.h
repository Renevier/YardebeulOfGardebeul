#pragma once

class Manager
{
protected:
	RenderWindow window;

public:
	Manager();
	void Update();
	void Display();
	~Manager();
};