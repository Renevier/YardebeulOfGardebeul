#pragma once
//Mother of all our states
#include <iostream>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"

using namespace std;
using namespace sf;

class State
{
private:  

	vector<Texture> textures;

public:
	State();
	virtual void Update() = 0;
	virtual void Render() = 0;
	~State();

private:

};