#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

#define DEBOUNCE_DURATION 7 // time for the button to settle in ms
#define HOLD_DURATION 700 // time for the button hold action detection in ms

enum ButtonState : int
{
	RELEASED,
	PRESSED,
	HELD
};

class PushButton;
typedef void(*OnButtonEventFnc)(ButtonState, PushButton*);

class PushButton
{
	int _pin;
	volatile ButtonState _currBtn;
	ButtonState  _prevBtn;
	bool _btnHeld;
	volatile unsigned long int _btnT;
	OnButtonEventFnc _onButtonF;
public:
	PushButton(int pin, OnButtonEventFnc onButtonF);
	static void HandleInterrupt(void* param);
	void Simulate();
	bool IsButtonPessed() const;
	bool isButtonHeld() const;
};


#endif /* PUSHBUTTON_H */
