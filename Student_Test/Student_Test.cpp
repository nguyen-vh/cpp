// Works at least up to c++23

#include <iostream>
#include <sstream>
// Headers which might needed to be included: 
// <string>, <cctype>, <typeinfo>, <type_traits>, <utility>


//! STUDENT Code


namespace STUDENT {

//* Students code starts here . . .


    //#include <iostream>   // Commented out because formatter doing weird formatting 

    using namespace std;

    class MyClassX {
        public:
        void printed( ) { cout << "Printed..." << endl; }
        };

    class MyClassY {
        public:
        int printed;
        int IDE( ) { return 0; };
        };

    class MyClassZ {
        public:
        void OHM( ) {};
        double AMP;
        float VOLT;
        };

    void SomeFunctionX( ) {}

    int main( ) {
        MyClassX x;
        x.printed( );
        return 0;
        }


//* Student code ends here.

    }

//=// End of STUDENT Code


//! Macros

//* SFINAE check of Members inside of a Class 
// @param STRUCT_N Templatename @param MEMBER_N Membername

#define C_HAS_1_MEMBER( STRUCT_N, MEMBER_N1 ) \
template <typename T, typename = void> \
struct STRUCT_N : std::false_type {}; \
\
template <typename T> \
struct STRUCT_N<T , decltype( void( std::declval<T>( ).MEMBER_N1 ) )> : std::true_type {};

#define C_HAS_2_MEMBERS( STRUCT_N, MEMBER_N1, MEMBER_N2 ) \
template <typename T, typename = void> \
struct STRUCT_N : std::false_type {}; \
\
template <typename T> \
struct STRUCT_N<T , std::void_t<decltype( std::declval<T>( ).MEMBER_N1 ) , \
decltype( std::declval<T>( ).MEMBER_N2 )>>: std::true_type {};

#define C_HAS_3_MEMBERS( STRUCT_N, MEMBER_N1, MEMBER_N2, MEMBER_N3 ) \
template <typename T, typename = void> \
struct STRUCT_N : std::false_type {}; \
\
template <typename T> \
struct STRUCT_N<T , std::void_t<decltype( std::declval<T>( ).MEMBER_N1 ), \
decltype( std::declval<T>( ).MEMBER_N2 ), decltype( std::declval<T>( ).MEMBER_N3 )>>: std::true_type {}; 


//* Output of C_HAS_MEMBER
// @param NAME Funktionname @param STRUCT_N Name of Template to call

#define C_CHECK_MEMBER( NAME, STRUCT_N ) \
template <typename T> \
bool NAME( ) { \
 if (STRUCT_N<T>::value) { \
        std::cout << "+  > Found its Member" << std::endl; \
        return true;} else { \
        std::cout << "-  > Member not found" << std::endl; \
        return false;} } 


#define C_CHECK_MEMBERS( NAME, STRUCT_N ) \
template <typename T> \
bool NAME( ) { \
 if (STRUCT_N<T>::value) { \
        std::cout << "+  > Found its Members" << std::endl; \
        return true;} else { \
        std::cout << "-  > Members not found" << std::endl; \
        return false;} } 


//* Dummy Class
// @param CLASS_N Classname in Assignment

#define C_DUMMY_CLASS( CLASS_N ) \
namespace TASK::TESTER{ using CLASS_N = No; } 


//* T_Check Call
// @param NAME Functionname @param CHECK_MEMBER Name of C_CHECK_MEMBER

#define C_T_CHECK( NAME, CHECK_MEMBER ) \
template <typename T> \
bool NAME( ) { \
    return ( check_class<T>( ) && CHECK_MEMBER<T>( ) );} 


//=// End of Macros


//! Dummy Classes


namespace TASK::TESTER { struct No {}; }

C_DUMMY_CLASS( MyClassX )

C_DUMMY_CLASS( MyClassY )

C_DUMMY_CLASS( MyClassZ )

//=// End of Dummy Classes


//! SFINAE Templates for Members inside a Class


C_HAS_1_MEMBER( checks_for_ClassX , printed( ) )

C_HAS_2_MEMBERS( checks_for_MyClassY , printed , IDE( ) )

C_HAS_3_MEMBERS( checks_for_MyClassZ , OHM( ) , AMP , VOLT )

//=// End of SFINAE Templates for Members inside a Class


//! STUDENT::main Output-Handling
// @param main_call Executes the program inside namespace STUDENT
// @param expectedOutput Text which needs to match
// @param output_stream Temporary buffer for all std::cout
// @param std_buffer Normal buffer
//? Buffs the std::cout output and compares

