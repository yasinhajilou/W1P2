//
// Created by Yasin Hajilou on 1/22/24.
//

#include "mark.h"
#include "file.h"
#include "io.h"
#include "graph.h"
#include <iostream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <iomanip>

namespace seneca {
    bool printReport(const char *filename) {

        if (openFile(filename)) {
            int intervalCounts[10] = {0};

            Mark marks[MAX_NO_RECS];
            int numRecords = readAllMarks(marks);

            if (numRecords == 0) {
                closeFile();
                return false;
            }

            for (int i = 0; i < numRecords; ++i) {
                if (marks[i].m_mark >= 0 && marks[i].m_mark <= 10) {
                    ++intervalCounts[9];
                }
                if (marks[i].m_mark > 10 && marks[i].m_mark <= 20) {
                    ++intervalCounts[8];
                }
                if (marks[i].m_mark > 20 && marks[i].m_mark <= 30) {
                    ++intervalCounts[7];
                }
                if (marks[i].m_mark > 30 && marks[i].m_mark <= 40) {
                    ++intervalCounts[6];
                }
                if (marks[i].m_mark > 40 && marks[i].m_mark <= 50) {
                    ++intervalCounts[5];
                }
                if (marks[i].m_mark > 50 && marks[i].m_mark <= 60) {
                    ++intervalCounts[4];
                }
                if (marks[i].m_mark > 60 && marks[i].m_mark <= 70) {
                    ++intervalCounts[3];
                }
                if (marks[i].m_mark > 70 && marks[i].m_mark <= 80) {
                    ++intervalCounts[2];
                }
                if (marks[i].m_mark > 80 && marks[i].m_mark <= 90) {
                    ++intervalCounts[1];
                }
                if (marks[i].m_mark > 90 && marks[i].m_mark <= 100) {
                    ++intervalCounts[0];
                }
            }

            printGraph(intervalCounts, 10, "Students' Mark Distribution");

            // Sorting marks in descending order using BubbleSort
            for (int i = 0; i < numRecords - 1; ++i) {
                for (int j = 0; j < numRecords - i - 1; ++j) {
                    if (marks[j].m_mark < marks[j + 1].m_mark) {
                        // Swap marks
                        Mark temp = marks[j];
                        marks[j] = marks[j + 1];
                        marks[j + 1] = temp;
                    }
                }
            }

            // Printing sorted marks
            for (int i = 0; i < numRecords; ++i) {
                auto firstName = marks[i].m_firstName;
                auto lastName = marks[i].m_lastName;

                //marks
                // in order to have aligned numbers and marks to pass Matrix tests
                std::ostringstream streamMark;
                streamMark << std::left << std::setw(3) << marks[i].m_mark;
                std::string formattedMark = streamMark.str();

                //Number
                std::ostringstream streamNumber;
                streamNumber << std::left << std::setw(3) << i + 1;
                std::string formattedNumber = streamNumber.str();

                printMsg((formattedNumber + ":" + " [" + formattedMark + "]"
                          + " " + firstName + " " + lastName + "\n").c_str());
            }

            closeFile();

            return true;
        }
        return false;
    }
}
