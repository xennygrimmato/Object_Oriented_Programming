/*
    __OPERATOR OVERLOADING__
    
    SYNTAX:
    
    binary operators:    class_name operator << (classname& obj)
    unary prefix:        class_name operator ! ()
    unary postfix:       class_name operator -- (int)
    
    NOTE: 1. We pass an 'int' as a dummy argument for overloading a unary operator in a postfix manner.
             This syntax was chosen by the creator for disambiguation.
          2. Only '++' and '--' can overloaded in both - prefix and well as postfix ways.
    
    USEFUL INFORMATION:
    
    * This program uses a class named 'superhero'.
    * Every superhero has a power, whose default value is 100.
    * input_power() can be used to assign a power to that superhero.
    * operator '<<'
        . It is a binary operator that is overloaded.
        . It sums the powers of two superheroes and then doubles it.
    * operator '--'
        . It is overloaded first as a prefix and then as postfix.
        . It negates the power of a superhero.
    
*/

#include <iostream>

using namespace std;

class superhero
{
    public:
    int power;
    superhero()
    {
        power=100; // default power that a superhero is born with
    }
    void input_power()
    {
        int number;
        cin>>number;
        power=number; // assigning a custom power to superhero
    }
    superhero operator << (superhero &other) // passing other superhero as argument
    {
        superhero bazooka;
        bazooka.power = 2*(this->power + other.power); // new hero is twice as powerful as sum of both
        return bazooka;
    }
    
    superhero operator -- () // prefix
    {
        superhero neg;
        neg.power = (-1)*(this->power);
        return neg;
    }
    
    superhero operator -- (int) // postfix.
    {
        superhero neg;
        neg.power = (-1)*(this->power);
        return neg;
    }
    
};

int main()
{
    superhero first, second;
    first.input_power(); // input power of superhero 1
    second.input_power(); // input power of superhero 2
    
    superhero naya_hero = first << second;
    cout<<"( Hero 1 << Hero 2 ) = " << naya_hero.power << "\n";
    
    superhero negated = second--;
    superhero new_hero = first<<negated;
    
    cout<<"( First << (second--) ) = " << new_hero.power << "\n";
    return 0;
}
