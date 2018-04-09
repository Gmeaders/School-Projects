#include <stdio.h>
void make_pixel(int r, int g, int b);
void make_ppm_header(int width, int height);
void make_ppm_image(int country_code, int width);
void uk(int width);
void russia(int width);
void ire(int width);



int main()
{
        int width;
        int country_code;

        // prompt user to enter width and country_code of chosen flag 
        
        /* Read image dimensions and pixel color */
        fscanf(stdin, "%d %d", &country_code, &width);
        fprintf(stderr, "Making country %d with width %d \n",
                country_code, width);

        /* Write the image data */
        make_ppm_image(country_code, width);

        return(0);
}







void make_pixel(
	int r, // red intensity 
	int g, // green intensity 
	int b) // blue intensity 
{
	fprintf(stdout, "%c%c%c", r, g, b);
}

void make_ppm_header(int width, int height)
{
	fprintf(stdout, "P6\n");
	fprintf(stdout, "%d %d %d\n", width, height, 255);
}

void make_ppm_image(country_code, width)
{
	if(country_code == 0)
		uk(width);
	else if(country_code == 1)
		russia(width);
	else if(country_code ==2)
		ire(width);
}

void uk(int width){
	int row, col;
	int height = (width * (2/3.0));

	make_ppm_header(width, height);

	for(row = 0; row < height; row++){
		for(col = 0; col < width; col++){
			
			if(row < (height/2))
				make_pixel(0, 127, 255);
			else
				make_pixel(255, 255, 0);
		}
	}
}

void russia(int width){
	int row, col;
	int height = (width * (2/3.0));
	make_ppm_header(width, height);

	for(row = 0; row < height; row++){
		for(col = 0; col < width; col++){
			if(row < (height/3))
				make_pixel(255,255,255);
			else if(row < (height * 2.0/3) && row > (height/3))
					make_pixel(0, 0, 225);
			else
					make_pixel(255, 0, 0);
			}
	}
}

void ire(int width){
	int row;
	int col;
	int height = (width * (1/2.0));

	make_ppm_header(width, height);

	for(row = 0; row < height; row++){
		for(col = 0; col < width; col++){
			if(col < (width/3))
				make_pixel(0, 128, 0);
			else if(col < (width*2.0/3) && col > (width/3))
				make_pixel(225, 225, 225);
			else 
				make_pixel(225, 165, 0);
		}
	}

}


