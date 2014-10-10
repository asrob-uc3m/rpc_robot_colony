This is an example C++ library for Arduino 1.0

Installation
--------------------------------------------------------------------------------

To install this library, just place this entire folder as a subfolder in your
sketchbook/libraries folder.

When installed, this library should look like:

sketchbook/libraries/Test              (this library's folder)
sketchbook/libraries/Test/Test.cpp     (the library implementation file)
sketchbook/libraries/Test/Test.h       (the library description file)
sketchbook/libraries/Test/keywords.txt (the syntax coloring file)
sketchbook/libraries/Test/examples     (the examples in the "open" menu)
sketchbook/libraries/Test/readme.txt   (this file)

Building
--------------------------------------------------------------------------------

After this library is installed, you just have to start the Arduino application.
You may see a few warning messages as it's built.

To use this library in a sketch, go to the Sketch | Import Library menu and
select Test. This will add a corresponding line to the top of your sketch:

#include <Test.h>

To stop using this library, delete that line from your sketch.

Geeky information:
After a successful build of this library, a new file named "Test.o" will appear
in "sketchbook/libraries/Test". This file is the built/compiled library
code.

If you choose to modify the code for this library (i.e. "Test.cpp" or "Test.h"),
then you must first 'unbuild' this library by deleting the "Test.o" file. The
new "Test.o" with your code will appear after the next press of "verify".
