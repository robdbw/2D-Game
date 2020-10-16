#include "Weapon.h"

//Private
void Weapon::rotate(Window& w) {
	Vector2i cursor = Mouse::getPosition(w);
	direction = Vector2f(cursor.x, cursor.y) - sprite.getPosition();
	if (sqrt(pow(direction.x, 2) + pow(direction.y, 2)) < 50)
		sprite.rotate(-20);
	else
		sprite.setRotation(atan2(direction.x, -direction.y) * (180 / 3.142));
}

//Public
Weapon::Weapon() {
	if (!texture.loadFromFile("assets/sword.png")) {}
	sprite.setTexture(texture);
	sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y);
}

void Weapon::update(Window& w, Vector2f hp) {
	if (equipped) {
		rotate(w);
		setPosition(hp);
	}
}