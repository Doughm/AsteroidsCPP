#include "window.h"
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>
#include "convert.h"
#include <cmath>

Window::Window() :PI(3.141592653589793)
{
	programName = "Asteroids";
	loadINI.setFile("engine.ini");
	if(loadINI.fileExists("engine.ini"))
	{
		if(loadINI.inFile("ResolutionWidth")==true)
		{
			resolutionX = Convert::stringToInt(loadINI.getValue("ResolutionWidth"));
		}
		else
		{
			resolutionX = 640;
		}
		if(loadINI.inFile("ResolutionHeight")==true)
		{
			resolutionY = Convert::stringToInt(loadINI.getValue("ResolutionHeight"));
		}
		else
		{
			resolutionY = 480;
		}
		if(loadINI.inFile("FPSCapped")==true)
		{
			FPSLimit = Convert::stringToBool(loadINI.getValue("FPSCapped"));
		}
		else
		{
			FPSLimit = true;
		}
		if(loadINI.inFile("FPSLimit")==true)
		{
			fps = Convert::stringToInt(loadINI.getValue("FPSLimit"));
		}
		else
		{
			fps = 30;
		}
	}
	else
	{
		resolutionX = 640;
		resolutionY = 480;
		FPSLimit = true;
		fps = 30;
	}

	keyboardDown.clear();
	mouseClick.clear();
	updateSpeed = 1000000/(double)fps;
	gameWindow.create(sf::VideoMode(resolutionX, resolutionY), programName, sf::Style::Close);
	background = sf::Color::White;
	state = state.Default;
	vertexArray = new sf::Vertex[1];
	tempStr.reserve(50);
	tempStr.resize(0);
	gameTimer.restartClock();
}

//returns any keyboard input
std::string Window::inputKeyboard()
{
	tempStr.clear();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		tempStr.append("A");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
		tempStr.append("B");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
		tempStr.append("C");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		tempStr.append("D");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		tempStr.append("E");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
		tempStr.append("F");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
		tempStr.append("G");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
		tempStr.append("H");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
		tempStr.append("I");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
		tempStr.append("J");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
		tempStr.append("K");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
		tempStr.append("L");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
		tempStr.append("M");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
		tempStr.append("N");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
		tempStr.append("O");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
		tempStr.append("P");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		tempStr.append("Q");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		tempStr.append("R");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		tempStr.append("S");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
		tempStr.append("T");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::U))
		tempStr.append("U");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::V))
		tempStr.append("V");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		tempStr.append("W");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
		tempStr.append("X");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
		tempStr.append("Y");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		tempStr.append("Z");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0))
		tempStr.append("Num0");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
		tempStr.append("Num1");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
		tempStr.append("Num2");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
		tempStr.append("Num3");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
		tempStr.append("Num4");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
		tempStr.append("Num5");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
		tempStr.append("Num6");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7))
		tempStr.append("Num7");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8))
		tempStr.append("Num8");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9))
		tempStr.append("Num9");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		tempStr.append("Escape");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
		tempStr.append("Lctrl");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
		tempStr.append("Lshift");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt))
		tempStr.append("Lalt");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::RControl))
		tempStr.append("Rctrl");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))
		tempStr.append("Rshift");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt))
		tempStr.append("Ralt");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::RSystem))
		tempStr.append("Rsystem");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Menu))
		tempStr.append("Menu");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LBracket))
		tempStr.append("Lbracket");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::RBracket))
		tempStr.append("Rbracket");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::SemiColon))
		tempStr.append("SemiColon");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Comma))
		tempStr.append("Comma");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Period))
		tempStr.append("Period");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Quote))
		tempStr.append("Quote");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Slash))
		tempStr.append("Slash");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSlash))
		tempStr.append("Backslash");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tilde))
		tempStr.append("Tilde");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Equal))
		tempStr.append("Equal");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Dash))
		tempStr.append("Dash");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		tempStr.append("Space");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
		tempStr.append("Return");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
		tempStr.append("Backspace");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
		tempStr.append("Tab");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::PageUp))
		tempStr.append("Pageup");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::End))
		tempStr.append("End");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Home))
		tempStr.append("home");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Insert))
		tempStr.append("Insert");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Delete))
		tempStr.append("Delete");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Add))
		tempStr.append("Plus");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract))
		tempStr.append("Minus");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Multiply))
		tempStr.append("Star");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Divide))
		tempStr.append("Slash");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		tempStr.append("Left");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		tempStr.append("Right");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		tempStr.append("Up");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		tempStr.append("Down");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad0))
		tempStr.append("Numpad0");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1))
		tempStr.append("Numpad1");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2))
		tempStr.append("Numpad2");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad3))
		tempStr.append("Numpad3");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4))
		tempStr.append("Numpad4");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad5))
		tempStr.append("Numpad5");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6))
		tempStr.append("Numpad6");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad7))
		tempStr.append("Numpad7");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad8))
		tempStr.append("Numpad8");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad9))
		tempStr.append("Numpad9");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1))
		tempStr.append("F1");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F2))
		tempStr.append("F2");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F3))
		tempStr.append("F3");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F4))
		tempStr.append("F4");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F5))
		tempStr.append("F5");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F6))
		tempStr.append("F6");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F7))
		tempStr.append("F7");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F8))
		tempStr.append("F8");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F9))
		tempStr.append("F9");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F10))
		tempStr.append("F10");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F11))
		tempStr.append("F11");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F12))
		tempStr.append("F12");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F13))
		tempStr.append("F13");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F14))
		tempStr.append("F14");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F15))
		tempStr.append("F15");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Pause))
		tempStr.append("Pause");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Unknown))
		tempStr.append("unknownkey");
	return tempStr;
}

//returns one keyboard input
std::string Window::inputKeyboardSingle()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		return "A";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
		return "B";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
		return "C";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		return "D";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		return "E";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
		return "F";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
		return "G";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
		return "H";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
		return "I";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
		return "J";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
		return "K";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
		return "L";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
		return "M";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
		return "N";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
		return "O";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
		return "P";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		return "Q";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		return "R";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		return "S";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
		return "T";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::U))
		return "U";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::V))
		return "V";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		return "W";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
		return "X";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
		return "Y";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		return "Z";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0))
		return "Num0";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
		return "Num1";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
		return "Num2";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
		return "Num3";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
		return "Num4";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
		return "Num5";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
		return "Num6";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7))
		return "Num7";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8))
		return "Num8";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9))
		return "Num9";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		return "Escape";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
		return "Lctrl";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
		return "Lshift";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt))
		return "Lalt";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::RControl))
		return "Rctrl";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))
		return "Rshift";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt))
		return "Ralt";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::RSystem))
		return "Rsystem";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Menu))
		return "Menu";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LBracket))
		return "Lbracket";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::RBracket))
		return "Rbracket";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::SemiColon))
		return "SemiColon";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Comma))
		return "Comma";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Period))
		return "Period";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Quote))
		return "Quote";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Slash))
		return "Slash";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSlash))
		return "Backslash";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tilde))
		return "Tilde";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Equal))
		return "Equal";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Dash))
		return "Dash";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		return "Space";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
		return "Return";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
		return "Backspace";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
		return "Tab";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::PageUp))
		return "Pageup";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::End))
		return "End";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Home))
		return "home";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Insert))
		return "Insert";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Delete))
		return "Delete";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Add))
		return "Plus";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract))
		return "Minus";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Multiply))
		return "Star";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Divide))
		return "Slash";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		return "Left";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		return "Right";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		return "Up";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		return "Down";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad0))
		return "Numpad0";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1))
		return "Numpad1";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2))
		return "Numpad2";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad3))
		return "Numpad3";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4))
		return "Numpad4";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad5))
		return "Numpad5";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6))
		return "Numpad6";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad7))
		return "Numpad7";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad8))
		return "Numpad8";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad9))
		return "Numpad9";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1))
		return "F1";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F2))
		return "F2";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F3))
		return "F3";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F4))
		return "F4";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F5))
		return "F5";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F6))
		return "F6";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F7))
		return "F7";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F8))
		return "F8";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F9))
		return "F9";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F10))
		return "F10";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F11))
		return "F11";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F12))
		return "F12";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F13))
		return "F13";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F14))
		return "F14";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F15))
		return "F15";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Pause))
		return "Pause";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Unknown))
		return "unknownkey";
	return "";
}

//returns any mouse input
std::string Window::inputMouse()
{
	tempStr.clear();
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        tempStr.append("Leftbutton");
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
        tempStr.append("Rightbutton");
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Middle))
        tempStr.append("Middlebutton");
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::XButton1))
        tempStr.append("Button3");
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::XButton2))
        tempStr.append("Button4");
    return tempStr;
}

//returns one mouse input
std::string Window::inputMouseSingle()
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        return "Leftbutton";
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
            return "Rightbutton";
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Middle))
            return "Middlebutton";
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::XButton1))
            return "Button3";
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::XButton2))
        return "Button4";
    return "";
}

//returns any keyboard input once if a key is down
std::string Window::inputKeyboardDown()
{
    tempStr = inputKeyboard();
    if (tempStr != keyboardDown)
    {
        keyboardDown = tempStr;
        return tempStr;
    }
    return "";
}

//returns one keyboard input once if a key is down
std::string Window::inputKeyboardDownSingle()
{
    tempStr = inputKeyboardSingle();
    if (tempStr != keyboardDown)
    {
        keyboardDown = tempStr;
        return tempStr;
    }
    return "";
}

//returns any mouse input once if a button is down
std::string Window::inputMouseClick()
{
    tempStr = inputMouse();
    if (tempStr != mouseClick)
    {
        mouseClick = tempStr;
        return tempStr;
    }
    return "";
}

//returns any mouse input once if a button is down
std::string Window::inputMouseClickSingle()
{
    tempStr = inputMouseSingle();
    if (tempStr != mouseClick)
    {
        mouseClick = tempStr;
        return tempStr;
    }
    return "";
}

//gets the position of the mouse in screen coordinates
sf::Vector2i Window::mousePosistionRaw()
{
	return sf::Mouse::getPosition();
}

//gets the position of the mouse relative to the window
sf::Vector2i Window::mousePositionWindow()
{
	return sf::Mouse::getPosition(gameWindow);
}

//gets the position of the mouse within the view
sf::Vector2f Window::mousePositionView()
{
	tempVector.x = (float)sf::Mouse::getPosition(gameWindow).x;
	tempVector.y = (float)sf::Mouse::getPosition(gameWindow).y;
    return tempVector;
}

//takes a quad and copies it into the vertex array
void Window::copyQuad(Quad const& quad)
{
	sf::Vertex *temparray = new sf::Vertex[vertexCount + 4];
	for(unsigned int i = 0; i < vertexCount; ++i)
	{
		temparray[i] = vertexArray[i];
	}
	temparray[vertexCount] = quad.vertex[0];
	temparray[vertexCount + 1] = quad.vertex[1];
	temparray[vertexCount + 2] = quad.vertex[2];
	temparray[vertexCount + 3] = quad.vertex[3];
	vertexArray = temparray;
	vertexCount += 4;
	temparray = NULL;
	delete[] temparray;
}

//takes a quad and copies it into the vertex array
void Window::copyQuad(Quad const& quad, int place)
{
	if(vertexCount != 0)
	{
		vertexArray[place] = quad.vertex[0];
		vertexArray[place + 1] = quad.vertex[1];
		vertexArray[place + 2] = quad.vertex[2];
		vertexArray[place + 3] = quad.vertex[3];
	}
}

//adds a view
void Window::addView(std::string const& name, int xPos, int yPos, sf::Vector2f const& size)
{
	sf::Vector2f tempVect;
	tempVect.x = (float)xPos;
	tempVect.y = (float)yPos;
	views[name].setCenter(tempVect);
	views[name].setSize(size);
}

//adds a sprite sheet image into the sprite list
void Window::addSpriteSheet(std::string const& spriteSheet)
{
	sf::Texture *texture;
	texture = new sf::Texture();
	texture->loadFromFile(spriteSheet);
	state.texture = texture;
	texture = NULL;
	delete texture;
}

//adds an image definition to the sprite map
void Window::addSpriteMap(std::string const& name, sf::Vector2f const& position, int width, int height)
{
	spriteMaps[name].left = position.x;
	spriteMaps[name].top = position.y;
	spriteMaps[name].width = (float)width;
	spriteMaps[name].height = (float)height;
}

