#include "pch.h"
#include "GameState.h"


void GameState::InitDifferedRender()
{
	this->renderTexture.create(this->window->getSize().x, this->window->getSize().y);
	this->renderSprite.setTexture(this->renderTexture.getTexture());
	this->renderSprite.setTextureRect(IntRect(0, 0, this->window->getSize().x, this->window->getSize().y));
}

void GameState::InitView()
{
	this->view.setSize(Vector2f(this->window->getSize().x, this->window->getSize().y));
	this->view.setCenter(this->window->getSize().x / 2.f, this->window->getSize().y / 2.f);
}

void GameState::InitKeybinds()
{
	this->keybinds.emplace("ESCAPE", this->supportedKeys->at("Escape"));
	this->keybinds.emplace("MOVE_TOP", this->supportedKeys->at("Up"));
	this->keybinds.emplace("MOVE_LEFT", this->supportedKeys->at("Left"));
	this->keybinds.emplace("MOVE_RIGHT", this->supportedKeys->at("Right"));
	this->keybinds.emplace("MOVE_DOWN", this->supportedKeys->at("Down"));
}

void GameState::InitFont()
{
	if (!this->font.loadFromFile("../Ressources/Fonts/rpgFont.ttf"))
		exit(0);
}

void GameState::InitTexture()
{
	if (!this->textures["PLAYER_IDLE"].loadFromFile("../Ressources/Sprites/Player/blue_link.png"))
		throw "ERROR game state could not load idle texture";
}

void GameState::InitPauseMenu()
{
	this->pauseMenu = new PauseMenu(*this->window, this->font);

	this->InitButton();
}

void GameState::InitButton()
{
	this->pauseMenu->AddButton("GAME_RETURN", 100.f, 400.f, "Resume the game");
	this->pauseMenu->AddButton("LOAD_GAME", 100.f, 480.f, "Load");
	this->pauseMenu->AddButton("SAVE_GAME", 100.f, 550.f, "Save");
	this->pauseMenu->AddButton("EXIT_GAME", 100.f, 800.f, "Quit");

	this->pauseMenu->AddButton("SAVE_1", 100.f, 300.f, "Save 1");
	this->pauseMenu->AddButton("SAVE_2", 100.f, 400.f, "Save 2");
	this->pauseMenu->AddButton("SAVE_3", 100.f, 500.f, "Save 3");
	this->pauseMenu->AddButton("BACK_TO_GAME", 100.f, 600.f, "Resume the game");
	this->pauseMenu->AddButton("BACK_TO_MAINMENU", 100.f, 750.f, "Back to main menu");
}

void GameState::InitPlayer(string _sLoad)
{
	if (_sLoad == "NEW_GAME")
		this->player = new Hero(50, 50, this->textures["PLAYER_IDLE"]);
	else
	{
		this->LoadPos(_sLoad);
		this->player = new Hero(player->GetPos().x, player->GetPos().y, this->textures["PLAYER_IDLE"]);
		this->LoadStat(_sLoad);
	}
}

void GameState::InitTileMap()
{
	this->tileMap = new TileMap(this->stateData->gridSize, 100, 100,
		"../Ressources/Tilesmap/IceDungeonTiles.png");

	this->tileMap->Load("TileMap");
}

GameState::GameState(StateData* _state_data, string _sLoad)
	: State(_state_data)
{
	this->InitDifferedRender();
	this->InitView();
	this->InitKeybinds();
	this->InitFont();
	this->InitTexture();
	this->InitPauseMenu();
	this->InitPlayer(_sLoad);
	this->InitTileMap();
}

void GameState::LoadStat(string _readFile)
{
	ifstream readFile("../Ressources/Saves/" + _readFile + ".txt");

	string line;

	if (readFile.is_open())
	{
		while (getline(readFile, line))
		{
			if (line.find("TimeIngame") != -1)
				this->ingameTime = stof(line.substr(line.find(" ") + 1, line.size()));
			if (line.find("Lvl") != -1)
				this->player->SetLevel(stoi(line.substr(line.find(" ") + 1, line.size())));
			if (line.find("HP") != -1)
				this->player->SetHP(stof(line.substr(line.find(" ") + 1, line.size())));
			if (line.find("MP") != -1)
				this->player->SetMP(stof(line.substr(line.find(" ") + 1, line.size())));
			if (line.find("EndurePoint") != -1)
				this->player->SetEndurePoint(stof(line.substr(line.find(" ") + 1, line.size())));
			if (line.find("MindPoint") != -1)
				this->player->SetMindPoint(stof(line.substr(line.find(" ") + 1, line.size())));
			if (line.find("CurrentExp") != -1)
				this->player->SetMindPoint(stof(line.substr(line.find(" ") + 1, line.size())));
			if (line.find("ExpNeeded") != -1)
				this->player->SetExpNeed(stof(line.substr(line.find(" ") + 1, line.size())));
			if (line.find("TotalExp") != -1)
				this->player->SetExpNeed(stof(line.substr(line.find(" ") + 1, line.size())));
			if (line.find("NbCaracPoint") != -1)
				this->player->SetCaracPoint(stof(line.substr(line.find(" ") + 1, line.size())));
		}
	}
}

