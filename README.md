# PushButton
 A simple class to handle multiple push buttons
This simple PushButton class will execute given function passing button state (0 - released, 1 - pressed, 2 - held) and the class instance.
For best results, wire the button as shown in debounce-sch.png (see https://hackaday.com/2015/12/09/embed-with-elliot-debounce-your-noisy-buttons-part-i/ for more info)
Requires attachInterruptParam function, not all boards have it.
