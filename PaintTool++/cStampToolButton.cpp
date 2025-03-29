#include "cStampToolButton.h"

StampToolButton::StampToolButton(float x, float y, float width, float height, DrawTool& _userDrawTool, FileInterface& _userFileInterface)
	: Button(x, y, width, height), m_UserDrawTool(_userDrawTool), m_FileInterface(_userFileInterface)
{
	// Load image
	m_StampIconImage.loadFromFile("Sprites/StampSprite.png");
	m_StampIconTexture.loadFromImage(m_StampIconImage);
	m_UIIcon = new sf::Sprite(m_StampIconTexture);
	// Set position
	m_UIIcon->setOrigin(sf::Vector2f(8, 8));
	m_UIIcon->setPosition(sf::Vector2f(f_PosX + (f_Width / 2), f_PosY + (f_Height / 2)));
}

StampToolButton::~StampToolButton()
{
	delete m_UIIcon;
}

void StampToolButton::OnButtonClick()
{
	 m_FileInterface.LoadStamp(&m_UserDrawTool.GetStampTool().GetStampTexture());
	 m_UserDrawTool.GetStampTool().RefreshStampSprite();
	 m_UserDrawTool.SetTool(DrawTool::ToolType::ToolMode_StampTool);
}

void StampToolButton::Draw(sf::RenderWindow& window)
{
	Button::Draw(window);
	window.draw(*m_UIIcon);
}