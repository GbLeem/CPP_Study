//private ���
class Timer
{
public:
	explicit Timer(int tickFrequency);

	virtual void onTick() const;
};

class Widget : private Timer //Widget Ŭ�������� Timer Ŭ������ �����Լ��� ������ �ؾ�������, is-a ����� �ƴϴ�.
{
private:
	virtual void onTick() const;
};


// public ��Ӱ� ��ü �ռ� ->  �� ���� �����
class Widget2
{
private:
	class WidgetTimer :public Timer
	{
	public:
		virtual void onTick() const;
	};

	WidgetTimer timer;
};