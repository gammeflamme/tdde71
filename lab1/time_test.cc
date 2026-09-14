#include "catch.hpp"
#include "Time.h"
#include<iostream>
#include<sstream>

using namespace std;

TEST_CASE ("Constructors and getters")
{
   SECTION("Default")
   {
      Time empty{};
      CHECK( empty.get_hour()   == 0 );
      CHECK( empty.get_minute() == 0 );
      CHECK( empty.get_second() == 0 );
   }

   SECTION("Integer")
   {
      Time t0{0,0,0};
      Time t1{12,30,30};
      Time t2{23,59,59};
      Time t3{23,59,59,999};

      CHECK_THROWS( Time{13,35,60} );
      CHECK_THROWS( Time{13,60,35} );
      CHECK_THROWS( Time{24,35,35} );
      CHECK_THROWS( Time{21,35,35,1000} );//thou
             
      CHECK( t0.get_hour()   == 0 );
      CHECK( t0.get_minute() == 0 );
      CHECK( t0.get_second() == 0 );
      CHECK( t0.get_thou() == 0 );//thou
      CHECK( t1.get_hour()   == 12 );
      CHECK( t1.get_minute() == 30 );
      CHECK( t1.get_second() == 30 );
      CHECK( t1.get_thou() == 0 );//thou
      CHECK( t2.get_hour()   == 23 );
      CHECK( t2.get_minute() == 59 );
      CHECK( t2.get_second() == 59 );
      CHECK( t3.get_hour()   == 23 );//thou
      CHECK( t3.get_minute() == 59 );//thou
      CHECK( t3.get_second() == 59 );//thou
      CHECK( t3.get_thou() == 999 );//thou
   }

   SECTION("String")
   {
      Time t0{"00:00:00"};
      Time t1{"12:30:30"};
      Time t2{"23:59:59"};
      Time t3{"23:59:59:999"};//thou

      CHECK_THROWS( Time{"13:35:60"} );
      CHECK_THROWS( Time{"13:60:35"} );
      CHECK_THROWS( Time{"24:35:35"} );
      CHECK_THROWS( Time{"22:35:35:1000"} );

      CHECK( t0.get_hour()   == 0 );
      CHECK( t0.get_minute() == 0 );
      CHECK( t0.get_second() == 0 );
      CHECK( t1.get_hour()   == 12 );
      CHECK( t1.get_minute() == 30 );
      CHECK( t1.get_second() == 30 );
      CHECK( t2.get_hour()   == 23 );
      CHECK( t2.get_minute() == 59 );
      CHECK( t2.get_second() == 59 );  
      CHECK( t3.get_hour()   == 23 );//thou
      CHECK( t3.get_minute() == 59 );//thou
      CHECK( t3.get_second() == 59 );//thou
      CHECK( t3.get_thou() == 999 );//thou
   }
}
TEST_CASE ("is_am") 
{
   Time t0{"05:00:00"};
   Time t1{"14:00:00"};
   CHECK       ( t0.is_am() );
   CHECK_FALSE ( t1.is_am() );
   
   Time t2{"12:00:00"};
   Time t3{"00:00:10"};
   CHECK       ( t2.is_am() );
   CHECK_FALSE ( t3.is_am() );
}
TEST_CASE ("to_string")
{
   Time t0{};
   Time t1{11, 59, 59};
   Time t2{12, 0, 0};
   Time t3{13, 0, 0};
   Time t4{23, 59, 59};
   Time t5{23, 59, 59, 999};//thou
   SECTION("24 hour format no argument")
   {
      CHECK( t0.to_string() == "00:00:00" );
      CHECK( t1.to_string() == "11:59:59" );
      CHECK( t2.to_string() == "12:00:00" );
      CHECK( t3.to_string() == "13:00:00" );
      CHECK( t4.to_string() == "23:59:59" );
      CHECK( t5.to_string() == "23:59:59:999" );//thou
   }
   
   SECTION("24 hour format with argument")
   {
      CHECK( t0.to_string(false) == "00:00:00" );
      CHECK( t1.to_string(false) == "11:59:59" );
      CHECK( t2.to_string(false) == "12:00:00" );
      CHECK( t3.to_string(false) == "13:00:00" );
      CHECK( t4.to_string(false) == "23:59:59" );
      CHECK( t5.to_string(false) == "23:59:59:999" );//thou
   } 

   SECTION("12 hour format")
   {
      CHECK( t0.to_string(true) == "12:00:00pm" );
      CHECK( t1.to_string(true) == "11:59:59am" );
      CHECK( t2.to_string(true) == "12:00:00am" );
      CHECK( t3.to_string(true) == "01:00:00pm" );
      CHECK( t4.to_string(true) == "11:59:59pm" );
      CHECK( t5.to_string(true) == "11:59:59:999pm" );//thou
   }
}

