#include "Button.h"

Button::Button(float _x, float _y, float _width, float _height, Font* _font, string _text, Color _idleColor, Color _hoverColor, Color _activeColor)
{
	this->buttonState = BTN_STATES::BTN_IDLE;

	this->Shape.setSize(Vector2f(_width, _height));
	this->Shape.setPosition(Vector2f(_x, _y));
	this->Shape.setOrigin(Vector2f(_width / 2, _height / 2));

	this->font = _font;
	this->text.setFont(*this->font);
	this->text.setString(_text);
	this->text.setFillColor(Color::Black);
	this->text.setCharacterSize(12);
	this->text.setOrigin(Vector2f(this->text.getGlobalBounds().width / 2, this->text.getGlobalBounds().height / 2));
	this->text.setPosition(Vector2f(this->Shape.getOrigin().x, this->Shape.getOrigin().y));

	this->idleColor = _idleColor;
	this->hoverColor = _hoverColor;
	this->activeColor = _activeColor;

	this->Shape.setFillColor(this->idleColor);
}

void Button::Update(const Vector2f _mousePos)
{
	this->buttonState = BTN_STATES::BTN_IDLE;

	if (this->Shape.getGlobalBounds().contains(_mousePos))
	{
		if (this->Shape.getGlobalBounds().contains(_mousePos))
		{
			this->buttonState = BTN_STATES::BTN_HOVER;

			if (Mouse::isButtonPressed(Mouse::Left))
				this->buttonState = BTN_STATES::BTN_PRESSED;
		}
	}

	switch (this->buttonState)
	{
	case BTN_STATES::BTN_IDLE:
		this->Shape.setFillColor(this->idleColor);
		break;
	case BTN_STATES::BTN_HOVER:
		this->Shape.setFillColor(this->hoverColor);
		break;
	case BTN_STATES::BTN_PRESSED:
		this->Shape.setFillColor(this->activeColor);
		break;
	default:
		this->Shape.setFillColor(Color::Red);
		break;
	}
}

void Button::Render(RenderTarget* target)
{
	target->draw(this->Shape);
	target->draw(this->text);
}

const bool Button::IsPressed() const
{
	if(this->buttonState == BTN_STATES::BTN_PRESSED)
		return true;

	return false;
}

Button::~Button()
{
}
