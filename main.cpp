#include <iostream>

using namespace std;

/*
template<typename T>
void Print(std::initializer_list<T> args) // the problem with initalization list is that all params have to be the same type
{
    for(const auto& x: args)
    {
        cout << x << "" ;
    }
    cout << endl;
}
*/


//Base case to stop recursion
void Print()
{
    cout << endl;
}

//Template paramater pack
template<typename T, typename... Params>
//function parameter pack
void Print(T &&a, Params&&... args)
{
    if( sizeof...(args) != 0 )
        cout << a << ",";
    else
        cout << a;
    
    Print(std::forward<Params>(args)...); // Example how to use Perfect forwarding!!
}




int main() {

    Print(1, 2, 3, 4);
       
	return 0;
}
