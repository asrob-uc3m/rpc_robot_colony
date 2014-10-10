/**
 * File: test.ino
 * Description: Demostrates how to do something with the Test library.
 * Author: Raul Perula-Martinez <http://asrob.uc3m.es/RPC>
 * Created: 01 December 2013
 */
 
#include <Test.h>

Test myTest = Test(2);

void setup() {

}

void loop() {
    myTest.doSomething();
    delay(500);
}

