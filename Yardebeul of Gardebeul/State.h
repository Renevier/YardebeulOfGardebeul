#pragma once
//Mother of all our states
#include <iostream>
#include <stack>
#include <map>

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
	RenderWindow* window;
	vector<Texture> textures;
	bool Quit;

public:
	State(RenderWindow *_window);
	virtual void UpdateKeyBind(const float& _dt) = 0;
	virtual void Update(const float &_dt) = 0;
	virtual void Render(RenderTarget *_target = nullptr) = 0;
	virtual void CheckForQuit();
	virtual void EndState() = 0;
	const bool& GetQuit() const;
	~State();

private:

};