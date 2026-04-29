#pragma once

class MyVec{
    private: 
        int size;
        int* array;
        
    public:
        MyVec(int len);
        ~MyVec();
        MyVec(const MyVec& rhs);
        MyVec& operator=(const MyVec& rhs);
        MyVec(MyVec&& rhs);
        MyVec& operator=(MyVec&& rhs);
        int& operator[](int idx);
        MyVec operator+(const MyVec& rhs);
        friend ostream& operator<<(ostream& os, const MyVec& rhs);
};

