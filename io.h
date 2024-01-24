#ifndef NAMESPACE_IO_H // replace with relevant names, each header should have its own header guard, unique in the ENTIRE project
#define NAMESPACE_IO_H

 namespace seneca {

     const int MAX_NO_OF_SAMPLES = 20;
     const int GRAPH_WIDTH = 65;

     int intDigits(int value);

     void printInt(int value, int fieldWidth);

     void moveCursorBack(int n);

     void drawLineWithLabel(int length, const char *text);

     int getInt(int min, int max);

     void printMsg(const char *msg);

     void printErrorMsg(const char *msg);

     int menu(int noOfSamples);

     void drawLine(int length);
 }

#endif