template <typename T>
bool check_output( T&& main_call , const std::string& expectedOutput ) {
    std::stringstream output_stream;
    std::streambuf* std_buffer = std::cout.rdbuf( output_stream.rdbuf( ) );

    ( main_call )( );

    std::cout.rdbuf( std_buffer );

    std::string STUDENTOutput = output_stream.str( );

    if ( STUDENTOutput == expectedOutput ) {
        std::cout << "+ Student Output correct" << std::endl;
        return true;
        }
    else {
        std::cout << "- Student Output incorrect"
            << std::endl;
        std::cout << "- Expected Output: " << expectedOutput << std::endl;
        std::cout << "-  Student Output: " << STUDENTOutput << std::endl;
        return false;
        }
    }

//=// End of STUDENT::main Output-Handling


//! Check Members + Output


C_CHECK_MEMBER( check_Member_MyClassX , checks_for_ClassX )

C_CHECK_MEMBERS( check_Members_MyClassY , checks_for_MyClassY )

C_CHECK_MEMBERS( check_Members_MyClassZ , checks_for_MyClassZ )

//=// End of Check Members + Output


//! Class-Handling
// @param strClassReadable Only name of Class
//? Checks if the Class in Assignment is in namespace STUDENT and demangles the Classname

template <typename T>
bool check_class( ) {

    if ( !std::is_same<T , TASK::TESTER::No>::value ) {
        std::string strClassN = typeid( T ).name( ) , strClassNreadable {};
        strClassN = strClassN.erase( 0 , 9 );

        for ( int i = 0; i < strClassN.length( ); ++i ) {
            if ( std::isdigit( strClassN [ i ] ) ) {
                if ( !std::isdigit( strClassN [ i + 1 ] ) ) {
                    strClassNreadable = strClassN.substr( i + 1 );
                    }
                }
            }
        strClassNreadable.pop_back( );

        std::cout << "+ " << strClassNreadable << " found" << std::endl;
        return true;
        }
    else {
        std::cout << "- Class in Assignment not found. " << std::endl;
        std::cout << "-  > Members not found" << std::endl;
        return false;
        }
    }

//=// End of Class-Handling


//! Check Class + Members


C_T_CHECK( t_check_MyClassX , check_Member_MyClassX )

C_T_CHECK( t_check_MyClassY , check_Members_MyClassY )

C_T_CHECK( t_check_MyClassZ , check_Members_MyClassZ )

//=// End of Check Class + Members


//! Main Execution of the Program


//* Final Output
//? If all conditions are true the task has been solved successfully

void evaluation( const std::string& expectedOutput ,
                         const bool& Bt1 , const bool& Bt2 ,
                         const bool& Bt3 , const bool& Bt4 ,
                         const bool& Bt5 ) {
    if ( Bt1 && Bt2 && Bt3 && Bt4 && Bt5 ) {
        if ( check_output( *( STUDENT::main ) , expectedOutput ) ) {
            std::cout << std::endl;
            std::cout << "+ + Student did great Job! + +\n" << std::endl;
            }
        }
    else {
        std::cout << std::endl;
        std::cout << "- Student forgot a Member inside a Class!\n" << std::endl;
        }
    }


//* Class-Call
//? Input of the to test templates and text of expected Output

namespace STUDENT::TASK {
    using namespace ::TASK::TESTER;
    void testing( ) {

        // Fill unused ones with true
        bool Bt1 = t_check_MyClassX<MyClassX>( );
        bool Bt2 = t_check_MyClassY<MyClassY>( );
        bool Bt3 = t_check_MyClassZ<MyClassZ>( );
        bool Bt4 = true;
        bool Bt5 = true;

        // Always end with "\n"
        std::string expectedOutput = "Printed...\n";


        ::evaluation( expectedOutput , Bt1 , Bt2 , Bt3 , Bt4 , Bt5 );
        }

    }


//* Real Main


int main( ) {
    STUDENT::TASK::testing( );
    return 0;
    }

//=// End of Main Execution of the Program

//===// End of Program

/*
*   Summary of what is needed for a membercheck inside a class
*
*   1.  Create a Dummy Class with C_DUMMY_CLASS() and the name of the assignment class
*   2.1 Create a C_HAS_MEMBERS with as many Members you want the class need to have
*   2.2 e.x. C_HAS_2_MEMBERS( checks_for_MyClassY , printed , IDE() ) Templatename is now checks_for MyClassY
*       and we are checking for Variable printed and Function IDE()
*   3.  Create C_CHECK_MEMBERS() with a name and the Templatename from 2.
*   4.  Create a C_CHECK() which needs a name and the Templatename from 3.
*   5.  In Class-Call(line 263) insert the Templatecall from 4. and call with the class you want to check
*   6.  Insert the Output you want to have and end with \n in expectedOutput
*
*   Notes:  -Only Classes inside of namespace STUDENT will be tested
*           -Output can only be checked if there is an output call in namespace STUDENT
*
*/