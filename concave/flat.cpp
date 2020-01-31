#include "flat.h"

Flat::Flat()
{
	mainMenuPage = new Menu();
	settingsPage = new Page();
	instructionsPage = new Page();
	creditsPage = new Page();
	levelSelectPage = new Page();
	levelEasy = new Level();
	levelNormal = new Level();
	levelHard = new Level();
	tutorialPage = new Level();
	leaderboardPage = new Leaderboard();
	audio = new Audio();
	reset = false;
}

Flat::~Flat()
{
    releaseAll();
	delete mainMenuPage;
	delete settingsPage;
	delete instructionsPage;
	delete creditsPage;
	delete levelSelectPage;
	delete levelEasy;
	delete levelNormal;
	delete levelHard;
	delete tutorialPage;
	delete leaderboardPage;
}

void Flat::initialize(HWND hwnd)
{
    Game::initialize(hwnd);
	mainMenuPage->initialize(graphics, input);
	settingsPage->initialize(graphics, input);
	instructionsPage->initialize(graphics, input);
	creditsPage->initialize(graphics, input);
	levelSelectPage->initialize(graphics, input);
	leaderboardPage->initialize(graphics, input);
	tutorialPage->initialize(graphics, input, 0);
	levelEasy->initialize(graphics, input, 1);
	levelNormal->initialize(graphics, input, 2);
	levelHard->initialize(graphics, input, 3);
	currentPage = mainMenuPage;

    audio = new Audio();
    if (*WAVE_BANK != '\0' && *SOUND_BANK != '\0')  // if sound files defined
    {
        if( FAILED( hr = audio->initialize() ) )
        {
            if( hr == HRESULT_FROM_WIN32( ERROR_FILE_NOT_FOUND ) )
                throw(GameError(gameErrorNS::FATAL_ERROR, "Failed to initialize sound system because media file not found."));
            else
                throw(GameError(gameErrorNS::FATAL_ERROR, "Failed to initialize sound system."));
        }
    }
	audio->playCue("bensound-epic");
}

void Flat::update()
{
	PageType pageType = currentPage->update(frameTime);
	if (pageType != currentPageType) {
		setCurrentPage(pageType);
		currentPage->start();
	}
}

void Flat::render()
{
	if (!initialized) return;
    graphics->spriteBegin();
	currentPage->render();
    graphics->spriteEnd();
}

void Flat::releaseAll()
{
	mainMenuPage->releaseAll();
	settingsPage->releaseAll();
	instructionsPage->releaseAll();
	creditsPage->releaseAll();
	levelSelectPage->releaseAll();
	levelEasy->releaseAll();
	levelNormal->releaseAll();
	levelHard->releaseAll();
	tutorialPage->releaseAll();
	currentPage->releaseAll();
	leaderboardPage->releaseAll();
	Game::releaseAll();
}

void Flat::resetAll()
{
	mainMenuPage->resetAll();
	settingsPage->resetAll();
	instructionsPage->resetAll();
	creditsPage->resetAll();
	levelSelectPage->resetAll();
	levelEasy->resetAll();
	levelNormal->resetAll();
	levelHard->resetAll();
	tutorialPage->resetAll();
	currentPage->resetAll();
	leaderboardPage->resetAll();
	Game::resetAll();
}

void Flat::setCurrentPage(PageType pageType)
{
	currentPageType = pageType;
	switch (pageType)
	{
	case PageType::MAIN_MENU:
		currentPage = mainMenuPage;
		reset = true;
		break;
	case PageType::SETTINGS:
		currentPage = settingsPage;
		reset = false;
		break;
	case PageType::INSTRUCTION:
		currentPage = instructionsPage;
		reset = false;
		break;
	case PageType::CREDIT:
		currentPage = creditsPage;
		reset = false;
		break;
	case PageType::LEVEL_SELECT:
		currentPage = levelSelectPage;
		reset = false;
		break;
	case PageType::LEADERBOARD:
		currentPage = leaderboardPage;
		reset = true;
		break;
	case PageType::LEVEL_EASY:
		// Reinitialize the level
		if (reset) {
            delete levelEasy;
            levelEasy = new Level();
            levelEasy->initialize(graphics, input, 1);
		}
		currentPage = levelEasy;
		reset = false;
		break;
    case PageType::LEVEL_NORMAL:
		// Reinitialize the level
		if (reset) {
            delete levelNormal;
            levelNormal = new Level();
            levelNormal->initialize(graphics, input, 2);
		}
		currentPage = levelNormal;
		reset = false;
		break;
    case PageType::LEVEL_HARD:
		// Reinitialize the level
		if (reset) {
            delete levelHard;
            levelHard = new Level();
            levelHard->initialize(graphics, input, 3);
		}
		currentPage = levelHard;
		reset = false;
		break;
	case PageType::TUTORIAL:
		if (reset) {
            delete tutorialPage;
            tutorialPage = new Level();
            tutorialPage->initialize(graphics, input, 0);
		}
		currentPage = tutorialPage;
		reset = false;
		break;
	}
}