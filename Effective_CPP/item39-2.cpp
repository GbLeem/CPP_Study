//private 상속
class Timer
{
public:
	explicit Timer(int tickFrequency);

	virtual void onTick() const;
};

class Widget : private Timer //Widget 클래스에서 Timer 클래스의 가상함수를 재정의 해야하지만, is-a 관계는 아니다.
{
private:
	virtual void onTick() const;
};


// public 상속과 객체 합성 ->  더 많이 사용함
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