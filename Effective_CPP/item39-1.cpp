class Person
{

};

class Student :private Person
{

};

void eat(const Person& p);
void study(const Student& s);

int main()
{
	Person p;
	Student s;

	eat(p);
	//eat(s); ����-> private ��� :  �Ļ� Ŭ���� ��ü�� �⺻ Ŭ���� ��ü�� ��ȯ���� ����
								 // �⺻ Ŭ�����κ��� �������� ����� �Ļ�Ŭ�������� private ����� �ȴ�
	//-> private ����� �ǹ̴� is-implemented-in-terms-of �̴�.
	//private ����� ����� ����� ���� / ���� �Լ��� ������ �Ҷ� private ��� ����ϰ� �������� is-implemented-in-terms-of ���
}