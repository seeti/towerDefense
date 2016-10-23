#include "ObjBase.h"
#include "../GameAnimations/AnimatedSprite.h"

class StaticObject : public ObjBase
{
protected:
	sf::Sprite sfSprite;

public:
	virtual void draw(Game* game, const float dt = 0.0f);
	~StaticObject();
	void setSprite(sf::Sprite);
	virtual sf::Sprite getSprite();
	virtual sf::FloatRect getLocalBounds() const;
	virtual sf::FloatRect getGlobalBounds() const;
	virtual void setPosition(float x, float y);
};