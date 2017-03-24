#include <iostream>


enum class Unit:int{km=1000000, m=100, cm=1};

template<int v, Unit u>
struct Measure{    
	static const int value = v;
    static  const Unit unit = u;//should call the unit type from the Unit enum.
	
};
template<typename L1, typename L2>
struct Measure_add{
	static const int r = int (L1::unit)/int(L2::unit);
	static const Unit unit = (r>1 ? L2::unit : L1::unit);
	static const int value = L1::value*int(L1::unit)/int(unit) + L2::value*int(L2::unit)/int(unit) ;
	
};
int main()
{
    std::cout << Measure_add< Measure<10,Unit::cm>, Measure<20,Unit::m> >::value  << std::endl;
    std::cout << Measure_add< Measure<10,Unit::m>, Measure<20,Unit::cm> >::value << std::endl;

    return 0;
}