#include "pch.h"
#include "PauseMenu.h"

void PauseMenu::InitBackground(RenderWindow& window)
{
	this->background.setSize(Vector2f(
		window.getSize().x,
		window.getSize().y)
	);
	this->background.setFillColor(Color(20, 20, 20, 100));
}

void PauseMenu::InitButtonContainer(RenderWindow& window)
{
	this->buttonContainer.setSize(Vector2f(
		window.getSize().x / 4.f,
		window.getSize().y)
	);

	this->buttonContainer.setFillColor(Color(20, 20, 20, 100));
	this->buttonContainer.setPosition(Vector2f(
		0.f,
		0.f)
	);
}

void PauseMenu::InitText(Font& font)
{
	this->menuText.setFont(font);
	this->menuText.setFillColor(Color(255, 255, 255, 200));
	this->menuText.setCharacterSize(60);
	this->menuText.setString("PAUSED");
	this->menuText.setPosition(
		this->buttonContainer.getPosition().x + this->buttonContainer.getSize().x / 2.f - this->menuText.getGlobalBounds().width / 2.f,
		this->buttonContainer.getPosition().y + 40.f
	);
}

void PauseMenu::InitDescriptionText(Font& font)
{
	this->descriptionText.setFont(font);
	this->descriptionText.setFillColor(Color(255, 255, 255, 200));
	this->descriptionText.setCharacterSize(30);
	this->descriptionText.setString("lorem ipsus");
	this->descriptionText.setPosition(Vector2f(
		800.f,
		550.f
	));
}

void PauseMenu::InitDescriptionContainer(RenderWindow& window)
{
	this->descriptionContainer.setSize(Vector2f(
		window.getSize().x / 4.f,
		window.getSize().y / 4.f
	)
	);

	this->descriptionContainer.setOrigin(
		this->descriptionContainer.getGlobalBounds().width / 2,
		this->descriptionContainer.getGlobalBounds().height / 2
	);

	this->descriptionContainer.setFillColor(Color(20, 20, 20, 100));
	this->descriptionContainer.setPosition(Vector2f(
		window.getSize().x / 2,
		window.getSize().y / 2)
	);
}

PauseMenu::PauseMenu(RenderWindow& window, Font& font)
	:font(font)
{
	this->InitBackground(window);
	this->InitButtonContainer(window);
	this->InitDescriptionContainer(window);
	this->InitText(font);
	this->InitDescriptionText(font);
}

PauseMenu::~PauseMenu()
{
	for (auto it = this->buttons.begin(); it != this->buttons.end(); ++it)
		delete it->second;
}

void PauseMenu::UpdateDescriptionText(string _readFile)
{
	ifstream readfile("../Ressources/Saves/" + _readFile + ".txt");
	string timeInGame, champLevel;

	string line;

	if (readfile.is_open())
	{
		while (getline(readfile, line))
		{
			if (line.find("TimeIngame") != -1)
				timeInGame = line;

			if (line.find("Lvl") != -1)
				champLevel = line;

			this->descriptionText.setString(timeInGame + "\n" + champLevel);
		}
	}

	readfile.close();
}

void PauseMenu::Update(const Vector2f& mousePos)
{
	string file;

	for (auto& i : this->buttons)
		i.second->Update(mousePos);

	if (this->buttons.at("SAVE_1")->GetState() == BTN_STATES::BTN_HOVER)
	{
		file = "Save1";
		this->UpdateDescriptionText(file);
	}
	if (this->buttons.at("SAVE_2")->GetState() == BTN_STATES::BTN_HOVER)
	{
		file = "Save2";
		this->UpdateDescriptionText(file);
	}
	if (this->buttons.at("SAVE_3")->GetState() == BTN_STATES::BTN_HOVER)
	{
		file = "Save3";
		this->UpdateDescriptionText(file);
	}
}

void PauseMenu::Render(RenderTarget& target, bool wantSave)
{
	target.draw(this->background);
	target.draw(this->buttonContainer);

	target.draw(this->menuText);

	//Render button
	if (wantSave)
	{
		if (this->buttons.at("SAVE_1")->GetState() == BTN_STATES::BTN_HOVER ||
			this->buttons.at("SAVE_2")->GetState() == BTN_STATES::BTN_HOVER ||
			this->buttons.at("SAVE_3")->GetState() == BTN_STATES::BTN_HOVER)
		{
			target.draw(this->descriptionContainer);
			target.draw(this->descriptionText);
		}

		this->buttons.at("SAVE_1")->Render(target);
		this->buttons.at("SAVE_2")->Render(target);
		this->buttons.at("SAVE_3")->Render(target);
		this->buttons.at("BACK_TO_MAINMENU")->Render(target);
		this->buttons.at("BACK_TO_GAME")->Render(target);
	}
	else
	{
		this->buttons.at("GAME_RETURN")->Render(target);
		this->buttons.at("SAVE_GAME")->Render(target);
		this->buttons.at("EXIT_GAME")->Render(target);
	}
}

void PauseMenu::AddButton(const string key, float x, float y, const string text)
{
	this->buttons.emplace(key, new Button(
		x, y, 250, 40,
		&this->font, text, 50,
		Color(70, 70, 70, 200), Color(250, 250, 250, 250), Color(20, 20, 20, 50),
		Color(70, 70, 70, 0), Color(250, 250, 250, 0), Color(20, 20, 20, 0)));
}

bool PauseMenu::IsButtonPressed(const string key)
{
	return this->buttons.at(key)->IsPressed();
}

map<string, Button*>& PauseMenu::getButtons()
{
	return this->buttons;
}
