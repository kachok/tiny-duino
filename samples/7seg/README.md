README
------

So tiny-circuits.com has this cool board called the TinyDuino which is a 
really small Arduino, and some really small shields to go with it. I got
one and the 7 segment display (2 digits) at the Bay Area Maker faire and
was trying to use it.

Only the web site had little documentation and no working example. After
reading the data sheet for the IO Expander chip 
[here](http://www.semtech.com/images/datasheet/sx150x_456.pdf) I wrote
this little demo to prove my understanding.

Key points, you write a '0' bit to turn the LED on, my code does an exclusive
or to flip the bits before writing so that I can program in 'postive' logic
and have it write in negative logic. Second is that the LSB is connected to
segment A the MSB to the decimal point. All 7-segment displays have a standard
A-G order for segments so that will tell you what bit pattern to send to turn
on certain segments. As you can see I've done a HEX decoder (16 bit patterns
for the digits 0,1,2,3,4,5,6,7,8,9,A,b,C,d,E,F)

