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

