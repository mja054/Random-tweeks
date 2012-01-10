var tty = require('tty');
tty.setRawMode(true);

console.log(tty.getWindowSize(process.stdin))
process.stdin.resume();
process.stdin.on('data', function(char, chunk) {
 process.stdout.write('data: ' + chunk);
 if (chunk.name == 'c')
        process.stdout.write('enter');
        return;
});
