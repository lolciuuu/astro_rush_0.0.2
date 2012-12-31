#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include "Headers.hpp"
#include "StandardReferences.hpp"

/** Klasa przewijalnego tla w grze */
class Background : public StandardReferences {
public:

	Background();

	void update( float dt );

	void init();

	void draw();

private:
	GLuint pBackgroungImg;

	Rect pFirst;
	Rect pSecond;
};

#endif
