#pragma once

class Egg
{
private:
	int egg_count{ 0 };

	Egg() = default;

public:
	Egg(int eggs) : egg_count(eggs) {}
};

