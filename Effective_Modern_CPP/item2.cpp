//item2 : understand auto type deduction

//case1 : type specifier is a pointer or reference but not universal reference
//case2 : type specifier is universal reference
//case3 : type specifier is neither a pointer nor a reference 

auto x = 27;	    //case3
const auto cx = x;  //case3
const auto& rx = x; //case1