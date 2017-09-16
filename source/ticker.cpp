#include "MicroBit.h"

MicroBit uBit;
ManagedString delimiters("\r\n");
ManagedString message("READY");

void onMessageReceived(MicroBitEvent) {
  message = uBit.serial.readUntil(delimiters);
}

void onMessageDisplayed(MicroBitEvent) {
  uBit.display.scrollAsync(message);
}

int main() {
  uBit.init();

  uBit.serial.eventOn(delimiters);

  uBit.messageBus.listen(
    MICROBIT_ID_SERIAL,
    MICROBIT_SERIAL_EVT_DELIM_MATCH,
    onMessageReceived
  );

  // Do a dummy asynchronous read to initialize/enable reading.
  uBit.serial.read(MicroBitSerialMode::ASYNC);

  uBit.messageBus.listen(
    MICROBIT_ID_DISPLAY,
    MICROBIT_DISPLAY_EVT_ANIMATION_COMPLETE,
    onMessageDisplayed
  );

  uBit.display.scrollAsync(message);

  while (true) {
    uBit.sleep(1000);
  }
}

