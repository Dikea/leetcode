#define CATCH_CONFIG_MAIN
#include "../../Catch/include/catch.hpp"
#include "solution.h"

TEST_CASE("Regular Expression Matching", "isMatch")
{
	Solution s;
	REQUIRE( s.getPermutation(3, 1)== "123" );
	REQUIRE( s.getPermutation(3, 2)== "132" );
	REQUIRE( s.getPermutation(4, 1)== "1234" );
}
	
