#include "textedit.h"

TextEdit::TextEdit()
{
	str = "";
	speed = 125;
	delay = 350;
	repeat = 50;
	held = false;
	paused = false;
	lastKey = "";
	timer.restartClock();
}

TextEdit::TextEdit(std::string const& startingString)
{
	str = startingString;
	speed = 125;
	delay = 350;
	repeat = 50;
	held = false;
	paused = false;
	lastKey = "";
	timer.restartClock();
}

TextEdit::TextEdit(int keystrokeSpeed, int repeatDelay, int repeatRate)
{
	str = "";
	speed = keystrokeSpeed;
	delay = repeatDelay;
	repeat = repeatRate;
	held = false;
	paused = false;
	lastKey = "";
	timer.restartClock();
}

TextEdit::TextEdit(int keystrokeSpeed, int repeatDelay, int repeatRate, std::string const& startingString)
{
	speed = keystrokeSpeed;
	delay = repeatDelay;
	repeat = repeatRate;
	str = startingString;
	held = false;
	paused = false;
	lastKey = "";
	timer.restartClock();
}

std::string TextEdit::takeInput(std::string const& keyboard)
{
	if (keyboard != "")
	{
		if (lastKey == keyboard)
		{
			held = true;
			if (timer.getElapsedTimeMilliseconds() >= delay)
			{
				paused = true;
			}
		}
		else
		{
			held = false;
			paused = false;
		}

		//keystroke not held
		if (timer.getElapsedTimeMilliseconds() >= speed && held == false)
		{
			tempStr = "";
			if ((keyboard.find("Lshift") != std::string::npos) || (keyboard.find("Rshift") != std::string::npos))
			{
				for (int i = 0; i < keyboard.length(); i++)
				{
					tempStr += keyboard[i];
					if (changeStringShift(tempStr) == true)
					{
						tempStr = "";
					}
				}
			}
			else
			{
				for (int i = 0; i < keyboard.length(); i++)
				{
					tempStr += keyboard[i];
					if (changeString(tempStr) == true)
					{
						tempStr = "";
					}
				}
			}
			held = false;
			timer.restartClock();
		}
		//keystroke held
		else if (timer.getElapsedTimeMilliseconds() >= repeat && paused == true)
		{
			tempStr = "";
			if ((keyboard.find("Lshift") != std::string::npos) || (keyboard.find("Rshift") != std::string::npos))
			{
				for (int i = 0; i < keyboard.length(); i++)
				{
					tempStr += keyboard[i];
					if (changeStringShift(tempStr) == true)
					{
						tempStr = "";
					}
				}
			}
			else
			{
				for (int i = 0; i < keyboard.length(); i++)
				{
					tempStr += keyboard[i];
					if (changeString(tempStr) == true)
					{
						tempStr = "";
					}
				}
			}
			changeString(keyboard);
			timer.restartClock();
		}
	}
	lastKey = keyboard;
	return str;
}

std::string TextEdit::getString()
{
	return str;
}

bool TextEdit::changeString(std::string const& keyboardIn)
{
	if (keyboardIn == "Backspace")
	{
		if (str.length() != 0)
		{
			str = str.erase(str.length() - 1);
		}
		return true;
	}
	else if (keyboardIn == "Space")
	{
		str += " ";
		return true;
	}

	if (keyboardIn == "LetrA" || keyboardIn == "LetrB" || keyboardIn == "LetrC" ||
		keyboardIn == "LetrD" || keyboardIn == "LetrE" || keyboardIn == "LetrF" ||
		keyboardIn == "LetrG" || keyboardIn == "LetrH" || keyboardIn == "LetrI" ||
		keyboardIn == "LetrJ" || keyboardIn == "LetrK" || keyboardIn == "LetrL" ||
		keyboardIn == "LetrM" || keyboardIn == "LetrN" || keyboardIn == "LetrO" ||
		keyboardIn == "LetrP" || keyboardIn == "LetrQ" || keyboardIn == "LetrR" ||
		keyboardIn == "LetrS" || keyboardIn == "LetrT" || keyboardIn == "LetrU" ||
		keyboardIn == "LetrV" || keyboardIn == "LetrW" || keyboardIn == "LetrX" ||
		keyboardIn == "LetrY" || keyboardIn == "LetrZ")
	{

		str += tolower(keyboardIn[4]);
		return true;
	}
	else if (keyboardIn == "Num0" || keyboardIn == "Numpad0")
	{
		str += "0";
		return true;
	}
	else if (keyboardIn == "Num1" || keyboardIn == "Numpad1")
	{
		str += "1";
		return true;
	}
	else if (keyboardIn == "Num2" || keyboardIn == "Numpad2")
	{
		str += "2";
		return true;
	}
	else if (keyboardIn == "Num3" || keyboardIn == "Numpad3")
	{
		str += "3";
		return true;
	}
	else if (keyboardIn == "Num4" || keyboardIn == "Numpad4")
	{
		str += "4";
		return true;
	}
	else if (keyboardIn == "Num5" || keyboardIn == "Numpad5")
	{
		str += "5";
		return true;
	}
	else if (keyboardIn == "Num6" || keyboardIn == "Numpad6")
	{
		str += "6";
		return true;
	}
	else if (keyboardIn == "Num7" || keyboardIn == "Numpad7")
	{
		str += "7";
		return true;
	}
	else if (keyboardIn == "Num8" || keyboardIn == "Numpad8")
	{
		str += "8";
		return true;
	}
	else if (keyboardIn == "Num9" || keyboardIn == "Numpad9")
	{
		str += "9";
		return true;
	}
	else if (keyboardIn == "Lbracket")
	{
		str += "[";
		return true;
	}
	else if (keyboardIn == "Rbracket")
	{
		str += "]";
		return true;
	}
	else if (keyboardIn == "SemiColon")
	{
		str += ";";
		return true;
	}
	else if (keyboardIn == "Quote")
	{
		str += "'";
		return true;
	}
	else if (keyboardIn == "Comma")
	{
		str += ",";
		return true;
	}
	else if (keyboardIn == "Period")
	{
		str += ".";
		return true;
	}
	else if (keyboardIn == "Slash")
	{
		str += "/";
		return true;
	}
	else if (keyboardIn == "Backslash")
	{
		str += "\\";
		return true;
	}
	else if (keyboardIn == "Dash")
	{
		str += "-";
		return true;
	}
	else if (keyboardIn == "Equal")
	{
		str += "=";
		return true;
	}
	else if (keyboardIn == "Tilde")
	{
		str += "`";
		return true;
	}
	else if (keyboardIn == "Plus")
	{
		str += "+";
		return true;
	}
	else if (keyboardIn == "Minus")
	{
		str += "-";
		return true;
	}
	else if (keyboardIn == "Star")
	{
		str += "*";
		return true;
	}
	else if (keyboardIn == "Slash")
	{
		str += "/";
		return true;
	}

	return false;
}

