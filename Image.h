// FILE: Image.h
// Author: Theresa Wilson
// Date: 2/07/16; modified 1/29/17 to add class invariants
//
// CLASS PROVIDED: Image (part of the namespace imagelab)
//
// MEMBER CONSTANTS for the Image class:
//
//   static const int MAX_COLOR = _____
//     Image::MAX_COLOR is the integer value for the maximum color 
//       supported by the image format. For example, images represented
//       with RGB values will have a maximum value of 255.
//
// CONSTRUCTORS for the Image class:
//
//   Image(int w=100, int h=100, int r=0, int g=0, int b=0)
//     Sets the format, width, height, and maxcolor for the
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
//
//   Image(const Image &other)
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
//
//   Image(istream &in)
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
//
//
// DESTRUCTOR for the Image class:
//
//   ~Image()
//     Deallocates memory used by an Image object.
//     Postcondition: All memory used by the pixel array is deleted, and
//       the image's pixel array arr is set to NULL.
//
//
// MODIFICATION MEMBER FUNCTIONS for the Image class:
//
//   void setPixel(int x, int y, Pixel pix)
//     The pixel in arr at position x,y is set to pix.
//     Preconditions: 
//       (x, y) is a valid position in the array for this image.
//     Postconditions: 
//       The pixel at position x,y is pix.
//
//   void setPixel(int x, int y, int r, int g, int b);
//     The pixel in arr at position x,y is set to the given RGB values.
//     Preconditions: 
//       (x, y) is a valid position in the array for this image.
//       r <= 255; 0 <= g <= 255; 0 <= b <= 255
//     Postconditions: 
//       The pixel at position x,y has the red value r, the green value
//       g, and the blue value b.
//
//
// CONSTANT MEMBER FUNCTIONS for the Image class:
//
//   Pixel getPixel(int x, int y) const   
//     Precondition: (x, y) is a valid position in the array for this image
//     Postcondition: returns the pixel at position x,y.
//
//   string getFormat() const
//     Postcondition: returns the format of the image.
//
//   int getMaxColor() const
//     Postcondition: returns the maximum color value of the image.
//
//   int getWidth() const
//     Postcondition: returns the width of the image in pixels.
//
//   int getHeight() const
//     Postcondition: returns the height of the image in pixels.
//
//
// VALUE SEMANTICS for the Image class:
//   The copy constructor may be used with Image objects.
//   The assignment operator may be used with Image objects.
//
//
// OPERATOR OVERLOADING for the Image class:
//
//   void operator= (const Image& source)
//     Assignment operator (=) for the Image class.
//
//   friend std::ostream& operator<< (std::ostream& out, const Image& img)
//     Stream output operator (<<) for outputting the image
//     Note: Returns the `out` parameter to allow chaining of stream output.
//

#ifndef IMAGE_H
#define IMAGE_H

namespace imagelab
{
   class Image
   {
   public:

      // MEMBER CONSTANTS
      static const int MAX_COLOR = 255;

      // CONSTRUCTORS
      Image(int w=100, int h=100, int r=0, int g=0, int b=0);
      Image(const Image &other);    // copy constructor
      Image(std::istream &in);      // constructor for creating an image from
                                    //   stream input

      // DESTRUCTOR
      ~Image();

      // MODIFICATION MEMBER FUNCTIONS
      void setPixel(int x, int y, Pixel pix);
      void setPixel(int x, int y, int r, int g, int b);

      // CONSTANT MEMBER FUNCTIONS
      std::string getFormat() const;
      int getMaxColor() const;
      int getWidth() const;
      int getHeight() const;
      Pixel getPixel(int x, int y) const;

      // OPERATOR OVERLOADS
      void operator= (const Image& source);
      friend std::ostream& operator<< (std::ostream &out, const Image &image);

   private:
      // INSTANCE VARIABLES
      std::string format;  // image format 
      int width;           // width of the image in pixels
      int height;          // height of the image in pixels
      int maxcolor;        // maximum int value for red or blue or green color
      Pixel ** arr;        // pointer to a 2-dimensional dynamic array of Pixels
   
   };
   
   /*
   *  output stream operator, for printing the PPM version of the image
   */
   std::ostream& operator<< (std::ostream &out, const Image &image);

   #endif /* IMAGE_H */
}   
