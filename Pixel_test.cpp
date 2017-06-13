// Pixel_test.cpp
//
// Unit Tests for the Pixel Class
// CS 223, Winter 2017, Lab 4
//
// Name: Kenny Jarnagin
// Date: 2-4-17

#include <cassert>
#include <sstream>
#include <iostream>
#include <string>
#include "Pixel.h"

using namespace std;
using namespace imagelab;

// test_basic_functionality() should test the following:
//    Pixel (constructor)
//    getRed
//    getGreen
//    getBlue
//    set
//    setRed
//    setGreen
//    setBlue
void test_basic_functionality()
{
	//Testing the default constructor
   Pixel t4;
   assert (t4.getRed() == 0);
   assert (t4.getGreen() == 0);
   assert (t4.getBlue() == 0);
   cout << "\tDefault constructor is working properly!\n";

   //Testing the constructor (and get functions) with 3 arguments
   Pixel t2(200,15,35);
   assert (t2.getRed() == 200);
   assert (t2.getGreen() == 15);
   assert (t2.getBlue() == 35);
   cout << "\tConstructor is working properly!\n";

   //Testing the set function
   Pixel t3(1,1,1);
   t3.set(200,57,85);
   assert (t3.getRed() == 200);
   assert (t3.getGreen() == 57);
   assert (t3.getBlue() == 85);
   cout << "\tSet function is working properly!\n";

   //Testing the individual set functions
   Pixel t1(200,15,35);
   t1.setRed(203);
   t1.setGreen(35);
   t1.setBlue(128);
   assert (t1.getRed() == 203);
   assert (t1.getGreen() == 35);
   assert (t1.getBlue() == 128);
   cout << "\tIndividal set functions are working properly!\n";
}

// test equivalence (==) and inequivalence (!=) operators
void test_equality_inequality()
{
   //Testing equivalence operator
   Pixel eq(13,55,32);
   Pixel eq1(13,55,32);
   assert (eq == eq1);

   Pixel eq2(13,55,32);
   Pixel eq3(14,200,32);
   assert (eq2 != eq3);
   cout << "\tEquivalence operator is working properly!\n";

   //Testing inequivalence operator (even though I basically did this above)
   Pixel eq4(12,55,32);
   Pixel eq5(12,55,33);
   assert (eq4 != eq5);

   Pixel eq6(18,80,32);
   Pixel eq7(90,55,33);
   assert (eq4 != eq5);
   cout << "\tInequivalence operator is working properly!\n";
}


// test_streamIO() should test the following:
//    stream output (<<)
//    stream input (>>)
void test_streamIO() {

   // Follow the steps below for testing stream output and input.
   // See stream IO tests that were given for Labs 3 and 4 for examples.

   // 1. Create local variables:
   //      - a stringstream for input, called "in"
   //      - a stringstream for output, called "out"
   //      - a Pixel called "pix"
   //      - a string called "correct" for storing the expected output for "pix"

      stringstream in, out, bin;
      string correct;
      Pixel pix(200, 20, 16);
   //
   //    (To read more about stringstreams, see the bottom of the following
   //    tutorial page: http://www.cplusplus.com/doc/tutorial/basic_io/)
   //
   // 2. Store the expected output in the string variable "correct"
      correct = "200 20 16";

   //
   // 3. Use the output stream variable "out" and the operator "<<" to
   //    (hopefully) put the expected output for Pixel variable "pix"
   //    into "out".
      out << pix;

   // 4. Inside an assert, test whether the result of "out.str()"
   //    (.str() converts stream to string) equals the expected output
   //    in the variable "correct".

      string actual = out.str();
      assert(actual == correct || (actual + "\n") == correct ||
      (correct + "\n" == actual));

      cout << "\tIO Stream is working properly!\n";

   // 5. To test stream input, use the input stream variable "in" and the
   //    operator "<<" to store an appropriate output representation for
   //    a pixel.  NOTE: Use different RGB values than were used originally
   //    for the Pixel variable "pix".
      in << "225 50 35";
   //
   // 6. Use the input stream variable "in" and the operator ">>" to
   //    change the value of "pix".
      in >> pix;

   // 7. Use asserts to test that the attributes of "pix" were changed
   //    correctly.
      assert (pix.getRed() == 225 &&
        pix.getGreen() == 50 &&
        pix.getBlue() == 35);


//*****ERROR HERE: NOT SURE WHY IT DOESN'T CHANGE VALUES....STORES VALUES 225 0 0******
      bin << "235 39 12";
      bin >> pix;
      assert (pix.getRed() == 235 &&
         pix.getGreen() == 39 &&
         pix.getBlue() == 12);

      cout << "\tNew IO stream is working properly!\n";

}

int main2() {

   cout << "Ready to try some tests . . . " << endl;

   // TODO: Uncomment ONE test method call at a time, along with its cout line.
   //       Once that test function and the methods it is testing are fully
   //       implemented all those tests are, uncomment the call to the next
   //       test method and repeat.
   cout << "\nTesting basic methods . . . \n";
   test_basic_functionality();
   cout << ". . . basic methods passed\n" << endl;

   cout << "\nTesting (in)equality methods . . . \n";
   test_equality_inequality();
   cout << ". . . tests for (in)equality passed\n" << endl;

   cout << "\nTesting IO stream . . . \n";
   test_streamIO();
   cout << ". . . stream IO passed\n" << endl;

   cout << "All current tests passing!" << endl;
   return 0; // End the program (all memory should be freed)
}
