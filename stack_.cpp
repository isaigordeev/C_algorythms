#include <iostream>
//using namespace std;


class MinStack{
private:
    int m_length;
    int* m_data;

public:
    MinStack():
            m_length(0), m_data(nullptr)
    {
    }

    MinStack(int length):
            m_length(length)
    {
        if (length > 0)
            m_data = new int[length];
        else
            m_data = nullptr;
    }

    ~MinStack()
    {
        delete[] m_data;
    }

    void erase()
    {
        delete[] m_data;
        m_data = nullptr;
        m_length = 0;
    }

    int& operator[](int index)
    {
        return m_data[index];
    }


    void push_gen(int value, int index)
    {

        int *data = new int[m_length+1];

        for (int before=0; before < index; ++before)
            data [before] = m_data[before];

        data [index] = value;

        for (int after=index; after < m_length; ++after)
            data[after+1] = m_data[after];

        delete[] m_data;
        m_data = data;
        ++m_length;
    }
    void push(int value){
        push_gen(value,m_length);
    }

    void pop_gen(int index)
    {

        if (m_length == 1)
        {
            erase();
            return;
        }
        else{
            int *data = new int[m_length-1];

            for (int before=0; before  < index; ++before)
                data[before] = m_data[before];

            for (int after=index+1; after < m_length; ++after )
                data[after-1] = m_data[after];


            delete[] m_data;
            m_data = data;
            --m_length;}
    }
    void pop(){
        pop_gen(m_length);
    }

    int top(){
        return m_data[m_length-1];
    };

    void print(){
        for(int i = 0; i < m_length; ++i){
            std::cout << m_data[i] << std::endl;
        }
    }

    int getMin() {
        int a = m_data[0];
        for(int i = 0; i < m_length-1; ++i){
            if(m_data[i+1] < m_data[i])
                a = m_data[i+1];
        }
        return a;
}
};

//int main(){
//    MinStack a(10);
//    for(int i = 0; i < 10; ++i){
//        a[i] = i+1;
//    }
//    a.push(11);
//    cout << a.getMin() << " " << a.top() ;
//    a.pop();
//    return 0;
//}