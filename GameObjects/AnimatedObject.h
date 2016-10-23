#include "ObjBase.h"
#include "../GameAnimations/AnimatedSprite.h"

class AnimatedObject : public ObjBase, public AnimatedSprite
{
private:
protected:
	sf::Sprite sfSprite;
	Animation animacionObjeto;
	AnimatedSprite animatedSprite;
	sf::Clock frameClock;
public:
	virtual sf::FloatRect getLocalBounds() const;
	virtual sf::FloatRect getGlobalBounds() const;
	virtual void draw(Game* game, const float dt = 0.0f);
	virtual bool onTick(const float dt);
	Animation getAnimation();
	virtual void setPosition(float x, float y);
};