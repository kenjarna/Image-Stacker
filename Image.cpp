// Image.cpp
// Implementation file for Lab 4: Image Class

// Name: Kenny Jarnagin
// Date: 2-7-17

// INVARIANTS for the Image class:
//   1. Images are a 2-D array of pixels indexed by their x,y-coordinates such that:
//          (0,0) is the pixel in the upper-left corner
//          (0,width-1) is the pixel in the upper-right corner
//          (height-1,0) is the pixel in the lower-left corner
//          (height-1,width-1) is the pixel in the lower-right corner
//
//   2. In the 2-D image array, pixels are indexed first by their x-coordinate and
//      then by their y-coordinate.  For example, if arr is the 2-D array of pixels,
//      the pixel at coordinate (x,y) will be accessed as: arr[x][y].
//

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include "Pixel.h"
#include "Image.h"
#include <cassert>

using namespace std;

namespace imagelab
{
//		Image(int w, int h, int r, int g, int b)
// 	   Sets the format, width, height, and maxcolor for the
//     the new Image object. Also creates a default image 
//     of the designated width and height that is:
//        a) a dynamic 2-D array of Pixel objects 
//        b) all Pixels have the color represented by
//           the given red, green, and blue RGB value.
//     Preconditions: w > 0; h > 0; 0 <= r <= 255; 0 <= g <= 255; 0 <= b <= 255
//     Postconditions:
//        Image format is set to "P3".
//        Image width is set to the value of w.
//        Image height is set to the value of h.
//        Image maxcolor is set to MAX_COLOR.
//        Image arr is a 2-D array of pixels with width w and height h.
//        Each pixel in the pixel array is set to the RGB color indicated
//          by the values of r (red), g (green), and b (blue).
	Image::Image(int w, int h, int r, int g, int b)
	{
		assert (0 <= w && 0 <= h);
		assert (0 <= r && r <= 255);
		assert (0 <= g && g <= 255);
		assert (0 <= b && b <= 255);
		format = "P3";
		width = w;
		height = h;
		maxcolor = MAX_COLOR;
		Pixel pix(r,g,b);
		arr = new Pixel* [width];
		for (int i = 0; i < width; i++)
		{
			arr[i] = new Pixel [height];
		}
		for (int i = 0; i < width; i++)
        {
        	for (int j = 0; j < height; j++)
        	{
            	arr[i][j] = pix;
        	}
    	}
	}

//		Image(const Image &other)
//     Creates a copy of the given image.
//     Postconditions:
//        Image copy's format is set to the format of other.
//        Image copy's width is set to the width of other.
//        Image copy's height is set to the height of other.
//        Image copy's maxcolor is set to the maxcolor of other.
//        Image copy's arr is a 2-D array of pixels with the same width,
//          height as other's array of pixels.
//        Each pixel in the copy's pixel array has the same RGB color values 
//          as the pixel at the identical coordinate in other's pixel array.
//        The pixel array for the new Image is stored independently of the other
//          object's pixel array (deep copy).


   Image::Image(const Image &other)
   {
   		*this = other;
   }

//		Image(istream &in)
//     Reads a PPM image from the stream input. Sets the format, width
//       height, and maxcolor for the new Image object based on the
//       input, and creates a 2-D array of pixels, which is populated 
//       by the pixel values read from stream input.
//
//     PPM format in brief:
//        All items in PPM format are separated by whitespace.
//          1st item: 2-character format string 
//          2nd item: image width in pixels
//          3nd item: image height in pixels
//          4th item: maximum pixel color (255)
//          5th item: pixel-1 red value
//          6th item: pixel-1 green value
//          7th item: pixel-1 blue value
//          8th item: pixel-2 red value
//          9th item: pixel-2 green value
//            .... and so on until the RGB values have been given
//            for all the pixels in the image
//
//        For example, the following are the first 8 lines from a
//        PPM file that is 600 x 339 pixels.  The RGB values for
//        the first five pixels in the image are shown.
//
//          P3
//          600 339
//          255
//          0 0 0
//          0 10 16
//          86 8 14
//          0 0 0
//          84 6 8
//
//        In additional the PPM files that you will be working with will always
//        be formatted as follows:  
//
//            1st line: P3
//            2nd line: width height
//            3rd line: 255
//            4th line: r g b
//            5th line: r g b
//                .
//                .
//            last line: r g b
//
//        Note that from line 4 to the end of the file, there will be one pixel
//        per line. 
//
//        IMPORTANT: When writing out new PPM files, please use the format 
//        above. This will make it straightforward to check whether your 
//        stream output function is working correctly. (See moodle instructions.)
//
//     Postconditions:
//        Image format is set to the image format designated by the input stream.
//        Image width is set to the width designated by the input stream.
//        Image height is set to the height designated by the input stream.
//        Image maxcolor is set to the max color designated by the input stream.
//        Image arr is a 2-D array of pixels of the given width and height.
//        Each pixel in the pixel array is set to the RGB color designated 
//          for the pixel by the the input stream.

