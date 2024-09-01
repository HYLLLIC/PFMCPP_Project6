/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
    Not every pointer can be converted.
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference and don't change the return type either.

    You have to ask yourself if each pointer can be converted to a (const) reference.
    Think carefully when making your changes.

 2) revise the 'else' statement in main() that handles when `smaller` is a nullptr. 
 there is only one reason for `compare` to return nullptr. 
 Update this std::cout expression to specify why nullptr was returned.
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>

struct T
{
    T(int v, const char* w) : value(v), name(w) {}

    int value;
    std::string name;
};

struct Comparison
{
    T* compare(T& a, T& b)
    {
        if( a.value < b.value ) return &a;
        if( a.value > b.value ) return &b;
        return nullptr;
    }
};

struct U
{
    float a { 0 }, b { 0 };
    float makeCloser(float& newValue)
    {
        std::cout << "U's a value: " << a << std::endl;
        a = newValue;
        std::cout << "U's updated a value: " << a << std::endl;
        while( std::abs(b - a) > 0.001f )
        {
            if (b < a) 
            {
                b += 1.0f;
            }
            else
            {
                b -= 0.01f;
            }
        }
        std::cout << "U's b updated value: " << b << std::endl;
        return a * b;
    }
};

struct Closer
{
    static float getCloser(U& that, float& newValue )
    {
        std::cout << "U's a value: " << that.a << std::endl;
        that.a = newValue;
        std::cout << "U's a updated value: " << that.a << std::endl;
        while( std::abs(that.b - that.a) > 0.001f )
        {
            if (that.b < that.a)
            {
                that.b += 1.0f;
            }
            else
            {
                that.b -= 0.01f;
            }
        }
        std::cout << "U's b updated value: " << that.b << std::endl;
        return that.b * that.a;
    }
};
        
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    T test1(1, "x");
    T test2(2, "y");
    
    Comparison f;
    auto* smaller = f.compare(test1, test2);
    if(smaller != nullptr)
    {
        std::cout << "The smaller one is: " << smaller->name << std::endl;
    }
    else
    {
        std::cout << "the values of " << test1.name << " and " << test2.name << " are the same" << std::endl;
    }
    
    U test3;
    float updatedValue = 5.f;
    std::cout << "[static func] test3's multiplied values: " << Closer::getCloser(test3, updatedValue) << std::endl;        
    
    U test4;
    std::cout << "[member func] test4's multiplied values: " << test4.makeCloser( updatedValue ) << std::endl;
}
