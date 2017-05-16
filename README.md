# tm-trame-poc
a proof of concept of telemetry trame

trame overview :

timestamp,gps:lat,   gps:long   magn:x,magn:y,magn:z,acc:x, acc:y, acc:z, gyr.x, gyr.y, gyr.z

trame width calculation detail:

33.551998              =>  8 digit 
-40.741895,-73.989308, =>  16 digit (8 x 2) + 2 sign
100.00,200.00,300.00,  =>  15 digit (5 x 3) + 3 sign
400.00,500.00,600.00,  =>  15 digit (5 x 3) + 3 sign
700.00,800.00,900.00,  =>  15 digit (5 x 3) + 3 sign
===============================================
#total                      69 digit         +11 sign
                         = 80 symbol

8      => 28 bits          / 32bits
16 + 2 => 55 bits + 2 bits / 64bits 
15 + 3 => 51 bits + 3 bits / 64bits
15 + 3 => 51 bits + 3 bits / 64bits
15 + 3 => 51 bits + 3 bits / 64bits

====== 247bits(256)= 32bytes / 288bits= 36bytes
