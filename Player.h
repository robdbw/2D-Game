#include <SFML/Graphics.hpp>
using namespace sf;

class Player {
private:
	Sprite player, hand;
	Texture playerT, handT;
	Vector2f velocity, direction;
	float speed, angle;
	bool isMoving;
	void moveHand(Window&);

public:
	Player();
	void update(Window&);
	void move(float);
	void animations(float);
	void draw(RenderTarget&) const;
	Vector2f getHandPosition() { return hand.getPosition(); }
	bool getIsMoving() { return isMoving; }
};