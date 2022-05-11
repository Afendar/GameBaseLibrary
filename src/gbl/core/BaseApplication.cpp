
//GameBaseLibrary Includes
#include <core/BaseApplication.hpp>
#include <core/Exception.hpp>
#include <resource/TextureLoader.hpp>

#include <graphics/RectangleShape.hpp>
#include <graphics/CircleShape.hpp>
#include <graphics/ConvexShape.hpp>

gbl::core::BaseApplication::BaseApplication(int argc, char** argv)
{
	m_window = std::make_unique<gbl::graphics::RenderWindow>();
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
	m_context = std::make_unique<SharedContext>();
	m_context->m_resourceManager->loadConfigFile<gbl::resource::TextureLoader>("resources/config/textures.json");
	return true;
}

void gbl::core::BaseApplication::createWindow(int width, int height, const std::string& title)
{
	m_window->open(width, height, title);
}

void gbl::core::BaseApplication::loop()
{
	while (m_window->isOpen()) {
		handleEvents();

		m_window->clear();

		//Draw call
		gbl::graphics::RectangleShape rectangle(250, 50);
		rectangle.setPosition(50, 50);
		rectangle.setRotation(45);
		m_window->draw(rectangle);

		gbl::graphics::CircleShape circle(30.f);
		circle.setPosition(50, 160);
		circle.setColor(gbl::graphics::Color(150, 0, 150));
		m_window->draw(circle);

		gbl::graphics::CircleShape triangle(50.f, 3);
		triangle.setPosition(150, 50);
		m_window->draw(triangle);

		gbl::graphics::CircleShape square(40.f, 4);
		square.setPosition(150, 50);
		m_window->draw(square);

		gbl::graphics::CircleShape octagon(40.f, 8);
		octagon.setPosition(150, 150);
		m_window->draw(octagon);

		gbl::graphics::ConvexShape convex;
		convex.setPointCount(5);
		convex.setPoint(0, gbl::core::Vector2f(150.f, 150.f));
		convex.setPoint(1, gbl::core::Vector2f(300.f, 160.f));
		convex.setPoint(2, gbl::core::Vector2f(270.f, 240.f));
		convex.setPoint(3, gbl::core::Vector2f(180.f, 250.f));
		convex.setPoint(4, gbl::core::Vector2f(150.f, 200.f));
		m_window->draw(convex);

		m_window->display();
	}
}
