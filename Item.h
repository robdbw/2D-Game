#include <SFML/Graphics.hpp>
using namespace sf;

class Item {
private:

public:
	Sprite sprite;
	Texture texture;
	bool equipped{false};

	Item();
	void draw(RenderTarget&) const;
	void setPosition(Vector2f);
	void equip();
};