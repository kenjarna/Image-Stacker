// Image_test.cpp
//
// Unit and Other Tests for the Pixel Class
// CS 223, Winter 2017, Lab 4
//
// Name: Kenny Jarnagin
// Date: 2-7-17

#include <cassert>
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include "Pixel.h"
#include "Image.h"

using namespace std;
using namespace imagelab;

// test_basic_functionality() should test the following:
//    Image(w, h, r, g, b);   // (default) constructor
//    getFormat()
//    getMaxColor()
//    getWidth()
//    getHeight()
//    getPixel()
//    setPixel(x, y, pix)
//    setPixel(x, y, r, g, b)
void test_basic_functionality()
{
    //Testing the default constructor
    Image I;
    Pixel pix(0,0,0);
    assert (I.getWidth() == 100 && I.getHeight() == 100);
    //For loop to test ALL the positions in the array
    for (int i = 0; i < 100; i++) 
    {
        for (int j = 0; j < 100; j++)
        {
            assert (I.getPixel(i,j) == pix);
        }
    }



    //Testing the basic get commands
    Image I1(20,20,35,40,18);
    Pixel pix1(35,40,18);
    assert (I1.getFormat() == "P3");
    assert (I1.getMaxColor() == 255);
    assert (I1.getWidth() == 20);
    assert (I1.getHeight() == 20);
    //For loop to test ALL the positions in the array
    for (int i = 0; i < 20; i++) 
    {
        for (int j = 0; j < 20; j++)
        {
            assert (I1.getPixel(i,j) == pix1);
        }
    }

    //Testing rectangular arrays as well...
    Image I4(23,83,35,40,18);
    Pixel pix6(35,40,18);
    assert (I4.getWidth() == 23);
    assert (I4.getHeight() == 83);
    for (int i = 0; i < 23; i++)
    {
        for (int j = 0; j < 83; j++)
        {
            assert (I4.getPixel(i,j) == pix6);
        }
    }

    cout << "\tGet commands and constructors are working properly!\n";

    //Testing the set commands
    Image I2(20,20,35,81,24);
    //New pixel used to test the changes
    Pixel pix2(39,76,90); 
    //Same as the I2 pixel, just to make assertions easier later
    Pixel pix3(35,81,24); 
    I2.setPixel(3,8,pix2);
    assert (I2.getPixel(4,7) == pix3);
    assert (I2.getPixel(3,8) == pix2);
    cout << "\tSetpixel 'copier' function is working properly!\n";

    Image I3(20,20,79,200,155);
    //new pixel used to test changes
    Pixel pix4(30,25,19); 
    //Pixel used to test another position to verify it was not changed
    Pixel pix5(79,200,155); 
    I3.setPixel(5,14,30,25,19);
    assert (I3.getPixel(5,14) == pix4);
    assert (I3.getPixel(18,3) == pix5);
    cout << "\tSetpixel 'creator' function is working properly!\n";



}

void stream_input_constructor_test1()
{
    // Read in an image file to create an Image.
    // Check that image format, width, height, and maxcolor
    // are correctly set.  Also check that the first three
    // and the last three pixels of the the image are correct.

    cout << "  Test 1:" << endl;

    string imagefilestr = "/usr/local/share/images/images_noisy/n44f/n44f_001.ppm";
    cout << "    -reading image " << imagefilestr << endl;
    ifstream imagefile(imagefilestr.c_str());
    Image image(imagefile);
    imagefile.close();

    cout << "    -checking image format and dimensions" << endl;
    assert(image.getFormat() == "P3");
    assert(image.getWidth() == 600);
    assert(image.getHeight() == 339);
    assert(image.getMaxColor() == 255);

    cout << "    -checking first three pixels of image" << endl;
    assert(image.getPixel(0,0) == Pixel(0,0,0));
    assert(image.getPixel(1,0) == Pixel(0,10,16));
    assert(image.getPixel(2,0) == Pixel(86,8,14));

    cout << "    -checking last three pixels of image" << endl;
    assert(image.getPixel(597,338) == Pixel(255,100,0));
    assert(image.getPixel(598,338) == Pixel(17,118,0));
    assert(image.getPixel(599,338) == Pixel(255,0,0));
}

void stream_input_constructor_test2()
{
    // Read in an image file to create an Image.
    // Check that image format, width, height, and maxcolor
    // are correctly set.  Also check that the first three
    // and the last three pixels of the the image are correct.

    cout << "  Test 2:" << endl;

    string imagefilestr = "/usr/local/share/images/images_noisy/orion/orion_010.ppm";
    cout << "    -reading image " << imagefilestr << endl;
    ifstream imagefile(imagefilestr.c_str());
    Image image(imagefile);
    imagefile.close();

    cout << "    -checking image format and dimensions" << endl;
    assert(image.getFormat() == "P3");
    assert(image.getWidth() == 600);
    assert(image.getHeight() == 600);
    assert(image.getMaxColor() == 255);

    cout << "    -checking first three pixels of image" << endl;
    assert(image.getPixel(0,0) == Pixel(0,0,16));
    assert(image.getPixel(1,0) == Pixel(0,0,0));
    assert(image.getPixel(2,0) == Pixel(14,0,16));

    cout << "    -checking last three pixels of image" << endl;
    assert(image.getPixel(597,599) == Pixel(0,0,18));
    assert(image.getPixel(598,599) == Pixel(0,4,16));
    assert(image.getPixel(599,599) == Pixel(0,4,0));
}