TEST_CASE("std operators")
{
   SECTION("Equals")
   {
      Time t0{};
      Time t1{0,0,0};
      Time t2{1,0,1};
      CHECK(t1==t0);
      CHECK_FALSE(t0 == t2);
   }
   SECTION("Not Equals")
   {
      Time t0{};
      Time t1{0,0,0};
      Time t2{1,0,0};
      Time t3{1,0,0,1}; // thou
      CHECK_FALSE(t0 != t1);
      CHECK(t0 != t2);
      CHECK(t2 != t3); //thou
   }
   SECTION("Less than")
   {
      Time t0{0,0,0};
      Time t1{1,0,0};
      Time t2{1,0,0,1};
      CHECK_FALSE(t1 < t0);
      CHECK(t1 < t2);
      CHECK(t0 < t2);
      CHECK_FALSE(t1 < t1);
   }
      SECTION("Greater than")
   {
      Time t0{0,0,0};
      Time t1{1,0,0};
      Time t2{1,0,0,1};
      CHECK_FALSE(t0 > t1);
      CHECK(t2 > t1);
      CHECK(t2 > t0);
      CHECK_FALSE(t1 > t1);
   }
      SECTION("Less than equal")
   {
      Time t0{0,0,0};
      Time t1{1,0,0};
      Time t2{1,0,0,1};
      CHECK_FALSE(t1 <= t0);
      CHECK(t1 <= t2);
      CHECK(t0 <= t2);
      CHECK(t1 <= t1);
   }
      SECTION("Greater than equal")
   {
      Time t0{0,0,0};
      Time t1{1,0,0};
      Time t2{1,0,0,1};
      CHECK_FALSE(t0 >= t1);
      CHECK(t2 >= t1);
      CHECK(t2 >= t0);
      CHECK(t1 >= t1);
   }
}

TEST_CASE("Prefix postfix") 
{
   SECTION("Prefix")
   {
      Time t0{0,0,0};
      Time t1{22,59,59};
      Time t2{23,59,59};
      CHECK((++t0).to_string() == "00:00:01");
      CHECK((t0).to_string() == "00:00:01");
      CHECK((++t1).to_string() == "23:00:00");
      CHECK((++t2).to_string() == "00:00:00");
   }
      SECTION("Postfix")
   {
      Time t0{0,0,0};
      Time t1{22,59,59};
      Time t2{23,59,59,999};
      CHECK((t0++).to_string() == "00:00:00");
      CHECK((t0).to_string() == "00:00:01");
      CHECK((t1++).to_string() == "22:59:59");
      CHECK((t1).to_string() == "23:00:00");
      CHECK((t2++).to_string() == "23:59:59:999");
      CHECK((t2).to_string() == "00:00:00:999");
   }
}
TEST_CASE("Ostream")
{
   Time t1{22,59,59};
   std::ostringstream stream{"test"};
   //std::ostream stream{};
   t1 << std::cout << std::endl;
   t1 >> std::cout << std::endl;
   //std::cout << t1;
   //stream << t1;

}
//Fill with more tests of other functions and operators!
