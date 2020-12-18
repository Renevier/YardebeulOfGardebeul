#pragma once
#include "pch.h"

enum class BTN_STATES
{
	BTN_IDLE,
	BTN_HOVER,
	BTN_PRESSED
};

namespace gui
{
	class Button
	{
	protected:
		BTN_STATES buttonState;

		RectangleShape shape;
		Font* font;
		Text text;

		Color textIdleColor;
		Color textHoverColor;
		Color textActiveColor;

		Color buttonIdleColor;
		Color buttonHoverColor;
		Color buttonActiveColor;

	private:

	public:
		Button(float _x, float _y, float _width, float _height,
			Font* font, string text, unsigned _charactere_size,
			Color _text_idle_color, Color _text_hover_color, Color _text_active_color,
			Color _button_idle_color, Color _button_hover_color, Color _button_active_color);
		void Update(const Vector2f& _mousePos);
		void Render(RenderTarget& target);
		~Button();

		//get
		inline BTN_STATES GetState() { return this->buttonState; }
		inline bool IsPressed() const;
		inline string GetText() const { return this->text.getString(); }

		//set
		inline void SetText(string _txt) { this->text.setString(_txt); };
	};

	class DropDownList
	{
	private:
		Font& font;
		Button* activeElement;
		vector<gui::Button*> list;

	public:
		DropDownList(Font& _font, string _list[], unsigned _nbOfElement, unsigned _default_index = 0);
		~DropDownList();

		void Update(const Vector2f& _mousePos);
		void Render(RenderTarget& target);
	};
}