//adds a quad entity
void Window::addQuad(std::string const& name, sf::Vertex const& point1, sf::Vertex const& point2, sf::Vertex const& point3,sf::Vertex const& point4)
{
	entitys[name].vertex[0] = point1;
	entitys[name].vertex[1] = point2;
	entitys[name].vertex[2] = point3;
	entitys[name].vertex[3] = point4;
	entitys[name].color[0] = point1.color;
	entitys[name].color[1] = point2.color;
	entitys[name].color[2] = point3.color;
	entitys[name].color[3] = point4.color;
	entitys[name].rotation = 0;
	entitys[name].firstPosition = vertexCount;
	copyQuad(entitys[name]);
}

//adds a sprite entity
void Window::addSprite(std::string const& name, std::string const& imageName, sf::Vector2f const& position)
{
	std::unordered_map<std::string,sf::FloatRect>::iterator spriteMapIterator = spriteMaps.find(imageName);
	if(spriteMapIterator != spriteMaps.end())
	{
		entitys[name].vertex[0].position.x = position.x;
		entitys[name].vertex[0].position.y = position.y;
		entitys[name].vertex[1].position.x = position.x + spriteMaps[imageName].width;
		entitys[name].vertex[1].position.y = position.y;
		entitys[name].vertex[2].position.x = position.x + spriteMaps[imageName].width;
		entitys[name].vertex[2].position.y = position.y + spriteMaps[imageName].height;
		entitys[name].vertex[3].position.x = position.x;
		entitys[name].vertex[3].position.y = position.y + spriteMaps[imageName].height;
		entitys[name].vertex[0].texCoords.x = spriteMaps[imageName].left;
		entitys[name].vertex[0].texCoords.y = spriteMaps[imageName].top;
		entitys[name].vertex[1].texCoords.x = spriteMaps[imageName].left + spriteMaps[imageName].width;
		entitys[name].vertex[1].texCoords.y = spriteMaps[imageName].top;
		entitys[name].vertex[2].texCoords.x = spriteMaps[imageName].left + spriteMaps[imageName].width;
		entitys[name].vertex[2].texCoords.y = spriteMaps[imageName].top + spriteMaps[imageName].height;
		entitys[name].vertex[3].texCoords.x = spriteMaps[imageName].left;
		entitys[name].vertex[3].texCoords.y = spriteMaps[imageName].top + spriteMaps[imageName].height;
		entitys[name].vertex[0].color = sf::Color::White;
		entitys[name].vertex[1].color = sf::Color::White;
		entitys[name].vertex[2].color = sf::Color::White;
		entitys[name].vertex[3].color = sf::Color::White;
		entitys[name].color[0] = sf::Color::White;
		entitys[name].color[1] = sf::Color::White;
		entitys[name].color[2] = sf::Color::White;
		entitys[name].color[3] = sf::Color::White;
		entitys[name].rotation = 0;
		entitys[name].firstPosition = vertexCount;
		copyQuad(entitys[name]);
	}
}

//adds a rectangle entity
void Window::addRectangle(std::string const& name, sf::Vector2f const& position, int width, int height, sf::Color const& color)
{
	entitys.insert(std::pair<std::string, Quad>());
	entitys[name].vertex[0].position.x = position.x;
	entitys[name].vertex[0].position.y = position.y;
	entitys[name].vertex[1].position.x = position.x + width;
	entitys[name].vertex[1].position.y = position.y;
	entitys[name].vertex[2].position.x = position.x + width;
	entitys[name].vertex[2].position.y = position.y + height;
	entitys[name].vertex[3].position.x = position.x;
	entitys[name].vertex[3].position.y = position.y + height;
	entitys[name].vertex[0].color = color;
	entitys[name].vertex[1].color = color;
	entitys[name].vertex[2].color = color;
	entitys[name].vertex[3].color = color;
	entitys[name].color[0] = color;
	entitys[name].color[1] = color;
	entitys[name].color[2] = color;
	entitys[name].color[3] = color;
	entitys[name].rotation = 0;
	entitys[name].firstPosition = vertexCount;
	copyQuad(entitys[name]);
}

//adds a rectangle entity
void Window::addRectangle(std::string const& name, sf::Vector2f const& position, int width, int height, sf::Color const& color1, sf::Color const& color2,sf::Color const& color3,sf::Color const& color4)
{
	entitys.insert(std::pair<std::string, Quad>());
	entitys[name].vertex[0].position.x = position.x;
	entitys[name].vertex[0].position.y = position.y;
	entitys[name].vertex[1].position.x = position.x + width;
	entitys[name].vertex[1].position.y = position.y;
	entitys[name].vertex[2].position.x = position.x + width;
	entitys[name].vertex[2].position.y = position.y + height;
	entitys[name].vertex[3].position.x = position.x;
	entitys[name].vertex[3].position.y = position.y + height;
	entitys[name].vertex[0].color = color1;
	entitys[name].vertex[1].color = color2;
	entitys[name].vertex[2].color = color3;
	entitys[name].vertex[3].color = color4;
	entitys[name].color[0] = color1;
	entitys[name].color[1] = color2;
	entitys[name].color[2] = color3;
	entitys[name].color[3] = color4;
	entitys[name].rotation = 0;
	entitys[name].firstPosition = vertexCount;
	copyQuad(entitys[name]);
}

//adds a text entity
void Window::addText(std::string const& name, sf::Vector2f const& position, sf::Color const& color, int size, std::string const& newText)
{
	sf::Vector2f tempVect;
	tempVect.x = position.x;
	tempVect.y = position.y;
	text[name].setPosition(tempVect);
	text[name].setString(newText);
	text[name].setFont(font);
	text[name].setColor(color);
	text[name].setCharacterSize(size);
	colorMap[name] = color;
}

//adds a circle entity
void Window::addCircle(std::string const& name, sf::Vector2f const& position, sf::Color const& color, int radius)
{
	sf::Vector2f tempVect;
	tempVect.x = position.x;
	tempVect.y = position.y;
	circles[name].setPosition(tempVect);
	circles[name].setRadius((float)radius);
	circles[name].setFillColor(color);
	colorMap[name] = color;
}

//adds a animation entity made up of multiple sprite map images.
//the size is set by the first frames size. Normal speed is 1.
void Window::addAnimation(std::string const& name, std::vector<std::string> const& frames, sf::Vector2f const& position, float speed)
{
	animations[name].frames = frames;
	animations[name].positions.vertex[0].position.x = position.x;
	animations[name].positions.vertex[0].position.y = position.y;
	animations[name].positions.vertex[1].position.x = position.x + spriteMaps[frames[0]].width;
	animations[name].positions.vertex[1].position.y = position.y;
	animations[name].positions.vertex[2].position.x = position.x + spriteMaps[frames[0]].width;
	animations[name].positions.vertex[2].position.y = position.y + spriteMaps[frames[0]].height;
	animations[name].positions.vertex[3].position.x = position.x;
	animations[name].positions.vertex[3].position.y = position.y + spriteMaps[frames[0]].height;
	animations[name].positions.vertex[0].texCoords.x = spriteMaps[frames[0]].left;
	animations[name].positions.vertex[0].texCoords.y = spriteMaps[frames[0]].top;
	animations[name].positions.vertex[1].texCoords.x = spriteMaps[frames[0]].left + spriteMaps[frames[0]].width;
	animations[name].positions.vertex[1].texCoords.y = spriteMaps[frames[0]].top;
	animations[name].positions.vertex[2].texCoords.x = spriteMaps[frames[0]].left + spriteMaps[frames[0]].width;
	animations[name].positions.vertex[2].texCoords.y = spriteMaps[frames[0]].top + spriteMaps[frames[0]].height;
	animations[name].positions.vertex[3].texCoords.x = spriteMaps[frames[0]].left;
	animations[name].positions.vertex[3].texCoords.y = spriteMaps[frames[0]].top + spriteMaps[frames[0]].height;
	animations[name].positions.vertex[0].color = sf::Color::White;
	animations[name].positions.vertex[1].color = sf::Color::White;
	animations[name].positions.vertex[2].color = sf::Color::White;
	animations[name].positions.vertex[3].color = sf::Color::White;
	animations[name].positions.color[0] = sf::Color::White;
	animations[name].positions.color[1] = sf::Color::White;
	animations[name].positions.color[2] = sf::Color::White;
	animations[name].positions.color[3] = sf::Color::White;
	animations[name].positions.rotation = 0;
	animations[name].speed = 1000 -(speed * 500);
	animations[name].positions.firstPosition = vertexCount;
	copyQuad(animations[name].positions);
}

//adds X number of entitys of type quad
void Window::batchAddQuad(int numberToMake, std::string const& name, sf::Vertex const& point1, sf::Vertex const& point2, sf::Vertex const& point3,sf::Vertex const& point4)
{
	for (int i = 0; i < numberToMake; ++i)
    {
		addQuad(name + Convert::intToString(i + 1), point1, point2, point3, point4);
    }
}

//adds X number of entitys of type sprite
void Window::batchAddSprite(int numberToMake, std::string const& name, std::string const& imageName, sf::Vector2f const& position)
{
	for (int i = 0; i < numberToMake; ++i)
    {
		addSprite(name + Convert::intToString(i + 1), imageName, position);
    }
}

//adds X number of entitys of type rectangle
void Window::batchAddRectangle(int numberToMake, std::string const& name, sf::Vector2f const& position, int height, int width, sf::Color const& color)
{
	for (int i = 0; i < numberToMake; ++i)
    {
		addRectangle(name + Convert::intToString(i + 1), position, height, width, color);
    }
}

//adds X number of entitys of type rectangle
void Window::batchAddRectangle(int numberToMake, std::string const& name, sf::Vector2f const& position, int height, int width, sf::Color const& color1, sf::Color const& color2,sf::Color const& color3, sf::Color const& color4)
{
	for (int i = 0; i < numberToMake; ++i)
    {
		addRectangle(name + Convert::intToString(i + 1), position, height, width, color1, color2, color3, color4);
    }
}

//adds X number of entitys of type text
void Window::batchAddText(int numberToMake, std::string const& name, sf::Vector2f const& position, sf::Color const& color, int size, std::string const& text)
{
	for (int i = 0; i < numberToMake; ++i)
    {
		addText(name + Convert::intToString(i + 1), position, color, size, text);
    }
}

//adds X number of entitys of type circle
void Window::batchAddCircle(int numberToMake, std::string const& name, sf::Vector2f const& position, sf::Color const& color, int radius)
{
    for (int i = 0; i < numberToMake; ++i)
    {
		addCircle(name + Convert::intToString(i + 1), position, color, radius);
    }
}

//adds X number of entitys of type animation
void Window::batchAddAnimation(int numberToMake, std::string const& name, std::vector<std::string> const& frames, sf::Vector2f const& position, float speed)
{
	for (int i = 0; i < numberToMake; ++i)
    {
		addAnimation(name + Convert::intToString(i + 1), frames, position, speed);
    }
}

//returns the number in the name of a batch entity
int Window::batchNumber(std::string const& name)
{
	tempStr.clear();
	for(unsigned int i = 0 ; i < name.length(); ++i)
	{
		if(name[i] == '1' || name[i] == '2' || name[i] == '3' ||
		   name[i] == '4' || name[i] == '5' || name[i] == '6' ||
		   name[i] == '7' || name[i] == '8' || name[i] == '9' ||
		   name[i] == '0')
		{
			tempStr.push_back((name[i]));
		}
	}
	return Convert::stringToInt(tempStr);
}

//deletes one entity from the object
void Window::deleteEntity(std::string const& name)
{
	//circle
	circleIterator = circles.find(name);
	if(circleIterator != circles.end())
	{
		circles.erase(circleIterator->first);
	}
	//text
	textIterator = text.find(name);
	if(textIterator != text.end())
	{
		text.erase(textIterator->first);
	}
	//animation
	animationIterator = animations.find(name);
	if(animationIterator != animations.end())
	{
		vertexArray[animations[name].positions.firstPosition] = sf::Vector2f();
		vertexArray[animations[name].positions.firstPosition + 1] = sf::Vector2f();
		vertexArray[animations[name].positions.firstPosition + 2] = sf::Vector2f();
		vertexArray[animations[name].positions.firstPosition + 3] = sf::Vector2f();
	}
	//quad
	entityIterator = entitys.find(name);
	if(entityIterator != entitys.end())
	{
		vertexArray[entitys[name].firstPosition] = sf::Vector2f();
		vertexArray[entitys[name].firstPosition + 1] = sf::Vector2f();
		vertexArray[entitys[name].firstPosition + 2] = sf::Vector2f();
		vertexArray[entitys[name].firstPosition + 3] = sf::Vector2f();
	}
}

