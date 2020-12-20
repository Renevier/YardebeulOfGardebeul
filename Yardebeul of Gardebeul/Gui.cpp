#include "pch.h"
#include "Gui.h"

gui::Button::Button(float _x, float _y, float _width, float _height,
	Font* _font, string _text, unsigned _charactere_size,
	Color _text_idle_color, Color _text_hover_color, Color _text_active_color,
	Color _button_idle_color, Color _button_hover_color, Color _button_active_color,
	short unsigned _id)
{
	this->buttonState = BTN_STATES::BTN_IDLE;
	this->id = _id;

	this->shape.setSize(Vector2f(_width, _height));
	this->shape.setOrigin(this->shape.getSize().x / 2, this->shape.getSize().y / 2);
	this->shape.setPosition(_x + this->shape.getGlobalBounds().width / 2,
		_y + this->shape.getGlobalBounds().height / 2);

	this->font = _font;

	this->text.setString(_text);
	this->text.setFont(*this->font);
	this->text.setCharacterSize(_charactere_size);
	this->text.setOrigin(this->text.getGlobalBounds().width / 2, this->text.getGlobalBounds().height);
	this->text.setPosition(Vector2f(this->shape.getPosition().x, this->shape.getPosition().y));
	this->text.setFillColor(_text_idle_color);

	this->textIdleColor = _text_idle_color;
	this->textHoverColor = _text_hover_color;
	this->textActiveColor = _text_active_color;

	this->buttonIdleColor = _button_idle_color;
	this->buttonHoverColor = _button_hover_color;
	this->buttonActiveColor = _button_active_color;

	this->shape.setFillColor(this->buttonIdleColor);
}

void gui::Button::Update(const Vector2f& _mousePos)
{
	this->buttonState = BTN_STATES::BTN_IDLE;

	if (this->shape.getGlobalBounds().contains(_mousePos))
	{
		if (this->shape.getGlobalBounds().contains(_mousePos))
		{
			this->buttonState = BTN_STATES::BTN_HOVER;

			if (Mouse::isButtonPressed(Mouse::Left))
				this->buttonState = BTN_STATES::BTN_PRESSED;
		}
	}

	switch (this->buttonState)
	{
	case BTN_STATES::BTN_IDLE:
		this->shape.setFillColor(this->buttonIdleColor);
		this->text.setFillColor(this->textIdleColor);
		this->shape.setOutlineColor(this->outlineIdleColor);
		break;
	case BTN_STATES::BTN_HOVER:
		this->shape.setFillColor(this->buttonHoverColor);
		this->text.setFillColor(this->textHoverColor);
		this->shape.setOutlineColor(this->outlineHoverColor);
		break;
	case BTN_STATES::BTN_PRESSED:
		this->shape.setFillColor(this->buttonActiveColor);
		this->text.setFillColor(this->textActiveColor);
		this->shape.setOutlineColor(this->outlineActiveColor);
		break;
	default:
		this->shape.setFillColor(Color::Green);
		this->text.setFillColor(Color::Blue);
		this->shape.setOutlineColor(Color::Green);
		break;
	}
}

void gui::Button::Render(RenderTarget& target)
{
	target.draw(this->shape);
	target.draw(this->text);
}

bool gui::Button::IsPressed() const
{
	if (this->buttonState == BTN_STATES::BTN_PRESSED)
		return true;

	return false;
}

gui::Button::~Button()
{
}

//***************DropDownList****************************

gui::DropDownList::DropDownList(float _x, float _y, float _width, float _height, Font& _font, string _list[], unsigned _nbOfElement, unsigned _default_index)
	:font(_font), showList(false), keytimeMax(20.f), keytime(0.f)
{
	this->activeElement = new gui::Button(
		_x, _y, _width, _height,
		&this->font, _list[_default_index], 50,
		Color(70, 70, 70, 200), Color(250, 250, 250, 250), Color(20, 20, 20, 50),
		Color(70, 70, 70, 0), Color(250, 250, 250, 0), Color(20, 20, 20, 0));

	//unsigned nbOfElement = sizeof(_list) / sizeof(string);
	for (size_t i = 0; i < _nbOfElement; i++)
	{
		this->list.push_back(
			new gui::Button(
				_x, _y + (i + 1) * _height, _width, _height,
				&this->font, _list[i], 50,
				Color(70, 70, 70, 200), Color(250, 250, 250, 250), Color(20, 20, 20, 50),
				Color(70, 70, 70, 0), Color(250, 250, 250, 0), Color(20, 20, 20, 0),
			i));
	}

}

gui::DropDownList::~DropDownList()
{
	delete this->activeElement;

	for (auto& i : this->list)
		delete i;
}

bool gui::DropDownList::GetKeytime()
{
	if (this->keytime >= this->keytimeMax)
	{
		this->keytime = 0.f;
		return true;
	}

	return false;
}

void gui::DropDownList::UpdateKeytime(const float& _dt)
{
	if (this->keytime < this->keytimeMax)
		this->keytime += 100.f * _dt;
}

void gui::DropDownList::Update(const Vector2f& _mousePos, const float& _dt)
{
	this->UpdateKeytime(_dt);
	this->activeElement->Update(_mousePos);

	if (this->activeElement->IsPressed() && this->GetKeytime())
	{
		if (this->showList)
			this->showList = false;
		else
			this->showList = true;
	}

	//We want update the list just if we see it
	if (showList)
	{
		for (auto& i : this->list)
		{
			i->Update(_mousePos);

			if (i->IsPressed() && this->GetKeytime())
			{
				this->showList = false;
				this->activeElement->SetText(i->GetText());
				this->activeElement->SetID(i->GetID());
			}

		}
	}
}

void gui::DropDownList::Render(RenderTarget& target)
{
	this->activeElement->Render(target);

	if (showList)
	{
		for (auto& i : this->list)
			i->Render(target);
	}
}
