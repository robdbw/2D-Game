#include "Player.h"

//Private
void Player::moveHand(Window& w) {
	float armLength = 50;
	Vector2i cursor = Mouse::getPosition(w);
	direction = Vector2f(cursor.x, cursor.y) - player.getPosition();
	angle = atan2(direction.y, direction.x) + (3.142 / 2);
	if (sqrt(pow(direction.x, 2) + pow(direction.y, 2)) < armLength)
		hand.setPosition(cursor.x, cursor.y);
	else
		hand.setPosition(player.getPosition() + Vector2f(armLength * sin(angle), -armLength * cos(angle)));
}

//Public
Player::Player() {
	if (!playerT.loadFromFile("assets/player.png")) {}
	if (!handT.loadFromFile("assets/hand.png")) {}

	player.setTexture(playerT);
	player.setScale(5, 5);
	player.setOrigin(8, 8);
	player.setPosition(680, 440);

	hand.setTexture(handT);
	hand.setScale(5, 5);
	hand.setOrigin(2, 2);
}

void Player::update(Window& w) {
	moveHand(w);
}

void Player::move(float dt) {								//Kill me
	isMoving = false;
	speed = 0.04;
	velocity = velocity * 0.9f;

	if ((Keyboard::isKeyPressed(Keyboard::W) && Keyboard::isKeyPressed(Keyboard::D)) || 
		(Keyboard::isKeyPressed(Keyboard::D) && Keyboard::isKeyPressed(Keyboard::S)) || 
		(Keyboard::isKeyPressed(Keyboard::S) && Keyboard::isKeyPressed(Keyboard::A)) || 
		(Keyboard::isKeyPressed(Keyboard::A) && Keyboard::isKeyPressed(Keyboard::W)))
		speed = sqrt(pow(speed, 2) / 2);

	if (Keyboard::isKeyPressed(Keyboard::W)) {
		isMoving = true;
		velocity.y -= speed;
	}
	if (Keyboard::isKeyPressed(Keyboard::S)) {
		isMoving = true;
		velocity.y += speed;
	}
	if (Keyboard::isKeyPressed(Keyboard::A)) {
		isMoving = true;
		velocity.x -= speed;
	}
	if (Keyboard::isKeyPressed(Keyboard::D)) {
		isMoving = true;
		velocity.x += speed;
	}

	player.move(velocity * dt);
}

void Player::animations(float t) {											//Pls fix this shit, ty
	if (direction.x >= 0)													//sorta fixed (:
		if (isMoving)
			if (t >= 0.25) player.setTextureRect(IntRect(16, 0, 16, 16));
			else player.setTextureRect(IntRect(32, 0, 16, 16));
		else player.setTextureRect(IntRect(0, 0, 16, 16));
	else if (direction.x < 0)
		if (isMoving)
			if (t >= 0.25) player.setTextureRect(IntRect(16, 16, 16, 16));
			else player.setTextureRect(IntRect(32, 16, 16, 16));
		else player.setTextureRect(IntRect(0, 16, 16, 16));
}

void Player::draw(RenderTarget& target) const {
	target.draw(player);
	target.draw(hand);
}