//deletes all entitys from the object
void Window::deleteAllEntitys()
{
	delete[] vertexArray;
	vertexArray = new sf::Vertex[1];
	vertexCount = 0;
	entitys.clear();
	circles.clear();
	text.clear();
	colorMap.clear();
	animations.clear();
}

//deletes all views
void Window::deleteViews()
{
	views.clear();
}

//deletes everything
void Window::deleteAll()
{
	delete[] vertexArray;
	vertexArray = new sf::Vertex[1];
	vertexCount = 0;
	entitys.clear();
	circles.clear();
	text.clear();
	colorMap.clear();
	animations.clear();
	font.loadFromFile("null");
	views.clear();
	state = sf::RenderStates::Default;
	spriteMaps.clear();
	background = sf::Color::White;
	mouseClick = "";
	keyboardDown = "";
}

//sets the font used
void Window::setFont(std::string const& file)
{
	font.loadFromFile(file);
}

//sets the color of the window background
void Window::setBackgroundColor(sf::Color const& color)
{
	background = color;
}

//sets the speed of an animation. 1 is narmal.
void Window::setAnimationSpeed(std::string const& name, float speed)
{
	animationIterator = animations.find(name);
	if(animationIterator != animations.end())
	{
		animations[name].speed = speed;
	}
}

//sets the fill color of an entity
void Window::setColor(std::string const& name, sf::Color const& color)
{
	//circle
	circleIterator = circles.find(name);
	if(circleIterator != circles.end())
	{
		circles[name].setFillColor(color);
		colorMap[name] = color;
	}
	//text
	textIterator = text.find(name);
	if(textIterator != text.end())
	{
		text[name].setColor(color);
        colorMap[name] = color;
	}
	//animation
	animationIterator = animations.find(name);
	if(animationIterator != animations.end())
	{
		animations[name].positions.vertex[0].color = color;
        animations[name].positions.color[0] = color;
        animations[name].positions.vertex[1].color = color;
        animations[name].positions.color[1] = color;
        animations[name].positions.vertex[2].color = color;
        animations[name].positions.color[2] = color;
        animations[name].positions.vertex[3].color = color;
        animations[name].positions.color[3] = color;
		copyQuad(animations[name].positions, animations[name].positions.firstPosition);
	}
	//quad
	entityIterator = entitys.find(name);
	if(entityIterator != entitys.end())
	{
		entitys[name].vertex[0].color = color;
        entitys[name].color[0] = color;
        entitys[name].vertex[1].color = color;
        entitys[name].color[1] = color;
        entitys[name].vertex[2].color = color;
        entitys[name].color[2] = color;
        entitys[name].vertex[3].color = color;
        entitys[name].color[3] = color;
		copyQuad(entitys[name], entitys[name].firstPosition);
	}
}

//sets the fill color of an entity
void Window::setColor(std::string const& name, sf::Color const& color1, sf::Color const& color2, sf::Color const& color3, sf::Color const& color4)
{
	//animation
	animationIterator = animations.find(name);
	if(animationIterator != animations.end())
	{
		animations[name].positions.vertex[0].color = color1;
        animations[name].positions.color[0] = color1;
        animations[name].positions.vertex[1].color = color2;
        animations[name].positions.color[1] = color2;
        animations[name].positions.vertex[2].color = color3;
        animations[name].positions.color[2] = color3;
        animations[name].positions.vertex[3].color = color4;
        animations[name].positions.color[3] = color4;
		copyQuad(animations[name].positions, animations[name].positions.firstPosition);
	}
	//quad
	entityIterator = entitys.find(name);
	if(entityIterator != entitys.end())
	{
		entitys[name].vertex[0].color = color1;
        entitys[name].color[0] = color1;
        entitys[name].vertex[1].color = color2;
        entitys[name].color[1] = color2;
        entitys[name].vertex[2].color = color3;
        entitys[name].color[2] = color3;
        entitys[name].vertex[3].color = color4;
        entitys[name].color[3] = color4;
		copyQuad(entitys[name], entitys[name].firstPosition);
	}
}

//sets the outline of a circle entity
void Window::setCircleOutline(std::string const& name, sf::Color const& color, int thickness)
{
	circleIterator = circles.find(name);
	if(circleIterator != circles.end())
	{
		circles[name].setOutlineColor(color);
		circles[name].setOutlineThickness((float)thickness);
    }
}

//sets the text of a text entity
void Window::setText(std::string const& name, std::string const& newText)
{
	textIterator = text.find(name);
	if(textIterator != text.end())
	{
		text[name].setString(newText);
	}
}

//sets the current view
void Window::setView(std::string const& name)
{
	std::unordered_map<std::string, sf::View>::iterator viewIterator = views.find(name);
	if(viewIterator != views.end())
	{
		gameWindow.setView(views[name]);
	}
}

//returns the point of origin of a specific entity [-1,-1 is error]
sf::Vector2f Window::getPointOfOrigin(std::string const& name)
{
	//circle
	circleIterator = circles.find(name);
	if(circleIterator != circles.end())
	{
		return circles[name].getPosition();
	}
	//text
	textIterator = text.find(name);
	if(textIterator != text.end())
	{
		return text[name].getPosition();
	}
	//animation
	animationIterator = animations.find(name);
	if(animationIterator != animations.end())
	{
		return animations[name].positions.vertex[0].position;
	}
	//quad
	entityIterator = entitys.find(name);
	if(entityIterator != entitys.end())
	{
		return entitys[name].vertex[0].position;
	}
	return sf::Vector2f(-1,-1);
}

//returns the rotation of an entity [-1 is error]
double Window::getRotation(std::string const& name)
{
	//circle
	circleIterator = circles.find(name);
	if(circleIterator != circles.end())
	{
		return circles[name].getRotation();
	}
	//text
	textIterator = text.find(name);
	if(textIterator != text.end())
	{
		return text[name].getRotation();
	}
	//animation
	animationIterator = animations.find(name);
	if(animationIterator != animations.end())
	{
		return animations[name].positions.rotation;
	}
	//quad
	entityIterator = entitys.find(name);
	if(entityIterator != entitys.end())
	{
		return entitys[name].rotation;
	}
	return -1;
}

//returns the text of a text entity
std::string Window::getText(std::string const& name)
{
	textIterator = text.find(name);
	if(textIterator != text.end())
	{
		return text[name].getString();
	}
	return "no entity found";
}

//returns if an animation is paused
bool Window::getAnimationPaused(std::string const& name)
{
	animationIterator = animations.find(name);
	if(animationIterator != animations.end())
	{
		return animations[name].paused;
	}
	return false;
}

//returns if an animation loops
bool Window::getAnimationLoops(std::string const& name)
{
	animationIterator = animations.find(name);
	if(animationIterator != animations.end())
	{
		return animations[name].loops;
	}
	return false;
}

//returns the current frame on an animation [-1 is error]
int Window::getAnimationFrame(std::string const& name)
{
	animationIterator = animations.find(name);
	if(animationIterator != animations.end())
	{
		return animations[name].currentFrame;
	}
	return -1;
}

//returns an quad of an entity
Quad Window::getQuad(std::string const& name)
{
	//circle
	circleIterator = circles.find(name);
	if(circleIterator != circles.end())
	{
		Quad tempQuad;
		tempQuad.color[0] = circles[name].getFillColor();
		tempQuad.color[1] = circles[name].getOutlineColor();
		tempQuad.rotation = circles[name].getRotation();
		tempQuad.vertex[0].position = circles[name].getPosition();
		tempQuad.vertex[1].position.x = circles[name].getPosition().x + (circles[name].getRadius() * 2);
		tempQuad.vertex[1].position.y = circles[name].getPosition().y;
		tempQuad.vertex[2].position.x = circles[name].getPosition().x + (circles[name].getRadius() * 2);
		tempQuad.vertex[2].position.y = circles[name].getPosition().y + (circles[name].getRadius() * 2);
		tempQuad.vertex[3].position.x = circles[name].getPosition().x;
		tempQuad.vertex[3].position.y = circles[name].getPosition().y + (circles[name].getRadius() * 2);
		tempQuad.scale = circles[name].getScale();
		return tempQuad;
	}
	//text
	textIterator = text.find(name);
	if(textIterator != text.end())
	{
		Quad tempQuad;
		tempQuad.color[0] = text[name].getColor();
		tempQuad.vertex[0].position = text[name].getPosition();
		tempQuad.scale = text[name].getScale();
		return tempQuad;
	}
	//animation
	animationIterator = animations.find(name);
	if(animationIterator != animations.end())
	{
		return animations[name].positions;
	}
	//quad
	entityIterator = entitys.find(name);
	if(entityIterator != entitys.end())
	{
		return entitys[name];
	}
	return Quad();
}

//returns the number of elements in vectorArray
int Window::getVertexArrayCount()
{
	return vertexCount;
}

//returns the number of elements in entitys
int Window::getEntitysCount()
{
	int tempInt = 0;
	for(std::unordered_map<std::string, Quad>::iterator tempEntItr = entitys.begin(); tempEntItr != entitys.end(); ++tempEntItr)
	{
		tempInt++;
	}
	return tempInt;
}

//returns the number of elements in circles
int Window::getCirclesCount()
{
	int tempInt = 0;
	for(std::unordered_map<std::string, sf::CircleShape>::iterator tempCirItr = circles.begin(); tempCirItr != circles.end(); ++tempCirItr)
	{
		tempInt++;
	}
	return tempInt;
}

//returns the number of elements in text
int Window::getTextCount()
{
	int tempInt = 0;
	for(std::unordered_map<std::string, sf::Text>::iterator tempTexItr = text.begin(); tempTexItr != text.end(); ++tempTexItr)
	{
		tempInt++;
	}
	return tempInt;
}

//returns the number of elements in animations
int Window::getAnimationCount()
{
	int tempInt = 0;
	for(std::unordered_map<std::string, Animation>::iterator tempAniItr = animations.begin(); tempAniItr != animations.end(); ++tempAniItr)
	{
		tempInt++;
	}
	return tempInt;
}

//returns a list of all entities contained in this object
std::string Window::getAllEntities()
{
	tempStr.clear();
	//circle
	for(std::unordered_map<std::string, sf::CircleShape>::iterator tempCirItr = circles.begin(); tempCirItr != circles.end(); ++tempCirItr)
	{
		tempStr.append(tempCirItr->first);
		tempStr.push_back('\n');
	}
	//text
	for(std::unordered_map<std::string, sf::Text>::iterator tempTexItr = text.begin(); tempTexItr != text.end(); ++tempTexItr)
	{
		tempStr.append(tempTexItr->first);
		tempStr.push_back('\n');
	}
	//animation
	for(std::unordered_map<std::string, Animation>::iterator tempAniItr = animations.begin(); tempAniItr != animations.end(); ++tempAniItr)
	{
		tempStr.append(tempAniItr->first);
		tempStr.push_back('\n');
	}
	//quad
	for(std::unordered_map<std::string, Quad>::iterator tempEntItr = entitys.begin(); tempEntItr != entitys.end(); ++tempEntItr)
	{
		tempStr.append(tempEntItr->first);
		tempStr.push_back('\n');
	}
	return tempStr;
}

//returns the current window resolution
sf::Vector2f Window::getResolution()
{
	tempVector.x = (float)resolutionX;
	tempVector.x = (float)resolutionY;
	return tempVector;
}

