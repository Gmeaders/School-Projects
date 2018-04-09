#include <stdio.h>
#include <stdlib.h>


void header(int h, int w);
void makesidoodles(int r, int g, int b);


typedef struct pixel_type { 
 unsigned char r; 
 unsigned char g; 
 unsigned char b; 
 } pixel_t;

int main()
{
	getchar();
	getchar();
	int h;
	int w;
	int s;
	int i;
	int j;
	int x;
	int y;
	
	scanf("%d%d%d", &h, &w, &s);

	pixel_t pixel[h][w], temp;



	unsigned char swapsidoodles;

	for(i = 0; i < h; i++)
	{
		for(j = 0; j < w; j++)
		{
			scanf("%c%c%c", &pixel[i][j].r, &pixel[i][j].g, &pixel[i][j].b);
		}
	}
	for(i = 0; i < h; i++)
	{
		for(j = 0; j < w; j++)
		{
		pixel[i][j].r = 255 - pixel[i][j].r;
		pixel[i][j].g = 255 - pixel[i][j].g;
		pixel[i][j].b = 255 - pixel[i][j].b;
	
		swapsidoodles = pixel[i][j].r;
		pixel[i][j].r = pixel[i][j].g;
		pixel[i][j].g = swapsidoodles;
		}
	}

	header(h, w);

	for(i=0; i < h; i++)
	{
		for(j=0; j < w; j++)
		{
			makesidoodles(pixel[i][j].r, pixel[i][j].g, pixel[i][j].b);
		}
	}	
	
	return 0;
}


void header(int h, int w)
{
	printf("P6\n");
	printf("%d %d 255\n", h, w);
}	

void makesidoodles(int r, int g, int b)
{
	printf("%c%c%c", r, g, b);
}

