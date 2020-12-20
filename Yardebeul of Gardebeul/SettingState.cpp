#include "pch.h"
#include "SettingState.h"

void SettingState::InitKeybinds()
{
}

void SettingState::InitText()
{
	this->optionText.setFont(this->font);
	this->optionText.setPosition(100.f, 450.f);
	this->optionText.setCharacterSize(40);
	this->optionText.setFillColor(Color::White);

	this->optionText.setString("Resolution");
}

void SettingState::InitBackground()
{
	this->background.setSize(Vector2f((float)this->window->getSize().x, (float)this->window->getSize().y));

	if (!this->backgroundTexture.loadFromFile("../Ressources/Background/backgound_menu.png"))
		exit(0);

	this->background.setTexture(&this->backgroundTexture);
}

void SettingState::InitFont()
{
	if (!this->font.loadFromFile("../Ressources/Fonts/rpgFont.ttf"))
		exit(0);
}

void SettingState::InitGui()
{
	this->buttons.emplace("APPLY", new gui::Button(100, 800, 250, 50,
		&this->font, "Apply", 50,
		Color(70, 70, 70, 200), Color(250, 250, 250, 250), Color(20, 20, 20, 50),
		Color(70, 70, 70, 0), Color(250, 250, 250, 0), Color(20, 20, 20, 0)));

	this->buttons.emplace("EXIT", new gui::Button(350, 800, 250, 50,
		&this->font, "Quit", 50,
		Color(70, 70, 70, 200), Color(250, 250, 250, 250), Color(20, 20, 20, 50),
		Color(70, 70, 70, 0), Color(250, 250, 250, 0), Color(20, 20, 20, 0)));

	string li[] = { "1920x1080", "800x600", "640x480" };
	this->dropDownLists.emplace("RESOLUTION",
		new gui::DropDownList(450, 450, 200, 50, font, li, 3));
}

SettingState::SettingState(StateData* _state_data)
	:State(_state_data)
{
	this->InitBackground();
	this->InitText();
	this->InitFont();
	this->InitGui();
}

SettingState::~SettingState()
{
	for (auto it = this->buttons.begin(); it != this->buttons.end(); it++)
		delete it->second;

	for (auto it2 = this->dropDownLists.begin(); it2 != this->dropDownLists.end(); it2++)
		delete it2->second;
}

void SettingState::UpdateInput(const float& _dt)
{
	this->UpdateGui(_dt);
}

void SettingState::UpdateGui(const float& _dt)
{
	//Buttons
	for (auto& it : this->buttons)
		it.second->Update(this->mousePosView);

	if (this->GetKeytime())
	{
		if (this->buttons.at("EXIT")->IsPressed() || Keyboard::isKeyPressed(Keyboard::Escape))
			this->EndState();
	}

	if (this->GetKeytime())
	{
		if (this->buttons.at("APPLY")->IsPressed() || Keyboard::isKeyPressed(Keyboard::Enter))
		{

		}
	}

	//****************DropDownList***********************

	for (auto& it : this->dropDownLists)
		it.second->Update(this->mousePosView, _dt);
}

void SettingState::Update(const float& _dt)
{
	this->UpdateMousePosition();
	this->UpdateKeytime(_dt);
	this->UpdateInput(_dt);
}

void SettingState::RenderGui(RenderTarget& _target)
{
	for (auto& it : this->buttons)
		it.second->Render(_target);

	for (auto& it : this->dropDownLists)
		it.second->Render(_target);
}

void SettingState::Render(RenderTarget* _target)
{
	if (!_target)
		_target = this->window;

	_target->draw(this->background);

	this->RenderGui(*_target);

	_target->draw(this->optionText);
}