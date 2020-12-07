#include "EditorState.h"

void EditorState::InitKeybinds()
{
}

void EditorState::InitFont()
{
	if (!this->font.loadFromFile("../Ressources/Fonts/rpgFont.ttf"))
		exit(0);
}

void EditorState::InitButton()
{
	this->buttons.emplace("EXIT", new Button(100, 700, 250, 50,
		&this->font, "Quit", 50,
		Color(70, 70, 70, 200), Color(250, 250, 250, 250), Color(20, 20, 20, 50),
		Color(70, 70, 70, 0), Color(250, 250, 250, 0), Color(20, 20, 20, 0)));
}

EditorState::EditorState(RenderWindow* _window, map<string, int>* _supportedKeys, stack<State*>* _states)
	: State(_window, _supportedKeys, _states)
{
	this->InitFont();
	this->InitButton();
}

void EditorState::UpdateInput(const float& _dt)
{
	if (Keyboard::isKeyPressed(Keyboard::Key(this->keybinds.at("CLOSE"))))
		this->EndState();

	this->UpdateButton();
}

void EditorState::UpdateButton()
{
	for (auto it : this->buttons)
		it.second->Update(this->mousePosView);

	

	if (this->buttons.at("EXIT")->IsPressed())
		this->quit = true;
}

void EditorState::Update(RenderTarget* _window, const float& _dt)
{
	this->UpdateMousePosition();
	this->UpdateInput(_dt);
}

void EditorState::RenderButton(RenderTarget& _target)
{
	for (auto it : this->buttons)
		it.second->Render(_target);
}

void EditorState::Render(RenderTarget* _target)
{
	if (!_target)
		_target = this->window;

	this->RenderButton(*_target);

	//print mouse potiton in the console
	system("CLS");
	cout << this->mousePosView.x << " " << this->mousePosView.y;
}

void EditorState::EndState()
{
	this->quit = true;
}

EditorState::~EditorState()
{
	for (auto it = this->buttons.begin(); it != this->buttons.end(); ++it)
		delete it->second;
}