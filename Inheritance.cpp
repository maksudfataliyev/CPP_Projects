#include <cstring>
#include <iostream>

class Course {
protected:
    char* _title;
    int _credits;
public:
    Course(){};
    Course(char* title, int credits) : _credits(credits) {
        _title = new char[strlen(title) + 1];
        strcpy(_title, title);
    }

    char* get_title() const {
        return _title;
    }

    int get_credits() const {
        return _credits;
    }

    void set_title(char* title) {
        delete[] _title;
        _title = new char[strlen(title) + 1];
        strcpy(_title, title);
    }

    void set_credits(int credits) {
        _credits = credits;
    }

    friend void display_info(Course* course);

    ~Course() {
        delete[] _title;
    }
};

void display_info(Course* course) {
    std::cout << "Title: " << course->_title << std::endl;
    std::cout << "Credits: " << course->_credits << std::endl;
}


class OnlineCourse : public Course {
private:
    char* _platform;
public:
    OnlineCourse(char* title, int credits, char* platform) : Course(title, credits) {
        delete[] _platform;
        _platform = new char[strlen(platform) + 1];
        strcpy(_platform, platform);
    }

    friend void display_info(OnlineCourse* course);

    ~OnlineCourse() {
        delete[] _platform;
        delete[] _title;
    }
};

void display_info(OnlineCourse* course) {
    std::cout << "Title: " << course->_title << std::endl;
    std::cout << "Credits: " << course->_credits << std::endl;
    std::cout << "Platform: " << course->_platform << std::endl;
}

class OfflineCourse : public Course {
    private:
    char* _location;
    public:
    OfflineCourse(char* title, int credits, char* location) : Course(title, credits) {
        delete[] location;
        _location = new char[strlen(location) + 1];
        strcpy(_location, location);
    }
    ~OfflineCourse() {
        delete[] _location;
        delete[] _title;
    }
    friend void display_info(OfflineCourse* course);
};
void display_info(OfflineCourse* course) {
    std::cout << "Title: " << course->_title << std::endl;
    std::cout << "Credits: " << course->_credits << std::endl;
    std::cout << "Location: " << course->_location << std::endl;
}


class Student {
    private:
    char* _name;
    int _age;
    Course** _course;
    int _course_count = 0;
    public:
    Student(char* name, int age): _age(age) {
        _course = nullptr;
        delete[] _name;
        _name = new char[strlen(name) + 1];
        strcpy(_name, name);
    }

    ~Student() {
        delete[] _name;
        delete[] _course;
    }

    void enrollCourse(Course* course) {
        Course** temp = new Course*[_course_count + 1];
        for (int i = 0; i < _course_count; i++) {
            temp[i] = _course[i];
        }

        temp[_course_count] = course;
        delete[] _course;
        _course_count = _course_count + 1;
        _course = temp;
    }
    friend void display_info(Student* student);

};

void display_info(Student* student) {
    printf("Name:", student->_name);
    printf("Age:", student->_age);
    printf("Course Count:", student->_course_count);
    printf("Courses: \n");
    for (int i = 0; i < student->_course_count; i++) {
        display_info(student->_course[i]);
    }
}

class University {
    private:
    Course** _course;
    Student** _student;
    int _course_count = 0;
    int _student_count = 0;
    public:
    University() {
        _course = new Course*[_course_count + 1];
        _student = new Student*[_student_count + 1];
    }

    void addCourse(Course* course) {
        Course** temp = new Course*[_course_count + 1];
        for (int i = 0; i < _course_count; i++) {
            temp[i] = _course[i];
        }
        temp[_course_count] = course;
        delete[] _course;
        _course_count = _course_count + 1;
        _course = temp;
    }

    void addStudent(Student* student) {
        Student** temp = new Student*[_student_count + 1];
        for (int i = 0; i < _student_count; i++) {
            temp[i] = _student[i];
        }
        temp[_student_count] = student;
        delete[] _student;
        _student_count = _student_count + 1;
        _student = temp;
    }

    void enrollStudentInCourse(Student* student, Course* course) {
        student->enrollCourse(course);
    }

    friend void display_info(University* university);

};

void display_info(University *university) {
    for (int i = 0; i < university->_student_count; i++) {
        display_info(university->_student[i]);
    }

    for (int i = 0; i < university->_course_count; i++) {
        display_info(university->_course[i]);
    }
}


int main() {
    return 0;
}