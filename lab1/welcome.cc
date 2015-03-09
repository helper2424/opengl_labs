#include "tgaimage.h"
#include <stdint.h>
#include <algorithm>
#include <math.h>
#include <unordered_map>

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red   = TGAColor(255, 0,   0,   255);

void bresenham(TGAImage& img, const int x0, const int y0, const int x1, const int y1, const TGAColor & color)
{
	bool swaped = false;
	int _x0(x0), _x1(x1), _y0(y0), _y1(y1), inc(1);
	float k = static_cast<float>((y1 - y0)) / (x1 - x0), real_y;

	if(k < 0)
		inc = -1;

	if(fabs(k) > 1)
	{
		swaped = true;
		std::swap(_x0, _y0);
		std::swap(_x1, _y1);
		k = 1 / k;
	}

	if(_x0 > _x1)
	{
		std::swap(_x0, _x1);
		std::swap(_y0, _y1);
	}

	int y_buf = _y0;
	real_y = _y0;

	for(int i = _x0; i<=_x1; i++)
	{
		real_y += k;

		if(fabs(real_y - y_buf) >= 0.5)
			y_buf += inc;

		if(!swaped)
			img.set(i, y_buf ,color);
		else
			img.set(y_buf, i,color);
	}
}

int main(int argc, char** argv) {
        TGAImage image(1000, 1000, TGAImage::RGB);
	for(uint32_t i = 0; i < 1000000; i++)
	{
		bresenham(image, 0,0, 100, 200, white);
		bresenham(image, 100,200, 150, 110, red);
		bresenham(image, 150, 110,100,200, white);
		bresenham(image, 300, 0,300,500, white);
		bresenham(image, 200, 249,600,251, red);
	}
	image.flip_vertically();
	image.write_tga_file("output.tga");

        return 0;
}

void wuu(const TGAImage& img, const int32_t x0, const int32_t y0, const int32_t x1, const int32_t y1)
{

}

void draw( )
{
	//for
}