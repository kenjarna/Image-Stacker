// Pixel.cpp
// Implementation file for Lab 4: Pixel Class

// Name: Kenny Jarnagin
// Date: 2-4-17

#include <iostream>
#include <sstream>
#include "Pixel.h"
#include <cassert>

using namespace std;

namespace imagelab
{

	// 	CONSTRUCTOR for the Pixel class:
	//
	//   Pixel( int r=0, int g=0, int b=0 )
	//   Sets the RGB values for a new pixel. The default constructor will
	//       create a black pixel (RGB values all set to 0).
	//   Preconditions: 0 <= r <= 255; 0 <= g <= 255; 0 <= b <= 255
	//   Postconditions: 
	//       -The pixel's red value is set to the value of r.
	//       -The pixel's green value is set to the value of g.
	//       -The pixel's blue value is set to the value of b.

	Pixel::Pixel(int r, int g, int b)
    {

    	assert (0 <= r && r <= 255);
	    assert (0 <= g && g <= 255);
	    assert (0 <= b && b <= 255);
	    rval = r;
	    gval = g;
	    bval = b;

    }	

    //   void set( int r, int g, int b )
	//     Sets the RGB values for the pixel.
	//     Preconditions: 0 <= r <= 255; 0 <= g <= 255; 0 <= b <= 255
	//     Postconditions: 
	//       -The pixel's red value is set to the value of r.
	//       -The pixel's green value is set to the value of g.
	//       -The pixel's blue value is set to the value of b.
	
   	void Pixel::set(int r, int g, int b)
   	{
   		assert (0 <= r && r <= 255);
	    assert (0 <= g && g <= 255);
	    assert (0 <= b && b <= 255);
   		rval = r;
   		gval = g;
   		bval = b;
   	}
	    
	//   void setRed( int r )
	//     Sets the red value for the pixel.
	//     Precondition: 0 <= r <= 255
	//     Postconditions: The pixel's red value is set to the value of r.

    void Pixel::setRed( int r )
    {
    	assert (0 <= r && r <= 255);
    	rval = r;
    }

    //   void setGreen( int g )
	//     Sets the green value for the pixel.
	//     Precondition: 0 <= g <= 255
	//     Postconditions: The pixel's green value is set to the value of g.
	
	void Pixel::setGreen( int g )
	{
		assert (0 <= g && g <= 255);
		gval = g;
	}    

	//   void setBlue( int b )
	//     Sets the blue value for the pixel.
	//     Precondition: 0 <= b <= 255
	//     Postconditions: The pixel's blue value is set to the value of b.
    
    void Pixel::setBlue( int b )
    {
    	assert (0 <= b && b <= 255);
    	bval = b;
    }    

    //   int getRed( ) const
	//     Precondition: None
	//     Postcondition: The return value is the red value for the pixel.
    
    int Pixel::getRed() const
    {
    	return rval;
    }
	//   int getGreen( ) const
	//     Precondition: None
	//     Postcondition: The return value is the green value for the pixel.

    int Pixel::getGreen() const
    {
    	return gval;
    }

	//   int getBlue( ) const
	//     Precondition: None
	//     Postcondition: The return value is the blue value for the pixel.

    int Pixel::getBlue() const
    {
    	return bval;
    }


	//   bool operator== (const Pixel& pix1, const Pixel& pix2)
	//     Equivalence operator for pixels.
	//     Two pixels are equivalent if the pixels have the same red
	//       values, the same green values, and the same blue values.

	bool operator ==(const Pixel& pix1, const Pixel& pix2)
	{
		if (pix1.getRed() == pix2.getRed() && pix1.getGreen() == pix2.getGreen() && pix1.getBlue() == pix2.getBlue())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//   bool operator!= (const Pixel& pix1, const Pixel& pix2)
	//     Inequivalence operator for pixels.

    bool operator!= (const Pixel& pix1, const Pixel& pix2)
    {
    	if (pix1.getRed() != pix2.getRed() || pix1.getGreen() != pix2.getGreen() || pix1.getBlue() != pix2.getBlue())
		{
			return true;
		}
		else
		{
			return false;
		}	
    }
    

    //   std::ostream& operator<< (std::ostream& out, const Pixel& pix)
	//     Stream output operator (<<) for outputting the contents of a pixel.
	//     Example: A pixel with red value 100, green value 150, and blue value 200
	//              will produce the following output:100 150 200
	//     Note: Returns the `out` parameter to allow chaining of stream output.
	      
    ostream& operator<<(std::ostream& out, const Pixel& pix)
    {
    	out << pix.getRed() << " " << pix.getGreen() << " " << pix.getBlue();
    	return out;
    }
	//   std::istream& operator>> (std::istream& in, Pixel& pix)
	//     Stream input operator (>>) for reading a pixel from an input stream.
	//     Precondition: `in` holds a string of three integers separated by spaces;
	//        each integer must be in the range 0 to 255, inclusive.
	//     Postconditions:
	//        -The red value of pix is set to the first integer.
	//        -The green value of pix is set to the second integer.
	//        -The blue value of pix is set to the third integer.

    istream& operator>>(std::istream& in, Pixel& pix)
    {
    	in >> pix.rval >> pix.gval >> pix.bval;
    	return in;

    }

}

