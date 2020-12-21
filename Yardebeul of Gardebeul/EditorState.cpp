#include "pch.h"
#include "EditorState.h"

void EditorState::InitKeybinds()
{}

void EditorState::InitPauseMenu()
{
	this->pauseMenu = new PauseMenu(*this->window, this->font);

	this->InitButton();
}

void EditorState::InitBackground()
{}

void EditorState::InitFont()
{
	if (!this->font.loadFromFile("../Ressources/Fonts/rpgFont.ttf"))
		exit(0);
}

void EditorState::InitText()
{
	this->cursorText.setFont(this->font);
	this->cursorText.setFillColor(Color::White);
	this->cursorText.setCharacterSize(30);
	this->cursorText.setPosition(this->mousePosView.x + 50.f, this->mousePosView.y + 50.f);
}

void EditorState::InitButton()
{
	this->pauseMenu->AddButton("GAME_RETURN", 100.f, 400.f, "Resume");
	this->pauseMenu->AddButton("SAVE_GAME", 100.f, 550.f, "Save");
	this->pauseMenu->AddButton("EXIT_GAME", 100.f, 800.f, "Quit");

	this->pauseMenu->AddButton("SAVE_1", 100.f, 300.f, "Save 1");
	this->pauseMenu->AddButton("SAVE_2", 100.f, 400.f, "Save 2");
	this->pauseMenu->AddButton("SAVE_3", 100.f, 500.f, "Save 3");
	this->pauseMenu->AddButton("BACK_TO_GAME", 100.f, 600.f, "Resume");
	this->pauseMenu->AddButton("BACK_TO_MAINMENU", 100.f, 750.f, "Back to main menu");
}

void EditorState::InitGui()
{
	this->selector.setSize(Vector2f(this->stateData->gridSize, this->stateData->gridSize));
	this->selector.setFillColor(Color(255, 255, 255, 150));
	this->selector.setOutlineThickness(2.f);
	this->selector.setOutlineColor(Color::Red);

	this->selector.setTexture(this->tileMap->GetTileSheet());
	this->selector.setTextureRect(this->textureRect);
}

void EditorState::IniTileMap()
{
	this->textureRect = IntRect(0, 0, static_cast<int>(this->stateData->gridSize), static_cast<int>(this->stateData->gridSize));
	this->tileMap = new TileMap(this->stateData->gridSize, 10, 10);

}

EditorState::EditorState(StateData* _state_data)
	: State(_state_data)
{
	this->InitBackground();
	this->InitFont();
	this->InitText();
	this->InitPauseMenu();
	this->IniTileMap();
	this->InitGui();
}

void EditorState::UpdatePauseMenuButtons()
{
	if (this->pauseMenu->IsButtonPressed("EXIT_GAME"))
		this->EndState();
}

void EditorState::UpdateInput(const float& _dt)
{
	if (Keyboard::isKeyPressed(Keyboard::Escape) && this->GetKeytime())
	{
		if (!this->pause)
			this->PauseState();
		else
			this->UnpauseState();
	}
}

void EditorState::UpdateEditorInput(const float& _dt)
{
	if (Mouse::isButtonPressed(Mouse::Left) && this->GetKeytime())
	{
		this->tileMap->AddTile(this->mousePosGrid.x, this->mousePosGrid.y, 0, this->textureRect);
	}
	else if (Mouse::isButtonPressed(Mouse::Right) && this->GetKeytime())
	{
		this->tileMap->RemoveTile(this->mousePosGrid.x, this->mousePosGrid.y, 0);
	}
}

void EditorState::UpdateButton()
{
	for (auto& it : this->buttons)
		it.second->Update(this->mousePosView);
}

void EditorState::UpdateGui()
{
	this->selector.setTextureRect(this->textureRect);
	this->selector.setPosition(this->mousePosGrid.x * this->stateData->gridSize, this->mousePosGrid.y * this->stateData->gridSize);
	this->cursorText.setPosition(this->mousePosView.x - 50.f, this->mousePosView.y - 50.f);

	stringstream ss;
	ss << this->mousePosGrid.x / this->stateData->gridSize << " " << this->mousePosGrid.y / this->stateData->gridSize << endl;
	//ss << this->textureRect.left << " " << this->textureRect.top;

	this->cursorText.setString(ss.str());
}

void EditorState::Update(const float& _dt)
{
	this->UpdateKeytime(_dt);
	this->UpdateMousePosition();
	this->UpdateInput(_dt);

	if (!this->pause)
	{
		this->UpdateButton();
		this->UpdateGui();
		this->UpdateEditorInput(_dt);
	}
	else
	{
		this->pauseMenu->Update(this->mousePosView);
		this->UpdatePauseMenuButtons();
	}

}

void EditorState::RenderButton(RenderTarget& _target)
{
	for (auto& it : this->buttons)
		it.second->Render(_target);
}

void EditorState::RenderGui(RenderTarget& _target)
{
	_target.draw(this->selector);
	_target.draw(this->cursorText);
}

void EditorState::Render(RenderTarget* _target)
{
	if (!_target)
		_target = this->window;

	this->tileMap->Render(*_target);
	this->RenderGui(*_target);

	this->RenderButton(*_target);

	if (this->pause)
		this->pauseMenu->Render(*_target, this->wantSave);

}

void EditorState::EndState()
{
	this->quit = true;
}

EditorState::~EditorState()
{
	for (auto it = this->buttons.begin(); it != this->buttons.end(); ++it)
		delete it->second;

	delete this->pauseMenu;
	delete this->tileMap;
}