void GameState::LoadPos(string _readFile)
{
	ifstream readFile("../Ressources/Saves/" + _readFile + ".txt");

	string line;

	if (readFile.is_open())
	{
		while (getline(readFile, line))
		{
			if (line.find("PosX") != -1)
				this->player->SetPosX(stof(line.substr(line.find(" ") + 1, line.size())));
			if (line.find("PosY") != -1)
				this->player->SetPosY(stof(line.substr(line.find(" ") + 1, line.size())));
		}
	}
}

void GameState::Save(string _writeFile)
{
	ofstream writeFile("../Ressources/Saves/" + _writeFile + ".txt");

	if (writeFile.is_open())
	{
		writeFile << "TimeIngame: " << this->ingameTime << endl << endl;
		writeFile << "Player: " << endl;
		writeFile << "{" << endl;
		writeFile << "Lvl: " << player->GetLevel() << endl;
		writeFile << "HP: " << player->GetHP() << endl;
		writeFile << "MP: " << player->GetMP() << endl;
		writeFile << "EndurePoint: " << player->GetEndurePoint() << endl;
		writeFile << "MindPoint: " << player->GetMindPoint() << endl;
		writeFile << "CurrentExp: " << player->GetCurrentExp() << endl;
		writeFile << "ExpNeeded: " << player->GetExpNeed() << endl;
		writeFile << "TotalExp: " << player->GetTotalExp() << endl;
		writeFile << "NbCaracPoint: " << player->GetCaracPoint() << endl;
		writeFile << "PosX: " << player->GetPos().x << endl;
		writeFile << "PosY: " << player->GetPos().y << endl;
		writeFile << "}" << endl;
	}

	writeFile.close();
}

void GameState::UpdateView(const float& _dt)
{
	this->view.setCenter(Vector2f(this->player->GetPos().x, this->player->GetPos().y));
}

void GameState::UpdatePlayerInput(const float& _dt)
{
	if (Keyboard::isKeyPressed(Keyboard::Key(this->keybinds.at("MOVE_TOP"))))
		this->player->Move(0.f, -1.f, _dt);
	if (Keyboard::isKeyPressed(Keyboard::Key(this->keybinds.at("MOVE_DOWN"))))
		this->player->Move(0.f, 1.f, _dt);
	if (Keyboard::isKeyPressed(Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))
		this->player->Move(-1.f, 0.f, _dt);
	if (Keyboard::isKeyPressed(Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))
		this->player->Move(1.f, 0.f, _dt);

}

void GameState::Update(const float& _dt)
{
	this->UpdateMousePosition(&this->view);
	this->UpdateKeytime(_dt);
	this->UpdateInput(_dt);

	if (!this->pause)
	{
		this->UpdateView(_dt);
		this->UpdatePlayerInput(_dt);
		this->UpdateTileMap(_dt);
		this->player->Update(_dt);

		this->ingameTime += clock.restart().asSeconds();
	}
	else
	{
		this->pauseMenu->Update(this->mousePosWindow);
		this->UpdatePauseMenuButtons();
	}
}

void GameState::UpdateState()
{
}

void GameState::UpdatePauseMenuButtons()
{
	if (this->wantSave)
	{
		string file;

		if (this->pauseMenu->IsButtonPressed("SAVE_1"))
		{
			file = "Save1";
			this->Save(file);
		}

		if (this->pauseMenu->IsButtonPressed("SAVE_2"))
		{
			file = "Save2";
			this->Save(file);
		}

		if (this->pauseMenu->IsButtonPressed("SAVE_3"))
		{
			file = "Save3";
			this->Save(file);
		}
		if (this->pauseMenu->IsButtonPressed("BACK_TO_GAME"))
		{
			this->wantSave = false;
			this->UnpauseState();
		}

		if (this->pauseMenu->IsButtonPressed("BACK_TO_MAINMENU"))
			this->EndState();
	}
	else
	{
		if (this->pauseMenu->IsButtonPressed("GAME_RETURN"))
		{
			this->wantSave = false;
			this->UnpauseState();
		}

		if (this->pauseMenu->IsButtonPressed("SAVE_GAME"))
			this->wantSave = true;

		if (this->pauseMenu->IsButtonPressed("EXIT_GAME"))
			this->EndState();
	}

}

void GameState::UpdateTileMap(const float& _dt)
{
	this->tileMap->Update();
	this->tileMap->UpdateCollision(this->player, _dt);
}

void GameState::UpdateInput(const float& _dt)
{
	if (Keyboard::isKeyPressed(Keyboard::Escape) && this->GetKeytime())
	{
		if (!this->pause)
			this->PauseState();
		else
			this->UnpauseState();
	}
}

GameState::~GameState()
{
	delete this->pauseMenu;
	delete this->player;
	delete this->tileMap;
}

void GameState::Render(RenderTarget* _target)
{
	if (!_target)
		_target = this->window;

	this->renderTexture.clear();
	this->renderTexture.setView(this->view);
	this->tileMap->Render(this->renderTexture, this->player->GetGridPosition(static_cast<int>(this->stateData->gridSize)));

	this->player->Render(this->renderTexture);

	this->tileMap->RenderDeferred(this->renderTexture);

	if (this->pause)
	{
		this->renderTexture.setView(this->renderTexture.getDefaultView());
		this->pauseMenu->Render(this->renderTexture, this->wantSave);
	}

	this->renderTexture.display();
	this->renderSprite.setTexture(this->renderTexture.getTexture());
	_target->draw(this->renderSprite);
}