   Image::Image(istream &in)
   {
   	in >> format;
   	in >> width >> height;
   	in >> maxcolor;
   	Pixel pix;
   	arr = new Pixel* [width]; 
   	for (int i = 0; i < width; i++)
		{
			arr[i] = new Pixel [height];
		}
		for (int i = 0; i < height; i++)
    {
      for (int j = 0; j < width; j++)
      {
        in >> pix;
        arr[j][i] = pix;
      }
    }
   }


// DESTRUCTOR for the Image class:
//   Deallocates memory used by an Image object.
//   Postcondition: All memory used by the pixel array is deleted, and
//   the image's pixel array arr is set to NULL.
   Image::~Image()
   {
   		for (int i = 0; i < width; i++)
   		{	
      		delete [] arr[ i ];
   		}
   		delete [] arr;
   }


// MODIFICATION MEMBER FUNCTIONS for the Image class:
// The pixel in arr at position x,y is set to pix.
//     Preconditions: 
//       (x, y) is a valid position in the array for this image.
//     Postconditions: 
//       The pixel at position x,y is pix.
//
	void Image::setPixel(int x, int y, Pixel pix)
	{
		assert (0<=x && 0<=y);
		assert (x <= width && y <= height);
		arr[x][y] = pix;
	}


//   The pixel in arr at position x,y is set to the given RGB values.
//     Preconditions: 
//       (x, y) is a valid position in the array for this image.
//       r <= 255; 0 <= g <= 255; 0 <= b <= 255
//     Postconditions: 
//       The pixel at position x,y has the red value r, the green value
//       g, and the blue value b. 
   void Image::setPixel(int x, int y, int r, int g, int b)
   {
   	assert (0<=x && 0<=y);
		assert (x <= width && y <= height);
		assert (0<= r && r <= MAX_COLOR);
		assert (0<= g && g <= MAX_COLOR);
		assert (0<= b && b <= MAX_COLOR);
		Pixel newpix(r,g,b);
		arr[x][y] = newpix;

   }


// CONSTANT MEMBER FUNCTIONS for the Image class:

//    Precondition: (x, y) is a valid position in the array for this image
//     Postcondition: returns the pixel at position x,y.
//
	Pixel Image::getPixel(int x, int y) const   
    {
    	assert (0 <= x && 0 <= y);
    	assert (x <= width && y <= height);
    	return arr[x][y];
    }

//     Postcondition: returns the format of the image.
	string Image::getFormat() const
  	{
  		return format;
  	}

//     Postcondition: returns the maximum color value of the image.
    int Image::getMaxColor() const
    {
    	return maxcolor;
    }

//     Postcondition: returns the width of the image in pixels.
    int Image::getWidth() const
    {
    	return width;
    }

//     Postcondition: returns the height of the image in pixels.
    int Image::getHeight() const
    {
    	return height;
    }


// VALUE SEMANTICS for the Image class:
//   The copy constructor may be used with Image objects.
//   The assignment operator may be used with Image objects.
//
//
// OPERATOR OVERLOADING for the Image class:
//     Assignment operator (=) for the Image class.
   void Image::operator= (const Image& source)
   {
 		format = source.getFormat();
 		height = source.getHeight();
 		width = source.getWidth();
 		maxcolor = source.getMaxColor();
 		arr = new Pixel* [width];
 		Pixel pixx;
 		for (int i = 0; i < width; i++)
		{
			arr[i] = new Pixel [height];
		}
		for (int i = 0; i < width; i++)
    {
    	for (int j = 0; j < height; j++)
    	{
    		pixx = source.getPixel(i,j);
        	arr[i][j] = pixx;
    	}
    }  
   }

//     Stream output operator (<<) for outputting the image
//     Note: Returns the `out` parameter to allow chaining of stream output.
   std::ostream& operator<< (std::ostream &out, const Image &image)
   {
   		out << image.getFormat() << "\n";
   		out << image.getWidth() << " " << image.getHeight() << "\n";
   		out << image.getMaxColor() << "\n";
   		Pixel pix;
   		for (int i = 0; i < image.getHeight(); i++)
   		{
   			for (int j = 0; j < image.getWidth(); j++)
   			{
   				pix = image.getPixel(j,i);
   				out << pix <<"\n";
   			}
   		}
   }

}


