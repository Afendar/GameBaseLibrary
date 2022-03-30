#include "../../../include/gbl/core/BaseApplication.hpp"
#include "../../../include/gbl/core/Exception.hpp"
#include "../../../include/gbl/resource/TextureLoader.hpp"

gbl::core::BaseApplication::BaseApplication(int argc, char** argv)
{
	m_window = std::make_unique<Window>();
	m_context = std::make_unique<SharedContext>();
}

gbl::core::BaseApplication::~BaseApplication()
{
	std::cout << "Destroy Base Application" << std::endl;
	SDL_Quit();
}

int gbl::core::BaseApplication::run()
{
	bool isInit = false;

	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		throw gbl::core::Exception("SDL init error:", SDL_GetError());
	}
	
	createWindow(800, 600, "Test Game Base Library");

	if (isInit = init()) {
		loop();
	}

	if (isInit) {
		onExit();
	}

	return 0;
}

bool gbl::core::BaseApplication::init()
{
	m_context->m_resourceManager->loadConfigFile<gbl::resource::TextureLoader>("resources/config/textures.json");
	return true;
}

void gbl::core::BaseApplication::createWindow(int width, int height, const std::string& title)
{
	m_window->open(width, height, title);
}

void gbl::core::BaseApplication::handleEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		onEvent(event);
	}
}

void gbl::core::BaseApplication::onEvent(const SDL_Event& event)
{
	m_window->onEvent(event);
}

void gbl::core::BaseApplication::loop()
{
	while (m_window->isOpen()) {
		handleEvents();

		//m_window->clear();

		//Draw call

		//m_window->display();
	}
}
