//Item 10 : Prefer scoped enums to unscoped enums

//���� �ִ� enum => enum class!!
enum class Color //enum �ȿ��ִ� �͵��� Color ������ ���Ѵ�.
{
	black,
	white,
	red
};

auto white = false;
//Color c = white; ���� �ش� �������� white�� ����.
Color c = Color::white;
auto c = Color::white;

//enum class�� �Ϲ������� ���� �������� �ٲ�� ���� �������ش�.

//enum class�� ���� ������ �����ϴ�.
//enum�� ���漱�� �� �� ������..
enum Status
{
	good = 0,
	failed = 0,
	incomplete = 100,
	corrupt = 200,
	//audited = 500, �߰��� ��ü�� ���� ������ �ؾ��Ѵ�.
	indeterminate = 0xFFFFFFFF
};


//���� �ִ� enum�� �⺻ ������ int�̴�.
#include<cstdint>
enum class Status2; //int ����
enum class Status3 : std::uint32_t; //������ ���� ��ȯ

//���� ���� enum�� �⺻ ������ std::uint8_t�̴�.
enum Color2 : std::uint8_t;


//���� ���� enum�� ���� �� : std::tuple �ȿ� �ִ� �ʵ���� ��Ī�� ��
#include<tuple>
#include<string>
using UserInfo = std::tuple<std::string, std::string, std::size_t>;

UserInfo uInfo;
auto value = std::get<1>(uInfo); //1�� ����Ű�� ���� �������� �˱� ��ƴ�.

enum UserInfoFields { uiName, uiEmail, uiReputation };

auto value = std::get<uiName>(uInfo); //1 ��� ����Ű�� ���� �������� ��Ȯ�ϴ�.(enum class ���� �ʹ� ��������)

