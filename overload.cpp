#include <cstdint>
#include <iostream>
#include <utility>
using namespace std;


class Fraction {
private:
    // Do NOT rename
    __int64_t numerator;
    __uint64_t denominator;
    static int cancelling(int a , int b)
    {
        if(b==0) return a;
        a%=b;
        return cancelling(b,a);
    }
    // Do NOT delete
    template < class T >
    friend bool operator==(const Fraction& lhs, const T& rhs);

public:
    Fraction() = delete;
    Fraction(const Fraction& rhs):
        numerator(rhs.numerator),
        denominator(rhs.denominator){
//        this->numerator = rhs.numerator ;
//        this->denominator = rhs.denominator;
//        return this;
    }
    Fraction(__int64_t numerator, __uint64_t denominator){
        this->numerator = numerator;
        this->denominator = denominator;
    };

//    static void(Fraction& val){
//        uint64_t dcr = cancelling(val.numerator, val.denominator);
//        val.numerator=/dcr;
//        val.denuminator=/dcr;
//    };





    Fraction sum(const Fraction& val){
        Fraction result(0,1);
        result.denominator = val.denominator*denominator;
        result.numerator = val.denominator*numerator+denominator*val.numerator;
        return result;
    }
    Fraction subsrt(const Fraction& val){
        Fraction result(0,1);
        result.denominator = val.denominator*denominator;
        result.numerator = val.denominator*numerator-denominator*val.numerator;
        return result;
    }
    Fraction prod(const Fraction& val){
        Fraction result(0,1);
        result.denominator = val.denominator*denominator;
        result.numerator = val.numerator*numerator;
        return result;
    }
    Fraction divis(const Fraction& val){
        Fraction result(0,1);
        result.denominator =  val.numerator*denominator;
        result.numerator = val.denominator*numerator;
        return result;
    }

    void equal(const Fraction& val){
        Fraction result(0,1);
        this->denominator = val.denominator;
        this->numerator = val.numerator;
    }


    Fraction operator+(Fraction& val){
        return sum(val);
    }
    Fraction operator*( Fraction& val){
        return prod(val);
    }
    Fraction operator/( Fraction& val){
        return divis(val);
    }
    Fraction operator-( Fraction& val){
        return subsrt(val);
    }
    Fraction operator-(){
        return Fraction(-numerator, denominator);
    }
    Fraction operator=(const Fraction& rhs){
        equal(rhs);
        return Fraction(numerator, denominator);
    };
    string print() {
        string a;
        a+=(to_string(numerator) +"/" + to_string(denominator));
        return a;
    }

};

ostream& operator<<(ostream &os, Fraction &first){
    return os << first.print();
}




int main(){
    Fraction a(1,3);
    Fraction b(2,3);
    Fraction c = a + b;
    cout << c;
}