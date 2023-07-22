#include <iostream>
#include <sstream>

//! Macros
#define C_HAS_1_MEMBER( STRUCT_N, MEMBER_N1 ) \
template <typename T, typename = void> \
struct STRUCT_N : std::false_type {}; \
template <typename T> \
struct STRUCT_N<T , std::void_t<decltype( std::declval<T>( ).MEMBER_N1 )>> : std::true_type {};

#define C_HAS_2_MEMBERS( STRUCT_N, MEMBER_N1, MEMBER_N2 ) \
template <typename T, typename = void> \
struct STRUCT_N : std::false_type {}; \
template <typename T> \
struct STRUCT_N<T , std::void_t<decltype( std::declval<T>( ).MEMBER_N1 ) , \
decltype( std::declval<T>( ).MEMBER_N2 )>>: std::true_type {};

#define C_HAS_3_MEMBERS( STRUCT_N, MEMBER_N1, MEMBER_N2, MEMBER_N3 ) \
template <typename T, typename = void> \
struct STRUCT_N : std::false_type {}; \
template <typename T> \
struct STRUCT_N<T , std::void_t<decltype( std::declval<T>( ).MEMBER_N1 ), \
decltype( std::declval<T>( ).MEMBER_N2 ), decltype( std::declval<T>( ).MEMBER_N3 )>>: std::true_type {}; 

#define C_CHECK( Classname , _HAS_X_MEMBERS ) \
namespace TASK::TESTER{ using Classname = No; } \
template <typename T> \
bool _HAS_X_MEMBERS##_check_members( ) { \
 if (_HAS_X_MEMBERS<T>::value) { \
        std::cout << "+  > Found its Members" << std::endl; \
        return true;} else { \
        std::cout << "-  > Members not found" << std::endl; \
        return false;} } \
template <typename T> \
bool check_##Classname( ) { \
    return ( check_class<T>( ) && _HAS_X_MEMBERS##_check_members<T>( ) );} 

#define C_OUTPUT() \
template <typename T> \
bool check_output( T&& main_call , const std::string& expectedOutput ) { \
    std::stringstream output_stream; \
    std::streambuf* std_buffer = std::cout.rdbuf( output_stream.rdbuf( ) ); \
    ( main_call )( ); \
    std::cout.rdbuf( std_buffer ); \
    std::string STUDENTOutput = output_stream.str( ); \
    if ( STUDENTOutput == expectedOutput ) { \
        std::cout << "+ Student Output correct" << std::endl; \
        return true; } else { \
        std::cout << "- Student Output incorrect" << std::endl; \
        std::cout << "- Expected Output: " << expectedOutput << std::endl; \
        std::cout << "-  Student Output: " << STUDENTOutput << std::endl; \
        return false; }} 

#define C_CLASS_HANDLING() \
template <typename T> \
bool check_class( ) { \
    if ( !std::is_same<T , TASK::TESTER::No>::value ) { \
        std::string strClassN = typeid( T ).name( ) , strClassNreadable {}; \
        strClassN = strClassN.erase( 0 , 9 ); \
        for ( int i = 0; i < strClassN.length( ); ++i ) { \
            if ( std::isdigit( strClassN [ i ] ) ) { \
                if ( !std::isdigit( strClassN [ i + 1 ] ) ) { \
                    strClassNreadable = strClassN.substr( i + 1 ); } } } \
        strClassNreadable.pop_back( ); \
        std::cout << "+ " << strClassNreadable << " found" << std::endl; \
        return true; } else { \
        std::cout << "- Class in Assignment not found. " << std::endl; \
        std::cout << "-  > Members not found" << std::endl; \
        return false; }} 

#define C_MAIN( ExpectedOutput , check_Classname1 , check_Classname2 , check_Classname3 , check_Classname4 , check_Classname5 ) \
void evaluation( const std::string& expectedOutput ,const bool& Bt1 , const bool& Bt2 , \
    const bool& Bt3 , const bool& Bt4 , const bool& Bt5 ) { \
    if ( Bt1 && Bt2 && Bt3 && Bt4 && Bt5 ) { \
        if ( check_output( *( STUDENT::main ) , expectedOutput ) ) { \
            std::cout << std::endl; \
            std::cout << "+ + Student did great Job! + +\n" << std::endl; }} \
    else { std::cout << std::endl; \
        std::cout << "- Student forgot a Member inside a Class!\n" << std::endl; }} \
namespace STUDENT::TASK { using namespace ::TASK::TESTER; \
void testing( ) { \
        bool Bt1 = check_Classname1; bool Bt2 = check_Classname2; bool Bt3 = check_Classname3; \
        bool Bt4 = check_Classname4; bool Bt5 = check_Classname5; \
        std::string expectedOutput = ExpectedOutput; \
        ::evaluation( expectedOutput , Bt1 , Bt2 , Bt3 , Bt4 , Bt5 ); }} \
int main( ) { STUDENT::TASK::testing( ); return 0; }

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
namespace TASK::TESTER { struct No {}; }
C_OUTPUT( )
C_CLASS_HANDLING( )
//! Custom Settings
C_HAS_1_MEMBER( checks_MyClassX , printed( ) )
C_HAS_2_MEMBERS( checks_MyClassY , printed , IDE( ) )
C_HAS_3_MEMBERS( checks_MyClassZ , OHM( ) , AMP , VOLT )
C_CHECK( MyClassX , checks_MyClassX )
C_CHECK( MyClassY , checks_MyClassY )
C_CHECK( MyClassZ , checks_MyClassZ )
//! Mains
C_MAIN( "Printed...\n" , check_MyClassX<MyClassX>( ) , check_MyClassY<MyClassY>( ) , check_MyClassZ<MyClassZ>( ) , true , true )