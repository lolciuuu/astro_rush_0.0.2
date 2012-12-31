#include "../include/Background.hpp"
#include "../include/Resource.hpp"

Background::Background(): pBackgroungImg( 0 )
{
	logger.setClassName("Background");
}

//@TODO wywalic liczbe magiczna
void Background::update(float dt)
{
	if( pFirst.w + pFirst.x < 0 ) {
		pFirst.x = pSecond.x;
		pSecond.x += pFirst.w;
	}
	else {
		pFirst.x -= 600 * dt;
		pSecond.x = pFirst.w + pFirst.x;
	}

}

void Background::draw() {

	if( (pFirst.w + pFirst.x) <= pScreenWidth ) {
		pRendererPtr->draw( pBackgroungImg,  pFirst.x, pFirst.y, pFirst.w, pFirst.h );
		pRendererPtr->draw( pBackgroungImg,  pSecond.x, pFirst.y, pFirst.w, pFirst.h );
	}
	else
	    pRendererPtr->draw( pBackgroungImg, pFirst );
}

void Background::init() {

	SDL_Surface* surf =  Resource::getSurf("LEVEL_BACKGROUND") ;

	pSecond.w = pFirst.w = surf->w;
	pSecond.h = pFirst.h = surf->h;

	pFirst.y = pScreenHeight - pFirst.h;

	pBackgroungImg = RendererGL::getSurfaceInGLFormat( surf );
}
