// image_stacker.cpp
/*
  Specificications for the image stacker program:
     - Ask the user for the directory containing the images to stack
     - Ask the user for what to call the final good image file
     - Average all all noisy images in the given directory to create
       a final good image
     - write the final good image in PPM format to the filename given
       by the user.

  By: Kenneth Jarnagin
  Date: 2-15-17
*/

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <dirent.h>
#include "Pixel.h"
#include "Image.h"

using namespace std;
using namespace imagelab;

/*!
*   @function      readDir
*   @description   puts filenames from a directory into an output stream
*
*   @param out     output stream (may be a stringstream)
*   @param dir     string containing the path to the directory to read
*   @param n       int number of filenames to return
*   @returns       output stream with the filenames, separated by spaces
*
*   @precondition  dir is a valid directory
*   @precondition  n <= the number of files in dir
*/
ostream& readDir(ostream& out, string dir, int n)
{
    string fname, filepath;
    DIR *dp;
    struct dirent *dirp;
    cout << "dir to get files of: " << dir << endl;

    dp = opendir( dir.c_str() );
    if (dp == NULL)
    {
    cout << "ERROR_OPENING:" << dir << endl;
    return out;
    }

    int i = 0;
    while ((dirp = readdir( dp )) && i < n)
    {
       fname = dirp->d_name;

       if ((fname.length() >= 3) &&
          (fname.substr(fname.length()-3, 3) == "ppm"))
       {

           filepath = dir + "/" + fname;
           out << filepath << " ";
           i++;
       }
    }


    closedir( dp );
    return out;
}

/*!
*   @function           whattocallit
*   @description        asks the user what to call their new image after stacking
*   @preconditions      will not recognize spaces in the entered name
*
*   @returns            user-entered string
*/
string whattocallit()
{
  string name;
  cout << "First, what do you want to call the new image? (NO SPACES): ";
  cin >> name;
  name = name + ".ppm";
  return name;
}


/*!
*   @function           selectdir
*   @description        Asks the user which directory that will be used to stack the iamges
*
*   @returns            the directory path
*
*/
string selectdir()
{
  int dirnum;
  string dir;
  cout << "What directory of images did you want to stack? (1 = cone nebula,"
       << "2 = n44f, 3 = orion, 4 = wfc3_uvis): ";
  cin >> dirnum;

  // Decision structure for deciding which directory to use
  if (dirnum == 1)
  {
    dir = "C:/Users/Kenny Jarnagin/Pictures/Image_Stacker/Sakib/ImageFiles";
  }

  else // gives the user another chance to select the correct directory
  {
    cout << "You entered an incorrect value. Please try again!" <<endl;
    dir = selectdir();
  }
  return dir;
}


/*!
*   @function           imagefromfile
*   @description        creates an image object for the given files
*
*   @param files        filepath at a particular location in the array
*   @returns            the image object for each .ppm file in the array
*
*   @precondition       filepath is valid
*
*/
Image imagefromfile(string files)
{
  //declare a stream for reading a file
  ifstream Filestream;
  Filestream.open(files.c_str());
  Image result(Filestream);
  Filestream.close();
  return result;
}

/*!
*   @function           newimageval
*   @description        retrieves and averages the pixels in the image file for each image object
*                       in the image object array
*
*   @param imagearray[] the array holding all of the image objects
*   @returns            the new and improved image (via stacking)
*
*   @precondition       filepath is a valid filepath
*   @precondition       n <= the number of files in dir
*   @precondition       imagearray[] is not empty
*   @precondition       length of imagearray[] less than or equal to n
*/
Image newimageval(Image imagearray[], int n)
{
  Image final(imagearray[0].getWidth(),imagearray[0].getHeight(),0,0,0);  // Creates a black image, with given width and height of directory image
  int rval = 0;
  int gval = 0;
  int bval = 0;
  for (int x = 0; x < imagearray[0].getWidth(); x++)      // First two for loops access a specific pixel in the image
  {
    for (int y = 0; y < imagearray[0].getHeight(); y++)
    {
      rval = 0;
      gval = 0;
      bval = 0;
      for (int t = 0; t < n; t++)                        // Used to pull the pixel values at a given (x,y) position in the array
      {
        Pixel pix = imagearray[t].getPixel(x,y);
        rval = rval + pix.getRed();
        gval = gval + pix.getGreen();
        bval = bval + pix.getBlue();
      }
      rval = rval/n;    // Averages the red value of all the images passed to the function thus far
      gval = gval/n;    // Averages the green value of all the images passed to the function thus far
      bval = bval/n;    // Averages the blue value of all the images passed to the function thus far
      final.setPixel(x,y,rval,gval,bval);   // sets the averaged pixel values to individual pixel in the new image
    }
  }
return final;
}


/*!
*   @function           writeResult
*   @description        outputs the finalized, "stacked" image with the user-defined name
*
*   @param output       the image with average pixel values created from newimageval
*
*   @precondition       filepath is valid
*
*   @postcondition      create the new image with the given name (as defeind by the user)
*/
void writeResult(Image output, string ofilename)
{
  ofstream newfile;
  newfile.open(ofilename.c_str());
  newfile << output;
  newfile.close();
}


int main()
{
  string dir;
  stringstream files;
  string name;
  int n = 10;

  name = whattocallit();
  dir = selectdir();
  readDir(files,dir,n);

  //Creates an array of all the file image names of the directory
  string filearray[n];
  for (int i = 0; i < n; i++)
  {
    files >> filearray[i];                        // places file names into filearray
  }

  //Creates an array of Image objects given by the file names above
  Image imagearray[n];
  for (int i = 0; i < n; i++)
  {
    imagearray[i] = imagefromfile(filearray[i]); // inserts image objects (created by imagefromfile) into imagearray
  }

  Image output = newimageval(imagearray,n);     // create an "average" image object [from the directory provided]
  writeResult(output,name);                     // officially creates the new image


  return 0;  // Terminate the program
 }
