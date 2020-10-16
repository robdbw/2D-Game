#include "Item.h"

//Private

//Public
Item::Item() {
	sprite.setScale(5, 5);
}

void Item::draw(RenderTarget& target) const {
	target.draw(sprite);
}

void Item::setPosition(Vector2f p) {
	sprite.setPosition(p);
}

void Item::equip() {
	equipped = !equipped;
}
