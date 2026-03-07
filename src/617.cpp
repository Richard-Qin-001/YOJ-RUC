#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Event {
	private:
		char event;
		int  x, y;
		int  extra;
	public:
		Event() = delete;
		Event(char e, int a, int b, int d) : 
			event(e), x(a), y(b), extra(d) {}
		Event(const Event &) {cout << "Should Not Be Here\n";} 
		Event(Event &)  {cout << "Should Not Be Here\n";} 
		int getX() const {return x;}
		int getY() const {return y;}
		char getEvent() const {return event;}
		int getExtra() const {return extra;}
};

// ____qcodep____
class EventListener
{
public:
    void fire(const Event &event);
};

class OnClickListener : virtual public EventListener
{
public:
    static void onClick(const Event &event);
};

class OnDragListener : virtual public EventListener
{
public:
    static void onDrag(const Event &event);
};

std::ostream& operator<<(std::ostream& os, const Event& event){
    int event_extra = event.getExtra();
    if(event_extra == 0){
        os << "[" << event.getEvent() << " at (" << event.getX() << "," << event.getY() << ")]";
    }
    else {
        os << "[" << event.getEvent() << " at (" << event.getX() << "," << event.getY() << ") with extra " << event_extra << "]";
    }
    
    return os;
}

// complete the function definition
// void OnClickListener::onClick ____qcodep____
void OnClickListener::onClick(const Event& event){
    cout << "Click is happening at ("<< event.getX() << "," << event.getY() << ")" << endl;
}

// complete the function definition
// void OnDragListener::onDrag ____qcodep____
void OnDragListener::onDrag(const Event &event)
{
    char dir = ' ';
    switch (event.getExtra())
    {
    case 1:
        dir = 'E';
        break;
    case 2:
        dir = 'W';
        break;
    case 3:
        dir = 'S';
        break;
    case 4:
        dir = 'N';
        break;
    }
    cout << "Drag is happening at (" << event.getX() << "," << event.getY() << ") with direction " << dir << endl;
}
// complete the function definition
// void EventListener::fire ____qcodep____
void EventListener::fire(const Event &event)
{
    char event_type = event.getEvent();
    if (event_type == 'C'){
        OnClickListener::onClick(event);
    }
    else if (event_type == 'D'){
        OnDragListener::onDrag(event);
    }
    else{
        cout << "Unrecognized Event: " << event << endl;
    }
}

class Button : public OnClickListener, public OnDragListener {
};

int main() {
	int n;
	cin >> n;
	Button button;
	for (int i = 0; i < n; i++) {
		char C;
		int X, Y, E;
		cin >> C >> X >> Y >> E;
		Event event(C, X, Y, E);
		cout << "Fetch Event: " << event << endl;
		EventListener &listener = button;
		listener.fire(event);
	}
	return 0;
}

