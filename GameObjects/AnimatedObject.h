#include "ObjBase.h"
#include "../GameAnimations/AnimatedSprite.h"

class AnimatedObject : public ObjBase, public AnimatedSprite
{
private:
	sf::Sprite sfSprite;
protected:
public:
	virtual sf::FloatRect getLocalBounds() const;
	virtual sf::FloatRect getGlobalBounds() const;
	virtual void draw(Game* game, const float dt = 0.0f);
};