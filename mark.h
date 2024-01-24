#ifndef DESKTOP_MARK_H
#define DESKTOP_MARK_H

/// <summary>
/// Record of a mark received by a student.
/// </summary>
namespace seneca {

    struct Mark {
        /// <summary>
        /// The first name of the student.
        /// </summary>
        char m_firstName[20 + 1];
        /// <summary>
        /// The last name of the student.
        /// </summary>
        char m_lastName[30 + 1];
        /// <summary>
        /// The mark the student received (as a number between 0 and 100).
        /// </summary>
        int m_mark;
    };

    bool printReport(const char *filename);
}

#endif //DESKTOP_MARK_H
