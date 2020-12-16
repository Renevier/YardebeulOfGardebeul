#include "State.h"

void State::InitView()
{
	this->view.setSize(this->window->getSize().x, this->window->getSize().y);
	this->view.setCenter(this->window->getSize().x / 2.f, this->window->getSize().y / 2.f);
}

State::State(RenderWindow *_window, map<string, int>* _supportedKeys, stack<State*>* _states)
{
	this->window = _window;
	this->supportedKeys = _supportedKeys;
	this->states = _states;

	this->quit = false;
	this->pause = false;
	this->keytime = 0.f;
	this->keytimeMax = 10.f;

	this->InitView();
}

void State::UpdateMousePosition()
{
	this->mousePosScreen = Mouse::getPosition();
	this->mousePosWindow = Mouse::getPosition(*this->window);
	this->window->setView(this->view);
	this->mousePosView = this->window->mapPixelToCoords(mousePosWindow);
	this->window->setView(this->window->getDefaultView());
}

void State::UpdateKeytime(const float& _dt)
{
	if (this->keytime < this->keytimeMax)
		this->keytime += 100.f * _dt;
}

bool State::GetKeytime()
{
	if (this->keytime >= this->keytimeMax)
	{
		this->keytime = 0.f;
		return true;
	}

	return false;
}

State::~State()
{
}