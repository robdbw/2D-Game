#include <SFML/Graphics.hpp>
#include "Item.h"
using namespace sf;

class Weapon : public Item {
private:
	Vector2f direction;
	void rotate(Window&);

public:
	Weapon();
	void update(Window&, Vector2f);
};