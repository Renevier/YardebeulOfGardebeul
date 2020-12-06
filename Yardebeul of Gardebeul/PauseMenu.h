#pragma once
#include "Button.h"
#include "pch.h"

class PauseMenu
{
protected:
	Font& font;
	Text menuText;

	RectangleShape background;
	RectangleShape buttonContainer;

	RectangleShape descriptionContainer;
	RectangleShape saveDescription;

	map<string, Button*> buttons;
private:
	void InitBackground(RenderWindow& window);
	void InitButtonContainer(RenderWindow& window);
	void InitText(Font& font);
	void InitDescriptionContainer(RenderWindow& window);
public:
	PauseMenu(RenderWindow& window, Font& font);
	~PauseMenu();


	void Update(const Vector2f& mousePos);
	void Render(RenderTarget& target, bool wantSave);
	void AddButton(const string key, float x, float y, const string text);
	bool IsButtonPressed(const string key);

	//get
	map<string, Button*>& getButtons();
};