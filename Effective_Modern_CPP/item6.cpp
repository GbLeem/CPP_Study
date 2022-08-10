//Item 6 : Use the exlpicitly typed initializer idiom when auto deduces undesired types

//invisible proxy class�� auto�� ��︮�� �ʴ´�.
//auto�� �����ϱ� ������ invisible proxy class�� �Ÿ��� ����� ã�ƺ���
//-> Ŭ���̾�Ʈ�� ȣ���ϵ��� ������� � �Լ��� �����ָ�, �ش� �Լ��� ������ ���� Ȯ�� �����ϴ�.

//auto�� �ٸ� �������� deducing ���Ѿ� �Ѵ�.
#include<vector>
class Widget{};

std::vector<bool> features(const Widget& w);

int main()
{
	Widget w;
	//bool highPriority = features(w)[5]; ���� ����
	//auto highPriority = features(w)[5]; ���� �߻�
	auto highPriority = static_cast<bool>(features(w)[5]); //���� ĳ�������� ���� �ذ�
	processWidget(w, highPriority);
}