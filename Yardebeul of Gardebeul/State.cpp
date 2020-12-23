#include "pch.h"
#include "State.h"

void State::InitView()
{
	this->view.setSize(this->window->getSize().x, this->window->getSize().y);
	this->view.setCenter(this->window->getSize().x / 2.f, this->window->getSize().y / 2.f);
}

State::State(StateData* _state_data)
	: keytimeMax(15.f), keytime(keytimeMax)
{
	this->stateData = _state_data;
	this->window = _state_data->window;
	this->supportedKeys = _state_data->supportedKeys;
	this->states = _state_data->states;
	this->gridSize = _state_data->gridSize;

	this->wantSave = false;
	this->quit = false;
	this->pause = false;

	this->InitView();
}

void State::UpdateMousePosition(View* _view)
{
	this->mousePosScreen = Mouse::getPosition();
	this->mousePosWindow = Mouse::getPosition(*this->window);

	if(_view)
		this->window->setView(*_view);

	this->mousePosView = this->window->mapPixelToCoords(mousePosWindow);
	this->mousePosGrid = Vector2u(
		static_cast<unsigned> (this->mousePosView.x) / static_cast<unsigned> (this->gridSize),
		static_cast<unsigned> (this->mousePosView.y) / static_cast<unsigned> (this->gridSize));

	this->window->setView(this->window->getDefaultView());
}

void State::UpdateKeytime(const float& _dt)
{
	if (this->keytime < this->keytimeMax)
		this->keytime += 100.f * _dt;
}

void State::EndState()
{
	this->quit = true;
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