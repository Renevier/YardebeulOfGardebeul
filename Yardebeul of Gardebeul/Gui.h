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
		short unsigned id;

		RectangleShape shape;
		Font* font;
		Text text;

		Color textIdleColor;
		Color textHoverColor;
		Color textActiveColor;

		Color buttonIdleColor;
		Color buttonHoverColor;
		Color buttonActiveColor;

		Color outlineIdleColor;
		Color outlineHoverColor;
		Color outlineActiveColor;

	private:

	public:
		Button(float _x, float _y, float _width, float _height,
			Font* font, string text, unsigned _charactere_size,
			Color _text_idle_color, Color _text_hover_color, Color _text_active_color,
			Color _button_idle_color, Color _button_hover_color, Color _button_active_color, 
			short unsigned _id = 0);
		~Button();
		void Update(const Vector2f& _mousePos);
		void Render(RenderTarget& target);

		//get
		inline BTN_STATES GetState() { return this->buttonState; }
		inline bool IsPressed() const;
		inline string GetText() const { return this->text.getString(); }
		inline short unsigned GetID() { return this->id; }

		//set
		inline void SetText(string _txt) { this->text.setString(_txt); };
		inline void SetID(unsigned short _id) { this->id = _id; }
	};

	class DropDownList
	{
	private:
		float keytime;
		float keytimeMax;

		Font& font;
		Button* activeElement;
		vector<gui::Button*> list;
		bool showList;

	public:
		DropDownList(float _x, float _y, float _width, float _height, Font& _font, string _list[], unsigned _nbOfElement, unsigned _default_index = 0);
		~DropDownList();

		bool GetKeytime();
		void UpdateKeytime(const float& _dt);

		void Update(const Vector2f& _mousePos, const float& _dt);
		void Render(RenderTarget& target);
	};
}