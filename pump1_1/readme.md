# Pump 1.1 - Improvement on pump presented in Behrens et al. 2020

This is the updated design, which is easier to use, more robust, and cheaper. As of this writing, pump 1.1 is about $100 cheaper to build per unit than pump 1.0.

Here you can find the STL files for 3D printing pump 1.1. The STL files included here are rendered in millimeters.

# Major updates between pump 1.1 and pump 1.0

- The sizes of ball bearing used are more common, so they are much cheaper to purchase. The number of ball bearing used has also been reduced.
- The rotor design is improved to make it easier to build.
- The tube clamp design is improved to create more reproducable clamping pressure on the tubing.
- A stock D-profile shaft is used so there is no need to grind a D prifile into the end of the rotor shaft. 
- A 3D printed shaft pusher tool is included to make it easy to fine tune the position of the rotor on the rotor shaft to align it with the tubing.

# Bill of Materials
This list provides suggestions for what to purchase if you would like to build a pump yourself. However, these links might break, or the prices might change since I wrote this, so you might have to swap these parts out for equivalent ones. This list should still point you in the right direction. Some items here are bought in bulk, so if you are building multiple pumps you could save some money. 

| Item  | Quantity | Price | Link |
| ------------- | ------------- | ------------- | ------------- |
| NEMA 17 40mm 1.8° stepper motor  | 1 | $10.99 | [Amazon](https://www.amazon.com/Twotrees-Nema17-Stepper-17HS4401S-Printer/dp/B07Y2SVNGP/ref=sr_1_1_sspa?crid=3BSQJ65Y5G0XZ&keywords=nema%2B17%2Bstepper%2Bmotor&qid=1642617029&sprefix=nema%2B17%2Bste%2Caps%2C56&sr=8-1-spons&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUFGSUpRQ0o0VDZNNFAmZW5jcnlwdGVkSWQ9QTAyMzMzMzNBSERSMDRZWlI5MlMmZW5jcnlwdGVkQWRJZD1BMDAzNDI0OVRIN01LT0o3RjZWUyZ3aWRnZXROYW1lPXNwX2F0ZiZhY3Rpb249Y2xpY2tSZWRpcmVjdCZkb05vdExvZ0NsaWNrPXRydWU&th=1) |
| Hex socket machine screws M3 0.5 x 16 mm | 29 | $6.73 (for pack of 50) | [McMaster Carr](https://www.mcmaster.com/91274A107/) |
| Hex socket machine screws M3 0.5 x 40 mm| 2 | $3.95 (for pack of 25) | [McMaster Carr](https://www.mcmaster.com/91292A024/) |
| M3 0.5 nut | 20 | $1.17 (pack of 100) | [McMaster Carr](https://www.mcmaster.com/90592A085/) |
| 6 mm ID x 19 mm OD x 6 mm width ball bearing | 2 | $7.44 ($3.72 each) | [Grainger](https://www.grainger.com/product/TRITAN-Miniature-Ball-Bearing-Shielded-49DD56?cm_vc=AZHPRV_P-DPO-75-082619&req=Products_You_Have_Recently_Viewed&cm_sp=Home-_-Products_You_Have_Recently_Viewed-_-AZHPRV_P-DPO-75-082619)|
| 0.1875" ID x 0.375" OD x 0.125" width ball bearing | 3 | $18.06 ($6.02 each) | [Grainger](https://www.grainger.com/product/TRITAN-Miniature-Ball-Bearing-Shielded-49DE11)|
| 6 mm x 100 mm steel shaft | 1 | $6.99 | [Amazon](https://www.amazon.com/6mmX100mm-Linear-Motion-Shaft-Diameter/dp/B08HYF2WPX/ref=sr_1_1_sspa?keywords=6mm%2Bsteel%2Bshaft&qid=1642618959&sprefix=6mm%2Bsteel%2Bsh%2Caps%2C46&sr=8-1-spons&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUExOEtEOUlUNjM3RzYmZW5jcnlwdGVkSWQ9QTA5MTI3MzhVVjI0RVNOOUk5NEMmZW5jcnlwdGVkQWRJZD1BMDM1NzMzODJHTzdTWDVTOU8zMUgmd2lkZ2V0TmFtZT1zcF9hdGYmYWN0aW9uPWNsaWNrUmVkaXJlY3QmZG9Ob3RMb2dDbGljaz10cnVl&th=1) |
| D-profile 1/4" diameter steel shaft | 1 | $7.17 | [McMaster Carr](https://www.mcmaster.com/8632T132/)|
| EasyDriver stepper motor driver | 1 | $14.95 | [Sparkfun](https://www.sparkfun.com/products/12779)
| Arduino Uno R3 | 1 | $22.95 | [Sparkfun](https://www.sparkfun.com/products/11021)|
| 1kΩ resistors | 2 | $0.95 (for pack of 20) | [Sparkfun](https://www.sparkfun.com/products/14492)|
| Hookup wire | 1 | $19.95 (for assorted pack) | [Sparkfun](https://www.sparkfun.com/products/11367)|
| Breakaway Headers | 1 | $1.50 | [Sparkfun](https://www.sparkfun.com/products/116)|
| Rocker Switch | 2 | $1.90 ($0.95 each) | [Sparkfun](https://www.sparkfun.com/products/8837)|
| 12V Power Supply | 1 | $8.70 | [McMaster Carr](https://www.mcmaster.com/70235K49/)|
| ABS 3D printer filament | ~200 g | $39.95 (for an 800 g spool) | [Amazon](https://www.amazon.com/Zortrax-Z-ABS-2-3D-Printer-Filament/dp/B08T7VD63K/ref=sr_1_2?crid=JVAS24O9TVHC&keywords=z-abs&qid=1642620658&sprefix=z-abs%2Caps%2C30&sr=8-2)|
| Rotary Potentiometer | 1 | $1.18 | [Mouser](https://www.mouser.com/ProductDetail/Bourns/PDB181-K425K-104B?qs=Ivs1Be2ZGq4sYukQEDBRmw%3D%3D)|
| 1 mm ID 3 mm OD 50A silicone tubing | 10 ft | $9.70 ($0.97 per foot) | [McMaster Carr](https://www.mcmaster.com/5054K303/)|
|1/32" ID, 1/16" OD, 50A silicone tubing | 10 ft | $8.20 ($0.82 per foot) | [Mcmaster Carr](https://www.mcmaster.com/5236K204/)|
| Total (the per pump price is lower if building multiple pumps) | | ~ $190 (~$140 if you already have hookup wire and 3D printer filament)  | | 

