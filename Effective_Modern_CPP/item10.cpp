//Item 10 : Prefer scoped enums to unscoped enums

//범위 있는 enum => enum class!!
enum class Color //enum 안에있는 것들은 Color 범위에 속한다.
{
	black,
	white,
	red
};

auto white = false;
//Color c = white; 오류 해당 범위에는 white가 없다.
Color c = Color::white;
auto c = Color::white;

//enum class는 암묵적으로 정수 형식으로 바뀌는 것을 방지해준다.

//enum class는 전방 선언이 가능하다.
//enum을 전방선언 할 수 없을때..
enum Status
{
	good = 0,
	failed = 0,
	incomplete = 100,
	corrupt = 200,
	//audited = 500, 추가시 전체가 새로 컴파일 해야한다.
	indeterminate = 0xFFFFFFFF
};


//범위 있는 enum의 기본 형식은 int이다.
#include<cstdint>
enum class Status2; //int 형식
enum class Status3 : std::uint32_t; //강제로 형식 변환

//범위 없는 enum의 기본 형식은 std::uint8_t이다.
enum Color2 : std::uint8_t;


//범위 없는 enum이 사용될 때 : std::tuple 안에 있는 필드들을 지칭할 때
#include<tuple>
#include<string>
using UserInfo = std::tuple<std::string, std::string, std::size_t>;

UserInfo uInfo;
auto value = std::get<1>(uInfo); //1이 가리키는 것이 무엇인지 알기 어렵다.

enum UserInfoFields { uiName, uiEmail, uiReputation };

auto value = std::get<uiName>(uInfo); //1 대신 가리키는 것이 무엇인지 명확하다.(enum class 쓰면 너무 복잡해짐)