bool TextEdit::changeStringShift(std::string const& keyboardIn)
{
	if (keyboardIn == "LShift" || keyboardIn == "RShift")
	{
		return true;
	}
	else if (keyboardIn == "LetrA" || keyboardIn == "LetrB" || keyboardIn == "LetrC" ||
		keyboardIn == "LetrD" || keyboardIn == "LetrE" || keyboardIn == "LetrF" ||
		keyboardIn == "LetrG" || keyboardIn == "LetrH" || keyboardIn == "LetrI" ||
		keyboardIn == "LetrJ" || keyboardIn == "LetrK" || keyboardIn == "LetrL" ||
		keyboardIn == "LetrM" || keyboardIn == "LetrN" || keyboardIn == "LetrO" ||
		keyboardIn == "LetrP" || keyboardIn == "LetrQ" || keyboardIn == "LetrR" ||
		keyboardIn == "LetrS" || keyboardIn == "LetrT" || keyboardIn == "LetrU" ||
		keyboardIn == "LetrV" || keyboardIn == "LetrW" || keyboardIn == "LetrX" ||
		keyboardIn == "LetrY" || keyboardIn == "LetrZ")
	{
		str += keyboardIn[4];
		return true;
	}
	else if (keyboardIn == "Num1")
	{
		str += "!";
		return true;
	}
	else if (keyboardIn == "Num2")
	{
		str += "@";
		return true;
	}
	else if (keyboardIn == "Num3")
	{
		str += "#";
		return true;
	}
	else if (keyboardIn == "Num4")
	{
		str += "$";
		return true;
	}
	else if (keyboardIn == "Num5")
	{
		str += "%";
		return true;
	}
	else if (keyboardIn == "Num6")
	{
		str += "^";
		return true;
	}
	else if (keyboardIn == "Num7")
	{
		str += "&";
		return true;
	}
	else if (keyboardIn == "Num8")
	{
		str += "*";
		return true;
	}
	else if (keyboardIn == "Num9")
	{
		str += "(";
		return true;
	}
	else if (keyboardIn == "Num0")
	{
		str += ")";
		return true;
	}
	else if (keyboardIn == "Lbracket")
	{
		str += "{";
		return true;
	}
	else if (keyboardIn == "Rbracket")
	{
		str += "}";
		return true;
	}
	else if (keyboardIn == "SemiColon")
	{
		str += ":";
		return true;
	}
	else if (keyboardIn == "Quote")
	{
		str += "\"";
		return true;
	}
	else if (keyboardIn == "Comma")
	{
		str += "<";
		return true;
	}
	else if (keyboardIn == "Period")
	{
		str += ">";
		return true;
	}
	else if (keyboardIn == "Slash")
	{
		str += "?";
		return true;
	}
	else if (keyboardIn == "Backslash")
	{
		str += "|";
		return true;
	}
	else if (keyboardIn == "Dash")
	{
		str += "_";
		return true;
	}
	else if (keyboardIn == "Equal")
	{
		str += "+";
		return true;
	}
	else if (keyboardIn == "Tilde")
	{
		str += "~";
		return true;
	}
	else if (keyboardIn == "Plus")
	{
		str += "+";
		return true;
	}
	else if (keyboardIn == "Minus")
	{
		str += "-";
		return true;
	}
	else if (keyboardIn == "Star")
	{
		str += "*";
		return true;
	}
	else if (keyboardIn == "Slash")
	{
		str += "/";
		return true;
	}

	return false;
}