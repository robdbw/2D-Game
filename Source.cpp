#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h> 
#include "Player.h"
#include "Weapon.h"
using namespace sf;

int main() {
	RenderWindow window(VideoMode(1280, 960), "Hello");
	Player player;
	Weapon weapon;
	Clock clock, anim;

	Sprite background;
	Texture backgroundT;
	Text text;
	Font arial;

	if (!backgroundT.loadFromFile("assets/map.png")) {}
	if (!arial.loadFromFile("arial.ttf")) {}

	window.setFramerateLimit(120);
	//window.setMouseCursorVisible(false);
	background.setTexture(backgroundT);
	background.setScale(5, 5);
	text.setFont(arial);

	while (window.isOpen()) {
		float deltaTime = clock.restart().asMilliseconds();
		player.move(deltaTime);

		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed)
				if (event.key.code == Keyboard::E)
					weapon.equip();
		}

		player.update(window);
		weapon.update(window, player.getHandPosition());

		if (!player.getIsMoving())
			anim.restart();
		player.animations(anim.getElapsedTime().asSeconds());
		if (anim.getElapsedTime().asSeconds() > 0.5)
			anim.restart();

		window.clear();
		window.draw(background);
		player.draw(window);
		weapon.draw(window);
		window.draw(text);
		window.display();
	}
}