//checks if window is still open, if not ends the program
bool Window::isOpen()
{
	if(gameWindow.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
		{
            gameWindow.close();
		}
    }

	if(gameWindow.isOpen()==true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//finds if a specific entity exists
bool Window::entityExists(std::string const& name)
{
	//quad
	entityIterator = entitys.find(name);
	if(entityIterator != entitys.end())
	{
		return true;
	}
	//animation
	animationIterator = animations.find(name);
	if(animationIterator != animations.end())
	{
		return true;
	}
	return false;
	//circle
	circleIterator = circles.find(name);
	if(circleIterator != circles.end())
	{
		return true;
	}
	//text
	textIterator = text.find(name);
	if(textIterator != text.end())
	{
		return true;
	}
}

//moves an entitys position
void Window::moveEntity(std::string const& name, sf::Vector2f const& position)
{
	//quad
	entityIterator = entitys.find(name);
	if(entityIterator != entitys.end())
	{
		tempVector.x = entitys[name].vertex[0].position.x - position.x;
		tempVector.y = entitys[name].vertex[0].position.y - position.y;
		entitys[name].vertex[0].position.x -= tempVector.x;
		entitys[name].vertex[0].position.y -= tempVector.y;
		entitys[name].vertex[1].position.x -= tempVector.x;
		entitys[name].vertex[1].position.y -= tempVector.y;
		entitys[name].vertex[2].position.x -= tempVector.x;
		entitys[name].vertex[2].position.y -= tempVector.y;
		entitys[name].vertex[3].position.x -= tempVector.x;
		entitys[name].vertex[3].position.y -= tempVector.y;
		vertexArray[entitys[name].firstPosition].position.x -= tempVector.x;
		vertexArray[entitys[name].firstPosition].position.y -= tempVector.y;
		vertexArray[entitys[name].firstPosition + 1].position.x -= tempVector.x;
		vertexArray[entitys[name].firstPosition + 1].position.y -= tempVector.y;
		vertexArray[entitys[name].firstPosition + 2].position.x -= tempVector.x;
		vertexArray[entitys[name].firstPosition + 2].position.y -= tempVector.y;
		vertexArray[entitys[name].firstPosition + 3].position.x -= tempVector.x;
		vertexArray[entitys[name].firstPosition + 3].position.y -= tempVector.y;
		return;
	}
	//animation
	animationIterator = animations.find(name);
	if(animationIterator != animations.end())
	{
		tempVector.x = animations[name].positions.vertex[0].position.x - position.x;
		tempVector.y = animations[name].positions.vertex[0].position.y - position.y;
		animations[name].positions.vertex[0].position.x -= tempVector.x;
		animations[name].positions.vertex[0].position.y -= tempVector.y;
		animations[name].positions.vertex[1].position.x -= tempVector.x;
		animations[name].positions.vertex[1].position.y -= tempVector.y;
		animations[name].positions.vertex[2].position.x -= tempVector.x;
		animations[name].positions.vertex[2].position.y -= tempVector.y;
		animations[name].positions.vertex[3].position.x -= tempVector.x;
		animations[name].positions.vertex[3].position.y -= tempVector.y;
		vertexArray[animations[name].positions.firstPosition].position.x -= tempVector.x;
		vertexArray[animations[name].positions.firstPosition].position.y -= tempVector.y;
		vertexArray[animations[name].positions.firstPosition + 1].position.x -= tempVector.x;
		vertexArray[animations[name].positions.firstPosition + 1].position.y -= tempVector.y;
		vertexArray[animations[name].positions.firstPosition + 2].position.x -= tempVector.x;
		vertexArray[animations[name].positions.firstPosition + 2].position.y -= tempVector.y;
		vertexArray[animations[name].positions.firstPosition + 3].position.x -= tempVector.x;
		vertexArray[animations[name].positions.firstPosition + 3].position.y -= tempVector.y;
		return;
	}
	//circle
	circleIterator = circles.find(name);
	if(circleIterator != circles.end())
	{
		circles[name].setPosition(position);
		return;
	}
	//text
	textIterator = text.find(name);
	if(textIterator != text.end())
	{
		text[name].setPosition(position);
		return;
	}
}

//scales an entity (100% size is 1)
void Window::scaleEntity(std::string const& name, float scaler)
{
	//animation
	animationIterator = animations.find(name);
	if(animationIterator != animations.end())
	{
		vertexArray[animations[name].positions.firstPosition + 1].position.x = (vertexArray[animations[name].positions.firstPosition + 1].position.x
			- vertexArray[animations[name].positions.firstPosition].position.x)
			* scaler + vertexArray[animations[name].positions.firstPosition].position.x;
		vertexArray[animations[name].positions.firstPosition + 2].position.x = (vertexArray[animations[name].positions.firstPosition + 2].position.x
			- vertexArray[animations[name].positions.firstPosition].position.x)
			* scaler + vertexArray[animations[name].positions.firstPosition].position.x;
		vertexArray[animations[name].positions.firstPosition + 2].position.y = (vertexArray[animations[name].positions.firstPosition + 2].position.y
			- vertexArray[animations[name].positions.firstPosition].position.y)
			* scaler + vertexArray[animations[name].positions.firstPosition].position.y;
		vertexArray[animations[name].positions.firstPosition + 3].position.y = (vertexArray[animations[name].positions.firstPosition + 3].position.y
			- vertexArray[animations[name].positions.firstPosition].position.y)
			* scaler + vertexArray[animations[name].positions.firstPosition].position.y;
		return;
	}
	//quad
	entityIterator = entitys.find(name);
	if(entityIterator != entitys.end())
	{
		vertexArray[entitys[name].firstPosition + 1].position.x = (vertexArray[entitys[name].firstPosition + 1].position.x
			- vertexArray[entitys[name].firstPosition].position.x)
			* scaler + vertexArray[entitys[name].firstPosition].position.x;
		vertexArray[entitys[name].firstPosition + 2].position.x = (vertexArray[entitys[name].firstPosition + 2].position.x
			- vertexArray[entitys[name].firstPosition].position.x)
			* scaler + vertexArray[entitys[name].firstPosition].position.x;
		vertexArray[entitys[name].firstPosition + 2].position.y = (vertexArray[entitys[name].firstPosition + 2].position.y
			- vertexArray[entitys[name].firstPosition].position.y)
			* scaler + vertexArray[entitys[name].firstPosition].position.y;
		vertexArray[entitys[name].firstPosition + 3].position.y = (vertexArray[entitys[name].firstPosition + 3].position.y
			- vertexArray[entitys[name].firstPosition].position.y)
			* scaler + vertexArray[entitys[name].firstPosition].position.y;
		return;
	}
	//circle
	circleIterator = circles.find(name);
	if(circleIterator != circles.end())
	{
		tempVector.x = scaler;
		tempVector.y = scaler;
		circles[name].setScale(tempVector);
		return;
	}
	//text
	textIterator = text.find(name);
	if(textIterator != text.end())
	{
		tempVector.x = scaler;
		tempVector.y = scaler;
		text[name].setScale(tempVector);
		return;
	}
}

//scales an entity (100% size is 1)
void Window::scaleEntity(std::string const& name, sf::Vector2f const& scaler)
{
	//quad
	entityIterator = entitys.find(name);
	if(entityIterator != entitys.end())
	{
		vertexArray[entitys[name].firstPosition + 1].position.x = (vertexArray[entitys[name].firstPosition + 1].position.x
			- vertexArray[entitys[name].firstPosition].position.x)
			* scaler.x + vertexArray[entitys[name].firstPosition].position.x;
		vertexArray[entitys[name].firstPosition + 2].position.x = (vertexArray[entitys[name].firstPosition + 2].position.x
			- vertexArray[entitys[name].firstPosition].position.x)
			* scaler.x + vertexArray[entitys[name].firstPosition].position.x;
		vertexArray[entitys[name].firstPosition + 2].position.y = (vertexArray[entitys[name].firstPosition + 2].position.y
			- vertexArray[entitys[name].firstPosition].position.y)
			* scaler.y + vertexArray[entitys[name].firstPosition].position.y;
		vertexArray[entitys[name].firstPosition + 3].position.y = (vertexArray[entitys[name].firstPosition + 3].position.y
			- vertexArray[entitys[name].firstPosition].position.y)
			* scaler.y + vertexArray[entitys[name].firstPosition].position.y;
		return;
	}
	//animation
	animationIterator = animations.find(name);
	if(animationIterator != animations.end())
	{
		vertexArray[animations[name].positions.firstPosition + 1].position.x = (vertexArray[animations[name].positions.firstPosition + 1].position.x
			- vertexArray[animations[name].positions.firstPosition].position.x)
			* scaler.x + vertexArray[animations[name].positions.firstPosition].position.x;
		vertexArray[animations[name].positions.firstPosition + 2].position.x = (vertexArray[animations[name].positions.firstPosition + 2].position.x
			- vertexArray[animations[name].positions.firstPosition].position.x)
			* scaler.x + vertexArray[animations[name].positions.firstPosition].position.x;
		vertexArray[animations[name].positions.firstPosition + 2].position.y = (vertexArray[animations[name].positions.firstPosition + 2].position.y
			- vertexArray[animations[name].positions.firstPosition].position.y)
			* scaler.y + vertexArray[animations[name].positions.firstPosition].position.y;
		vertexArray[animations[name].positions.firstPosition + 3].position.y = (vertexArray[animations[name].positions.firstPosition + 3].position.y
			- vertexArray[animations[name].positions.firstPosition].position.y)
			* scaler.y + vertexArray[animations[name].positions.firstPosition].position.y;
		return;
	}
	//circle
	circleIterator = circles.find(name);
	if(circleIterator != circles.end())
	{
		circles[name].setScale(scaler);
		return;
	}
	//text
	textIterator = text.find(name);
	if(textIterator != text.end())
	{
		text[name].setScale(scaler);
		return;
	}
}

//rotates an entity around its top left point
void Window::rotateEntity(std::string const& name, float degrees)
{
	//quad
	entityIterator = entitys.find(name);
	if(entityIterator != entitys.end())
	{
		vertexArray[entitys[name].firstPosition].position.x = entitys[name].vertex[0].position.x;
		vertexArray[entitys[name].firstPosition].position.y = entitys[name].vertex[0].position.y;

		tempVector.x = entitys[name].vertex[1].position.x - entitys[name].vertex[0].position.x;
		tempVector.y = entitys[name].vertex[1].position.y - entitys[name].vertex[0].position.y;
		currentAngle = std::atan2(tempVector.y, tempVector.x) * (180 / PI);
		distance = std::sqrt((tempVector.x * tempVector.x) + (tempVector.y * tempVector.y));
		entitys[name].rotation = currentAngle - degrees;
		vertexArray[entitys[name].firstPosition + 1].position.x = entitys[name].vertex[0].position.x + (float)std::cos(PI * entitys[name].rotation / 180.0) * (float)distance;
		vertexArray[entitys[name].firstPosition + 1].position.y = entitys[name].vertex[0].position.y - (float)std::sin(PI * entitys[name].rotation / 180.0) * (float)distance;
		
		tempVector.x = entitys[name].vertex[2].position.x - entitys[name].vertex[0].position.x;
		tempVector.y = entitys[name].vertex[2].position.y - entitys[name].vertex[0].position.y;
		currentAngle = std::atan2(tempVector.y, tempVector.x) * (180 / PI);
		distance = sqrt((tempVector.x * tempVector.x) + (tempVector.y * tempVector.y));
		entitys[name].rotation = currentAngle - degrees - (currentAngle * 2);
		vertexArray[entitys[name].firstPosition + 2].position.x = entitys[name].vertex[0].position.x + (float)std::cos(PI * entitys[name].rotation / 180.0) * (float)distance;
		vertexArray[entitys[name].firstPosition + 2].position.y = entitys[name].vertex[0].position.y - (float)std::sin(PI * entitys[name].rotation / 180.0) * (float)distance;
		
		tempVector.x = entitys[name].vertex[3].position.x - entitys[name].vertex[0].position.x;
		tempVector.y = entitys[name].vertex[3].position.y - entitys[name].vertex[0].position.y;
		currentAngle = std::atan2(tempVector.y, tempVector.x) * (180 / PI);
		distance = std::sqrt((tempVector.x * tempVector.y) + (tempVector.y * tempVector.y));
		entitys[name].rotation = currentAngle - degrees - (currentAngle * 2);
		vertexArray[entitys[name].firstPosition + 3].position.x = entitys[name].vertex[0].position.x + (float)std::cos(PI * entitys[name].rotation / 180.0) * (float)distance;
		vertexArray[entitys[name].firstPosition + 3].position.y = entitys[name].vertex[0].position.y - (float)std::sin(PI * entitys[name].rotation / 180.0) * (float)distance;
		
		if (degrees >= 360 || degrees <= -360)
		{
			degrees = (int)degrees % 360;
		}
		if (degrees < 0)
		{
			degrees = degrees + 360;
		}

		entitys[name].rotation = degrees;

		if (entitys[name].scale.x != 0 || entitys[name].scale.y != 0)
		{
			scaleEntity(name, entitys[name].scale);
		}
		return;
	}
	//animation
	animationIterator = animations.find(name);
	if(animationIterator != animations.end())
	{
		
		vertexArray[animations[name].positions.firstPosition].position.x = animations[name].positions.vertex[0].position.x;
		vertexArray[animations[name].positions.firstPosition].position.y = animations[name].positions.vertex[0].position.y;

		tempVector.x = animations[name].positions.vertex[1].position.x - animations[name].positions.vertex[0].position.x;
		tempVector.y = animations[name].positions.vertex[1].position.y - animations[name].positions.vertex[0].position.y;
		currentAngle = std::atan2(tempVector.y, tempVector.x) * (180 / PI);
		distance = std::sqrt((tempVector.x * tempVector.x) + (tempVector.y * tempVector.y));
		animations[name].positions.rotation = currentAngle - degrees;
		vertexArray[animations[name].positions.firstPosition + 1].position.x = animations[name].positions.vertex[0].position.x + (float)std::cos(PI * animations[name].positions.rotation / 180.0) * (float)distance;
		vertexArray[animations[name].positions.firstPosition + 1].position.y = animations[name].positions.vertex[0].position.y - (float)std::sin(PI * animations[name].positions.rotation / 180.0) * (float)distance;
		
		tempVector.x = animations[name].positions.vertex[2].position.x - animations[name].positions.vertex[0].position.x;
		tempVector.y = animations[name].positions.vertex[2].position.y - animations[name].positions.vertex[0].position.y;
		currentAngle = std::atan2(tempVector.y, tempVector.x) * (180 / PI);
		distance = std::sqrt((tempVector.x * tempVector.x) + (tempVector.y * tempVector.y));
		animations[name].positions.rotation = currentAngle - degrees - (currentAngle * 2);
		vertexArray[animations[name].positions.firstPosition + 2].position.x = animations[name].positions.vertex[0].position.x + (float)std::cos(PI * animations[name].positions.rotation / 180.0) * (float)distance;
		vertexArray[animations[name].positions.firstPosition + 2].position.y = animations[name].positions.vertex[0].position.y - (float)std::sin(PI * animations[name].positions.rotation / 180.0) * (float)distance;
		
		tempVector.x = animations[name].positions.vertex[3].position.x - animations[name].positions.vertex[0].position.x;
		tempVector.y = animations[name].positions.vertex[3].position.y - animations[name].positions.vertex[0].position.y;
		currentAngle = std::atan2(tempVector.y, tempVector.x) * (180 / PI);
		distance = std::sqrt((tempVector.x * tempVector.x) + (tempVector.y * tempVector.y));
		animations[name].positions.rotation = currentAngle - degrees - (currentAngle * 2);
		vertexArray[animations[name].positions.firstPosition + 3].position.x = animations[name].positions.vertex[0].position.x + (float)std::cos(PI * animations[name].positions.rotation / 180.0) * (float)distance;
		vertexArray[animations[name].positions.firstPosition + 3].position.y = animations[name].positions.vertex[0].position.y - (float)std::sin(PI * animations[name].positions.rotation / 180.0) * (float)distance;
		
		if (degrees >= 360 || degrees <= -360)
		{
			degrees = (int)degrees % 360;
		}
		if (degrees < 0)
		{
			degrees = degrees + 360;
		}

		animations[name].positions.rotation = degrees;

		if (animations[name].positions.scale.x != 0 || animations[name].positions.scale.y != 0)
		{
			scaleEntity(name, animations[name].positions.scale);
		}
		return;
	}
	//circle
	circleIterator = circles.find(name);
	if(circleIterator != circles.end())
	{
		circles[name].setRotation(degrees);
		return;
	}
	//text
	textIterator = text.find(name);
	if(textIterator != text.end())
	{
		text[name].setRotation(degrees);
		return;
	}
}

//rotates an entity around its center (vertex array only)
void Window::rotateEntityCenter(std::string const& name, float degrees)
{
	//quad
	entityIterator = entitys.find(name);
	if(entityIterator != entitys.end())
	{
		rotateEntity(name, degrees);
		tempVector.x = entitys[name].vertex[2].position.x;
		tempVector.y = entitys[name].vertex[2].position.y;
		tempVector.x = ((entitys[name].vertex[2].position.x - entitys[name].vertex[0].position.x) / 2);
        tempVector.y = ((entitys[name].vertex[2].position.y - entitys[name].vertex[0].position.y) / 2);
        currentAngle = std::atan2(tempVector.y, tempVector.x) * (180 / PI);
        distance = std::sqrt((tempVector.x * tempVector.x) + (tempVector.y * tempVector.y));
        entitys[name].rotation = currentAngle - degrees - (currentAngle * 2);
		tempVector.x = entitys[name].vertex[0].position.x + (float)std::cos(PI * entitys[name].rotation / 180.0) * (float)distance;
		tempVector.y = entitys[name].vertex[0].position.y - (float)std::sin(PI * entitys[name].rotation / 180.0) * (float)distance;
		middle.x = ((entitys[name].vertex[1].position.x - entitys[name].vertex[0].position.x) / 2) + entitys[name].vertex[0].position.x;
		middle.y = ((entitys[name].vertex[2].position.y - entitys[name].vertex[0].position.y) / 2) + entitys[name].vertex[0].position.y;
		middle.x = middle.x - tempVector.x;
		middle.y = middle.y - tempVector.y;
		vertexArray[entitys[name].firstPosition].position.x = vertexArray[entitys[name].firstPosition].position.x + middle.x;
        vertexArray[entitys[name].firstPosition].position.y = vertexArray[entitys[name].firstPosition].position.y + middle.y;
		vertexArray[entitys[name].firstPosition + 1].position.x = vertexArray[entitys[name].firstPosition + 1].position.x + middle.x;
        vertexArray[entitys[name].firstPosition + 1].position.y = vertexArray[entitys[name].firstPosition + 1].position.y + middle.y;
		vertexArray[entitys[name].firstPosition + 2].position.x = vertexArray[entitys[name].firstPosition + 2].position.x + middle.x;
		vertexArray[entitys[name].firstPosition + 2].position.y = vertexArray[entitys[name].firstPosition + 2].position.y + middle.y;
		vertexArray[entitys[name].firstPosition + 3].position.x = vertexArray[entitys[name].firstPosition + 3].position.x + middle.x;
		vertexArray[entitys[name].firstPosition + 3].position.y = vertexArray[entitys[name].firstPosition + 3].position.y + middle.y;
		return;
	}
	//animation
	animationIterator = animations.find(name);
	if(animationIterator != animations.end())
	{
		rotateEntity(name, degrees);
		tempVector.x = animations[name].positions.vertex[2].position.x;
		tempVector.y = animations[name].positions.vertex[2].position.y;
		tempVector.x = ((animations[name].positions.vertex[2].position.x - animations[name].positions.vertex[0].position.x) / 2);
		tempVector.y = ((animations[name].positions.vertex[2].position.y - animations[name].positions.vertex[0].position.y) / 2);
        currentAngle = std::atan2(tempVector.y, tempVector.x) * (180 / PI);
        distance = std::sqrt((tempVector.x * tempVector.x) + (tempVector.y * tempVector.y));
		animations[name].positions.rotation = currentAngle - degrees - (currentAngle * 2);
		tempVector.x = animations[name].positions.vertex[0].position.x + (float)std::cos(PI * animations[name].positions.rotation / 180.0) * (float)distance;
		tempVector.y = animations[name].positions.vertex[0].position.y - (float)std::sin(PI * animations[name].positions.rotation / 180.0) * (float)distance;
		middle.x = ((animations[name].positions.vertex[1].position.x - animations[name].positions.vertex[0].position.x) / 2) + animations[name].positions.vertex[0].position.x;
		middle.y = ((animations[name].positions.vertex[2].position.y - animations[name].positions.vertex[0].position.y) / 2) + animations[name].positions.vertex[0].position.y;
		middle.x = middle.x - tempVector.x;
		middle.y = middle.y - tempVector.y;
		vertexArray[animations[name].positions.firstPosition].position.x = vertexArray[animations[name].positions.firstPosition].position.x + middle.x;
		vertexArray[animations[name].positions.firstPosition].position.y = vertexArray[animations[name].positions.firstPosition].position.y + middle.y;
		vertexArray[animations[name].positions.firstPosition + 1].position.x = vertexArray[animations[name].positions.firstPosition + 1].position.x + middle.x;
		vertexArray[animations[name].positions.firstPosition + 1].position.y = vertexArray[animations[name].positions.firstPosition + 1].position.y + middle.y;
		vertexArray[animations[name].positions.firstPosition + 2].position.x = vertexArray[animations[name].positions.firstPosition + 2].position.x + middle.x;
		vertexArray[animations[name].positions.firstPosition + 2].position.y = vertexArray[animations[name].positions.firstPosition + 2].position.y + middle.y;
		vertexArray[animations[name].positions.firstPosition + 3].position.x = vertexArray[animations[name].positions.firstPosition + 3].position.x + middle.x;
		vertexArray[animations[name].positions.firstPosition + 3].position.y = vertexArray[animations[name].positions.firstPosition + 3].position.y + middle.y;
		return;
	}
}

//finds if a point is within an entity
bool Window::isWithin(std::string const& name, sf::Vector2f const& point)
{
	//circle
	circleIterator = circles.find(name);
	if(circleIterator != circles.end())
	{
		if (point.x >= circles[name].getPosition().x && point.y >= circles[name].getPosition().y &&
			point.x <= circles[name].getPosition().x + ((circles[name].getRadius() * 2) * circles[name].getScale().x) &&
			point.y <= circles[name].getPosition().y + ((circles[name].getRadius() * 2) * circles[name].getScale().y))
        {
            return true;
        }
        return false;
	}
	//animation
	animationIterator = animations.find(name);
	if(animationIterator != animations.end())
	{
		if (animations[name].positions.rotation >= 0 && animations[name].positions.rotation < 90)
        {
			if (point.y >= vertexArray[animations[name].positions.firstPosition].position.y &&
				point.x <= vertexArray[animations[name].positions.firstPosition + 1].position.x &&
				point.y <= vertexArray[animations[name].positions.firstPosition + 2].position.y &&
				point.x >= vertexArray[animations[name].positions.firstPosition + 3].position.x)
            {
                return true;
            }
        }
        else if (animations[name].positions.rotation >= 90 && animations[name].positions.rotation < 180)
        {
			if (point.x <= vertexArray[animations[name].positions.firstPosition].position.x &&
				point.y <= vertexArray[animations[name].positions.firstPosition + 1].position.y &&
				point.x >= vertexArray[animations[name].positions.firstPosition + 2].position.x &&
				point.y >= vertexArray[animations[name].positions.firstPosition + 3].position.y)
            {
                return true;
            }
        }
        else if (animations[name].positions.rotation >= 180 && animations[name].positions.rotation < 270)
        {
			if (point.y <= vertexArray[animations[name].positions.firstPosition].position.y &&
				point.x >= vertexArray[animations[name].positions.firstPosition + 1].position.x &&
				point.y >= vertexArray[animations[name].positions.firstPosition + 2].position.y &&
				point.x <= vertexArray[animations[name].positions.firstPosition + 3].position.x)
            {
                return true;
            }
        }
        else if (animations[name].positions.rotation >= 270)
        {
			if (point.x >= vertexArray[animations[name].positions.firstPosition].position.x &&
				point.y >= vertexArray[animations[name].positions.firstPosition + 1].position.y &&
				point.x <= vertexArray[animations[name].positions.firstPosition + 2].position.x &&
				point.y <= vertexArray[animations[name].positions.firstPosition + 3].position.y)
            {
                return true;
            }
        }
		return false;
	}
	//quad
	entityIterator = entitys.find(name);
	if(entityIterator != entitys.end())
	{
		if (entitys[name].rotation >= 0 && entitys[name].rotation < 90)
        {
			if (point.y >= vertexArray[entitys[name].firstPosition].position.y &&
				point.x <= vertexArray[entitys[name].firstPosition + 1].position.x &&
				point.y <= vertexArray[entitys[name].firstPosition + 2].position.y &&
				point.x >= vertexArray[entitys[name].firstPosition + 3].position.x)
            {
                return true;
            }
        }
        else if (entitys[name].rotation >= 90 && entitys[name].rotation < 180)
        {
			if (point.x <= vertexArray[entitys[name].firstPosition].position.x &&
				point.y <= vertexArray[entitys[name].firstPosition + 1].position.y &&
				point.x >= vertexArray[entitys[name].firstPosition + 2].position.x &&
				point.y >= vertexArray[entitys[name].firstPosition + 3].position.y)
            {
                return true;
            }
        }
        else if (entitys[name].rotation >= 180 && entitys[name].rotation < 270)
        {
			if (point.y <= vertexArray[entitys[name].firstPosition].position.y &&
				point.x >= vertexArray[entitys[name].firstPosition + 1].position.x &&
				point.y >= vertexArray[entitys[name].firstPosition + 2].position.y &&
				point.x <= vertexArray[entitys[name].firstPosition + 3].position.x)
            {
                return true;
            }
        }
        else if (entitys[name].rotation >= 270)
        {
			if (point.x >= vertexArray[entitys[name].firstPosition].position.x &&
				point.y >= vertexArray[entitys[name].firstPosition + 1].position.y &&
				point.x <= vertexArray[entitys[name].firstPosition + 2].position.x &&
				point.y <= vertexArray[entitys[name].firstPosition + 3].position.y)
            {
                return true;
            }
        }
		return false;
	}
	return false;
}

//finds if two entitys are overlapping
bool Window::isOverlapping(std::string const& entity1, std::string const& entity2)
{
	//circle
	circleIterator = circles.find(entity1);
	if(circleIterator != circles.end())
	{
		entityIterator = entitys.find(entity2);
		if(entityIterator != entitys.end())
		{
			//circle in a box
			if (isWithin(entity2, circles[entity1].getPosition()))
			{
				return true;
			}
			tempVector = circles[entity1].getPosition();
			tempVector.x = tempVector.x + ((circles[entity1].getRadius() * 2) * circles[entity1].getScale().x);
			if (isWithin(entity2, tempVector))
			{
				return true;
			}
			tempVector = circles[entity1].getPosition();
			tempVector.y = tempVector.y + ((circles[entity1].getRadius() * 2) * circles[entity1].getScale().y);
			if (isWithin(entity2, tempVector))
			{
				return true;
			}
			tempVector = circles[entity1].getPosition();
			tempVector.x = tempVector.x + ((circles[entity1].getRadius() * 2) * circles[entity1].getScale().x);
			tempVector.y = tempVector.y + ((circles[entity1].getRadius() * 2) * circles[entity1].getScale().y);
			if (isWithin(entity2, tempVector))
			{
				return true;
			}

			//box in a circle
            if (isWithin(entity1, entitys[entity2].vertex[0].position))
            {
                return true;
            }
            if (isWithin(entity1, entitys[entity2].vertex[1].position))
            {
                return true;
            }
            if (isWithin(entity1, entitys[entity2].vertex[2].position))
            {
                return true;
            }
            if (isWithin(entity1, entitys[entity2].vertex[3].position))
            {
                return true;
            }
		}
		circleIterator = circles.find(entity2);
		if(circleIterator != circles.end())
		{
			//circle 1 in circle 2
			if (isWithin(entity2, circles[entity1].getPosition()))
			{
				return true;
			}
			tempVector = circles[entity1].getPosition();
			tempVector.x = tempVector.x + ((circles[entity1].getRadius() * 2) * circles[entity1].getScale().x);
			if (isWithin(entity2, tempVector))
			{
				return true;
			}
			tempVector = circles[entity1].getPosition();
			tempVector.y = tempVector.y + ((circles[entity1].getRadius() * 2) * circles[entity1].getScale().y);
			if (isWithin(entity2, tempVector))
			{
				return true;
			}
			tempVector = circles[entity1].getPosition();
			tempVector.x = tempVector.x + ((circles[entity1].getRadius() * 2) * circles[entity1].getScale().x);
			tempVector.y = tempVector.y + ((circles[entity1].getRadius() * 2) * circles[entity1].getScale().y);
			if (isWithin(entity2, tempVector))
			{
				return true;
			}

			//circle 2 in circle 1
			if (isWithin(entity1, circles[entity2].getPosition()))
			{
				return true;
			}
			tempVector = circles[entity2].getPosition();
			tempVector.x = tempVector.x + ((circles[entity2].getRadius() * 2) * circles[entity2].getScale().x);
			if (isWithin(entity1, tempVector))
			{
				return true;
			}
			tempVector = circles[entity2].getPosition();
			tempVector.y = tempVector.y + ((circles[entity2].getRadius() * 2) * circles[entity2].getScale().y);
			if (isWithin(entity1, tempVector))
			{
				return true;
			}
			tempVector = circles[entity2].getPosition();
			tempVector.x = tempVector.x + ((circles[entity2].getRadius() * 2) * circles[entity2].getScale().x);
			tempVector.y = tempVector.y + ((circles[entity2].getRadius() * 2) * circles[entity2].getScale().y);
			if (isWithin(entity1, tempVector))
			{
				return true;
			}
		}
		animationIterator = animations.find(entity2);
		if(animationIterator != animations.end())
		{
		//circle in an animation
			if (isWithin(entity2, circles[entity1].getPosition()))
            {
                return true;
            }
            tempVector = circles[entity1].getPosition();
			tempVector.x = tempVector.x + ((circles[entity1].getRadius() * 2) * circles[entity1].getScale().x);
            if (isWithin(entity2, tempVector))
            {
                return true;
            }
            tempVector = circles[entity1].getPosition();
			tempVector.y = tempVector.y + ((circles[entity1].getRadius() * 2) * circles[entity1].getScale().y);
            if (isWithin(entity2, tempVector))
            {
                return true;
            }
            tempVector = circles[entity1].getPosition();
            tempVector.x = tempVector.x + ((circles[entity1].getRadius() * 2) * circles[entity1].getScale().x);
            tempVector.y = tempVector.y + ((circles[entity1].getRadius() * 2) * circles[entity1].getScale().y);
            if (isWithin(entity2, tempVector))
            {
                return true;
            }

            //animation in a circle
            if (isWithin(entity1, animations[entity2].positions.vertex[0].position))
            {
                return true;
            }
            if (isWithin(entity1, animations[entity2].positions.vertex[1].position))
            {
                return true;
            }
            if (isWithin(entity1, animations[entity2].positions.vertex[2].position))
            {
                return true;
            }
            if (isWithin(entity1, animations[entity2].positions.vertex[3].position))
            {
                return true;
            }
        }
		return false;
	}
	//animation
	animationIterator = animations.find(entity1);
	if(animationIterator != animations.end())
	{
		entityIterator = entitys.find(entity2);
		if(entityIterator != entitys.end())
		{
			
		    //animation in box
            if (isWithin(entity1, entitys[entity2].vertex[0].position))
            {
                return true;
            }
            if (isWithin(entity1, entitys[entity2].vertex[1].position))
            {
                return true;
            }
            if (isWithin(entity1, entitys[entity2].vertex[2].position))
            {
                return true;
            }
            if (isWithin(entity1, entitys[entity2].vertex[3].position))
            {
                return true;
            }

            //box in animation
			if (isWithin(entity2, animations[entity1].positions.vertex[0].position))
            {
                return true;
            }
            if (isWithin(entity2, animations[entity1].positions.vertex[1].position))
            {
                return true;
            }
            if (isWithin(entity2, animations[entity1].positions.vertex[2].position))
            {
                return true;
            }
            if (isWithin(entity2, animations[entity1].positions.vertex[3].position))
            {
                return true;
            }
		}
		circleIterator = circles.find(entity2);
		if(circleIterator != circles.end())
		{
			//circle in a animation
			if (isWithin(entity1, circles[entity2].getPosition()))
            {
                return true;
            }
            tempVector = circles[entity2].getPosition();
			tempVector.x = tempVector.x + ((circles[entity2].getRadius() * 2) * circles[entity2].getScale().x);
            if (isWithin(entity1, tempVector))
            {
                return true;
            }
            tempVector = circles[entity2].getPosition();
            tempVector.y = tempVector.y + ((circles[entity2].getRadius() * 2) * circles[entity2].getScale().y);
            if (isWithin(entity1, tempVector))
            {
                return true;
            }
            tempVector = circles[entity2].getPosition();
            tempVector.x = tempVector.x + ((circles[entity2].getRadius() * 2) * circles[entity2].getScale().x);
            tempVector.y = tempVector.y + ((circles[entity2].getRadius() * 2) * circles[entity2].getScale().y);
            if (isWithin(entity1, tempVector))
            {
                return true;
            }

            //animation in a circle
            if (isWithin(entity2, animations[entity1].positions.vertex[0].position))
            {
                return true;
            }
            if (isWithin(entity2, animations[entity1].positions.vertex[1].position))
            {
                return true;
            }
            if (isWithin(entity2, animations[entity1].positions.vertex[2].position))
            {
                return true;
            }
            if (isWithin(entity2, animations[entity1].positions.vertex[3].position))
            {
                return true;
            }
		}
		animationIterator = animations.find(entity2);
		if(animationIterator != animations.end())
		{
			//animation in animation
			if (isWithin(entity1, animations[entity2].positions.vertex[0].position))
			{
				return true;
			}
			if (isWithin(entity1, animations[entity2].positions.vertex[1].position))
			{
				return true;
			}
			if (isWithin(entity1, animations[entity2].positions.vertex[2].position))
			{
				return true;
			}
			if (isWithin(entity1, animations[entity2].positions.vertex[3].position))
			{
				return true;
			}

			//animation in animation
			if (isWithin(entity2, animations[entity1].positions.vertex[0].position))
			{
				return true;
			}
			if (isWithin(entity2, animations[entity1].positions.vertex[1].position))
			{
				return true;
			}
			if (isWithin(entity2, animations[entity1].positions.vertex[2].position))
			{
				return true;
			}
			if (isWithin(entity2, animations[entity1].positions.vertex[3].position))
			{
				return true;
			}
		}
		return false;
	}
	//quad
	entityIterator = entitys.find(entity1);
	if(entityIterator != entitys.end())
	{
		entityIterator = entitys.find(entity2);
		if(entityIterator != entitys.end())
		{
		    //box 1 in box 2
            if (isWithin(entity1, entitys[entity2].vertex[0].position))
            {
                return true;
            }
            if (isWithin(entity1, entitys[entity2].vertex[1].position))
            {
                return true;
            }
            if (isWithin(entity1, entitys[entity2].vertex[2].position))
            {
                return true;
            }
            if (isWithin(entity1, entitys[entity2].vertex[3].position))
            {
                return true;
            }

            //box 2 in box 1
            if (isWithin(entity2, entitys[entity1].vertex[0].position))
            {
                return true;
            }
            if (isWithin(entity2, entitys[entity1].vertex[1].position))
            {
                return true;
            }
            if (isWithin(entity2, entitys[entity1].vertex[2].position))
            {
                return true;
            }
            if (isWithin(entity2, entitys[entity1].vertex[3].position))
            {
                return true;
            }
		}
		circleIterator = circles.find(entity2);
		if(circleIterator != circles.end())
		{
			//circle in a box
			if (isWithin(entity1, circles[entity2].getPosition()))
            {
                return true;
            }
            tempVector = circles[entity2].getPosition();
			tempVector.x = tempVector.x + ((circles[entity2].getRadius() * 2) * circles[entity2].getScale().x);
            if (isWithin(entity1, tempVector))
            {
                return true;
            }
            tempVector = circles[entity2].getPosition();
			tempVector.y = tempVector.y + ((circles[entity2].getRadius() * 2) * circles[entity2].getScale().y);
            if (isWithin(entity1, tempVector))
            {
                return true;
            }
            tempVector = circles[entity2].getPosition();
			tempVector.x = tempVector.x + ((circles[entity2].getRadius() * 2) * circles[entity2].getScale().x);
			tempVector.y = tempVector.y + ((circles[entity2].getRadius() * 2) * circles[entity2].getScale().y);
            if (isWithin(entity1, tempVector))
            {
                return true;
            }

            //box in a circle
            if (isWithin(entity2, entitys[entity1].vertex[0].position))
            {
                return true;
            }
            if (isWithin(entity2, entitys[entity1].vertex[1].position))
            {
                return true;
            }
            if (isWithin(entity2, entitys[entity1].vertex[2].position))
            {
                return true;
            }
            if (isWithin(entity2, entitys[entity1].vertex[3].position))
            {
                return true;
            }
		}
		animationIterator = animations.find(entity2);
		if(animationIterator != animations.end())
		{
			//box in animation
            if (isWithin(entity1, animations[entity2].positions.vertex[0].position))
            {
                return true;
            }
            if (isWithin(entity1, animations[entity2].positions.vertex[1].position))
            {
                return true;
            }
            if (isWithin(entity1, animations[entity2].positions.vertex[2].position))
            {
                return true;
            }
            if (isWithin(entity1, animations[entity2].positions.vertex[3].position))
            {
                return true;
            }

            //animation in box
            if (isWithin(entity2, entitys[entity1].vertex[0].position))
            {
                return true;
            }
            if (isWithin(entity2, entitys[entity1].vertex[1].position))
            {
                return true;
            }
            if (isWithin(entity2, entitys[entity1].vertex[2].position))
            {
                return true;
            }
            if (isWithin(entity2, entitys[entity1].vertex[3].position))
            {
                return true;
            }
		}
		return false;
	}
	return false;
}

//returns if an entity is within an area
bool Window::isWithinArea(std::string const& name, sf::Vector2f const& point, int width, int height)
{
	//animation
	animationIterator = animations.find(name);
	if(animationIterator != animations.end())
	{
		if(animations[name].positions.vertex[0].position.x >= point.x && animations[name].positions.vertex[0].position.y >= point.y &&
		   animations[name].positions.vertex[0].position.x < width && animations[name].positions.vertex[0].position.y < height)
		{
			return true;
		}
		return false;
	}
	//quad
	entityIterator = entitys.find(name);
	if(entityIterator != entitys.end())
	{
		if(entitys[name].vertex[0].position.x >= point.x && entitys[name].vertex[0].position.y >= point.y &&
		   entitys[name].vertex[0].position.x < width && entitys[name].vertex[0].position.y < height)
		{
			return true;
		}
		return false;
	}
	return false;
	//circle
	circleIterator = circles.find(name);
	if(circleIterator != circles.end())
	{
		if(circles[name].getPosition().x >= point.x && circles[name].getPosition().y >= point.y &&
		   circles[name].getPosition().x < width && circles[name].getPosition().y < height)
		{
			return true;
		}
		return false;
	}
	//text
	textIterator = text.find(name);
	if(textIterator != text.end())
	{
		if(text[name].getPosition().x >= point.x && text[name].getPosition().y >= point.y &&
		   text[name].getPosition().x < width && text[name].getPosition().y < height)
		{
			return true;
		}
		return false;
	}
}

//returns if a given entity is within the window
bool Window::isWithinWindow(std::string const& name)
{
	//quad
	entityIterator = entitys.find(name);
	if(entityIterator != entitys.end())
	{
		if(entitys[name].vertex[0].position.x >= 0 && entitys[name].vertex[0].position.y >= 0 &&
		   entitys[name].vertex[0].position.x < resolutionX && entitys[name].vertex[0].position.y < resolutionY)
		{
			return true;
		}
		return false;
	}
	return false;
	//animation
	animationIterator = animations.find(name);
	if(animationIterator != animations.end())
	{
		if(animations[name].positions.vertex[0].position.x >= 0 && animations[name].positions.vertex[0].position.y >= 0 &&
		   animations[name].positions.vertex[0].position.x < resolutionX && animations[name].positions.vertex[0].position.y < resolutionY)
		{
			return true;
		}
		return false;
	}
	//circle
	circleIterator = circles.find(name);
	if(circleIterator != circles.end())
	{
		if(circles[name].getPosition().x >= 0 && circles[name].getPosition().y >= 0 &&
		   circles[name].getPosition().x < resolutionX && circles[name].getPosition().y < resolutionY)
		{
			return true;
		}
		return false;
	}
	//text
	textIterator = text.find(name);
	if(textIterator != text.end())
	{
		if(text[name].getPosition().x >= 0 && text[name].getPosition().y >= 0 &&
		   text[name].getPosition().x < resolutionX && text[name].getPosition().y < resolutionY)
		{
			return true;
		}
		return false;
	}
}

//returns if a given entity is within the window
bool Window::isWithinWindow(std::string const& name,  int width, int height)
{
	//quad
	entityIterator = entitys.find(name);
	if(entityIterator != entitys.end())
	{
		if(entitys[name].vertex[0].position.x >= 0 && entitys[name].vertex[0].position.y >= 0 &&
		   entitys[name].vertex[0].position.x < width && entitys[name].vertex[0].position.y < height)
		{
			return true;
		}
		return false;
	}
	return false;
	//animation
	animationIterator = animations.find(name);
	if(animationIterator != animations.end())
	{
		if(animations[name].positions.vertex[0].position.x >= 0 && animations[name].positions.vertex[0].position.y >= 0 &&
		   animations[name].positions.vertex[0].position.x < width && animations[name].positions.vertex[0].position.y < height)
		{
			return true;
		}
		return false;
	}
	//circle
	circleIterator = circles.find(name);
	if(circleIterator != circles.end())
	{
		if(circles[name].getPosition().x >= 0 && circles[name].getPosition().y >= 0 &&
		   circles[name].getPosition().x < width && circles[name].getPosition().y < height)
		{
			return true;
		}
		return false;
	}
	//text
	textIterator = text.find(name);
	if(textIterator != text.end())
	{
		if(text[name].getPosition().x >= 0 && text[name].getPosition().y >= 0 &&
		   text[name].getPosition().x < width && text[name].getPosition().y < height)
		{
			return true;
		}
		return false;
	}
}

//finds if a point is within a set entities within the given string
std::string Window::batchIsWithin(std::string const& name, sf::Vector2f const& point)
{
	tempStr.clear();
	//quad
	for(entityIterator = entitys.begin(); entityIterator != entitys.end(); ++entityIterator)
	{
		if(entityIterator->first.find(name) != std::string::npos)
		{
			if(isWithin(entityIterator->first, point) == true)
			{
				tempStr.append(entityIterator->first);
			}
		}
	}
	//animation
	for(animationIterator = animations.begin(); animationIterator != animations.end(); ++animationIterator)
	{
		if(animationIterator->first.find(name) != std::string::npos)
		{
			if(isWithin(animationIterator->first, point) == true)
			{
				tempStr.append(animationIterator->first);
			}
		}
	}
	//circle
	for(circleIterator = circles.begin(); circleIterator != circles.end(); ++circleIterator)
	{
		if(circleIterator->first.find(name) != std::string::npos)
		{
			if(isWithin(circleIterator->first, point) == true)
			{
				tempStr.append(circleIterator->first);
			}
		}
	}
	return tempStr;
}

//finds if an entity is overlapping a set of entities within the given string
//the first parameter is the entity being tested, and the second is anything that may collide with it
std::string Window::batchIsOverlapping(std::string const& entity, std::string const& severalEntitys)
{
	tempStr.clear();
	//quad
	for(std::unordered_map<std::string, Quad>::iterator tempEntItr = entitys.begin(); tempEntItr != entitys.end(); ++tempEntItr)
	{
		if(tempEntItr->first.find(severalEntitys) != std::string::npos)
		{
			if(isOverlapping(tempEntItr->first, entity) == true && tempEntItr->first != entity)
			{
				tempStr.append(tempEntItr->first);
			}
		}
	}
	//animation
	for(std::unordered_map<std::string, Animation>::iterator tempAniItr = animations.begin(); tempAniItr != animations.end(); ++tempAniItr)
	{
		if(tempAniItr->first.find(severalEntitys) != std::string::npos)
		{
			if(Window::isOverlapping(tempAniItr->first, entity) == true && tempAniItr->first != entity)
			{
				tempStr.append(tempAniItr->first);
			}
		}
	}
	//circle
	for(std::unordered_map<std::string, sf::CircleShape>::iterator tempCirItr = circles.begin(); tempCirItr != circles.end(); ++tempCirItr)
	{
		if(tempCirItr->first.find(severalEntitys) != std::string::npos)
		{
			if(Window::isOverlapping(tempCirItr->first, entity) == true && tempCirItr->first != entity)
			{
				tempStr.append(tempCirItr->first);
			}
		}
	}
	return tempStr;
}

//plays an animation
void Window::playAnimation(std::string const& name)
{
	if(animations[name].paused == false)
	{
		if(animations[name].animationTimer.getElapsedTimeMilliseconds() >= animations[name].speed)
		{
			if (animations[name].currentFrame + 1 != animations[name].frames.size())
            {
                animations[name].currentFrame += 1;
                //point 1 dictionary
				animations[name].positions.vertex[0].texCoords.x = spriteMaps[animations[name].frames[animations[name].currentFrame]].left;
				animations[name].positions.vertex[0].texCoords.y = spriteMaps[animations[name].frames[animations[name].currentFrame]].top;
                //point 2 dictionary
				animations[name].positions.vertex[1].texCoords.x = spriteMaps[animations[name].frames[animations[name].currentFrame]].left + spriteMaps[animations[name].frames[animations[name].currentFrame]].width;
				animations[name].positions.vertex[1].texCoords.y = spriteMaps[animations[name].frames[animations[name].currentFrame]].top;
                //point 3 dictionary
				animations[name].positions.vertex[2].texCoords.x = spriteMaps[animations[name].frames[animations[name].currentFrame]].left + spriteMaps[animations[name].frames[animations[name].currentFrame]].width;
                animations[name].positions.vertex[2].texCoords.y = spriteMaps[animations[name].frames[animations[name].currentFrame]].top + spriteMaps[animations[name].frames[animations[name].currentFrame]].height;
                //point 4 dictionary
				animations[name].positions.vertex[3].texCoords.x = spriteMaps[animations[name].frames[animations[name].currentFrame]].left;
				animations[name].positions.vertex[3].texCoords.y = spriteMaps[animations[name].frames[animations[name].currentFrame]].top + spriteMaps[animations[name].frames[animations[name].currentFrame]].height;
				
                //point 1 vertex
				vertexArray[animations[name].positions.firstPosition].texCoords.x = spriteMaps[animations[name].frames[animations[name].currentFrame]].left;
                vertexArray[animations[name].positions.firstPosition].texCoords.y = spriteMaps[animations[name].frames[animations[name].currentFrame]].top;
                //point 2 vertex
                vertexArray[animations[name].positions.firstPosition + 1].texCoords.x = spriteMaps[animations[name].frames[animations[name].currentFrame]].left + spriteMaps[animations[name].frames[animations[name].currentFrame]].width;
                vertexArray[animations[name].positions.firstPosition + 1].texCoords.y = spriteMaps[animations[name].frames[animations[name].currentFrame]].top;
                //point 3 vertex
				vertexArray[animations[name].positions.firstPosition + 2].texCoords.x = spriteMaps[animations[name].frames[animations[name].currentFrame]].left + spriteMaps[animations[name].frames[animations[name].currentFrame]].width;
                vertexArray[animations[name].positions.firstPosition + 2].texCoords.y = spriteMaps[animations[name].frames[animations[name].currentFrame]].top + spriteMaps[animations[name].frames[animations[name].currentFrame]].height;
                //point 4 vertex
                vertexArray[animations[name].positions.firstPosition + 3].texCoords.x = spriteMaps[animations[name].frames[animations[name].currentFrame]].left;
                vertexArray[animations[name].positions.firstPosition + 3].texCoords.y = spriteMaps[animations[name].frames[animations[name].currentFrame]].top + spriteMaps[animations[name].frames[animations[name].currentFrame]].height;
				
            }
			else
            {
                animations[name].currentFrame = 0;
                //point 1 dictionary
				animations[name].positions.vertex[0].texCoords.x = spriteMaps[animations[name].frames[0]].left;
				animations[name].positions.vertex[0].texCoords.y = spriteMaps[animations[name].frames[0]].top;
                //point 2 dictionary
				animations[name].positions.vertex[1].texCoords.x = spriteMaps[animations[name].frames[0]].left + spriteMaps[animations[name].frames[0]].width;
				animations[name].positions.vertex[1].texCoords.y = spriteMaps[animations[name].frames[0]].top;
                //point 3 dictionary
				animations[name].positions.vertex[2].texCoords.x = spriteMaps[animations[name].frames[0]].left + spriteMaps[animations[name].frames[0]].width;
				animations[name].positions.vertex[2].texCoords.y = spriteMaps[animations[name].frames[0]].top + spriteMaps[animations[name].frames[0]].height;
                //point 4 dictionary
				animations[name].positions.vertex[3].texCoords.x = spriteMaps[animations[name].frames[0]].left;
				animations[name].positions.vertex[3].texCoords.y = spriteMaps[animations[name].frames[0]].top + spriteMaps[animations[name].frames[0]].height;
				
                //point 1 vertex
				vertexArray[animations[name].positions.firstPosition].texCoords.x = spriteMaps[animations[name].frames[0]].left;
				vertexArray[animations[name].positions.firstPosition].texCoords.y = spriteMaps[animations[name].frames[0]].top;
                //point 2 vertex
				vertexArray[animations[name].positions.firstPosition + 1].texCoords.x = spriteMaps[animations[name].frames[0]].left + spriteMaps[animations[name].frames[0]].width;
				vertexArray[animations[name].positions.firstPosition + 1].texCoords.y = spriteMaps[animations[name].frames[0]].top;
                //point 3 vertex
				vertexArray[animations[name].positions.firstPosition + 2].texCoords.x = spriteMaps[animations[name].frames[0]].left + spriteMaps[animations[name].frames[0]].width;
				vertexArray[animations[name].positions.firstPosition + 2].texCoords.y = spriteMaps[animations[name].frames[0]].top + spriteMaps[animations[name].frames[0]].height;
                //point 4 vertex
				vertexArray[animations[name].positions.firstPosition + 3].texCoords.x = spriteMaps[animations[name].frames[0]].left;
				vertexArray[animations[name].positions.firstPosition + 3].texCoords.y = spriteMaps[animations[name].frames[0]].top + spriteMaps[animations[name].frames[0]].height;
            }
			animations[name].animationTimer.restartClock();
		}
	}
}

//pauses an animation
void Window::pauseAnimation(std::string const& name)
{
	animationIterator = animations.find(name);
	if(animationIterator != animations.end())
	{
		animations[name].paused = true;
	}
}

//resumes an animation
void Window::resumeAnimation(std::string const& name)
{
	animationIterator = animations.find(name);
	if(animationIterator != animations.end())
	{
		animations[name].paused = false;
	}
}

//goes to a specific animation frame
void Window::goToFrame(std::string const& name, int frameIndex)
{
	animationIterator = animations.find(name);
	if(animationIterator != animations.end())
	{
		animations[name].currentFrame = frameIndex;
        //point 1 dictionary
		animations[name].positions.vertex[0].texCoords.x = spriteMaps[animations[name].frames[animations[name].currentFrame]].left;
		animations[name].positions.vertex[0].texCoords.y = spriteMaps[animations[name].frames[animations[name].currentFrame]].top;
        //point 2 dictionary
		animations[name].positions.vertex[1].texCoords.x = spriteMaps[animations[name].frames[animations[name].currentFrame]].left + spriteMaps[animations[name].frames[animations[name].currentFrame]].width;
		animations[name].positions.vertex[1].texCoords.y = spriteMaps[animations[name].frames[animations[name].currentFrame]].top;
        //point 3 dictionary
		animations[name].positions.vertex[2].texCoords.x = spriteMaps[animations[name].frames[animations[name].currentFrame]].left + spriteMaps[animations[name].frames[animations[name].currentFrame]].width;
		animations[name].positions.vertex[2].texCoords.y = spriteMaps[animations[name].frames[animations[name].currentFrame]].top + spriteMaps[animations[name].frames[animations[name].currentFrame]].height;
        //point 4 dictionary
		animations[name].positions.vertex[3].texCoords.x = spriteMaps[animations[name].frames[animations[name].currentFrame]].left;
		animations[name].positions.vertex[3].texCoords.y = spriteMaps[animations[name].frames[animations[name].currentFrame]].top + spriteMaps[animations[name].frames[animations[name].currentFrame]].height;

        //point 1 vertex
		vertexArray[animations[name].positions.firstPosition].texCoords.x = spriteMaps[animations[name].frames[animations[name].currentFrame]].left;
		vertexArray[animations[name].positions.firstPosition].texCoords.y = spriteMaps[animations[name].frames[animations[name].currentFrame]].top;
        //point 2 vertex
		vertexArray[animations[name].positions.firstPosition + 1].texCoords.x = spriteMaps[animations[name].frames[animations[name].currentFrame]].left + spriteMaps[animations[name].frames[animations[name].currentFrame]].width;
		vertexArray[animations[name].positions.firstPosition + 1].texCoords.y = spriteMaps[animations[name].frames[animations[name].currentFrame]].top;
        //point 3 vertex
		vertexArray[animations[name].positions.firstPosition + 2].texCoords.x = spriteMaps[animations[name].frames[animations[name].currentFrame]].left + spriteMaps[animations[name].frames[animations[name].currentFrame]].width;
		vertexArray[animations[name].positions.firstPosition + 2].texCoords.y = spriteMaps[animations[name].frames[animations[name].currentFrame]].top + spriteMaps[animations[name].frames[animations[name].currentFrame]].height;
        //point 4 vertex
		vertexArray[animations[name].positions.firstPosition + 3].texCoords.x = spriteMaps[animations[name].frames[animations[name].currentFrame]].left;
		vertexArray[animations[name].positions.firstPosition + 3].texCoords.y = spriteMaps[animations[name].frames[animations[name].currentFrame]].top + spriteMaps[animations[name].frames[animations[name].currentFrame]].height;
	}
}

//finds if a point is within a bounding box
bool Window::boundingBoxPoint(sf::Vector2f const& point, sf::Vector2f const& boxOrigin, int width, int height)
{
	if (point.x >= boxOrigin.x && point.x <= boxOrigin.x + width &&
    point.y >= boxOrigin.y && point.y <= boxOrigin.y + height)
    {
        return true;
    }
    return false;
}

//finds if a point is within a bounding circle
bool Window::boudingCirclePoint(sf::Vector2f point, sf::Vector2f const& boxOrigin, int radius)
{
	point.x = point.x - boxOrigin.x;
	point.y = point.y - boxOrigin.y;
	if ((std::sqrt((point.x * point.x) + (point.y * point.y))) <= radius)
    {
        return true;
    }
    return false;
}

//finds if two bounding boxes are overlapping
bool Window::boundingBoxOverlap(sf::Vector2f boxOrigin1, int width1, int height1, sf::Vector2f boxOrigin2, int width2, int height2)
{
	if (boundingBoxPoint(boxOrigin1, boxOrigin2, width2, height2))
    {
        return true;
    }
    boxOrigin1.x += width1;
    if (boundingBoxPoint(boxOrigin1, boxOrigin2, width2, height2))
    {
        return true;
    }
    boxOrigin1.y += height1;
    if (boundingBoxPoint(boxOrigin1, boxOrigin2, width2, height2))
    {
        return true;
    }
    boxOrigin1.x -= width1;
    if (boundingBoxPoint(boxOrigin1, boxOrigin2, width2, height2))
    {
        return true;
    }
    boxOrigin1.y -= height1;
    if (boundingBoxPoint(boxOrigin2, boxOrigin1, width1, height1))
    {
        return true;
    }
    boxOrigin2.x += width2;
    if (boundingBoxPoint(boxOrigin2, boxOrigin1, width1, height1))
    {
        return true;
    }
    boxOrigin2.y += height2;
    if (boundingBoxPoint(boxOrigin2, boxOrigin1, width1, height1))
    {
        return true;
    }
    boxOrigin2.x -= width2;
    if (boundingBoxPoint(boxOrigin2, boxOrigin1, width1, height1))
    {
        return true;
    }
    return false;
}

//finds if two bounding circles are overlapping
bool Window::boundingCircleOverlap(sf::Vector2f const& circleOrigin1, int radius1, sf::Vector2f const& circleOrigin2, int radius2)
{
	tempVector.x = circleOrigin1.x - circleOrigin2.x;
    tempVector.y = circleOrigin1.y - circleOrigin2.y;
    if ((std::sqrt((tempVector.x * tempVector.x) + (tempVector.y * tempVector.y))) < (radius1 + radius2))
    {
        return true;
    }
    return false;
}

//makes an entity visible
void Window::makeVisible(std::string const& name)
{
	//quad
	entityIterator = entitys.find(name);
	if(entityIterator != entitys.end())
	{
		vertexArray[entitys[name].firstPosition].color = entitys[name].color[0];
		vertexArray[entitys[name].firstPosition + 1].color = entitys[name].color[1];
		vertexArray[entitys[name].firstPosition + 2].color = entitys[name].color[2];
		vertexArray[entitys[name].firstPosition + 3].color = entitys[name].color[3];
		return;
	}
	//animation
	animationIterator = animations.find(name);
	if(animationIterator != animations.end())
	{
		vertexArray[animations[name].positions.firstPosition].color = animations[name].positions.color[0];
		vertexArray[animations[name].positions.firstPosition + 1].color = animations[name].positions.color[1];
		vertexArray[animations[name].positions.firstPosition + 2].color = animations[name].positions.color[2];
		vertexArray[animations[name].positions.firstPosition + 3].color = animations[name].positions.color[3];
		return;
	}
	//circle
	circleIterator = circles.find(name);
	if(circleIterator != circles.end())
	{
		circles[name].setFillColor(colorMap[name]);
		return;
	}
	//text
	textIterator = text.find(name);
	if(textIterator != text.end())
	{
		text[name].setColor(colorMap[name]);
		return;
	}
}

//makes an entity invisible
void Window::makeInvisible(std::string const& name)
{
	//quad
	entityIterator = entitys.find(name);
	if(entityIterator != entitys.end())
	{
		vertexArray[entitys[name].firstPosition].color = sf::Color::Transparent;
		vertexArray[entitys[name].firstPosition + 1].color = sf::Color::Transparent;
		vertexArray[entitys[name].firstPosition + 2].color = sf::Color::Transparent;
		vertexArray[entitys[name].firstPosition + 3].color = sf::Color::Transparent;
		return;
	}
	//animation
	animationIterator = animations.find(name);
	if(animationIterator != animations.end())
	{
		vertexArray[animations[name].positions.firstPosition].color = sf::Color::Transparent;
		vertexArray[animations[name].positions.firstPosition + 1].color = sf::Color::Transparent;
		vertexArray[animations[name].positions.firstPosition + 2].color = sf::Color::Transparent;
		vertexArray[animations[name].positions.firstPosition + 3].color = sf::Color::Transparent;
		return;
	}
	//circle
	circleIterator = circles.find(name);
	if(circleIterator != circles.end())
	{
		circles[name].setFillColor(sf::Color::Transparent);
		return;
	}
	//text
	textIterator = text.find(name);
	if(textIterator != text.end())
	{
		text[name].setColor(sf::Color::Transparent);
		return;
	}
}

//moves a view
void Window::moveView(std::string name, sf::Vector2f position)
{
	views[name].move(position);
}

//rotates a view
void Window::rotateView(std::string name, float rotation)
{
	views[name].setRotation(rotation);
}

//zooms a view
void Window::zoomView(std::string name, float zoom)
{
	views[name].zoom(zoom);
}

//draws everything onto the screen
void Window::drawAll()
{
	if(gameTimer.getElapsedTimeMicroseconds() >= updateSpeed || FPSLimit==false)
	{
		//update animations
		for(animationIterator = animations.begin(); animationIterator != animations.end(); ++animationIterator)
		{
			playAnimation(animationIterator->first);
		}

		gameWindow.clear(background);
		
		//draw quads
		gameWindow.draw(vertexArray, vertexCount, sf::PrimitiveType::Quads, state);
		//draw text
		for(textIterator = text.begin(); textIterator != text.end(); ++textIterator)
		{
			gameWindow.draw(text[textIterator->first]);
		}
		//draw circles
		for(circleIterator = circles.begin(); circleIterator != circles.end(); ++circleIterator)
		{
			gameWindow.draw(circles[circleIterator->first]);
		}
		gameWindow.display();
		gameTimer.restartClock();
	}
}