void stream_output_test()
{
    // Read in an image file to create an Image, then write that
    // image out to a new file. Use the linux command line to check
    // for differences in the two files.

    string imagefilestr = "/usr/local/share/images/images_noisy/n44f/n44f_001.ppm";
    cout << "    -reading image " << imagefilestr << endl;
    ifstream imagefile(imagefilestr.c_str());
    Image image(imagefile);
    imagefile.close();

    string outfilestr = "testimage.ppm";
    cout << "    -writing image to " << outfilestr << endl;
    ofstream outfile(outfilestr.c_str());
    outfile << image;
    outfile.close();

    cout << "\nTo check for differences between the original image file \n";
    cout << "and the newly created image file, please run the following \n";
    cout << "command:\n" << endl;
    cout << "    diff " << imagefilestr << " " << outfilestr << endl << endl;
    cout << "If there are no differences, your stream output operator\n";
    cout << "is correct! If there are differences, there's an error in \n";
    cout << "the implementation of your stream output. Use the 'head'\n";
    cout << "and 'tail' commands to inspect the two files and help you \n";
    cout << "figure out what is wrong.\n";
    cout << "\nAs a final test, you should use an image viewer to try to\n";
    cout << "view " << outfilestr << "." << endl;
    cout << "-----------------------------------------" << endl << endl;

}


void test_copy_constructor()
{
    //Create an image (varies by pixel) [rectangular array]
    Image CS(73,103,1,1,30);
    for (int i = 0; i < 73; i++)
    {
        for (int j = 0; j < 103; j++)
        {
            CS.setPixel(i,j,j,i,j);
        }
    }

    //Test to see if the new object is EXACTLY the same as the C object above
    Image C3(CS);
    assert (C3.getFormat() == "P3");
    assert (C3.getMaxColor() == 255);
    assert (C3.getWidth() == 73);
    assert (C3.getHeight() == 103);
    //For loop to test ALL the positions in the array
    for (int i = 0; i < C3.getWidth(); i++) 
    {
        for (int j = 0; j < C3.getHeight(); j++)
        {
            assert (C3.getPixel(i,j) == CS.getPixel(i,j));
        }
    }

    //Create an image (varies by pixel) [square array]
    Image CSX(50,50,1,1,30);
    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            CSX.setPixel(i,j,j,i,j);
        }
    }

    //Test to see if the new object is EXACTLY the same as the C object above
    Image C4(CSX);
    assert (C4.getFormat() == "P3");
    assert (C4.getMaxColor() == 255);
    assert (C4.getWidth() == 50);
    assert (C4.getHeight() == 50);
    //For loop to test ALL the positions in the array
    for (int i = 0; i < C4.getWidth(); i++) 
    {
        for (int j = 0; j < C4.getHeight(); j++)
        {
            assert (C4.getPixel(i,j) == CSX.getPixel(i,j));
        }
    }
    cout << "\tCopy Constructor is working properly!" <<endl;
}

void test_assignment_operator()
{
    //Create an image (varies by pixel)
    Image C(100,103,1,1,30);
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 103; j++)
        {
            C.setPixel(i,j,j,i,j);
        }
    }

    //Test to see if the new object is EXACTLY the same as the C object above
    Image C2 = C;
    assert (C2.getFormat() == "P3");
    assert (C2.getMaxColor() == 255);
    assert (C2.getWidth() == 100);
    assert (C2.getHeight() == 103);
    //For loop to test ALL the positions in the array
    for (int i = 0; i < C2.getWidth(); i++) 
    {
        for (int j = 0; j < C2.getHeight(); j++)
        {
            assert (C2.getPixel(i,j) == C.getPixel(i,j));
        }

    }
    cout << "\tAssignment Operator is working correctly!" <<endl;
}


int main()
{
   cout << "\nTesting the Image class!" << endl;

   cout << "\nTesting basic image creation and functionality . . . " << endl;
   test_basic_functionality();
   cout << ". . . Basic Image creation and functionality passed!\n" << endl;

   cout << "Testing creation of an image from stream input . . . " << endl;
   stream_input_constructor_test1();
   stream_input_constructor_test2();
   cout << ". . . input constuctor passed!\n" << endl;

   //cout << "\n-----------------------------------------" << endl;
   cout << "Testing stream output for an image . . . \n" << endl << endl;
   stream_output_test();
   cout << ". . . output test working properly!" << endl;

   cout << "\nTesting copy constructor and assignment operator . . . " << endl;
   test_copy_constructor();
   test_assignment_operator();
   cout << ". . . copy constructor and assignment operator working properly!\n" << endl;

   return 0; //Verifies that the program has terminated
}
