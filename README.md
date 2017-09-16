# calliope-ticker

calliope-ticker is a small application for the
[Calliope mini](http://www.calliope.cc/) that can be used to display messages
on a Calliope mini. The messages are sent from a PC to the mini over a serial
port and displayed on the minis 5 x 5 LED display.

A message is a string of characters terminated by a newline character. When
the mini receives a message it will continuously display that message until
the next message is received.

## Compiling

```
yotta build
```

Note that the compile step is optional as the compiled hex file
`calliope-ticker-combined.hex` is provided in the `firmware` directory.

## Flashing

Copy `calliope-ticker-combined.hex` onto the board.

## Example - Digital Clock

There's an example Node.js program in the `example` directory. The example
requires Node.js 8. It sends messages containing the current time from the PC
on which it run to the mini over a serial port.

The example program may need to be tweaked in order to get it to work on your
computer. For example, the path `/dev/ttyACM0` for the serial port may need to
be modified.

```js
var SerialPort = require('serialport');
var port = new SerialPort('/dev/ttyACM0', {
  baudRate: 115200
});

setInterval(function () {
  var date = new Date();

  port.write(
    date.getHours().toString().padStart(2, '0') +
    ':' +
    date.getMinutes().toString().padStart(2, '0') +
    '\n'
  );
}, 1000);
```

To run the example `cd` to the `example` directory and run the following
command to install the required Node.js modules.

```
npm install
```

Then run the Node.js application with the following command.

```
node digital-clock
```


