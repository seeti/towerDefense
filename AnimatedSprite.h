/*

#include <functional>
#include <assert.h>
#include <iso646.h>
#include <SFML/Graphics.hpp>
#include "Animation.h"

#pragma once
class AnimatedSprite : public sf::Drawable, public sf::Transformable
{
public:
	AnimatedSprite(const AnimatedSprite&) = default;
	AnimatedSprite &operator = (const AnimatedSprite&) = default;
	AnimatedSprite(AnimatedSprite&&) = default;
	AnimatedSprite &operator=(AnimatedSprite&&) = default;

	using FuncType = std::function<void()>;
	static FuncType defaultFunc;
	FuncType onFinished;
	enum Status { Stopped, Paused, Playing };

	AnimatedSprite(Animation* animation = nullptr,
		Status status = Playing,
		const sf::Time &deltaTime = sf::seconds(0.15),
		bool loop = true,
		int repeat = 0);

	void setAnimation(Animation* animation);
	Animation* getAnimation() const;

	void setFrameTime(sf::Time deltaTime);
	sf::Time getFrameTime() const;

	void setLoop(bool loop);
	bool getLoop() const;
	void setRepeat(int nb);
	int getRepeat() const;

	void play();
	void pause();
	void stop();
	Status getStatus() const;

	void setFrame(size_t index);
	void setColor(const sf::Color &color);
	void update(const sf::Time &deltaTime);

	~AnimatedSprite();

private:
	Animation* _animation;
	sf::Time _delta;
	sf::Time _elapsed;
	bool _loop;
	int _repeat;
	Status _status;
	size_t _currentFrame;
	sf::Vertex _vertices[4];

	void setFrame(size_t index, bool resetTime);
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};

*/