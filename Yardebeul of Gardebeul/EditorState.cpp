#include "pch.h"
#include "EditorState.h"

void EditorState::InitView()
{
	this->view.setSize(Vector2f(
		static_cast<float>(this->window->getSize().x),
		static_cast<float>(this->window->getSize().y)
	));

	this->view.setCenter(
		static_cast<float>(this->window->getSize().x / 2.f),
		static_cast<float>(this->window->getSize().y / 2.f)
	);
}

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
	this->pauseMenu->AddButton("LOAD_GAME", 100.f, 480.f, "Load");
	this->pauseMenu->AddButton("SAVE_GAME", 100.f, 550.f, "Save");
	this->pauseMenu->AddButton("EXIT_GAME", 100.f, 800.f, "Quit");

	//**********************************************************************************************

	this->pauseMenu->AddButton("SAVE_1", 100.f, 300.f, "Save 1");
	this->pauseMenu->AddButton("SAVE_2", 100.f, 400.f, "Save 2");
	this->pauseMenu->AddButton("SAVE_3", 100.f, 500.f, "Save 3");
	this->pauseMenu->AddButton("BACK_TO_GAME", 100.f, 600.f, "Resume");
	this->pauseMenu->AddButton("BACK_TO_MAINMENU", 100.f, 750.f, "Back to main menu");
}

void EditorState::InitGui()
{
	this->sideBar.setSize(Vector2f(
		80.f,
		static_cast<float>(this->window->getSize().y)
	));
	this->sideBar.setFillColor(Color(50, 50, 50, 100));
	this->sideBar.setOutlineThickness(1.f);
	this->sideBar.setOutlineColor(Color(200, 200, 200, 150));

	this->selector.setSize(Vector2f(this->stateData->gridSize, this->stateData->gridSize));
	this->selector.setFillColor(Color(255, 255, 255, 150));
	this->selector.setOutlineThickness(2.f);
	this->selector.setOutlineColor(Color::Red);

	this->selector.setTexture(this->tileMap->GetTileSheet());
	this->selector.setTextureRect(this->textureRect);

	this->textureSelector = new gui::TextureSelector(
		35.f, 35.f, 500.f, 500.f, this->stateData->gridSize, *this->tileMap->GetTileSheet(), this->font, "TS");
}

void EditorState::IniTileMap()
{
	this->textureRect = IntRect(0, 0, static_cast<int>(this->stateData->gridSize), static_cast<int>(this->stateData->gridSize));

	this->tileMap = new TileMap(this->stateData->gridSize, 100, 100,
		"../Ressources/Tilesmap/IceDungeonTiles.png");
}

EditorState::EditorState(StateData* _state_data)
	: State(_state_data), collision(false), type(TILE_TYPE::DEFAULT), cameraSpeed(1000.f), layer(0)
{
	this->InitBackground();
	this->InitView();
	this->InitFont();
	this->InitText();
	this->InitPauseMenu();
	this->IniTileMap();
	this->InitGui();
}

void EditorState::UpdatePauseMenuButtons()
{
	if (this->pauseMenu->IsButtonPressed("GAME_RETURN"))
		this->UnpauseState();

	if (this->pauseMenu->IsButtonPressed("EXIT_GAME"))
		this->EndState();

	if (this->pauseMenu->IsButtonPressed("SAVE_GAME"))
		this->tileMap->Save("TileMap");

	if (this->pauseMenu->IsButtonPressed("LOAD_GAME"))
		this->tileMap->Load("TileMap");
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
	//Camera movement
	if (Keyboard::isKeyPressed(Keyboard::Z) && this->GetKeytime())
		this->view.move(0.f, -this->cameraSpeed * _dt);
	if (Keyboard::isKeyPressed(Keyboard::S) && this->GetKeytime())
		this->view.move(0.f, this->cameraSpeed * _dt);
	if (Keyboard::isKeyPressed(Keyboard::Q) && this->GetKeytime())
		this->view.move(-this->cameraSpeed * _dt, 0.f);
	if (Keyboard::isKeyPressed(Keyboard::D) && this->GetKeytime())
		this->view.move(this->cameraSpeed * _dt, 0.f);

	if (!this->sideBar.getGlobalBounds().contains(Vector2f(this->mousePosWindow)))
	{
		if (Mouse::isButtonPressed(Mouse::Left) && this->GetKeytime())
		{
			if (!this->textureSelector->GetActive())
				this->tileMap->AddTile(this->mousePosGrid.x, this->mousePosGrid.y, 0, this->textureRect, this->collision, this->type);
			else
				this->textureRect = this->textureSelector->GetTextureRect();
		}
		else if (Mouse::isButtonPressed(Mouse::Right) && this->GetKeytime())
		{
			if (!this->textureSelector->GetActive())
				this->tileMap->RemoveTile(this->mousePosGrid.x, this->mousePosGrid.y, 0);
		}

		//Collision

		if (Keyboard::isKeyPressed(Keyboard::C) && this->GetKeytime())
		{
			if (this->collision)
				this->collision = false;
			else
				this->collision = true;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Up) && this->GetKeytime())
		{
			this->type++;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Down) && this->GetKeytime())
		{
			if(this->type > 0)
				this->type--;
		}
	}

}

void EditorState::UpdateButton()
{
	for (auto& it : this->buttons)
		it.second->Update(this->mousePosWindow);
}

void EditorState::UpdateGui(const float& _dt)
{
	this->textureSelector->Update(this->mousePosWindow, _dt);

	if (!this->textureSelector->GetActive())
	{
		this->selector.setTextureRect(this->textureRect);
		this->selector.setPosition(this->mousePosGrid.x * this->stateData->gridSize, this->mousePosGrid.y * this->stateData->gridSize);
	}

	this->cursorText.setPosition(this->mousePosView.x + 50.f, this->mousePosView.y + 50.f);

	stringstream ss;
	ss << "X: " << this->mousePosGrid.x << endl
		<< "Y: " << this->mousePosGrid.y << endl
		<< "[C] Collision: " << this->collision << endl
		<< "Type: " << this->type << endl;

	this->cursorText.setString(ss.str());

}

void EditorState::Update(const float& _dt)
{
	this->UpdateMousePosition(&this->view);
	this->UpdateKeytime(_dt);
	this->UpdateInput(_dt);

	if (!this->pause)
	{
		this->UpdateButton();
		this->UpdateGui(_dt);
		this->UpdateEditorInput(_dt);
	}
	else
	{
		this->pauseMenu->Update(this->mousePosWindow);
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
	if (!this->textureSelector->GetActive())
	{
		_target.setView(this->view);
		_target.draw(this->selector);
	}

	_target.setView(this->window->getDefaultView());
	this->textureSelector->Render(_target);
	_target.draw(this->sideBar);

	_target.setView(this->view);
	_target.draw(this->cursorText);
}

void EditorState::Render(RenderTarget* _target)
{
	if (!_target)
		_target = this->window;

	_target->setView(this->view);
	this->tileMap->Render(*_target, this->mousePosGrid);
	this->tileMap->RenderDeferred(*_target);

	_target->setView(this->window->getDefaultView());
	this->RenderButton(*_target);
	this->RenderGui(*_target);


	if (this->pause)
	{
		_target->setView(this->window->getDefaultView());
		this->pauseMenu->Render(*_target, this->wantSave);
	}

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
	delete this->textureSelector;
}
