#include <Arduino.h>
#include "PushButton.h"


PushButton::PushButton(int pin, OnButtonEventFnc onButtonF) 
	: _pin(pin), _currBtn(ButtonState::RELEASED), _prevBtn(ButtonState::RELEASED), _btnHeld(false), _btnT(0), _onButtonF(onButtonF)
{
	if (_pin >= 0 && _onButtonF)
		attachInterruptParam(digitalPinToInterrupt(_pin), &PushButton::HandleInterrupt, CHANGE, this);
}

void PushButton::HandleInterrupt(void* param)
{
	PushButton* button = static_cast<PushButton*>(param);
	button->_btnT = millis();
	button->_currBtn = digitalRead(button->_pin) == LOW ? ButtonState::PRESSED : ButtonState::RELEASED;
}

void PushButton::Simulate()
{
	if (_onButtonF)
	{
		if (_currBtn != _prevBtn && millis() - _btnT > DEBOUNCE_DURATION)
		{
			_onButtonF(_prevBtn = _currBtn, this);
			if (_btnHeld && _prevBtn == ButtonState::RELEASED)
				_btnHeld = false;
		}

		if (_prevBtn == ButtonState::PRESSED && !_btnHeld && millis() - _btnT > HOLD_DURATION)
		{
			_btnHeld = true;
			_onButtonF(ButtonState::HELD, this);
		}
	}
}

bool PushButton::IsButtonPessed() const
{
	return _prevBtn != ButtonState::RELEASED;
}

bool PushButton::isButtonHeld() const
{
	return _btnHeld;
}
